#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cs50.h>
#include <math.h>

int main (void)
{
    string text= get_string("Text: ");
    int i=0;
    int word=1;
    int letter=0;
    int sentence=0;
    int grade;
    float index;
    float L;
    float S;
    while (text[i] != '\0'){

        if (((int)text[i]>=65 && (int)text[i]<=90) || ((int)text[i]>=97 && (int)text[i]<=122)){
            letter++;
        }
        else if (text[i] == ' '){
            word++;
        }
        else if ( text[i]== '.' || text[i]== '?' || text[i]== '!'){
            sentence++;
        }
        i++;
    }
    L=((float)letter / (float)word)*100;
    S=((float)sentence / (float)word)*100;
    index= 0.0588 * L - 0.296 * S - 15.8;
    grade= (int)round(index);
    printf("Words-> %d\tLetters-> %d\tSentences-> %d\n", word, letter, sentence);
    printf("%f , %f , %f\n", L,S,index);
    if (grade<1){
        printf("Before Grade 1\n");
        return 0;
    }
    if (grade> 16){
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %d\n",grade);
}