// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>  //new library
#include <stdlib.h> //new library
#include <ctype.h> //new library
#include <strings.h> //new library


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
    int hash_value = hash(word); // get a hash for the word
    node *p = table[hash_value]; // point at the head of word's bucket

    while (p != NULL) // while there is more nodes to look at
    {
        if (strcasecmp(word, p->word) == 0) // case insensitive string comparison
        {
            return true; // got a match
        }

        p = p->next; // move to the next word in the bucket
    }
    return false; // if we made it here no matches were found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    /* djb2 by Dan Bernstring - adapted to be case insensitive */
    unsigned long hash = 5381;
    int c;
    while ((c = tolower(*word++))) // convert chars to lowercase
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N; // keep result within bounds of our table
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
    if (dict_size > 0) // if a dictionary is loaded
    {
        return dict_size // return its size
    }

    return 0; // default return if no dict is loaded
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) // iterate through buckets
    {
        node *p = table[i]; // initalize pointer at head of current bucket
    }
    return false;
}
