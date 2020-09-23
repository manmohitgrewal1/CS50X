// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26
int static word_counter=0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[N];


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        word_counter++;
        // node_insertion(word);
        int res = hash(word);
        node* value= (node*) malloc (sizeof(node));
        if (value == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }
        strcpy(value->word, word);
        value->next=NULL;
        if (!hashtable[res])
        {
            hashtable[res]= value;
        }
        else if (hashtable[res])
        {
            for(node* ptr= hashtable[res]; ptr!=NULL; ptr= ptr->next)
            {
                if (!ptr->next)
                {
                    ptr->next=value;
                    break;
                }
            }
        }
    }
    // for(int i=0;i<26;i++){
    // for(node* ptr= hashtable[i]; ptr!=NULL; ptr= ptr->next)
    // {
    //     printf("%p-%s\t",hashtable[i], ptr->word);
    // }
    // }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (word_counter>= 1)
    {
        return word_counter;
    }
    else
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *s_word)
{
    int word_len= strlen(s_word);
    char new_word[word_len];
    for(int i=0;i<word_len;i++)
    {
        new_word[i]=tolower(s_word[i]);
    }
    new_word[word_len]='\0';

    // printf("-> %s\n", new_word);
    int res= hash(new_word);
    if (!hashtable[res])
    {
        return false;
    }
    if (hashtable[res])
    {
        for(node* ptr= hashtable[res]; ptr!=NULL; ptr= ptr->next)
        {
            if (strcmp(ptr->word, new_word)==0)
            {
                return true;
            }
            else
            continue;
        }
    }

    return false;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i=0;i < 26;i++)
    {
    //     if(!hashtable[i])
    //     {
    //         continue;
    //     }
    //     else if (hashtable[i])
    //     {
            node* cursor= hashtable[i];
            while (cursor!=NULL)
            {
                node *tmp=cursor;
                cursor= cursor->next;
                free(tmp);
            }

        }


    return true;
}

