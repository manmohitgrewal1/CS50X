#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main(void)
{    
    long card;
    int sum_m = 0, sum_mn = 0;
    // prompt user input
    do
    {
        card = get_long("Enter the card number: ");
    }
    // Limiting the input to positive integers only
    while (card < 0);
    // check=1 --> measuring the length 
    int len = 0;
    long bkp = card;
    int r;
    for (; card > 0; len++)
    {
        card /= 10;
    }
    card = bkp;
    if (len == 13 || len == 15 || len == 16)
    { 
        /* if the length of 13 or 15 or 16 then it will proceed furtherelse declare the card invaild*/
        // Check=2 --> checkin the Luhn's Algorithm
        for (int i = 1; i <= len; i++)
        {
            r = card % 10;
            if (i % 2 == 0)
            {
                int num = r * 2;
                while (num > 0)
                {
                    int rem = num % 10;
                    sum_m = sum_m + rem;
                    num /= 10;
                }
            }
            else
            {
                sum_mn = sum_mn + r;
                card /= 10;
            }
        }
        if ((sum_m + sum_mn) % 10 == 0)
        {
            // check 3 --> Identify the card type
            int check = bkp / (long) pow(10, 14);
            if (bkp / (long) pow(10, 15) == 4)
            {    
                printf("VISA Card\n");
            }
            else if (check == 51 || check == 52 || check == 53 || check == 54 || check == 55)
            {
                printf("master card\n");
            }
            else if (check == 34 || check == 37)
            {
                printf("AMEX\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }

}
