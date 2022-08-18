#include <stdbool.h> 

#define INT_SIZE 30
#define MAX_FLOAT_SIZE 15
#define MAX_STRING_SIZE 500

enum bops{
    PLUS,
};

enum types{
    NUM,
    DECIMAL, 
    BOOL, 
    STR,
};

// Basic Data Types 
typedef struct INT
{
    enum types type;
    int value; 
}
INT;
typedef struct DEC 
{
    enum types type; 
    float value; 
}
DEC; 
typedef struct BOOLEAN
{
    enum types type; 
    bool value; 
}
BOOLEAN;
typedef struct STRING
{
    enum types type; 
    char value[MAX_STRING_SIZE]; 
}
STRING;

// typedef struct BINOP
// {
//     enum bops op; 
//     expr *left; 
//     expr *right; 
// }
// Binop;


typedef struct expr
{
    union {
        INT integer;
        DEC decimal; 
        BOOLEAN boolean; 
        STRING string; 
        // BINOP  binop; 
    } ;
}
expr; 


expr create_int_node(enum types type, int val);
expr create_dec_node(enum types type, float val); 
expr create_bool_node(enum types type, bool val); 
expr create_str_node(enum types type, char *val); 

expr eval(expr expression); 
char *to_concrete(expr expression);