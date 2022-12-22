//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//Speller.c
//---------------------------------
// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>  //add new library
#include <stdlib.h> //add new library
#include <ctype.h> //add new library
#include <string.h> //add new libraryy
#include <strings.h> //add new library


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

    while (p != NULL) // cek more words
    {
        if (strcasecmp(word, p->word) == 0) // try compare case insensitive
        {
            return true; // match
        }

        p = p->next; // move to the next word
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // try use djb2 by Dan Bernstring - adapted to be case insensitive
    unsigned long hash = 5381; //number djb2
    int c;
    while ((c = tolower(*word++))) // convert to lowercase
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c *
    }
    return hash % N; // keep result in table
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r"); // initalize a pointer to our stream
    if (dict == NULL) // check for if errors
    {
        return false;
    }
    char word[LENGTH + 1]; // create a buffer to keep word
    while (fscanf(dict, "%s", word) != EOF) // scan until EOF
    {
        node *n = malloc(sizeof(node)); // allocate enough memory for node
        if (n == NULL) // failed allocation handlg
        {
            return false;
        }
        strcpy(n->word, word); // copy word to n propery
        int hash_value = hash(word); // recieve a hash for word value
        n->next = table[hash_value]; // point node
        table[hash_value] = n; // insert the new node
        dict_size++; // increase dictionary word count
    }

    fclose(dict); // close stream
    return true; // try check if we made it this nothing went wrong
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (dict_size > 0) // if a dictionary is loaded
    {
        return dict_size; // return its size
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

        while (p != NULL) // while there are nodes left in the bucket
        {
            node *tmp = p; // alias current node to temp
            p = p->next; // move our pointer to the next node
            free(tmp); // do the above to avoid leaking memory
        }

        if (p == NULL && i == N - 1) // check if the last node is null
        {
            return true; // everything was free'd successfully
        }
    }
    return false; // something went wrong
}
//some code taken from staff reference