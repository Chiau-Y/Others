#include <stdio.h>

void HighestOrderBit(unsigned int n){
    
    int ans = 1, shift = 1;
    
    while (n >> shift++) ans *= 2;
    
    printf("%3.d belongs to %d\n",n,ans); 
}

void HighestOrderBit2(unsigned int n){
    
    unsigned int nn = n;
    
    n |= (n >>  1);
    n |= (n >>  2);
    n |= (n >>  4);
    n |= (n >>  8);
    n |= (n >> 16);
    
    printf("%3.d belongs to %d\n",nn,n - (n >> 1));

}

// Assume there is a 32-bits number
int main()
{
    
    // First method, not good
    // HighestOrderBit(1);    // 1
    // HighestOrderBit(2);    // 2
    // HighestOrderBit(4);    // 4
    // HighestOrderBit(9);    // 8
    // HighestOrderBit(63);    // 32
    // HighestOrderBit(652);    // 0010 1000 1100, 512
    // HighestOrderBit(12652);    // 8192
    
    // // Second method, good
    // HighestOrderBit2(1);    // 1
    // HighestOrderBit2(2);    // 2
    // HighestOrderBit2(4);    // 4
    // HighestOrderBit2(9);    // 8
    // HighestOrderBit2(63);    // 32
    // HighestOrderBit2(652);    // 0010 1000 1100, 512    
    // HighestOrderBit2(12652);    // 8192 
    
    return 0;
}
