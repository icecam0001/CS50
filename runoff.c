#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdbool.h>  // Added for bool type

int main(int argc, string argv[])
{
    typedef struct
    {
        string name;
        int votes;
        bool inrace;
    } candidate;

    candidate candidates[argc];
    for (int i = 0; i < (argc - 1); i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].inrace = true;
    }

    int users = get_int("How many voters: ");

    string voted[users][argc - 1];  // Moved array declaration outside the loop
    for (int i = 0; i < users; i++)
    {
        int sum = 0;
        for (int k = 0; k < argc - 1; k++)
        {
            voted[i][k] = get_string("Choice %i: ", (k + 1));
        }
    }
    int m =(argc-2);
    while (1)
    {


        // Reset votes
        for (int i = 0; i < (argc - 1); i++)
        {
            candidates[i].votes = 0;
        }

        // Count votes
        for (int i = 0; i < users; i++)
        {
            int lmao=0;
            for (int j = 0; j < (argc - 1); j++)
            {

                for (int y = 0; y < argc - 1; y++)
                {
                    string a = candidates[y].name;  // Changed to y index
                    if (strcmp(a, voted[i][j]) == 0)  // Changed to j index
                    {
                        if (candidates[y].inrace == true)  // Changed to y index
                        {
                            candidates[y].votes += 1;  // Changed to y index
                            lmao=1;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if (lmao==1) {
                    break;
                }
            }
        }
        m=(argc-2);
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


            }


        }


        if (swapped==0){
            break;
        }
    }
    if (candidates[m].votes > (users)/2) {
            printf("%s wins \n", candidates[m].name);
            printf("%s %i %s %i %s %i", candidates[0].name, candidates[0].votes, candidates[2].name, candidates[2].votes, candidates[m].name, candidates[m].votes);
            break;
        } else{
            for (int gg = 0; gg<(argc-1); gg++){
                if (candidates[gg].inrace == true) {
                    candidates[gg].inrace = false;
                    break;
                }
            }
        }
    }
}
