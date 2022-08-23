%option noyywrap

%{
	#include "ev.h"
	#include "pond.tab.h"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include <strings.h>

%}


%x ML_COMMENT
digit 		[0-9]
alnum 		{alpha}|{digit}

ID 			[a-zA-Z][a-zA-Z0-9_]*
DECIMAL     "0"|{digit}*"."{digit}+
STRING      \"([^\"\\\n]|\\.|\\\n)*\"
%%

"+"    { return ADD; }
"-"    { return SUB; }
"*"    { return MUL; } 
"/"    { return DIV; }
"%"|mod    { return MOD; }  
"|"    { return ABS; }
"^"    { return POW; }
"("    { return LPAR; }
")"    { return RPAR; }
"{"    { return LBRACK; }
"}"    { return RBRACK; }
"["    { return LSQUARE; }
"]"    { return RSQUARE; }
"!"    { return FACT; }
","    { return COMMA; }
"=="|"equals" { return EQUALS; }
">"    { return GREATER; }
"<"    { return LESS; }
">="   { return GREATEREQUAL; }
"<="   { return LESSEQUAL; }
"="    { return ASSIGN; }
"!="   { return NOTEQUAL; }
"if"   { return IF; }
"else" { return ELSE; }
"do"   { return DO; }
"for"  { return FOR; }
"to"   { return TO; }
"incr"|"add" { return INCR; }
"not"  { return NOT; }
"TRUE"  { return TRUE; }
"FALSE"  { return FALSE; }
"print"  { return PRINT; }
"printn" { return PRINTN; }
"prints" { return PRINTS; }
"while" {return WHILE; }
"stop"|"break"  { return STOP; }
"and"|"AND"  { return AND; }
"or"|"OR" {return OR; }
"getnum"  { return GETINT; }
"getfloat" { return GETDEC; }
"getstring" {return GETSTRING; }
"output"|"return" {return OUTPUT; }
"sjoin"|"&"    { return CONCAT; }
"ljoin"|"@"    { return LISTCONCAT; }

[0-9]+ { yylval.intval = atoi(yytext); return NUMBER; }
{ID}   { strcpy(yylval.strval, yytext); return ID; }
{DECIMAL} {yylval.fval = atof(yytext); return FLOAT; }
{STRING} { strcpy(yylval.strval, yytext); return STRS; }

";"     { return EOL; }
[ \t \n] { /* ignore whitespace */ }

%%


