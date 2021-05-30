#include <stdio.h>


unsigned int Remainder(unsigned int x, unsigned int n){

    return (x & (n - 1));
    
}

// Assume there is a 32 bits number
int main()
{
    unsigned int divisor = 8; // 2^n
    unsigned int ans;
    
    ans = Remainder(5, divisor); // dividend
    printf("Divide by %d is %d\n", divisor, ans);   
    
    ans = Remainder(9, divisor); // dividend
    printf("Divide by %d is %d\n", divisor, ans);

    ans = Remainder(12, divisor); // dividend
    printf("Divide by %d is %d\n", divisor, ans);

    ans = Remainder(125, divisor); // dividend
    printf("Divide by %d is %d\n", divisor, ans);    

    
    return 0;
}
