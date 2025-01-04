#include <stdio.h>
#include <cs50.h>
long suming (long num);
int main (void) {
    long a;
    do {
        a = get_long("credit card number");
    }
    while (!(a>100000000000));
    suming(a);



}
long suming (long num) {
    long i = 1;
    int p = 1;
    int sum = 0;
    int v=0;
    printf("%ld",num);

    while (i<=(num)){
        if ((p%2)==0){
            int u = (num%10)*2;
            int uu = u%10;
            int uuu = u/10;
            sum+=uu;
            sum+=uuu;
            printf("%i \n %i \n%i\n", u, uu, uuu);
            printf("sum %i \n",sum);

        } else{
            sum+=(num%10);
        }

        p+=1;
        num/=10;
        if (num>=51 && num<=55){
            v=11;
        } else if (num==4){
            v=12;
        } else if (num==34 || num==37){
            v=13;
        }

    }
    if (sum%10 ==0){
        if (v==12) {
            printf("VISA");
        } else if(v==11) {
            printf("MASTERCARD");
        } else if (v==13) {
            printf("AMEX Gold");
        }
    } else{
        printf("INVALID");
    }
    return num;
}
