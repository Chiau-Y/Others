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

void Insert_Position(int x, int position){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  
    if (position != 1){
	    struct Node* head_temp = head;
        position = position-2;
        
        while (position != 0){
            head_temp = head_temp -> next;
            position--;
        } 
        
        temp -> val = x;
        temp -> next = head_temp -> next;
        head_temp -> next = temp;        
    }
    else{
        temp -> val = x;
        temp -> next = head;
        head = temp;        
    }
}

int main()
{
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(1000);
    Insert(81);
    
    Insert_Position(18,1);
    Insert_Position(11,4);
    Insert_Position(999,8);
    
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}
