#include <stdio.h>
#include <cs50.h>
int main (void){
    int height;
    do {
        height = get_int("Height: ");
    }
    while(!(1<=height&& height<=8));
    int n=1;
    while (n<=height){
        for (int i=1; i<=(height-n); i++){
            printf(" ");
        }
        for (int i =1; i<=n; i++) {
            printf("#");
        }
        printf("  ");
        for (int i =1; i<=n; i++) {
            printf("#");
        }
        printf("\n");
        n++;
    }
}
