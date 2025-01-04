#include <stdio.h>
#include <string.h>
#include <cs50.h>
int main (int argc, string argv[]){
    typedef struct{
        string name;
        int votes;
    } candidate;

    candidate candidates[argc];
    for (int i = 0; i<(argc-1); i++){
        candidates[i].name = argv[i+1];
        candidates[i].votes =0;
    }

    int users = get_int("How many voters: ");
    for (int i=0; i<users; i++) {
        int sum =0;

        string voted = get_string("vote: ");
        for (int j=0; j<argc-1; j++){
            string a= candidates[j].name;
            if (strcmp(a, voted) ==0){
                candidates[j].votes +=1;
                sum+=1;
            }
        }
        if (sum==0){
            printf("Invalid Vote");
        }
    }
    int tcount=0;
    int trackerk =0;
    while(1){
        int swapped = 0;
        for (int k=0; k<(argc-2); k++){
            if (candidates[k].votes>candidates[k+1].votes){
                string temp = candidates[k+1].name;
                int tempp = candidates[k+1].votes;
                candidates[k+1].name = candidates[k].name;
                candidates[k+1].votes = candidates[k].votes;
                candidates[k].votes = tempp;
                candidates[k].name = temp;
                swapped=1;

                tcount=0;

            } else if (candidates[k].votes<candidates[k+1].votes){
                tcount=0;


            } else if (candidates[k].votes==candidates[k+1].votes){
                tcount+=1;

            }
            trackerk = k;

        }
        if (swapped==0){
            break;
        }
    }

    if (!(tcount==0)){
        printf("TIE");
        for (int i=0; i<tcount+1; i++){
            printf("%s \n", candidates[trackerk+1-i].name);
        }
    } else{
        printf("%s", candidates[trackerk+1].name);
    }
}
