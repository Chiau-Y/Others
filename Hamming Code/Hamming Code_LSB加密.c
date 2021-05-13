#include <stdio.h>
#include <string.h>

// -------------------------- Dec to Bin ---------------------------- //
// the dec num, ptr to array, ptr to length
void DectoBin (int dec, int *ptr_array, int *ptr_len)
{
    long int q = dec;
    int remain;
    
    while (q != 0)
        {
            remain = q % 2;
            q = q / 2;
            *ptr_array++ = remain; // 取值後，位置+1
            (*ptr_len)++; // 取值後做+1
        }
}
// -------------------- Calculation for parity bits ------------------ //
// M ≦ 2^n ，K = n + 1
// M + K is total bit 
int LenofParityBits(int len){
    int base = 1, count_k = 1;
    
    while (len > (base*=2)) count_k++;
    
    return count_k + 1;
}


// ------------------------- Data transferred --------------------- //
void HammingCode(int* b_ptr, int* h_ptr, int h_len, int m_len){
    int xor_value = -1;//, initial = b_ptr;

    h_ptr += 2; // Start from H[2]
    for (int i=3; i<= h_len ; i++){ 
        // put the value into array except for parity bit
        if ((i)&(i-1)){
            if (*b_ptr == 1){
                // set the hamming code
                *h_ptr = 1;
                // xor the index
                if (xor_value == -1) xor_value = i;
                else xor_value^=i;
            } 
            b_ptr++;
        }
        h_ptr++;
    }

    // put parity bit into array 
    h_ptr -= h_len;
    *h_ptr++ = xor_value&1;
    for (int i=2; (i<=h_len); i++, h_ptr++){
        if (!((i)&(i-1))){
            xor_value = xor_value>>1;
            *h_ptr = xor_value&1;             
        }
    }   
}


// ---------------------------- Main ------------------------------ //
int main ()
{
    int num, length = 0; // num needs to larger than and equal to 2
    int bin[32] = {0}; // binary

    printf ("Decimal : ");  // Input a number
    scanf("%d", &num);
    
    DectoBin(num, &bin[0], &length); // return binary and length
    
    printf ("Binary : ");
    // print binary
    for (int i=length-1; i>=0 ;i--){
        printf ("%d", bin[i]);
    }
    
    int k = LenofParityBits(length); // Length of Parity Bit
    
    printf ("\n\nThe Length of Massage = %d bits\n", length);
    printf ("The Length of Parity Bit = %d bits\n", k);
    printf ("The Length of Transferred Data  = %d bits\n", k+length);
    
    int Ham[k+length];   // Array for Hamming Code  
    memset(Ham, 0, (k+length)*sizeof(int));  
    HammingCode(&bin[0], &Ham[0], k+length, length);    // Transferred Data, Hamming Code
    
    printf ("\nHamming Code : ");
    for (int i=k+length-1; i>=0 ;i--){
        printf ("%d", Ham[i]);
    }  
    
    getchar();
    return 0;
}