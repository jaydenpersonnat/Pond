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
     LESS = 268,
     GREATER = 269,
     PRINT = 270,
     EOL = 271,
     LPAR = 272,
     RPAR = 273,
     FLOAT = 274,
     ID = 275,
     ASSIGN = 276,
     WHILE = 277,
     LBRACK = 278,
     RBRACK = 279,
     TRUE = 280,
     FALSE = 281,
     STRS = 282
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
#define LESS 268
#define GREATER 269
#define PRINT 270
#define EOL 271
#define LPAR 272
#define RPAR 273
#define FLOAT 274
#define ID 275
#define ASSIGN 276
#define WHILE 277
#define LBRACK 278
#define RBRACK 279
#define TRUE 280
#define FALSE 281
#define STRS 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "pond.y"
{
    int intval; 
    double fval; 
    char strval[60]; 
    expr exp; 
}
/* Line 1529 of yacc.c.  */
#line 110 "pond.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

