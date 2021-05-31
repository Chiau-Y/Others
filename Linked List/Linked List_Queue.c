#include <stdio.h>
#include <stdlib.h>

struct Node{
  int val;
  struct Node *next;
};

struct Node *front = NULL;	// global variable
struct Node *rear = NULL;	// global variable
int count = 0;

void Push (int x){
    
    count++;
    struct Node *temp = (struct Node *) malloc (sizeof (struct Node *));
    
    temp->val = x;
    temp->next = NULL;
    
    if (front == NULL && rear == NULL)
    {
      front = temp;
      rear = temp;
      return;
    }
    
    rear->next = temp;
    rear = temp;
    return;
}

void Pop (){

    if (front == NULL && rear == NULL)
    {
      printf ("Not elements in the linked list !");  
      return;
    }
    
    count--;
    struct Node *temp = (struct Node *) malloc (sizeof (struct Node *));
    
    temp = front;
    front = front->next;
    free (temp);
    return;
}

void GetBack (){

    if (front == NULL && rear == NULL)
    {
      printf ("Not Found !");
      return;
    }
    printf ("Back : %d\n", rear->val);
}

void GetFront (){

  if (front == NULL && rear == NULL)
    {
      printf ("Not Found !");
      return;
    }
  printf ("Front : %d\n", front->val);
}

void GetSize(){
    printf ("\nThere is/are %d element(s)\n", count);
}

void IsEmpty(){
    if (front == NULL && rear == NULL) {
        printf("\nEmpty !\n"); 
        return;
    }
    printf("\nNot Empty !\n");
}

// Queue, push/pop/back/front/size/is empty(T/F)
int main (void){
    
    Pop();  // Not elements in the linked list
    IsEmpty();  // Empty
    Push(6);
    Push(8);
    Push(7);
    Push(1);
    GetSize();  // 4
    Pop();  // remove 6
    GetBack();  // 1
    GetFront(); // 8
    GetSize();  // 3
    IsEmpty();  // Not Empty
    
    printf ("\nThe Linked List : ");    // 8 7 1
    while (front != NULL){
        printf ("%d ", front->val);
        front = front->next;
    }
    
    return 0;
}
