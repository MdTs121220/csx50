// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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
FILE *dict_pointer = fopen(dictionary, "r"); //Open dictionary file
if (dictionary == NULL) // Check if null
{
    printf("Unable to open %s\n", dictionary);
    return false;
    }
    char next_word[LENGTH + 1]; // Initialise word array
    while (fscanf(dict_pointer, "%s", next_word) != EOF) // Read strings from file one at a time
    {
        node *n = malloc(sizeof(node)); // Create new node for each word
        if (n == NULL)
        {
            return false;
            }
            strcpy(n->word, next_word); // copy word into node using strcopy
            int hash_value = hash(next_word); // Hash word to obtain hash value
            n->next = table[hash_value]; // Insert node into hash table at that location
            table[hash_value] = n;
            dict_size++;
            }
            fclose(dict_pointer); // Close file
            return false;
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
