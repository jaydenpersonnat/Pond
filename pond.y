
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
    expr_node *list; 
    varid_node *varlist; 
}

%token NUMBER 
%token ADD SUB 
%token MUL DIV ABS MOD 
%token POW 
%token FACT
%token EQUALS NOTEQUAL 
%token LESS GREATER 
%token PRINT PRINTS PRINTN
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
%token STOP 
%token AND OR
%token GETINT 
%token GETDEC 
%token GETSTRING 
%token COMMA 
%token OUTPUT
%token ELSE 
%token CONCAT    
%token LISTCONCAT; 
 
%type <varlist> varidlist
%type <list> explist
%type <exp> exp binop unop
%type <intval> NUMBER 
%type <strval> ID STRS 
%type <fval> FLOAT 


// figure out precedence and associativy of operators 

%left EOL
%right ASSIGN
%left OR 
%left AND 
%right NOT 
%left EQUALS NOTEQUAL 
%left LESS GREATER LESSEQUAL GREATEREQUAL
%nonassoc ABS  
%left ADD SUB CONCAT LISTCONCAT 
%left MUL DIV MOD 
%nonassoc FACT 
%right POW 
%nonassoc LBRACK RBRACK LPAR RPAR 

 
  
%%  
program: 
  exp      { eval($1); } 
; 
 
varidlist: ID COMMA varidlist { $$ = cons_var($1, $3); }
           | ID               { $$ = cons_var($1, NULL); }

explist: exp COMMA explist { $$ = cons($1, $3)}
        | exp             { $$ = cons($1, NULL); } 
; 

unop: 
    exp FACT       {$$ = create_unop_node(FACTORIAL, $1); }
    | SUB exp        {$$ = create_unop_node(NEGATIVE, $2); } 
    | NOT exp        {$$ = create_unop_node(NOTOP, $2); }
    | ABS exp ABS       {$$ = create_unop_node(ABSV, $2); }

binop: 
   exp ADD exp { $$ = create_binop_node(PLUS, $1, $3); }
  | exp SUB exp { $$ = create_binop_node(MINUS, $1, $3); }
  | exp MUL exp    {$$ = create_binop_node(TIMES, $1, $3); }
  | exp DIV exp    {$$ = create_binop_node(DIVIDE, $1, $3); }
  | exp MOD exp    {$$ = create_binop_node(MODULO, $1, $3);}
  | exp POW exp    {$$ = create_binop_node(POWER, $1, $3);}
  | exp EQUALS exp {$$ = create_binop_node(EQUALTO, $1, $3); }
  | exp NOTEQUAL exp {$$ = create_binop_node(NOTEQUALTO, $1, $3); }
  | exp LESS  exp  {$$ = create_binop_node(LESSTHAN, $1, $3); } 
  | exp GREATER exp {$$ = create_binop_node(GREATERTHAN, $1, $3); } 
  | exp GREATEREQUAL exp {$$ = create_binop_node(GREATERTHANEQUAL, $1, $3);} 
  | exp LESSEQUAL exp {$$ = create_binop_node(LESSTHANEQUAL, $1, $3); }
  | exp AND exp      {$$ = create_binop_node(ANDOP, $1, $3); }
  | exp OR exp       { $$ = create_binop_node(OROP, $1, $3); }
  | exp CONCAT exp   { $$ = create_binop_node(SJOIN, $1, $3); } 
  | exp LISTCONCAT exp {$$ = create_binop_node(LJOIN, $1, $3); } 
 

exp: NUMBER        { $$ = create_int_node(NUM, $1); }
  | FLOAT         { $$ = create_dec_node(DECIMAL, $1); }
  | TRUE          { $$ = create_bool_node(BOOL, true);}
  | FALSE         { $$ = create_bool_node(BOOL, false);}
  | STRS          { $$ = create_str_node(STR, remove_double_quotes($1)) }
  | binop
  | unop 
  | LPAR exp RPAR  {$$ = $2;} 
  | ID ASSIGN exp    { $$ = create_assign_node($1, $3);} 
  | ID             {$$ = create_varid_node($1);}   
  | PRINT LPAR exp RPAR  { $$ = create_print_node($3, false); }   
  | PRINTN LPAR exp RPAR { $$ = create_print_node($3, false); }   
  | PRINTS LPAR exp RPAR { $$ = create_print_node($3, true); }   
  | STOP                  {$$ = create_break_node(); }  
  | GETINT LPAR STRS RPAR {$$ = create_getnum_node(remove_double_quotes($3));}
  | GETDEC LPAR STRS RPAR {$$ = create_getfloat_node(remove_double_quotes($3)); }    
  | GETSTRING LPAR STRS RPAR {$$ = create_getstr_node(remove_double_quotes($3)); }
  | exp EOL              { $$ = $1; }  
  | exp EOL exp          {$$ = create_seq_node($1, $3); }    
  | DO NUMBER LBRACK exp RBRACK { $$ = create_doloop_node($2, $4);} 
  | FOR ID ASSIGN exp TO exp INCR exp LBRACK exp RBRACK { $$ = create_forloop_node($2, $4, $6, $8, $10, $4); }
  | IF exp LBRACK exp RBRACK ELSE exp {$$ = create_if_node($2, $4, $7);}
  | IF exp LBRACK exp RBRACK   { $$ = create_if_node($2, $4, create_int_node(NUM, 0));}
  | WHILE exp LBRACK exp RBRACK {$$ = create_while_node($2, $4);}   
  | LSQUARE explist RSQUARE       { $$ = create_list_node($2); }
  | LSQUARE RSQUARE               {$$ = create_list_node(NULL); }
  | ID LPAR varidlist RPAR LBRACK exp RBRACK {$$ = create_func_node($1, $3, $6); }
  | ID LPAR explist RPAR            {$$ = create_app_node($1, $3); }
  | OUTPUT exp                         {$$ = create_return_node($2); }
  | exp LBRACK exp RBRACK           {$$ = create_binop_node(INDEX, $3, $1);}  
  | LBRACK exp RBRACK                  {$$ = $2; } 
 ;        
%%              
               
    
int main(int argc, char **argv) 
{
    init_hash_table();   

    yyin = fopen(argv[1], "r"); 

    if (argc != 2)
    {
        printf("Usage ./pond filename.pond\n");
        return 1; 
    }

    char *tmp = malloc(sizeof(5));
    for (int i = strlen(argv[1]) - 4, y = 0; i <= strlen(argv[1]); i++, y++)
    {
        tmp[y] = argv[1][i];
    }

    if (strcmp(tmp, "pond") != 0)
    {
        printf("file extension must be .pond\n");
        return 1;
    }
    
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