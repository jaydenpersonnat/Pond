
#ifndef SYM_H
#define SYM_H


#include <stdbool.h> 


#define INT_SIZE 30
#define MAX_FLOAT_SIZE 6
#define MAX_STRING_SIZE 600
#define TABLE_SIZE 1000


struct expr; 
struct UNOP; 
struct BINOP;
struct SEQ; 
struct ASSIGNM; 
struct IF_S; 
struct PRINTI; 
struct FORLOOP;
struct WHILELOOP;
struct DOLOOP; 
struct expr_node;
struct exprlist;
struct FUNC; 
struct APP; 

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
    ANDOP,
    OROP, 
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
    FUNCTION, 
    FORL,
    WHILEL, 
    BREAK, 
    GETNUM, 
    GETFLOAT, 
    GETSTR, 
    EXPLIST, 
    FUNCAPP, 
    RETURN_t, 
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
    struct expr *left;
    struct expr *right; 
}
SEQ;

typedef struct IF_S
{
    enum types type; 
    struct expr *cond; 
    struct expr *body; 
    struct expr *else_c; 
}
IF_S; 

typedef struct DOLOOP
{
    enum types type; 
    int iterations; 
    struct expr *exp;
}
DOLOOP; 

typedef struct WHILELOOP
{
    enum types type;
    struct expr *cond; 
    struct expr *exp; 
}
WHILELOOP; 

typedef struct BREAK_t
{
    enum types type; 
}
BREAK_t;

typedef struct RETURN
{
    enum types type;
    struct expr *exp; 
    
} RETURN; 


typedef struct PRINTI
{
    enum types type; 
    struct expr *exp; 
}
PRINTI; 

typedef struct GETNUM_f
{
    enum types type; 
    char prompt[MAX_STRING_SIZE];
}
GETNUM_f;

typedef struct GETSTR_f
{
    enum types type;
    char prompt[MAX_STRING_SIZE];
}
GETSTR_f; 


typedef struct GETFLOAT_f
{
    enum types type; 
    char prompt[MAX_STRING_SIZE];
}
GETFLOAT_f; 

typedef struct EVALERROR
{
    enum types type; 
    char msg[MAX_STRING_SIZE];
}
EVALERROR;

typedef struct FORLOOP
{
    enum types type; 
    char varidname[MAX_STRING_SIZE];
    struct expr *start;
    struct expr *end; 
    struct expr *incr;
    struct expr *counter; 
    struct expr *exp; 
}
FORLOOP;

typedef struct expr_node
{
    // int index; 
    enum types type; 
    struct expr *node; 
    struct expr_node *next; 
    int index; 
}
expr_node; 

typedef struct exprlist
{
    enum types type; 
    struct expr_node *list; 
}
exprlist; 

typedef struct varid_node
{
    char varid[MAX_STRING_SIZE];
    struct varid_node *next; 
}
varid_node;

typedef struct FUNC
{  
    enum types type; 
    char name[MAX_STRING_SIZE];
    struct varid_node *list;
    struct expr *body; 
} FUNC; 


typedef struct APP
{
    enum types type; 
    char name[MAX_STRING_SIZE];
    struct expr_node *list; 

} APP;

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
        FORLOOP forloop;
        WHILELOOP whileloop;  
        BREAK_t breakt; 
        GETNUM_f getnum; 
        GETFLOAT_f getfloat; 
        GETSTR_f getstr; 
        exprlist explist; 
        FUNC function; 
        APP app; 
        RETURN return_t; 
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
expr *create_if_node(expr *cond, expr *body, expr *else_c);
expr *create_break_node(void);

expr *create_print_node(expr *exp);
expr *create_doloop_node(int iterations, expr *exp);
expr *create_eval_error(char *msg);
expr *create_seq_node(expr *left, expr *right);

expr *eval(expr *expression); 
char *to_concrete(expr *expression);
expr *create_assign_node(char *varidname, expr *exp); 
expr *create_forloop_node(char *varidname, expr *start, expr *end, expr *incr, expr *exp, expr *counter);
expr *create_while_node(expr *cond, expr *exp);
expr *create_getnum_node(char *prompt);
expr *create_getfloat_node(char *prompt);
expr *create_getstr_node(char *prompt); 
expr_node *cons(expr *exp, expr_node *list);
expr *create_list_node(expr_node *list);
expr *create_func_node(char *name, varid_node *varidnames, expr *body);
varid_node *cons_var(char *varidname, varid_node *n);
expr *create_app_node(char *name, expr_node *list);
expr *create_return_node(expr *exp);
char *remove_double_quotes(char *input);


#endif