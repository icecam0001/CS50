#include <cs50.h>
#include <stdio.h>
int collatz (int n);
int main (void){
    int g =get_int("integer: ");
    collatz(g);
}
int collatz (int n){
    if (n==1){
        printf("%i \n", n);

        return 1;
    } else if (n%2==0){
        printf("%i \n", n);
        return collatz(n/2);
    } else {
        printf("%i \n", n);

        return collatz(3*n+1);

    }
}
