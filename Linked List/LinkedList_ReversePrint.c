#include stdio.h
#include stdlib.h

struct Node{
    int val;
    int h;
    int y;
    struct Node next;
};

struct Node head = NULL;   global variable

void Insert(int x){
    struct Node temp = (struct Node)malloc(sizeof(struct Node));
    temp - val = x;
    temp - next = head;
    head = temp;
}

void ReversePrint(struct Node HeadPtr){
    if (HeadPtr == NULL) return;
    
    ReversePrint(HeadPtr-next);
    printf(%d ,HeadPtr-val);
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
    
    ReversePrint(head)

    return 0;
}
