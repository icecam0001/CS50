#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int main (int argc, string argv[]) {
    if (argc ==1) {
        printf("put a damn code");
        return 1;
    } else if (argc>2) {
        printf("too many strings");
        return 1;
    }
    string input = argv[1]
    int len = strlen(input);
    for (int i =0; i<=len; i++){
        for (int j=i+1; j<=len;j++){
            if (input[i] ==input[j]){
                return 1;
            }
        }
    }

    }

    string message = get_string("enter your cypther: ");
    int length = strlen(message);

    char newmessage[length+1];
    for (int aa=0; aa<strlen(message); aa++){
        char la = message[aa];
        char lp= tolower(la);
        int lpp = (int) la;
        int xx = lp -'a';
        if (lpp >= 97) {  // If uppercase
            char orig = input[xx];

            char lower = tolower(orig);

            newmessage[aa] = lower;
        } else {  // If lowercase
            char orig = input[xx];
            char upper = toupper(orig);
            newmessage[aa] = upper;

        }

    }
    newmessage[length] = '\0';
    printf("%s \n", newmessage);
}
