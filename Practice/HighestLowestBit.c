#include <stdio.h>

int BitNum = 32;    // global variable

int HighestBit(unsigned int x){
    
    if (x == 0) return -1;
    
    int bit = BitNum; // answer
    int shiftbit = BitNum/2; // the step to shift right
    int half = shiftbit;    // Binary
    
    while(half != 0){
        if ((x >> shiftbit) == 0) {
            bit -= half;
            x = x << half;
        }
        half /= 2;
        shiftbit += half;        
    }

    return bit;
}

int LowestBit(unsigned int x){
    
    if (x == 0) return -1;
    
    int bit = 0; // answer
    int shiftbit = BitNum/2; // the step to shift left
    int half = shiftbit;    // Binary
    
    while(half != 0){
        if ((x << shiftbit) == 0) {
            bit += half;
            x = x >> half;
        }
        half /= 2;
        shiftbit += half; 
    }

    return bit;
}


// Assume there is a 32-bits number
int main()
{
    unsigned int num = 652;  // 0010 1000 1100
    
    int ansH = HighestBit(num);
    int ansL = LowestBit(num);  // first method, not good
    
    unsigned int num_two = -num & num; // Second method, 2's compliment, good
    int ansL_two = HighestBit(num_two);
    
    if (ansH == -1) printf("No Found !");
    else printf("The highest bit at bit %d \n", ansH);

    if (ansL == -1) printf("No Found !");
    else printf("The lowest bit at bit %d \n", ansL);
    
    if (ansL_two == -1) printf("No Found !");
    else printf("The lowest bit at bit %d by 2's compliment\n", ansL);
    
    return 0;
}
