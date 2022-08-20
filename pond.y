
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
    // exprlist list; 
}

%token NUMBER 
%token ADD SUB 
%token MUL DIV ABS MOD 
%token POW 
%token FACT
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
%token LSQUARE RSQUARE
%type <exp> exp
%type <intval> NUMBER 
%type <strval> ID STRS
%type <fval> FLOAT 
// %type <list> explist


// figure out precedence and associativy of operators 
%left EQUALS NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL ASSIGN EOL 
%left ADD SUB 
%left MUL DIV MOD
%right POW

%nonassoc NOT 
%nonassoc ABS 
%nonassoc FACT


%%
program: 
  exp      { eval($1);}
 | FOR ID ASSIGN NUMBER TO ID ASSIGN NUMBER INCR NUMBER LBRACK exp RBRACK
                {
                    for (int i = $4; i <= $8; i = i + $10)
                    {
                        eval($12);
                    }
                }

 | 
;

exp: NUMBER        { $$ = create_int_node(NUM, $1); }
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
  | exp GREATEREQUAL exp {$$ = create_binop_node(GREATERTHANEQUAL, $1, $3);}
  | exp LESSEQUAL exp {$$ = create_binop_node(LESSTHANEQUAL, $1, $3); }
  | exp LESS
  | NOT exp         {$$ = create_unop_node(NOTOP, $2); } 
  | LPAR exp RPAR  {$$ = $2;} 
  | SUB exp        {$$ = create_unop_node(NEGATIVE, $2); }
  | ID ASSIGN exp    { $$ = create_assign_node($1, $3);}
  | ID             {$$ = create_varid_node($1);}   
  | PRINT LPAR exp RPAR  { $$ = create_print_node($3); }   
  | exp EOL              { $$ = $1; } 
  | exp EOL exp          {$$ = create_seq_node($1, $3); }
  | DO NUMBER LBRACK exp RBRACK { $$ = create_doloop_node($2, $4);}
  | FOR ID ASSIGN NUMBER TO NUMBER INCR NUMBER LBRACK exp RBRACK { $$ = create_forloop_node($2, $4, $6, $8, $10); }
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