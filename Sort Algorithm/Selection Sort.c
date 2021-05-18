#include <stdio.h>
#include <limits.h>
#define Swap(A,B) {int temp = A; A = B; B = temp;}

void SelectionSort(int *ptr, int len){
    
    int  min, index_min = 0;   // The minimum number
    for(int i=0; i<len-1; i++){
        index_min = i;   // Initialize for min
        for(int j=i+1; j<len; j++){
            if (ptr[j] < ptr[index_min]) index_min = j ;   // Find the least number
        }
        if (i != index_min) Swap(ptr[i],ptr[index_min]);
        
        printf("\nMinimum : %2d ==> ",ptr[i]); // Print array
        for(int z=0; z<len; z++) printf("%d ",ptr[z]); 
    }
}

int main()
{
    int A[10] = {2,5,85,65,74,1,23,15,7,10};    // Original array
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    printf("\n\n------- Selection Sort -------"); 
    SelectionSort(&A[0], (sizeof(A)/sizeof(A[0])));
    
    printf("\n\nThe Array After Selection Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}