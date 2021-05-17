#include <stdio.h>

void ShellSort(int *ptr, int len, int gap){
    
    int temp;  
    while(gap){
            for (int i = gap; i<len; i++){
                temp = ptr[i];
                for(int j=i; j-gap>=0 && temp < ptr[j-gap]; j-=gap){
                    ptr[j] = ptr[j-gap];
                    ptr[j-gap] =  temp;
                }            
            }
        printf("\nGap : %d ==> ",gap); // Print array
        for(int z=0; z<len; z++) printf("%d ",ptr[z]);        
        gap/=2;
    }
}

int main()
{
    int A[10] = {2,5,85,65,74,7,23,15,1,10};    // Original array
    int Gap = 4;
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    printf("\n\n------- ShellSort -------"); 
    ShellSort(&A[0], (sizeof(A)/sizeof(A[0])), Gap);
    
    printf("\n\nThe Array After Shell Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}