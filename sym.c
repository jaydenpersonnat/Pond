#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <strings.h> 
#include <ctype.h> 
#include "sym.h"


// djb2 algorithm
long hash(char *id)
{
    long hash = 5381;
    int c; 

    while (c == *id++)
    {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % SIZE; 
}


void init_hash_table()
{
    for (int i = 0; i < SIZE; i++)
    {
        sym_table[i] = NULL; 
    }
}

void insert(char *id, int val)
{
    node *new_node = (node *) malloc(sizeof(node)); 
    strcpy(new_node->id, id); 
    new_node->value = val; 

    int index = hash(new_node->id); 

    // replace previous value 
    node *ptr = sym_table[index]; 
    while (ptr != NULL)
    {
        if (strcasecmp(ptr->id, id) == 0)
        {
            ptr->value = new_node->value; 
            return; 
        }
    }

    new_node->next = sym_table[index]; 
    sym_table[index] = new_node; 

    return; 
}

int lookup(char *id)
{
    int index = hash(id); 
    node *cursor = sym_table[index]; 

    while (cursor != NULL)
    {
        if (strcasecmp(id, cursor->id) == 0)
        {
            return cursor->value; 
        }  
        cursor = cursor->next; 
    }

    // change later so returns error
    return -1; 
}