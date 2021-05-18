#include <stdio.h>

void InsertionSort(int *ptr, int len){
    
    int temp, current;   
    for(int i=1; i<len; i++){
        temp = ptr[i];
        for(int j=i; j>0 && temp < ptr[j-1]; j--){
            ptr[j] = ptr[j-1];
            ptr[j-1] =  temp;
        }
        printf("\nValue : %2d ==> ",temp); // Print array
        for(int z=0; z<len; z++) printf("%d ",ptr[z]); 
    }
}

int main()
{
    int A[10] = {2,5,85,65,74,1,23,15,7,10};    // Original array
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    printf("\n\n------- Insertion Sort -------"); 
    InsertionSort(&A[0], (sizeof(A)/sizeof(A[0])));
    
    printf("\n\nThe Array After Insertion Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}