#include <stdio.h>

void Check(unsigned int x){
    
    printf("%3.d belongs to %d\n",x,((((x-1)>>5)+1)<<5));  
}


// 1~32 to 32, 33~64 to 64, and so on...
int main()
{
  
    Check(1);
    Check(31);
    Check(32);
    Check(64);
    Check(65);
    Check(185);
    
    return 0;
}
