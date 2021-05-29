#include <stdio.h>

void SumOne(unsigned int x){
    int sum = 0, shift = -1;
    
    while(shift++ < 31 && (x >> shift)) sum+=(x >> shift) & 1;

    printf("There is/are %d one in %d\n", sum, x);
}

int SumOne2(unsigned int x){
    int sum = 0;
    
    while( x ){
        x &= (x-1);
        sum++;
    } 

    return sum;
}

// Assume there is a 32-bits number
int main()
{
    
    int ans;
    // First method, not good
    SumOne(0);  // 0
    SumOne(1);  // 1
    SumOne(2);  // 1
    SumOne(15); // 4
    SumOne(1296);   // 3
    
    // Second method
    ans = SumOne2(0);  // 0
    printf("\nThere is/are %d one in 0\n", ans);
    ans = SumOne2(1);  // 1
    printf("There is/are %d one in 1\n", ans);
    ans = SumOne2(2);  // 1
    printf("There is/are %d one in 2\n", ans);
    ans = SumOne2(15); // 4
    printf("There is/are %d one in 15\n", ans);
    ans = SumOne2(1296);   // 3
    printf("There is/are %d one in 1296\n", ans);
    
    return 0;
}
