#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <strings.h> 
#include <ctype.h> 
#include "sym.h"
#include "ev.h"


node *sym_table[TABLE_SIZE];

// djb2 algorithm
long hash(char *id)
{
    long hash = 5381;
    int c; 

    while (c == *id++)
    {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % TABLE_SIZE; 
}


void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        sym_table[i] = NULL; 
    }
}

void insert(char *id, expr *val)
{
    node *new_node = (node *) malloc(sizeof(node)); 
    strcpy(new_node->id, id); 
    new_node->value = val; 

    int index = hash(new_node->id); 

    new_node->next = sym_table[index]; 
    sym_table[index] = new_node; 

    return; 
}

expr *lookup(char *id)
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

    // change later so returns error - create type NONE or NOT FOUND
    char varidname[MAX_STRING_SIZE];
    snprintf(varidname, sizeof(varidname), "variable \"%s\" not found", id);
    return create_eval_error(varidname); 
}