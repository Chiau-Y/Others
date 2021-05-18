#include <stdio.h>

#define Swap(A,B) {int temp = A; A = B; B = temp;}

int Partition(int *ptr, int begin, int end){
    
    int pivot = end;
    int i = begin-1; // position of last minimum number 
                    // the next one will be larger than pivot
    
    for (int j=begin; j<=end; j++){
        if (ptr[j] < ptr[pivot]){   // find the one smaller than pivot
            i++;    // find the one lager than pivot
            Swap(ptr[i],ptr[j]);
        }
    }
    
    i++;
    Swap(ptr[i],ptr[pivot]);
    return i; // return pivot position
}

void QuickSort(int *ptr, int begin, int end, int len){  // len only for print
    
    if (end > begin){
        int pivot = Partition(ptr,begin,end);

        printf("\nPivot = %2d [%2d,%2d]==> ", ptr[pivot],ptr[begin],ptr[end]);
        for(int z=0; z<len; z++) printf("%d ",ptr[z]);
        
        QuickSort(ptr,begin,pivot-1,len);
        QuickSort(ptr,pivot+1,end,len);
    }
    return;
}

int main()
{
    int A[10] = {2,5,85,65,74,7,23,15,1,10};    // Original array
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    printf("\n\n------- QuickSort -------"); 
    QuickSort(&A[0], 0, (sizeof(A)/sizeof(A[0])-1), sizeof(A)/sizeof(A[0]));
    
    printf("\n\nThe Array After Quick Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}