// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>  //new library
#include <stdlib.h> //new library


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int dict_size = 0; //type dictionary size

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
   bool load(const char *dictionary)
   {
    FILE *dict = fopen(dictionary, "r"); // initalize a pointer to our stream
    if (dict == NULL) // check for errors
    {
        return false; // fail fast and return false; // fail fast and return false
        }

        char word[LENGTH + 1]; // create a buffer to hold our word
        while (fscanf(dict, "%s", word) != EOF) // scan until we hit EOF
        {
            node *n = malloc(sizeof(node)); // allocate enough memory for a node
            if (n == NULL) // failed allocation handling
            {
                return false;
                }
        }

        strcpy(n->word, word); // copy word to n's word property

        int hash_value = hash(word); // recieve a hash value for word

        n->next = table[hash_value]; // point node to the head of its bucket
        table[hash_value] = n; // insert the new node
        dict_size++; // increase globally declared dictionary word count
    }

    fclose(dict); // close stream

    return true; // if we made it this far nothing went wrong!
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
