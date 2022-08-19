
%{
     #include "sym.h"
    #include "ev.h"

    #include <stdio.h>
    #include <math.h> 
    #include <stdbool.h> 
    #include <string.h>

    int yylex();
    int yyerror(char *s);
    extern FILE *yyin; 
%}

%union{
    int intval; 
    double fval; 
    char strval[60]; 
    expr *exp; 
}

%token NUMBER 
%token ADD SUB MUL DIV ABS MOD POW FACT
%token EQUALS NOTEQUAL 
%token LESS GREATER 
%token PRINT 
%token EOL 
%token LPAR RPAR 
%token FLOAT
%token ID 
%token ASSIGN
%token WHILE 
%token LBRACK RBRACK 
%token TRUE FALSE
%token STRS
%token IF
%token DO 
%token FOR 
%token INCR
%token TO 
%token NOT 
%token LESSEQUAL GREATEREQUAL 

%type <exp> exp
%type <intval> NUMBER 
%type <strval> ID STRS
%type <fval> FLOAT 

%left EQUALS NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL 
%left ADD SUB
%left MUL DIV MOD
%right POW


%%
program: 
 | program exp     { eval($2);}
 | program DO NUMBER LBRACK exp RBRACK { for (int i = 0; i < $3; i++)  eval($5);}
 | program FOR ID ASSIGN NUMBER TO ID ASSIGN NUMBER INCR NUMBER LBRACK exp RBRACK
                {
                    for (int i = $5; i <= $9; i = i + $11)
                    {
                        eval($13);
                    }
                }
 | program WHILE exp LBRACK exp RBRACK 
                {
                    while (strcmp(to_concrete(eval($3)), "TRUE") == 0)
                    {
                        eval($5);
                    }
                }
 | program IF exp LBRACK exp RBRACK 
                {
                    if (strcmp(to_concrete(eval($3)), "TRUE") == 0)
                    {
                        eval($5);
                    }
                }
;



exp: 
  | NUMBER        { $$ = create_int_node(NUM, $1); }
  | FLOAT         { $$ = create_dec_node(DECIMAL, $1); }
  | TRUE          { $$ = create_bool_node(BOOL, true);}
  | FALSE         { $$ = create_bool_node(BOOL, false);}
  | STRS          { $$ = create_str_node(STR, $1); }
  | exp ADD exp { $$ = create_binop_node(PLUS, $1, $3); }
  | exp SUB exp { $$ = create_binop_node(MINUS, $1, $3); }
  | exp MUL exp    {$$ = create_binop_node(TIMES, $1, $3); }
  | exp DIV exp    {$$ = create_binop_node(DIVIDE, $1, $3); }
  | exp MOD exp    {$$ = create_binop_node(MODULO, $1, $3);}
  | ABS exp ABS       {$$ = create_unop_node(ABSV, $2); }
  | exp POW exp    {$$ = create_binop_node(POWER, $1, $3);}
  | exp FACT       {$$ = create_unop_node(FACTORIAL, $1); }
  | exp EQUALS exp {$$ = create_binop_node(EQUALTO, $1, $3); }
  | exp NOTEQUAL exp {$$ = create_binop_node(NOTEQUALTO, $1, $3); }
  | exp LESS  exp  {$$ = create_binop_node(LESSTHAN, $1, $3); } 
  | exp GREATER exp {$$ = create_binop_node(GREATERTHAN, $1, $3); } 
  | exp LESS exp    {$$ = create_binop_node(LESSTHAN, $1, $3); }
  | exp GREATEREQUAL exp {$$ = create_binop_node(GREATERTHANEQUAL, $1, $3);}
  | exp LESSEQUAL exp {$$ = create_binop_node(LESSTHANEQUAL, $1, $3); }
  | exp LESS
  | NOT exp         {$$ = create_unop_node(NOTOP, $2); }
  | LPAR exp RPAR  {$$ = $2;}
  | SUB exp        {$$ = create_unop_node(NEGATIVE, $2); }
  | ID             {$$ = create_varid_node($1);}
  | ID ASSIGN exp EOL  { $$ = create_assign_node($1, $3);}
  | PRINT LPAR exp RPAR EOL { $$ = create_print_node($3); }  
 ; 
%%
 

int main(int argc, char **argv)
{
    init_hash_table(); 

    yyin = fopen(argv[1], "r");

    if (!yyin)
    {
        printf("no such file %s\n", argv[1]);
        return 1;
    }
    yyparse(); 
    fclose(yyin);
}

int yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s); 
    return 1;
}