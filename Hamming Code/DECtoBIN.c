
#include <stdio.h>

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


// ---------------------------- Main ------------------------------ //
int main ()
{
    int num = 13, length = 0;
    int bin[32] = {0}; // binary

    DectoBin(num, &bin[0], &length); // return binary and length

    printf ("Decimal : %d\n", num);
    printf ("Binary : ");    
    // print binary
    for (int i=length-1; i>=0 ;i--){
        printf ("%d", bin[i]);
    }
    
    getchar();
    return 0;
}
