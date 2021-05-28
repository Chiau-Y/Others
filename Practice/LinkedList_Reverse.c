#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* head = NULL;  // global variable

void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> val = x;
    temp -> next = head;
    head = temp;
}

void Reverse(struct Node* HeadPtr){
    struct Node* nextptr = NULL;
    struct Node* last = NULL;
    struct Node* current = head;
    
    while (current != NULL){
        nextptr = current -> next;
        current -> next = last;
        last = current;
        current = nextptr;        
    }
    
    head = last;
}

int main()
{
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(1000);
    Insert(81);
    Insert(36);
    
    Reverse(head);
    
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}
