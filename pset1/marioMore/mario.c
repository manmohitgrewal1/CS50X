
#include <stdio.h>

int main(void)
    // Prompt user input for height of the pyramid 

{  int n;
    do 
    {
        n= get_int("Pyramid's Height: ");
    }
    while(n<0 || n>23);
    // Making rows - represented by the variable "i"
    for (int i= 1; i<=n; i++)
   
    {
        for (int j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        for (int j=1; j<= i; j++)
        {
            printf("#");
        }
        for (int j=1; j<=2; j++)
        {
            printf(" ");
        }
         for (int j=1; j<= i; j++)
        {
             printf("#");
        }
        
        printf("\n");
    }
}
