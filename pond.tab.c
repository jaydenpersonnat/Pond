/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "pond.y"

     #include "sym.h"
    #include "ev.h"

    #include <stdio.h>
    #include <math.h> 
    #include <stdbool.h> 
    #include <string.h>

    int yylex();
    int yyerror(char *s);
    extern FILE *yyin;  


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 221 "pond.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "pond.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    15,    17,    20,    23,
      26,    30,    34,    38,    42,    46,    50,    54,    58,    62,
      66,    70,    74,    78,    82,    86,    90,    94,    96,    98,
     100,   102,   104,   106,   108,   112,   116,   118,   123,   128,
     133,   135,   140,   145,   150,   153,   157,   163,   175,   183,
     189,   195,   199,   202,   210,   215,   218,   223
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    58,    -1,    23,    47,    54,    -1,    23,
      -1,    58,    47,    55,    -1,    58,    -1,    58,    11,    -1,
       5,    58,    -1,    36,    58,    -1,     8,    58,     8,    -1,
      58,     4,    58,    -1,    58,     5,    58,    -1,    58,     6,
      58,    -1,    58,     7,    58,    -1,    58,     9,    58,    -1,
      58,    10,    58,    -1,    58,    12,    58,    -1,    58,    13,
      58,    -1,    58,    14,    58,    -1,    58,    15,    58,    -1,
      58,    38,    58,    -1,    58,    37,    58,    -1,    58,    42,
      58,    -1,    58,    43,    58,    -1,    58,    50,    58,    -1,
      58,    51,    58,    -1,     3,    -1,    22,    -1,    28,    -1,
      29,    -1,    30,    -1,    57,    -1,    56,    -1,    20,    58,
      21,    -1,    23,    24,    58,    -1,    23,    -1,    16,    20,
      58,    21,    -1,    18,    20,    58,    21,    -1,    17,    20,
      58,    21,    -1,    41,    -1,    44,    20,    30,    21,    -1,
      45,    20,    30,    21,    -1,    46,    20,    30,    21,    -1,
      58,    19,    -1,    58,    19,    58,    -1,    32,     3,    26,
      58,    27,    -1,    33,    23,    24,    58,    35,    58,    34,
      58,    26,    58,    27,    -1,    31,    58,    26,    58,    27,
      49,    58,    -1,    31,    58,    26,    58,    27,    -1,    25,
      58,    26,    58,    27,    -1,    39,    55,    40,    -1,    39,
      40,    -1,    23,    20,    54,    21,    26,    58,    27,    -1,
      23,    20,    55,    21,    -1,    48,    58,    -1,    58,    26,
      58,    27,    -1,    26,    58,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    92,    93,    95,    96,   100,   101,   102,
     103,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ADD", "SUB", "MUL", "DIV",
  "ABS", "MOD", "POW", "FACT", "EQUALS", "NOTEQUAL", "LESS", "GREATER",
  "PRINT", "PRINTS", "PRINTN", "EOL", "LPAR", "RPAR", "FLOAT", "ID",
  "ASSIGN", "WHILE", "LBRACK", "RBRACK", "TRUE", "FALSE", "STRS", "IF",
  "DO", "FOR", "INCR", "TO", "NOT", "LESSEQUAL", "GREATEREQUAL", "LSQUARE",
  "RSQUARE", "STOP", "AND", "OR", "GETINT", "GETDEC", "GETSTRING", "COMMA",
  "OUTPUT", "ELSE", "CONCAT", "LISTCONCAT", "$accept", "program",
  "varidlist", "explist", "unop", "binop", "exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     1,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     4,     4,     4,
       1,     4,     4,     4,     2,     3,     5,    11,     7,     5,
       5,     3,     2,     7,     4,     2,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,     0,     0,     0,     0,     0,     0,    28,    36,
       0,     0,    29,    30,    31,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,    33,    32,     2,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    52,     0,     6,     0,     0,     0,    55,
       1,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,    34,    36,     0,     0,    35,     0,
      57,     0,     0,     0,    51,     0,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    45,
       0,    22,    21,    23,    24,    25,    26,    37,    39,    38,
       0,     0,    54,     0,     0,     0,     0,     5,    41,    42,
      43,    56,     4,     3,     0,    50,    49,    46,     0,     0,
       0,     0,    53,    48,     0,     0,     0,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    25,    76,    44,    26,    27,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
    1155,   -39,  1155,  1155,   -16,    -7,    -6,  1155,   -39,    10,
    1155,  1155,   -39,   -39,   -39,  1155,    13,    -4,  1155,  1111,
     -39,     8,     9,    17,  1155,    38,   -39,   -39,   809,    16,
      89,  1155,  1155,  1155,   137,  1190,  1155,   857,   185,   905,
      14,    15,  1037,   -39,     1,   233,    18,    19,    20,   809,
     -39,  1155,  1155,  1155,  1155,  1155,  1155,   -39,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
     -39,   281,   329,   377,   -39,   -12,    22,    23,   971,  1155,
     -39,  1155,  1155,  1155,   -39,  1155,    24,    25,    26,    16,
      16,    -5,    -5,    -5,    -9,  1075,  1075,   155,   155,   971,
     425,   155,   155,  1037,  1019,    16,    16,   -39,   -39,   -39,
      34,    45,   -39,   473,   521,   569,   617,   -39,   -39,   -39,
     -39,   -39,    27,   -39,  1155,   -39,    28,   -39,  1155,   665,
    1155,   713,   -39,   809,  1155,   953,  1155,   761,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -38,   -15,   -39,   -39,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
      28,    56,    29,    30,    31,    56,    57,    34,    35,    -4,
      37,    38,    36,    32,    33,    39,    40,    63,    42,    41,
      77,    63,    53,    54,    49,    55,    56,    57,    46,    47,
      35,    71,    72,    73,    36,   110,    78,    48,    50,    83,
      82,    84,    63,   111,   112,   118,   119,   120,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   122,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     117,   124,   123,     0,   110,     0,     0,   130,     0,   113,
       0,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,    54,    70,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,   129,     0,    64,    65,   131,     0,
     133,    66,    67,     0,   135,     0,   137,     0,     0,    68,
      69,    51,    52,    53,    54,     0,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    62,     0,    74,    51,
      52,    53,    54,    63,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,    64,    65,     0,     0,     0,    66,
      67,    63,     0,     0,     0,     0,     0,    68,    69,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    62,    68,    69,     0,     0,     0,
       0,    63,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,    68,    69,    51,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,     0,     0,     0,    66,    67,     0,     0,     0,
      85,     0,     0,    68,    69,    51,    52,    53,    54,     0,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,     0,   107,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
       0,     0,     0,    66,    67,     0,     0,     0,     0,     0,
       0,    68,    69,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,     0,
     108,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,     0,     0,
       0,    66,    67,     0,     0,     0,     0,     0,     0,    68,
      69,    51,    52,    53,    54,     0,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    62,     0,   109,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,    68,    69,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,    68,    69,    51,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,     0,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,    68,    69,    51,    52,    53,    54,     0,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    63,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
       0,     0,     0,    66,    67,     0,     0,     0,     0,     0,
       0,    68,    69,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,    63,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,     0,     0,
       0,    66,    67,     0,     0,     0,     0,     0,     0,    68,
      69,    51,    52,    53,    54,     0,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,    64,    65,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,    68,    69,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,    68,    69,    51,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,   134,     0,     0,
      64,    65,     0,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,    68,    69,    51,    52,    53,    54,     0,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    63,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
       0,     0,     0,    66,    67,     0,     0,     0,     0,     0,
       0,    68,    69,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,     0,     0,
       0,    66,    67,     0,     0,     0,     0,     0,     0,    68,
      69,    51,    52,    53,    54,     0,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,    68,    69,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,    68,    69,    51,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,     0,     0,    51,    52,    53,    54,   136,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      64,    65,     0,     0,     0,    66,    67,    63,     0,     0,
       0,     0,     0,    68,    69,     0,     0,     0,    64,    65,
       0,     0,     0,    66,    67,     0,     0,     0,     0,     0,
       0,    68,    69,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,    51,    52,    53,    54,    63,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    64,    65,     0,     0,
       0,    66,     0,    63,     0,     0,     0,     0,     0,    68,
      69,     0,     0,     0,    64,    65,     0,     0,     0,    51,
      52,    53,    54,     0,    55,    56,    57,    68,    69,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     1,     0,     2,     0,     0,     3,
       0,     0,     0,     0,     0,    68,    69,     4,     5,     6,
       0,     7,     0,     8,     9,     0,    10,    11,     0,    12,
      13,    14,    15,    16,    17,     0,     0,    18,     0,     0,
      19,    43,    20,     0,     0,    21,    22,    23,     1,    24,
       2,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     0,     7,     0,     8,     9,     0,
      10,    11,     0,    12,    13,    14,    15,    16,    17,     0,
       0,    18,     0,     1,    19,     2,    20,     0,     3,    21,
      22,    23,     0,    24,     0,     0,     4,     5,     6,     0,
       7,     0,     8,    75,     0,    10,    11,     0,    12,    13,
      14,    15,    16,    17,     0,     0,    18,     0,     0,    19,
       0,    20,     0,     0,    21,    22,    23,     0,    24
};

