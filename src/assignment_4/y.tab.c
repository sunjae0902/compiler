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
     ELSE_SYM = 259,
     GOTO_SYM = 260,
     AUTO_SYM = 261,
     BREAK_SYM = 262,
     CASE_SYM = 263,
     CONTINUE_SYM = 264,
     DEFAULT_SYM = 265,
     DO_SYM = 266,
     ENUM_SYM = 267,
     FOR_SYM = 268,
     IF_SYM = 269,
     RETURN_SYM = 270,
     SIZEOF_SYM = 271,
     STATIC_SYM = 272,
     STRUCT_SYM = 273,
     SWITCH_SYM = 274,
     TYPEDEF_SYM = 275,
     UNION_SYM = 276,
     WHILE_SYM = 277,
     PLUSPLUS = 278,
     MINUSMINUS = 279,
     ARROW = 280,
     LSS = 281,
     GTR = 282,
     LEQ = 283,
     GEQ = 284,
     EQL = 285,
     NEQ = 286,
     AMPAMP = 287,
     BARBAR = 288,
     DOTDOTDOT = 289,
     LP = 290,
     RP = 291,
     LB = 292,
     RB = 293,
     LR = 294,
     RR = 295,
     COLON = 296,
     PERIOD = 297,
     COMMA = 298,
     EXCL = 299,
     STAR = 300,
     SLASH = 301,
     PERCENT = 302,
     AMP = 303,
     SEMICOLON = 304,
     PLUS = 305,
     MINUS = 306,
     ASSIGN = 307,
     INTEGER_CONSTANT = 308,
     FLOAT_CONSTANT = 309,
     STRING_LITERAL = 310,
     CHARACTER_CONSTANT = 311,
     ESCAPE_CONSTANT = 312,
     IDENTIFIER = 313,
     TYPE_IDENTIFIER = 314
   };
#endif
/* Tokens.  */
#define ELSE_SYM 259
#define GOTO_SYM 260
#define AUTO_SYM 261
#define BREAK_SYM 262
#define CASE_SYM 263
#define CONTINUE_SYM 264
#define DEFAULT_SYM 265
#define DO_SYM 266
#define ENUM_SYM 267
#define FOR_SYM 268
#define IF_SYM 269
#define RETURN_SYM 270
#define SIZEOF_SYM 271
#define STATIC_SYM 272
#define STRUCT_SYM 273
#define SWITCH_SYM 274
#define TYPEDEF_SYM 275
#define UNION_SYM 276
#define WHILE_SYM 277
#define PLUSPLUS 278
#define MINUSMINUS 279
#define ARROW 280
#define LSS 281
#define GTR 282
#define LEQ 283
#define GEQ 284
#define EQL 285
#define NEQ 286
#define AMPAMP 287
#define BARBAR 288
#define DOTDOTDOT 289
#define LP 290
#define RP 291
#define LB 292
#define RB 293
#define LR 294
#define RR 295
#define COLON 296
#define PERIOD 297
#define COMMA 298
#define EXCL 299
#define STAR 300
#define SLASH 301
#define PERCENT 302
#define AMP 303
#define SEMICOLON 304
#define PLUS 305
#define MINUS 306
#define ASSIGN 307
#define INTEGER_CONSTANT 308
#define FLOAT_CONSTANT 309
#define STRING_LITERAL 310
#define CHARACTER_CONSTANT 311
#define ESCAPE_CONSTANT 312
#define IDENTIFIER 313
#define TYPE_IDENTIFIER 314




