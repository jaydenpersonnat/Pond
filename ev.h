#include <stdbool.h> 

#define INT_SIZE 30
#define MAX_FLOAT_SIZE 15
#define MAX_STRING_SIZE 500

struct expr; 
struct BINOP;

enum uops{
    ABSV,
    FACTORIAL,
    NEGATIVE, 

};

enum bops{
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    MODULO, 
    POWER, 
    EQUALTO, 
    LESSTHAN,
    GREATERTHAN,
};

enum types{
    NUM,
    DECIMAL, 
    BOOL, 
    STR,
    BINARYOP, 
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

typedef struct BINOP
{
    enum types type; 
    enum bops op; 
    struct expr *left;
    struct expr *right; 
}
BINOP;


typedef struct expr
{
    union {
        INT integer;
        DEC decimal; 
        BOOLEAN boolean; 
        STRING string; 
        BINOP binop; 
    };
}
expr; 




expr *create_int_node(enum types type, int val);
expr *create_dec_node(enum types type, float val); 
expr *create_bool_node(enum types type, bool val); 
expr *create_str_node(enum types type, char *val); 
expr *create_binop_node(enum bops op, expr *left, expr *right);

expr *eval(expr *expression); 
char *to_concrete(expr *expression);