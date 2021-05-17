#include <stdio.h>

#define Swap(A,B) {int temp = A; A = B; B = temp;}

void ShakerSort(int *ptr, int len, int gap){
    
    int right=0, left=len-1;   
    while(right<left){
        for (int i=right; i<left; i++){    // maximum to right
            if (ptr[i]>ptr[i+1]) Swap(ptr[i],ptr[i+1]);
        }
        left--;
        
        printf("\nShake left  ==> "); // Print array
        for(int z=0; z<len; z++) printf("%d ",ptr[z]); 
        
        for (int i=left; i>right; i--){    // maximum to right
            if (ptr[i-1]>ptr[i]) Swap(ptr[i-1],ptr[i]);
        }
        right++;
        
        printf("\nShake right ==> "); // Print array
        for(int z=0; z<len; z++) printf("%d ",ptr[z]); 
    }
}

int main()
{
    int A[10] = {2,5,85,65,74,7,23,15,1,10};    // Original array
    int Gap = 4;
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    printf("\n\n------- ShakeSort -------"); 
    ShakerSort(&A[0], (sizeof(A)/sizeof(A[0])), Gap);
    
    printf("\n\nThe Array After Shaker Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}