#include <stdio.h>
#include <pthread.h>

// Reference : https://is.gd/vRXZ9I

/* pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; */
pthread_mutex_t mutex;

int count;

void * thread_run1(void *arg)
{
    int i;
    pthread_mutex_lock(&mutex);
    // thread_mutex_unlock(&mutex);  // 放這等於沒有拿到lock，Thread 2 會先執行
    for (i = 0; i < 3; i++) {
        printf("Thread 1 value of count %d\n",  ++count);
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}

void * thread_run2(void *arg)
{
    int i;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < 3; i++) {
        printf("Thread 2 value of count %d\n",  ++count);
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}

int main(int argc, char argv[])
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, 0);
    pthread_create(&thread1, NULL, thread_run1, 0);
    pthread_create(&thread2, NULL, thread_run2, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_mutex_destroy(&mutex);
    return 0;
}