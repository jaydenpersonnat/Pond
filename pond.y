
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
    expr exp; 
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

%type <exp> exp
%type <intval> NUMBER 
%type <strval> ID STRS
%type <fval> FLOAT 

%left ADD SUB
%left MUL DIV
%right POW


%%
program: 
 | program exp
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
//  | exp ADD exp { $$ = $1 + $3; }
//  | exp SUB exp { $$ = $1 - $3; }
//  | exp MUL exp    {$$ = $1 * $3; }
//  | exp DIV exp    {$$ = $1 / $3; }
//  | exp MOD exp    {$$ = $1 % $3}
//  | ABS exp ABS       {$$ = $2 >= 0? $2: - $2; }
//  | exp POW exp    {$$ = pow($1, $3)}
//  | exp FACT       {$$ = tgamma($1 + 1)}
//  | exp EQUALS exp {$$ = $1 == $3? true: false;}
//  | exp LESS  exp  {$$ = $1 < $3; }
//  | exp GREATER exp {$$ = $1 > $3; }
//  | LPAR exp RPAR  {$$ = $2;}
//  | SUB exp        {$$ = -$2}
//  | ID             {$$ = lookup($1);}
//  | ID ASSIGN exp EOL  { insert($1, $3); }
 | PRINT LPAR exp RPAR EOL {printf("> %s\n", to_concrete(eval($3)))}
//  | WHILE exp LBRACK exp RBRACK { while ($2) $4;}
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