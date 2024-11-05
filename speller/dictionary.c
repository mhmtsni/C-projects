// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>      
#include "dictionary.h"
#include <strings.h>
#include <string.h>

#include <stdlib.h> 
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;


// TODO: Choose number of buckets in hash table
const unsigned int N = 10000000;
int count = 0;
// Hash table
node *table[N]; 

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *current = table[index];
    
    while (current != NULL)
    {
        if (strcasecmp(current->word, word) == 0)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31 + tolower(word[i])) % N;
    }
    return hash_value;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
     for (int i = 0; i < N; i++) {
        table[i] = NULL;
    }
    
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF) {
        node *word = malloc(sizeof(node));
        if (word == NULL) {
            return false;
        }
        strcpy(word->word, buffer);
        int index = hash(word->word);
        word->next = table[index];
        table[index] = word;
        count++;
        
    } 
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) {
        node *current = table[i];
        while(current != NULL) {
            node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    return true;
}