static const yytype_int16 yycheck[] =
{
       0,    10,     2,     3,    20,    10,    11,     7,    20,    21,
      10,    11,    24,    20,    20,    15,     3,    26,    18,    23,
      35,    26,     6,     7,    24,     9,    10,    11,    20,    20,
      20,    31,    32,    33,    24,    47,    36,    20,     0,    24,
      26,    40,    26,    21,    21,    21,    21,    21,    30,    30,
      30,    51,    52,    53,    54,    55,    56,    23,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      85,    26,   110,    -1,    47,    -1,    -1,    49,    -1,    79,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    37,    38,   128,    -1,
     130,    42,    43,    -1,   134,    -1,   136,    -1,    -1,    50,
      51,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    -1,    21,     4,
       5,     6,     7,    26,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,
      43,    26,    -1,    -1,    -1,    -1,    -1,    50,    51,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    50,    51,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      21,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    -1,    21,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,     4,     5,     6,     7,    26,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    42,    43,    26,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,    26,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    42,    -1,    26,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,     4,
       5,     6,     7,    -1,     9,    10,    11,    50,    51,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,     3,    -1,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    50,    51,    16,    17,    18,
      -1,    20,    -1,    22,    23,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    -1,    -1,    44,    45,    46,     3,    48,
       5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    -1,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    -1,     3,    39,     5,    41,    -1,     8,    44,
      45,    46,    -1,    48,    -1,    -1,    16,    17,    18,    -1,
      20,    -1,    22,    23,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    39,
      -1,    41,    -1,    -1,    44,    45,    46,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     8,    16,    17,    18,    20,    22,    23,
      25,    26,    28,    29,    30,    31,    32,    33,    36,    39,
      41,    44,    45,    46,    48,    53,    56,    57,    58,    58,
      58,    20,    20,    20,    58,    20,    24,    58,    58,    58,
       3,    23,    58,    40,    55,    58,    20,    20,    20,    58,
       0,     4,     5,     6,     7,     9,    10,    11,    12,    13,
      14,    15,    19,    26,    37,    38,    42,    43,    50,    51,
       8,    58,    58,    58,    21,    23,    54,    55,    58,    26,
      27,    26,    26,    24,    40,    47,    30,    30,    30,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    21,    21,    21,
      47,    21,    21,    58,    58,    58,    58,    55,    21,    21,
      21,    27,    23,    54,    26,    27,    27,    27,    35,    58,
      49,    58,    27,    58,    34,    58,    26,    58,    27
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "pond.y"
    { eval((yyvsp[(1) - (1)].exp)); ;}
    break;

  case 3:
#line 92 "pond.y"
    { (yyval.varlist) = cons_var((yyvsp[(1) - (3)].strval), (yyvsp[(3) - (3)].varlist)); ;}
    break;

  case 4:
#line 93 "pond.y"
    { (yyval.varlist) = cons_var((yyvsp[(1) - (1)].strval), NULL); ;}
    break;

  case 5:
#line 95 "pond.y"
    { (yyval.list) = cons((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].list));}
    break;

  case 6:
