#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int compution (string terminal);
int main (void) {
    string first = get_string("Player 1");
    string second = get_string("Player 2");
    int sumone = compution(first);
    int sumtwo = compution(second);
    if (sumone>sumtwo){
        printf("Player one wins");
    } else if (sumtwo>sumone){
        printf("player 2 wins");
    } else{
        printf("TIE!");
    }

}
int compution (string terminal){
    int sum =0;
    int length = strlen(terminal);
    for (int i=0; i<length; i++){
        char a = toupper(terminal[i]);
        if (a == 'A' || a == 'E' || a == 'I' || a == 'N' || a == 'O' || a == 'R' || a == 'S' || a == 'T' || a == 'U'){
            sum+=1;
        } else if (a == 'B' || a == 'C' || a == 'M' || a == 'P'){
            sum+=4;
        } else if (a == 'F' || a == 'H' || a == 'V' || a == 'W' || a == 'Y'){
            sum+=5;
        } else if (a == 'D'|| a == 'G'){
            sum+=2;
        } else if (a == 'B' || a == 'C' || a == 'M'){
            sum+=3;
        }  else if (a == 'Q'|| a == 'Z'){
            sum+=10;
        } else if (a == 'J'|| a == 'X'){
            sum+=8;
        }
    }
    return sum;
}

