#include "ev.h"

typedef struct node
{
    // possibly make union 

    struct expr *value; 
    char id[MAX_STRING_SIZE]; 
    struct node* next; 
}
node;

node *sym_table[TABLE_SIZE];

// Hash function 
long hash(char *id); 

void init_hash_table(); 

void insert(char *id, expr *val);

expr *lookup(char *id);
