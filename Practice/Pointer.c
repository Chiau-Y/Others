#include <stdio.h>

// Priority : () -> ++ -> *
int main()
{
    int a[6] = {1,2,3,4,5,6};

    int *ptr = a;
    int i = 0;
    
    // // (1)
    *(ptr++) += 100;    // 1 -> 101
    *(++ptr) += 100;    // 3 -> 103
    
    // // (2)
    // ++(*ptr) += 100;    // lvalue error
    // *(++ptr) += 100;    // 2 -> 102 
    
    // (3)
    // *ptr += 100 + (*ptr+1);    // 1 -> 103
    // *ptr += 100 + (*ptr++);    // 2 -> 103
    
    for(int z=0; z<5; z++) printf("%d ",a[z]);    
    
    // (4)
    // printf("%d\n",*(ptr++));    // 100,a[i++]
    // printf("%d\n",*ptr++);  // 100,a[i++]
    
    // printf("%d\n",*(++ptr));    // 200,a[++i]
    // printf("%d\n",*++ptr);    // 200,a[++i]
    
    // printf("%d\n",++*ptr);    // 101,a[i]+1
    // printf("%d\n",++(*ptr));  // 101,a[i]+1
    
    
    return 0;
}