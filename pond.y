
%{
     #include "sym.h"
    #include "ev.h"

    #include <stdio.h>
    #include <math.h> 
    #include <stdbool.h> 

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
%token EQUALS
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

%type <exp> exp
%type <intval> NUMBER 
%type <strval> ID STRS
%type <fval> FLOAT 

%left ADD SUB
%left MUL DIV
%right POW


%%
program: 
 | program exp     { eval($2);}
//  | program whileLOOP
;

// line: 
//     print
//     assign

// print: PRINT LPAR exp RPAR EOL {printf("> %d\n", $3);}
// whileLOOP: WHILE exp LBRACK exp RBRACK {
//      while ($2)
//      {
//         printf("%d", $4); 
//      }
// }

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
  | exp LESS  exp  {$$ = create_binop_node(LESSTHAN, $1, $3); }
  | exp GREATER exp {$$ = create_binop_node(GREATERTHAN, $1, $3); }
  | exp LESS exp    {$$ = create_binop_node(LESSTHAN, $1, $3); }
//   | IF exp LBRACK exp RBRACK {$$ = create_if_node($2, $4); }
  // ADD >= and <= later 
  | LPAR exp RPAR  {$$ = $2;}
  | SUB exp        {$$ = create_unop_node(NEGATIVE, $2); }
  | ID             {$$ = create_varid_node($1);}
  | ID ASSIGN exp EOL  { $$ = create_assign_node($1, $3);}
  | PRINT LPAR exp RPAR EOL { $$ = create_print_node($3); }
  | DO NUMBER LBRACK exp RBRACK { $$ = create_doloop_node($2, $4);}    
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