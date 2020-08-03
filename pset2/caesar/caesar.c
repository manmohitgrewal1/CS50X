#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int main(int argc, string argv[])

{
    if (!argv[1] || argc >=3 || argv[1]<0){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int ascii;
    for (int i=0; i<strlen(argv[1]); i++){
        ascii= (int)argv[1][i];
        if (ascii >=48 && ascii<=57){
            continue;
        }
        else{
            printf("Usage: ./caesar key\n");
            return 1;
        } 
    }
    string plain = get_string("Plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        
        int val = (int)plain[i];
        if (val>=65 && val<=90){
         val= val - 65;
        int hash = (val + atoi(argv[1])) % 26;
        char crypt= (char) hash + 65;
        printf("%c", crypt); 
        
        }
        else if(val>=97 && val<= 122){
        val= val - 97; 
        int hash = (val + atoi(argv[1])) % 26;
        char crypt= (char) hash + 97;
        printf("%c", crypt); 
    }
    else {
        printf("%c", plain[i]);
    }
    }
    printf("\n");
}
