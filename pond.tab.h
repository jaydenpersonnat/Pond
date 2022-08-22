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
     EOL = 272,
     LPAR = 273,
     RPAR = 274,
     FLOAT = 275,
     ID = 276,
     ASSIGN = 277,
     WHILE = 278,
     LBRACK = 279,
     RBRACK = 280,
     TRUE = 281,
     FALSE = 282,
     STRS = 283,
     IF = 284,
     DO = 285,
     FOR = 286,
     INCR = 287,
     TO = 288,
     NOT = 289,
     LESSEQUAL = 290,
     GREATEREQUAL = 291,
     LSQUARE = 292,
     RSQUARE = 293,
     STOP = 294,
     AND = 295,
     OR = 296,
     GETINT = 297,
     GETDEC = 298,
     GETSTRING = 299,
     COMMA = 300
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
#define EOL 272
#define LPAR 273
#define RPAR 274
#define FLOAT 275
#define ID 276
#define ASSIGN 277
#define WHILE 278
#define LBRACK 279
#define RBRACK 280
#define TRUE 281
#define FALSE 282
#define STRS 283
#define IF 284
#define DO 285
#define FOR 286
#define INCR 287
#define TO 288
#define NOT 289
#define LESSEQUAL 290
#define GREATEREQUAL 291
#define LSQUARE 292
#define RSQUARE 293
#define STOP 294
#define AND 295
#define OR 296
#define GETINT 297
#define GETDEC 298
#define GETSTRING 299
#define COMMA 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "pond.y"
{
    int intval; 
    double fval; 
    char strval[60]; 
    expr *exp; 
    exprlist *list; 
}
/* Line 1529 of yacc.c.  */
#line 147 "pond.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