/* Copy the first part of user declarations.  */
#line 1 "kim.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "string.h"
    int yylex();
    int yywrap(void);
    int yyerror(const char *s);
    extern char *yytext;


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "y.tab.c"

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNRULES -- Number of states.  */
#define YYNSTATES  286

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    21,
      25,    26,    28,    30,    32,    35,    38,    40,    42,    44,
      46,    50,    52,    56,    58,    60,    62,    64,    70,    75,
      78,    80,    82,    84,    87,    91,    93,    96,    98,   102,
     104,   107,   111,   117,   122,   125,   127,   131,   133,   137,
     140,   142,   144,   147,   149,   153,   158,   163,   164,   166,
     167,   169,   171,   175,   177,   181,   184,   187,   188,   190,
     192,   194,   197,   201,   205,   209,   214,   219,   221,   223,
     225,   227,   229,   231,   236,   240,   244,   249,   250,   253,
     254,   257,   259,   262,   269,   277,   283,   289,   297,   307,
     308,   310,   314,   317,   320,   324,   326,   328,   330,   332,
     334,   338,   340,   343,   346,   351,   356,   360,   364,   365,
     367,   369,   373,   375,   378,   381,   384,   387,   390,   393,
     396,   399,   404,   406,   411,   413,   416,   418,   422,   426,
     430,   432,   436,   440,   442,   444,   448,   452,   456,   460,
     462,   466,   470,   472,   476,   478,   480,   482,   486,   488,
     492,   494,   496,   500,   502,   504
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    -1,    63,    -1,    62,    63,    -1,
      64,    -1,    65,    -1,    67,    83,    96,    -1,    83,    96,
      -1,    67,    66,    49,    -1,    -1,    69,    -1,    72,    -1,
      68,    -1,    72,    67,    -1,    68,    67,    -1,     6,    -1,
      17,    -1,    20,    -1,    70,    -1,    69,    43,    70,    -1,
      83,    -1,    83,    52,    71,    -1,   122,    -1,    73,    -1,
      80,    -1,    59,    -1,    74,    58,    39,    75,    40,    -1,
      74,    39,    75,    40,    -1,    74,    58,    -1,    18,    -1,
      21,    -1,    76,    -1,    75,    76,    -1,    77,    78,    49,
      -1,    72,    -1,    72,    77,    -1,    79,    -1,    78,    43,
      79,    -1,    83,    -1,    41,   125,    -1,    83,    41,   125,
      -1,    12,    58,    39,    81,    40,    -1,    12,    39,    81,
      40,    -1,    12,    58,    -1,    82,    -1,    81,    43,    82,
      -1,    58,    -1,    58,    52,   125,    -1,    84,    85,    -1,
      85,    -1,    45,    -1,    45,    84,    -1,    58,    -1,    35,
      83,    36,    -1,    85,    37,    86,    38,    -1,    85,    35,
      87,    36,    -1,    -1,   125,    -1,    -1,    88,    -1,    89,
      -1,    89,    43,    34,    -1,    90,    -1,    89,    43,    90,
      -1,    67,    83,    -1,    67,    91,    -1,    -1,    92,    -1,
      84,    -1,    93,    -1,    84,    93,    -1,    35,    92,    36,
      -1,    37,    86,    38,    -1,    35,    87,    36,    -1,    93,
      37,    86,    38,    -1,    93,    35,    87,    36,    -1,    95,
      -1,    96,    -1,    99,    -1,   100,    -1,   101,    -1,   103,
      -1,     8,   125,    41,    94,    -1,    10,    41,    94,    -1,
      58,    41,    94,    -1,    39,    97,    98,    40,    -1,    -1,
      97,    65,    -1,    -1,    98,    94,    -1,    49,    -1,   124,
      49,    -1,    14,    35,   124,    36,    94,     3,    -1,    14,
      35,   124,    36,    94,     4,    94,    -1,    19,    35,   124,
      36,    94,    -1,    22,    35,   124,    36,    94,    -1,    11,
      94,    22,    35,   124,    36,    49,    -1,    13,    35,   102,
      49,   102,    49,   102,    36,    94,    -1,    -1,   124,    -1,
      15,   102,    49,    -1,     9,    49,    -1,     7,    49,    -1,
       5,    58,    49,    -1,    58,    -1,    53,    -1,    54,    -1,
      56,    -1,    55,    -1,    35,   124,    36,    -1,   104,    -1,
     105,    23,    -1,   105,    24,    -1,   105,    37,   124,    38,
      -1,   105,    35,   106,    36,    -1,   105,    42,    58,    -1,
     105,    25,    58,    -1,    -1,   107,    -1,   122,    -1,   107,
      43,   122,    -1,   105,    -1,    23,   108,    -1,    24,   108,
      -1,    48,   109,    -1,    45,   109,    -1,    44,   109,    -1,
      51,   109,    -1,    50,   109,    -1,    16,   108,    -1,    16,
      35,   110,    36,    -1,   108,    -1,    35,   110,    36,   109,
      -1,    67,    -1,    67,    92,    -1,   109,    -1,   111,    45,
     109,    -1,   111,    46,   109,    -1,   111,    47,   109,    -1,
     111,    -1,   112,    50,   111,    -1,   112,    51,   111,    -1,
     112,    -1,   113,    -1,   114,    26,   113,    -1,   114,    27,
     113,    -1,   114,    28,   113,    -1,   114,    29,   113,    -1,
     114,    -1,   115,    30,   114,    -1,   115,    31,   114,    -1,
     115,    -1,   116,    48,   115,    -1,   116,    -1,   117,    -1,
     118,    -1,   119,    32,   118,    -1,   119,    -1,   120,    33,
     119,    -1,   120,    -1,   121,    -1,   108,    52,   122,    -1,
     122,    -1,   123,    -1,   122,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    20,    20,    24,    25,    29,    30,    34,    35,    39,
      42,    44,    48,    49,    50,    51,    55,    56,    57,    62,
      63,    67,    68,    72,    76,    77,    78,    82,    83,    84,
      88,    89,    93,    94,    98,   102,   103,   107,   108,   112,
     113,   114,   118,   119,   120,   124,   125,   129,   130,   134,
     135,   139,   140,   144,   145,   146,   147,   150,   152,   155,
     157,   161,   162,   166,   167,   171,   172,   175,   177,   181,
     182,   183,   187,   188,   189,   190,   191,   195,   196,   197,
     198,   199,   200,   204,   205,   206,   210,   213,   215,   218,
     220,   224,   225,   229,   230,   231,   235,   236,   237,   240,
     242,   246,   247,   248,   249,   253,   254,   255,   256,   257,
     258,   262,   263,   264,   265,   266,   267,   268,   271,   273,
     277,   278,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   295,   296,   300,   301,   305,   306,   307,   308,
     312,   313,   314,   318,   322,   323,   324,   325,   326,   330,
     331,   332,   336,   337,   341,   345,   349,   350,   354,   355,
     359,   363,   364,   368,   372,   376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"then\"", "ELSE_SYM", "GOTO_SYM",
  "AUTO_SYM", "BREAK_SYM", "CASE_SYM", "CONTINUE_SYM", "DEFAULT_SYM",
  "DO_SYM", "ENUM_SYM", "FOR_SYM", "IF_SYM", "RETURN_SYM", "SIZEOF_SYM",
  "STATIC_SYM", "STRUCT_SYM", "SWITCH_SYM", "TYPEDEF_SYM", "UNION_SYM",
  "WHILE_SYM", "PLUSPLUS", "MINUSMINUS", "ARROW", "LSS", "GTR", "LEQ",
  "GEQ", "EQL", "NEQ", "AMPAMP", "BARBAR", "DOTDOTDOT", "LP", "RP", "LB",
  "RB", "LR", "RR", "COLON", "PERIOD", "COMMA", "EXCL", "STAR", "SLASH",
  "PERCENT", "AMP", "SEMICOLON", "PLUS", "MINUS", "ASSIGN",
  "INTEGER_CONSTANT", "FLOAT_CONSTANT", "STRING_LITERAL",
  "CHARACTER_CONSTANT", "ESCAPE_CONSTANT", "IDENTIFIER", "TYPE_IDENTIFIER",
  "$accept", "program", "translation_unit", "external_declaration",
  "function_definition", "declaration", "init_declarator_list_opt",
  "declaration_specifiers", "storage_class_specifier",
  "init_declarator_list", "init_declarator", "initializer",
  "type_specifier", "struct_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "declarator", "pointer", "direct_declarator", "constant_expression_opt",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "labeled_statement", "compound_statement", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "expression_opt", "jump_statement",
  "primary_expression", "postfix_expression", "arg_expression_list_opt",
  "arg_expression_list", "unary_expression", "cast_expression",
  "type_name", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "comma_expression",
  "expression", "constant_expression", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   101,   102,
     102,   103,   103,   103,   103,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   113,   114,   114,   114,   114,   114,   115,
     115,   115,   116,   116,   117,   118,   119,   119,   120,   120,
     121,   122,   122,   123,   124,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     2,     3,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     1,     2,     1,     3,     1,
       2,     3,     5,     4,     2,     1,     3,     1,     3,     2,
       1,     1,     2,     1,     3,     4,     4,     0,     1,     0,
       1,     1,     3,     1,     3,     2,     2,     0,     1,     1,
       1,     2,     3,     3,     3,     4,     4,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     4,     0,     2,     0,
       2,     1,     2,     6,     7,     5,     5,     7,     9,     0,
       1,     3,     2,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     4,     4,     3,     3,     0,     1,
       1,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     1,     4,     1,     2,     1,     3,     3,     3,
       1,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     3,     1,     3,
       1,     1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,     0,    17,    30,    18,    31,     0,    51,    53,
      26,     0,     2,     3,     5,     6,    10,    13,    12,    24,
       0,    25,     0,     0,    50,     0,    44,     0,    52,     1,
       4,     0,    11,    19,    21,    15,    14,     0,    29,    87,
       8,    49,    59,    57,    47,     0,    45,     0,    54,     9,
       0,     0,     7,    35,     0,    32,     0,     0,    89,    67,
       0,    60,    61,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   109,   108,   105,     0,   111,
     122,   132,   136,   140,   143,   144,   149,   152,   154,   155,
     156,   158,   160,   161,   165,    58,     0,    43,     0,     0,
      20,    21,    22,    23,    36,    28,    33,     0,     0,    37,
      39,     0,    88,    10,     0,    59,    57,    65,    69,    66,
      68,    70,    56,     0,     0,   130,     0,   123,   124,   134,
       0,   163,   164,     0,   132,   127,   126,   125,   129,   128,
      55,   112,   113,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    46,    42,    40,     0,    34,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,    86,    91,   105,    90,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,    71,    59,    57,    62,    64,
       0,    59,    69,   135,     0,   110,   117,     0,   119,   120,
       0,   116,   162,   137,   138,   139,   141,   142,   145,   146,
     147,   148,   150,   151,   153,   157,   159,    38,    41,     0,
     103,     0,   102,     0,     0,    99,     0,     0,   100,     0,
       0,     0,    92,    74,    72,    73,     0,     0,   131,   133,
     115,     0,   114,   104,     0,    84,     0,     0,     0,   101,
       0,     0,    85,    76,    75,   121,    83,     0,    99,     0,
       0,     0,     0,     0,     0,    95,    96,     0,    99,    93,
       0,    97,     0,    94,     0,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    31,    59,    17,    32,
      33,   102,    18,    19,    20,    54,    55,    56,   108,   109,
      21,    45,    46,    22,    23,    24,    78,   192,    61,    62,
      63,   119,   193,   121,   184,   185,   186,    58,   114,   187,
     188,   189,   237,   190,    79,    80,   207,   208,    81,    82,
     130,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   131,   132,   191,    95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -223
