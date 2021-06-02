#include <stdio.h>

int Merge(int *ptr, int front, int midd, int rear){
    
    // Divid the data to left and right array
    int LeftData[midd-front+1], RightData[rear-midd];
    int leftlen = midd-front+1, rightlen = rear - midd;
    
    // Input the number to the arrays
    for (int i=0; i<leftlen; i++) LeftData[i] = ptr[front+i];
    for (int i=0; i<rightlen; i++) RightData[i] = ptr[midd+1+i];
    
    // Compare
    int leftindex = 0, rightindex = 0;
    for (int i=0; i<leftlen+rightlen; i++){
        if (leftindex < leftlen && rightindex >= rightlen) ptr[front+i] = LeftData[leftindex++];
        else if (leftindex >= leftlen && rightindex < rightlen) ptr[front+i] = RightData[rightindex++];
        else if (LeftData[leftindex] < RightData[rightindex]) ptr[front+i] = LeftData[leftindex++];
        else ptr[front+i] = RightData[rightindex++];
    }
}

void MergeSort(int *ptr, int begin, int end){  // len only for print
    
    if (begin >= end) return;
    
    int mid = (begin + end)/2;
    
    MergeSort(ptr,begin,mid);
    MergeSort(ptr,mid+1,end);

    Merge(ptr,begin,mid,end);   // Merge two array
    
    printf("\n[%2d,%2d] ==> ", ptr[begin],ptr[end]);
    for(int z=0; z<10; z++) printf("%d ",ptr[z]);   
    
    return;
}

int main()
{
    int A[10] = {2,5,85,65,74,7,23,15,1,10};    // Original array
    
    printf("The Array : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    printf("\n\n------- MergeSort -------"); 
    MergeSort(&A[0], 0, (sizeof(A)/sizeof(A[0])-1));
    
    printf("\n\nThe Array After Merge Sort : "); // Print array
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) printf("%d ",A[i]);
    
    return 0;
}