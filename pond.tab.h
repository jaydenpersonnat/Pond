/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ADD = 259,
     SUB = 260,
     MUL = 261,
     DIV = 262,
     ABS = 263,
     MOD = 264,
     POW = 265,
     FACT = 266,
     EQUALS = 267,
     NOTEQUAL = 268,
     LESS = 269,
     GREATER = 270,
     PRINT = 271,
     PRINTS = 272,
     PRINTN = 273,
     EOL = 274,
     LPAR = 275,
     RPAR = 276,
     FLOAT = 277,
     ID = 278,
     ASSIGN = 279,
     WHILE = 280,
     LBRACK = 281,
     RBRACK = 282,
     TRUE = 283,
     FALSE = 284,
     STRS = 285,
     IF = 286,
     DO = 287,
     FOR = 288,
     INCR = 289,
     TO = 290,
     NOT = 291,
     LESSEQUAL = 292,
     GREATEREQUAL = 293,
     LSQUARE = 294,
     RSQUARE = 295,
     STOP = 296,
     AND = 297,
     OR = 298,
     GETINT = 299,
     GETDEC = 300,
     GETSTRING = 301,
     COMMA = 302,
     OUTPUT = 303,
     ELSE = 304,
     CONCAT = 305,
     LISTCONCAT = 306
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ADD 259
#define SUB 260
#define MUL 261
#define DIV 262
#define ABS 263
#define MOD 264
#define POW 265
#define FACT 266
#define EQUALS 267
#define NOTEQUAL 268
#define LESS 269
#define GREATER 270
#define PRINT 271
#define PRINTS 272
#define PRINTN 273
#define EOL 274
#define LPAR 275
#define RPAR 276
#define FLOAT 277
#define ID 278
#define ASSIGN 279
#define WHILE 280
#define LBRACK 281
#define RBRACK 282
#define TRUE 283
#define FALSE 284
#define STRS 285
#define IF 286
#define DO 287
#define FOR 288
#define INCR 289
#define TO 290
#define NOT 291
#define LESSEQUAL 292
#define GREATEREQUAL 293
#define LSQUARE 294
#define RSQUARE 295
#define STOP 296
#define AND 297
#define OR 298
#define GETINT 299
#define GETDEC 300
#define GETSTRING 301
#define COMMA 302
#define OUTPUT 303
#define ELSE 304
#define CONCAT 305
#define LISTCONCAT 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "pond.y"
{
    int intval; 
    double fval; 
    char strval[60]; 
    expr *exp; 
    expr_node *list; 
    varid_node *varlist; 
}
/* Line 1529 of yacc.c.  */
#line 160 "pond.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