static const yytype_int16 yypact[] =
{
     344,  -223,    -7,  -223,  -223,  -223,  -223,    28,   -16,  -223,
    -223,    33,   344,  -223,  -223,  -223,    28,   255,   255,  -223,
       6,  -223,    13,   -10,    87,    10,    36,    57,  -223,  -223,
    -223,    69,    91,  -223,    37,  -223,  -223,    22,   115,  -223,
    -223,    87,   255,   400,    56,    29,  -223,    10,  -223,  -223,
      28,   400,  -223,    22,     2,  -223,    25,    22,   255,    84,
     120,  -223,   117,  -223,   441,   458,   458,   286,   400,   400,
     400,   400,   400,  -223,  -223,  -223,  -223,  -223,   126,  -223,
     124,   106,  -223,    98,   102,  -223,   112,   132,   119,  -223,
    -223,   138,   156,  -223,  -223,  -223,   400,  -223,    10,    63,
    -223,   158,  -223,  -223,  -223,  -223,  -223,   400,     1,  -223,
     167,    92,  -223,    28,   183,   337,   400,  -223,   -11,  -223,
    -223,    90,  -223,   393,   286,  -223,   400,  -223,  -223,    42,
     185,  -223,  -223,   188,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,   168,   400,   400,   171,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,  -223,  -223,  -223,  -223,    25,  -223,   400,  -223,
     177,   176,   400,   198,   211,   235,   218,   220,   400,   221,
     225,  -223,  -223,   222,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,   213,   228,   229,   230,    90,   255,   400,  -223,  -223,
     233,   363,    96,  -223,   400,  -223,  -223,   241,   223,  -223,
     240,  -223,  -223,  -223,  -223,  -223,    98,    98,  -223,  -223,
    -223,  -223,   112,   112,   132,  -223,   138,  -223,  -223,   232,
    -223,   246,  -223,   235,   249,   400,   400,   245,  -223,   400,
     400,   235,  -223,  -223,  -223,  -223,   259,   244,  -223,  -223,
    -223,   400,  -223,  -223,   235,  -223,   261,   248,   263,  -223,
     264,   265,  -223,  -223,  -223,  -223,  -223,   400,   400,   235,
     235,   235,   269,   262,   200,  -223,  -223,   266,   400,  -223,
     235,  -223,   272,  -223,   235,  -223
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,   300,  -223,   258,  -223,     4,  -223,  -223,
     267,  -223,   -26,  -223,  -223,   256,   -44,   270,  -223,   152,
    -223,   273,   224,    -1,    -6,   -18,  -109,   -39,  -223,  -223,
     196,  -223,   -47,  -101,  -134,  -223,    -4,  -223,  -223,  -223,
    -223,  -223,  -222,  -223,  -223,  -223,  -223,  -223,    26,   -33,
     201,    65,  -223,    59,    62,   165,  -223,  -223,   166,   172,
    -223,  -223,   -42,  -223,   -67,   -88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     133,    94,    28,    60,    16,    41,    27,   194,   162,   103,
     106,    53,   120,   257,     2,    34,    16,   195,    40,   165,
       4,    35,    36,     6,   115,     7,   116,    53,    53,     8,
      52,    53,    25,    29,     2,   135,   136,   137,   138,   139,
       4,   234,   105,     6,   166,    37,   273,     9,     9,   101,
     167,    26,    39,   118,    94,   110,   282,   133,   117,   133,
       7,    10,   113,     7,    38,    94,   107,   106,    44,    97,
       8,   129,    98,     8,    94,    47,    39,   201,   210,   116,
     228,    10,   203,     9,   231,    53,     9,     8,   247,    51,
     125,   127,   128,    48,   134,   134,   134,   134,   134,   255,
      41,   195,   209,   164,     2,   212,    98,   262,    96,   118,
       4,   238,   101,     6,    27,   213,   214,   215,    49,   115,
     266,   116,    42,   202,    43,   196,    94,   197,   129,     8,
      94,   201,   169,   116,    50,   274,   275,   276,   153,   154,
     155,   156,     9,   148,   149,   150,   283,   141,   142,   143,
     285,    10,   151,   152,    57,    94,   122,   246,   147,   144,
     123,   145,   157,   158,   140,   110,   146,   159,   238,   258,
     160,   249,   260,   261,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   170,   161,
     171,   172,   173,   174,   175,   202,   176,   177,   178,    64,
     272,   238,   179,   279,   280,   180,    65,    66,   168,   265,
      51,   238,   218,   219,   220,   221,   216,   217,    67,   222,
     223,   204,    39,   181,   205,   230,   206,    68,    69,   211,
     134,    70,   182,    71,    72,   229,    73,    74,    75,    76,
     170,   183,   171,   172,   173,   174,   175,   232,   176,   177,
     178,    64,   233,   235,   179,   236,   239,   180,    65,    66,
     240,     1,   242,   241,   243,   244,   251,     2,   245,   248,
      67,   256,     3,     4,    39,     5,     6,   250,   252,    68,
      69,   253,   264,    70,   182,    71,    72,   254,    73,    74,
      75,    76,     1,   183,   259,   263,   267,   268,     2,   269,
     270,   271,    64,     3,     4,   277,     5,     6,   284,    65,
      66,   278,    30,   111,    10,   281,   112,   100,   227,   199,
      99,    67,   163,   104,   224,   200,   225,     0,     0,     0,
      68,    69,     0,   226,    70,     0,    71,    72,     0,    73,
      74,    75,    76,     1,    77,    10,     0,     0,     0,     2,
       1,     0,     0,     0,     3,     4,     2,     5,     6,     0,
       0,     3,     4,     0,     5,     6,     0,     0,     0,     1,
       0,     0,   115,     0,   116,     2,     0,     0,     0,     7,
       3,     4,     8,     5,     6,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     9,    10,     0,   201,     1,
     116,     0,     9,    10,     0,     2,     0,     0,     8,     0,
       3,     4,     0,     5,     6,     0,    64,     0,     0,     0,
       0,     0,    10,    65,    66,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,     0,     0,    70,     0,
      71,    72,    10,    73,    74,    75,    76,    64,    77,     0,
       0,     0,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,   124,     0,     0,     0,
       0,    65,    66,     0,     0,    68,    69,     0,     0,    70,
       0,    71,    72,   126,    73,    74,    75,    76,     0,    77,
       0,     0,    68,    69,     0,     0,    70,     0,    71,    72,
       0,    73,    74,    75,    76,     0,    77
};

