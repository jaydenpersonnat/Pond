
%{
    #include <stdio.h>
    #include <math.h> 
    #include <stdbool.h> 
    #include "sym.h"

    int yylex();
    int yyerror(char *s);
    extern FILE *yyin; 
%}

%union{
    int intval; 
    float fval; 
    char strval[60]; 
}

%token NUMBER 
%token ADD SUB MUL DIV ABS MOD POW FACT
%token EQUALS
%token PRINT 
%token EOL 
%token LPAR RPAR 
%token FLOAT
%token ID 
%token ASSIGN

%type <intval> exp NUMBER 
%type <strval> ID
// %type <fval> exp FLOAT 

%left ADD SUB
%left MUL DIV
%right POW



%%

program: 
 | program PRINT LPAR exp RPAR EOL { printf("> %d\n", $4);}
 | program ID ASSIGN exp EOL           { insert($2, $4) }
;




exp: NUMBER 
 | exp ADD exp { $$ = $1 + $3; }
 | exp SUB exp { $$ = $1 - $3; }
 | exp MUL exp    {$$ = $1 * $3; }
 | exp DIV exp    {$$ = $1 / $3; }
 | exp MOD exp    {$$ = $1 % $3}
 | ABS exp ABS       {$$ = $2 >= 0? $2: - $2; }
 | exp POW exp    {$$ = pow($1, $3)}
 | exp FACT       {$$ = tgamma($1 + 1)}
 | exp EQUALS exp {$$ = $1 == $3? true: false;}
 | LPAR exp RPAR  {$$ = $2;}
 | SUB exp        {$$ = -$2}
 | ID             {$$ = lookup($1);}
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