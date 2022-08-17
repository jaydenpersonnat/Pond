%option noyywrap

%{
	#include "pond.tab.h"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
   #include <strings.h>



%}


%x ML_COMMENT
alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}

ID 			{alpha}+{alnum}*
DECIMAL     "0"|{digit}*"."{digit}+

%%
"+"    { return ADD; }
"-"    { return SUB; }
"*"    { return MUL; }
"/"    { return DIV; }
"%"    { return MOD; }
"|"    { return ABS; }
"^"    { return POW; }
"("    { return LPAR; }
")"    { return RPAR; }
"!"    { return FACT; }
"=="   { return EQUALS; }
"="    { return ASSIGN; }
"print" { return PRINT; }


[0-9]+ { yylval.intval = atoi(yytext); return NUMBER; }
{ID}   { strcpy(yylval.strval, yytext); return ID; }
{DECIMAL} {yylval.fval = atof(yytext); return FLOAT; }


";"     { return EOL; }
[ \t \n]  { /* ignore whitespace */ }
%%