static const yytype_int16 yycheck[] =
{
      67,    43,     8,    42,     0,    23,     7,   116,    96,    51,
      54,    37,    59,   235,    12,    16,    12,   118,    22,   107,
      18,    17,    18,    21,    35,    35,    37,    53,    54,    45,
      34,    57,    39,     0,    12,    68,    69,    70,    71,    72,
      18,   175,    40,    21,    43,    39,   268,    58,    58,    50,
      49,    58,    39,    59,    96,    56,   278,   124,    59,   126,
      35,    59,    58,    35,    58,   107,    41,   111,    58,    40,
      45,    67,    43,    45,   116,    39,    39,    35,   145,    37,
     168,    59,   129,    58,   172,   111,    58,    45,   197,    52,
      64,    65,    66,    36,    68,    69,    70,    71,    72,   233,
     118,   202,   144,    40,    12,   147,    43,   241,    52,   115,
      18,   178,   113,    21,   115,   148,   149,   150,    49,    35,
     254,    37,    35,   129,    37,    35,   168,    37,   124,    45,
     172,    35,    40,    37,    43,   269,   270,   271,    26,    27,
      28,    29,    58,    45,    46,    47,   280,    23,    24,    25,
     284,    59,    50,    51,    39,   197,    36,   196,    52,    35,
      43,    37,    30,    31,    38,   166,    42,    48,   235,   236,
      32,   204,   239,   240,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     5,    33,
       7,     8,     9,    10,    11,   201,    13,    14,    15,    16,
     267,   268,    19,     3,     4,    22,    23,    24,    41,   251,
      52,   278,   153,   154,   155,   156,   151,   152,    35,   157,
     158,    36,    39,    40,    36,    49,    58,    44,    45,    58,
     204,    48,    49,    50,    51,    58,    53,    54,    55,    56,
       5,    58,     7,     8,     9,    10,    11,    49,    13,    14,
      15,    16,    41,    35,    19,    35,    35,    22,    23,    24,
      35,     6,    49,    41,    36,    36,    43,    12,    38,    36,
      35,    22,    17,    18,    39,    20,    21,    36,    38,    44,
      45,    49,    38,    48,    49,    50,    51,    41,    53,    54,
      55,    56,     6,    58,    49,    36,    35,    49,    12,    36,
      36,    36,    16,    17,    18,    36,    20,    21,    36,    23,
      24,    49,    12,    57,    59,    49,    58,    50,   166,   123,
      47,    35,    98,    53,   159,   124,   160,    -1,    -1,    -1,
      44,    45,    -1,   161,    48,    -1,    50,    51,    -1,    53,
      54,    55,    56,     6,    58,    59,    -1,    -1,    -1,    12,
       6,    -1,    -1,    -1,    17,    18,    12,    20,    21,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,     6,
      -1,    -1,    35,    -1,    37,    12,    -1,    -1,    -1,    35,
      17,    18,    45,    20,    21,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    58,    59,    -1,    35,     6,
      37,    -1,    58,    59,    -1,    12,    -1,    -1,    45,    -1,
      17,    18,    -1,    20,    21,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    59,    23,    24,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,
      50,    51,    59,    53,    54,    55,    56,    16,    58,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    35,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,    50,    51,    35,    53,    54,    55,    56,    -1,    58,
      -1,    -1,    44,    45,    -1,    -1,    48,    -1,    50,    51,
      -1,    53,    54,    55,    56,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    12,    17,    18,    20,    21,    35,    45,    58,
      59,    61,    62,    63,    64,    65,    67,    68,    72,    73,
      74,    80,    83,    84,    85,    39,    58,    83,    84,     0,
      63,    66,    69,    70,    83,    67,    67,    39,    58,    39,
      96,    85,    35,    37,    58,    81,    82,    39,    36,    49,
      43,    52,    96,    72,    75,    76,    77,    39,    97,    67,
      87,    88,    89,    90,    16,    23,    24,    35,    44,    45,
      48,    50,    51,    53,    54,    55,    56,    58,    86,   104,
     105,   108,   109,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   125,    52,    40,    43,    81,
      70,    83,    71,   122,    77,    40,    76,    41,    78,    79,
      83,    75,    65,    67,    98,    35,    37,    83,    84,    91,
      92,    93,    36,    43,    35,   108,    35,   108,   108,    67,
     110,   122,   123,   124,   108,   109,   109,   109,   109,   109,
      38,    23,    24,    25,    35,    37,    42,    52,    45,    46,
      47,    50,    51,    26,    27,    28,    29,    30,    31,    48,
      32,    33,   125,    82,    40,   125,    43,    49,    41,    40,
       5,     7,     8,     9,    10,    11,    13,    14,    15,    19,
      22,    40,    49,    58,    94,    95,    96,    99,   100,   101,
     103,   124,    87,    92,    86,    93,    35,    37,    34,    90,
     110,    35,    84,    92,    36,    36,    58,   106,   107,   122,
     124,    58,   122,   109,   109,   109,   111,   111,   113,   113,
     113,   113,   114,   114,   115,   118,   119,    79,   125,    58,
      49,   125,    49,    41,    94,    35,    35,   102,   124,    35,
      35,    41,    49,    36,    36,    38,    87,    86,    36,   109,
      36,    43,    38,    49,    41,    94,    22,   102,   124,    49,
     124,   124,    94,    36,    38,   122,    94,    35,    49,    36,
      36,    36,   124,   102,    94,    94,    94,    36,    49,     3,
       4,    49,   102,    94,    36,    94
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
      
/* Line 1267 of yacc.c.  */
#line 1765 "y.tab.c"
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


#line 379 "kim.y"

    
int main () {
    yyparse();
    printf("success!\n");
    return 0;
}
    
int yyerror(const char *s) {
    printf("%s near '%s'\n",s,yytext);
    exit(1);
    }
int yywrap(void){
    return 1;
    }
    

