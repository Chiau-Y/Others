#include <stdio.h>

#define Swap(A,B) {int temp = A; A = B; B = temp;}

void BubbleSort(int *ptr, int len){
    
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len; j++){
            if (ptr[j] < ptr[j-1]) Swap(ptr[j],ptr[j-1]);
        }        
    }
}

int main()
{
    int A[10] = {2,5,85,65,74,1,23,15,7,10};    // Original array
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    BubbleSort(&A[0], (sizeof(A)/sizeof(A[0])));
    
    printf("\n\nThe Array After Bubble Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}