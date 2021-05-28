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

void Middle(struct Node* HeadPtr){
    struct Node* last = head;
    struct Node* mid = head;
    _Bool key = 0;
    
    while (last != NULL){
        last = last->next;
        if (key) mid = mid->next;
        key = key ^ 1;
    }
    
    printf("The middle number is %d \n\n", mid->val);
}

int main()
{
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(81);
    Insert(36);
    
    Middle(head);
    
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}
