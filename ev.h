#include <stdbool.h> 

#ifndef SYM_H
#define SYM_H

#define INT_SIZE 30
#define MAX_FLOAT_SIZE 6
#define MAX_STRING_SIZE 500
#define TABLE_SIZE 1000


struct expr; 
struct UNOP; 
struct BINOP;
struct SEQ; 
struct ASSIGNM; 
struct IF_S; 
struct PRINTI; 

enum uops{
    ABSV,
    FACTORIAL,
    NEGATIVE, 
    NOTOP, 
};

enum bops{
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    MODULO, 
    POWER, 
    EQUALTO, 
    NOTEQUALTO, 
    LESSTHAN,
    GREATERTHAN,
    LESSTHANEQUAL,
    GREATERTHANEQUAL, 
};

enum types{
    NUM,
    DECIMAL, 
    BOOL, 
    STR,
    BINARYOP, 
    UNARYOP, 
    VAR, 
    ASSIGNMENT, 
    CONDITIONAL, 
    PRINTING, 
    DOL, 
    ERROR,
    SEQUENCE, 
};

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

typedef struct VARID
{
    enum types type; 
    char varidname[MAX_STRING_SIZE];
}
VARID; 

typedef struct ASSIGNM
{
    enum types type; 
    char varidname[MAX_STRING_SIZE];
    struct expr *exp; 
}
ASSIGNM; 

typedef struct UNOP
{
    enum types type; 
    enum uops op; 
    struct expr *exp; 
}
UNOP; 

typedef struct BINOP
{
    enum types type; 
    enum bops op; 
    struct expr *left;
    struct expr *right; 
}
BINOP;

typedef struct SEQ
{
    enum types type; 
    enum bops op; 
    struct expr *left;
    struct expr *right; 
}
SEQ;

typedef struct IF_S
{
    enum types type; 
    struct expr *cond; 
    struct expr *body; 
}
IF_S; 

typedef struct DOLOOP
{
    enum types type; 
    int iterations; 
    struct expr *exp;
}
DOLOOP; 

typedef struct PRINTI
{
    enum types type; 
    struct expr *exp; 
}
PRINTI; 

typedef struct EVALERROR
{
    enum types type; 
    char msg[MAX_STRING_SIZE];
}EVALERROR;

typedef struct expr
{
    union {
        INT integer;
        DEC decimal; 
        BOOLEAN boolean; 
        STRING string; 
        VARID varid; 
        ASSIGNM assign; 
        IF_S conditional; 
        UNOP unop; 
        BINOP binop; 
        PRINTI print; 
        DOLOOP doloop; 
        EVALERROR error; 
        SEQ sequence; 
    };
}
expr; 


expr *create_int_node(enum types type, int val);
expr *create_dec_node(enum types type, float val); 
expr *create_bool_node(enum types type, bool val); 
expr *create_str_node(enum types type, char *val); 
expr *create_varid_node(char *varidname);
expr *create_binop_node(enum bops op, expr *left, expr *right);
expr *create_unop_node(enum uops op, expr *exp); 

expr *create_print_node(expr *exp);
expr *create_doloop_node(int iterations, expr *exp);
expr *create_eval_error(char *msg);

expr *eval(expr *expression); 
char *to_concrete(expr *expression);
expr *create_assign_node(char *varidname, expr *exp); 


#endif