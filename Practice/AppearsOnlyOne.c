#include <stdio.h>

void FindOnly(unsigned int *ptr, int len){
    unsigned int ans;
    
    ans = ptr[0];
    for(int i=1; i<len; i++){
        ans ^= ptr[i];
    }
    printf("The number apprears ones is %x\n",ans);
}

void FindTwoOnly(unsigned int *ptr, int len){
    
    unsigned int temp = ptr[0];
    for(int i=1; i<len; i++) temp ^= ptr[i];
    temp &= -temp; // Find Lowest bit which is 1
        
    int temp_0 = -1, temp_1 = -1;
    for(int i=0; i<len; i++) {
        // check the bit is 1 or 0
        if (((int)ptr[i] & temp) == temp ){              // the bit is 1
            if (temp_1 == -1) temp_1 = ptr[i];
            else temp_1 ^= ptr[i];
        } 
        else{                                   // the bit is 0
            if (temp_0 == -1) temp_0 = ptr[i];
            else temp_0 ^= ptr[i];
        } 
    }
    printf("The number apprears ones is %d and %d\n", temp_0, temp_1);
}

int main()
{
    unsigned int A[5] = {1,5,2,5,2};    // 1
    FindOnly(&A[0], sizeof(A)/sizeof(A[0]));
    
    unsigned int B[6] = {7,5,2,5,2,3};  // 3, 7
    FindTwoOnly(&B[0], sizeof(B)/sizeof(B[0]));
    
    return 0;
}
