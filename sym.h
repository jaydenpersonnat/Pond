#define SIZE 1000


typedef struct node
{
    // possibly make union 

    int value; 
    char id[60]; 
    struct node* next; 
}
node;

node *sym_table[SIZE];

// Hash function 
long hash(char *id); 

void init_hash_table(); 

void insert(char *id, int val); 

int lookup(char *id);
