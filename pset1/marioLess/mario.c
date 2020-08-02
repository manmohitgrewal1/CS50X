#include <stdio.h>

int main()
{
    int height;
    printf("Height: ");
    scanf("%d", &height);
    while (height<=0 || height>8){
        printf("Height: ");
        scanf("%d", &height);
    }
    for (int i=0; i< height; i++){
        for (int j=0; j< height; j++){
            if (j>= height-i-1){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}



