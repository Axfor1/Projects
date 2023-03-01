// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node
typedef struct node
{
char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int I = 2600;

// Hash table
node *table[I];

// Counter for size
int counter;

// Loads dictionary into memory
bool load(const char *dictionary)
{
    // Making a pointer
    FILE *file = fopen(dictionary, "r");
    // Declaring a temporary word to store the copied word
    char w[LENGTH + 1];
    // Check if memory is available
    if (file == NULL)
        return false;

    // Clearing to NULL
    for (int i = 0; i < I; i++)
    {
        table[i] = NULL;
    }

    // run until the file is finished
    while(fscanf(file, "%s", w) != EOF)
    {
        node *n = malloc(sizeof(node));
        // Check if memory is available
        if (n == NULL)
            return false;

        // Copy the word from the dictionary to w
        strcpy(n -> word, w);
        // Store the index at which the word should be stored
        int pos = hash(n -> word);

        // Set the 'next' value of 'n' to point at the head of the list
        n -> next = table[pos];
        table[pos] = n;

        // Increase the counter per word copied
        counter++;

    }
    size();
    // close the file
    fclose(file);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        sum +=  (int) word[i];
    }
    return (sum % I);
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Returns true if word exists else false
bool check(const char *word)
{
    // Make a temporary string to store the word to be checked
    char *temp = malloc(sizeof(char) * (LENGTH + 1));
    for (int i = 0; i < LENGTH; i++)
    {
        temp[i] = tolower(word[i]);
    }
    // Getting the hash
    int h = hash(temp);
    node *ptr = malloc(sizeof(node));
    temp[LENGTH] = '\0';

    // ptr searches table where the word would be
    ptr = table[h];
    while (ptr != NULL)
    {
        if (strcasecmp(temp, ptr -> word) == 0)
        {
            return true;
        }
        ptr = ptr -> next;
    }
    return false;
}

// Unloads dictionary from memory
bool unload(void)
{
    for (int i = 0; i < I; i++)
    {
        node *ptr = table[i];
        // Free each linked list
        while (ptr != NULL)
        {
            node *tmp = ptr;;
            ptr = ptr->next;
            free(tmp);
        }
    }
    return true;
}