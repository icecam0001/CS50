// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>    // for FILE, fopen, fscanf, etc.
#include <stdlib.h>   // for malloc
#include <strings.h>
#include <string.h>  // for strcpy
int wordcount = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;


// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
//dont malloc for pointers remember that
    int firsttwo = hash(word);
    node *cursor = table[firsttwo];
    if (cursor == NULL) {
        return false;
    }
    while(cursor !=NULL) {
         if (strcasecmp(cursor->word, word) == 0) {
            return true;
        }
        if (cursor->next==NULL) {
            return false;
        }
        cursor = cursor->next;



    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char* word) {
    if (!word || word[0] == '\0' || word[1] == '\0') return -1;  // Check for empty/short strings

    char first = toupper(word[0]);
    char second = toupper(word[1]);

    if (first < 'A' || first > 'Z' || second < 'A' || second > 'Z') return -1;

    return ((first - 'A') * 26 + (second - 'A'));
}

// Loads dictionary into memory, returning true if successful, else false


bool load(const char* dictionary) {
    FILE* file = fopen(dictionary, "r");
    if (file == NULL) {
        return false;
    }

    char wordd[LENGTH];
    while (fscanf(file, "%s", wordd) != EOF) {
        node* temp = malloc(sizeof(node));
        if (temp == NULL) {
            fclose(file);
            return false;
        }

        strcpy(temp->word, wordd);

        int x = hash(wordd);
        temp->next = table[x];
        table[x] = temp;
        wordcount++;
    }

    fclose(file);
    return true;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursortwo= table[0];
    node *temp = cursortwo;


    for (int i = 0; i<N; i++) {
        cursortwo= table[i];
        while(cursortwo !=NULL) {
            temp = cursortwo;
            cursortwo = cursortwo->next;
            free(temp);
        }
    }
    return true;
}
