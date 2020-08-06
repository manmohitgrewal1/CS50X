#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
    // prompt user for change input & limit the input to positive integers
{    float dollars;
    do
    {
        dollars= get_float("Change owned: ");
    }
    while (dollars<0);
 // Using math.h function   we round off the amount
 int cents=round(dollars*100);  
 // Creating a variable "coins" which will store the number of coins to be returned 
 int coins=0;
 while (cents>=25)
 {
  cents-=25;
     coins++;
 }
 while (cents>=10)
 {
     cents-=10;
     coins++;
 }
 while (cents>=5)
 {
     cents-=5;
     coins++;
 }
 while (cents>=1)
 {
     cents-=1;
     coins++;
 }
 // Printing command for showing the the number to coins to be returned
 printf("Total coins returnd= %d\n", coins);
 }
