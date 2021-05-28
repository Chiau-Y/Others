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

void ReverseRecursion(struct Node* HeadPtr, struct Node* NextPtr){

    if (NextPtr == NULL) {
        head = HeadPtr;
        return;
    }
    
    ReverseRecursion(HeadPtr->next, NextPtr->next);
    NextPtr -> next = HeadPtr;
    HeadPtr -> next = NULL;
    return;
}

int main()
{
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(1000);
    Insert(81);
    Insert(36);
    
    ReverseRecursion(head, head->next);
    
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}