#line 96 "pond.y"
    { (yyval.list) = cons((yyvsp[(1) - (1)].exp), NULL); ;}
    break;

  case 7:
#line 100 "pond.y"
    {(yyval.exp) = create_unop_node(FACTORIAL, (yyvsp[(1) - (2)].exp)); ;}
    break;

  case 8:
#line 101 "pond.y"
    {(yyval.exp) = create_unop_node(NEGATIVE, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 9:
#line 102 "pond.y"
    {(yyval.exp) = create_unop_node(NOTOP, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 10:
#line 103 "pond.y"
    {(yyval.exp) = create_unop_node(ABSV, (yyvsp[(2) - (3)].exp)); ;}
    break;

  case 11:
#line 106 "pond.y"
    { (yyval.exp) = create_binop_node(PLUS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 12:
#line 107 "pond.y"
    { (yyval.exp) = create_binop_node(MINUS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 13:
#line 108 "pond.y"
    {(yyval.exp) = create_binop_node(TIMES, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 14:
#line 109 "pond.y"
    {(yyval.exp) = create_binop_node(DIVIDE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 15:
#line 110 "pond.y"
    {(yyval.exp) = create_binop_node(MODULO, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 16:
#line 111 "pond.y"
    {(yyval.exp) = create_binop_node(POWER, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 17:
#line 112 "pond.y"
    {(yyval.exp) = create_binop_node(EQUALTO, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 18:
#line 113 "pond.y"
    {(yyval.exp) = create_binop_node(NOTEQUALTO, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 19:
#line 114 "pond.y"
    {(yyval.exp) = create_binop_node(LESSTHAN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 20:
#line 115 "pond.y"
    {(yyval.exp) = create_binop_node(GREATERTHAN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 21:
#line 116 "pond.y"
    {(yyval.exp) = create_binop_node(GREATERTHANEQUAL, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 22:
#line 117 "pond.y"
    {(yyval.exp) = create_binop_node(LESSTHANEQUAL, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 23:
#line 118 "pond.y"
    {(yyval.exp) = create_binop_node(ANDOP, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 24:
#line 119 "pond.y"
    { (yyval.exp) = create_binop_node(OROP, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 25:
#line 120 "pond.y"
    { (yyval.exp) = create_binop_node(SJOIN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 26:
#line 121 "pond.y"
    {(yyval.exp) = create_binop_node(LJOIN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 27:
#line 124 "pond.y"
    { (yyval.exp) = create_int_node(NUM, (yyvsp[(1) - (1)].intval)); ;}
    break;

  case 28:
#line 125 "pond.y"
    { (yyval.exp) = create_dec_node(DECIMAL, (yyvsp[(1) - (1)].fval)); ;}
    break;

  case 29:
#line 126 "pond.y"
    { (yyval.exp) = create_bool_node(BOOL, true);;}
    break;

  case 30:
#line 127 "pond.y"
    { (yyval.exp) = create_bool_node(BOOL, false);;}
    break;

  case 31:
#line 128 "pond.y"
    { (yyval.exp) = create_str_node(STR, remove_double_quotes((yyvsp[(1) - (1)].strval))) ;}
    break;

  case 34:
#line 131 "pond.y"
    {(yyval.exp) = (yyvsp[(2) - (3)].exp);;}
    break;

  case 35:
#line 132 "pond.y"
    { (yyval.exp) = create_assign_node((yyvsp[(1) - (3)].strval), (yyvsp[(3) - (3)].exp));;}
    break;

  case 36:
#line 133 "pond.y"
    {(yyval.exp) = create_varid_node((yyvsp[(1) - (1)].strval));;}
    break;

  case 37:
#line 134 "pond.y"
    { (yyval.exp) = create_print_node((yyvsp[(3) - (4)].exp), false); ;}
    break;

  case 38:
#line 135 "pond.y"
    { (yyval.exp) = create_print_node((yyvsp[(3) - (4)].exp), false); ;}
    break;

  case 39:
#line 136 "pond.y"
    { (yyval.exp) = create_print_node((yyvsp[(3) - (4)].exp), true); ;}
    break;

  case 40:
#line 137 "pond.y"
    {(yyval.exp) = create_break_node(); ;}
    break;

  case 41:
#line 138 "pond.y"
    {(yyval.exp) = create_getnum_node(remove_double_quotes((yyvsp[(3) - (4)].strval)));;}
    break;

  case 42:
#line 139 "pond.y"
    {(yyval.exp) = create_getfloat_node(remove_double_quotes((yyvsp[(3) - (4)].strval))); ;}
    break;

  case 43:
#line 140 "pond.y"
    {(yyval.exp) = create_getstr_node(remove_double_quotes((yyvsp[(3) - (4)].strval))); ;}
    break;

  case 44:
#line 141 "pond.y"
    { (yyval.exp) = (yyvsp[(1) - (2)].exp); ;}
    break;

  case 45:
#line 142 "pond.y"
    {(yyval.exp) = create_seq_node((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 46:
#line 143 "pond.y"
    { (yyval.exp) = create_doloop_node((yyvsp[(2) - (5)].intval), (yyvsp[(4) - (5)].exp));;}
    break;

  case 47:
#line 144 "pond.y"
    { (yyval.exp) = create_forloop_node((yyvsp[(2) - (11)].strval), (yyvsp[(4) - (11)].exp), (yyvsp[(6) - (11)].exp), (yyvsp[(8) - (11)].exp), (yyvsp[(10) - (11)].exp), (yyvsp[(4) - (11)].exp)); ;}
    break;

  case 48:
#line 145 "pond.y"
    {(yyval.exp) = create_if_node((yyvsp[(2) - (7)].exp), (yyvsp[(4) - (7)].exp), (yyvsp[(7) - (7)].exp));;}
    break;

  case 49:
#line 146 "pond.y"
    { (yyval.exp) = create_if_node((yyvsp[(2) - (5)].exp), (yyvsp[(4) - (5)].exp), create_int_node(NUM, 0));;}
    break;

  case 50:
#line 147 "pond.y"
    {(yyval.exp) = create_while_node((yyvsp[(2) - (5)].exp), (yyvsp[(4) - (5)].exp));;}
    break;

  case 51:
#line 148 "pond.y"
    { (yyval.exp) = create_list_node((yyvsp[(2) - (3)].list)); ;}
    break;

  case 52:
#line 149 "pond.y"
    {(yyval.exp) = create_list_node(NULL); ;}
    break;

  case 53:
#line 150 "pond.y"
    {(yyval.exp) = create_func_node((yyvsp[(1) - (7)].strval), (yyvsp[(3) - (7)].varlist), (yyvsp[(6) - (7)].exp)); ;}
    break;

  case 54:
#line 151 "pond.y"
    {(yyval.exp) = create_app_node((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].list)); ;}
    break;

  case 55:
#line 152 "pond.y"
    {(yyval.exp) = create_return_node((yyvsp[(2) - (2)].exp)); ;}
    break;

  case 56:
#line 153 "pond.y"
    {(yyval.exp) = create_binop_node(INDEX, (yyvsp[(3) - (4)].exp), (yyvsp[(1) - (4)].exp));;}
    break;

  case 57:
#line 154 "pond.y"
    {(yyval.exp) = (yyvsp[(2) - (3)].exp); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2026 "pond.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 156 "pond.y"
              
               
    
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
