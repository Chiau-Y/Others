#include <stdio.h>


unsigned int ABS(int x){

    // unsigned int shift will be filled in -1
    // signed int shift will be filled in 0
    
    return (x ^ (x >> 31)) + ((x >> 31)&1);
    // return (x + (x >> 31)) ^ (x >> 31);   // another method
    
}

// Assume there is a 32 bits number
int main()
{
    unsigned int ans;
    
    ans = ABS(-6); 
    printf("After ABS = %d\n", ans);
    
    ans = ABS(6); 
    printf("After ABS = %d\n", ans);
    
    ans = ABS(0); 
    printf("After ABS = %d\n", ans);
    
    ans = ABS(-100); 
    printf("After ABS = %d\n", ans);
    
    return 0;
}
