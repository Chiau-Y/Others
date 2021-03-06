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

void Delete(int position){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    if (position != 1){
        
        struct Node* head_temp = head;
        position = position-2;
        
        while (position != 0){  // Find the position
            head_temp = head_temp -> next;
            position--;
        } 
        
        temp = head_temp -> next;
        head_temp -> next = temp -> next;
        temp -> next = NULL;
        free(temp);
    }
    else{   // delete head
        temp = head;
        head = temp -> next;
        temp -> next = NULL;
        free(temp);
    }

}

int main()
{
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(1000);
    Insert(81);
    Insert(36);
    
    Delete(3);
    Delete(1);
    
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}
