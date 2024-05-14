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
     AUTO_SYM = 260,
     BREAK_SYM = 261,
     CASE_SYM = 262,
     CONTINUE_SYM = 263,
     DEFAULT_SYM = 264,
     DO_SYM = 265,
     ENUM_SYM = 266,
     FOR_SYM = 267,
     IF_SYM = 268,
     RETURN_SYM = 269,
     SIZEOF_SYM = 270,
     STATIC_SYM = 271,
     STRUCT_SYM = 272,
     SWITCH_SYM = 273,
     TYPEDEF_SYM = 274,
     UNION_SYM = 275,
     WHILE_SYM = 276,
     PLUSPLUS = 277,
     MINUSMINUS = 278,
     ARROW = 279,
     LSS = 280,
     GTR = 281,
     LEQ = 282,
     GEQ = 283,
     EQL = 284,
     NEQ = 285,
     AMPAMP = 286,
     BARBAR = 287,
     DOTDOTDOT = 288,
     LP = 289,
     RP = 290,
     LB = 291,
     RB = 292,
     LR = 293,
     RR = 294,
     COLON = 295,
     PERIOD = 296,
     COMMA = 297,
     EXCL = 298,
     STAR = 299,
     SLASH = 300,
     PERCENT = 301,
     AMP = 302,
     SEMICOLON = 303,
     PLUS = 304,
     MINUS = 305,
     ASSIGN = 306,
     INTEGER_CONSTANT = 307,
     FLOAT_CONSTANT = 308,
     STRING_LITERAL = 309,
     CHARACTER_CONSTANT = 310,
     ESCAPE_CONSTANT = 311,
     IDENTIFIER = 312,
     TYPE_IDENTIFIER = 313
   };
#endif
/* Tokens.  */
#define ELSE_SYM 259
#define AUTO_SYM 260
#define BREAK_SYM 261
#define CASE_SYM 262
#define CONTINUE_SYM 263
#define DEFAULT_SYM 264
#define DO_SYM 265
#define ENUM_SYM 266
#define FOR_SYM 267
#define IF_SYM 268
#define RETURN_SYM 269
#define SIZEOF_SYM 270
#define STATIC_SYM 271
#define STRUCT_SYM 272
#define SWITCH_SYM 273
#define TYPEDEF_SYM 274
#define UNION_SYM 275
#define WHILE_SYM 276
#define PLUSPLUS 277
#define MINUSMINUS 278
#define ARROW 279
#define LSS 280
#define GTR 281
#define LEQ 282
#define GEQ 283
#define EQL 284
#define NEQ 285
#define AMPAMP 286
#define BARBAR 287
#define DOTDOTDOT 288
#define LP 289
#define RP 290
#define LB 291
#define RB 292
#define LR 293
#define RR 294
#define COLON 295
#define PERIOD 296
#define COMMA 297
#define EXCL 298
#define STAR 299
#define SLASH 300
#define PERCENT 301
#define AMP 302
#define SEMICOLON 303
#define PLUS 304
#define MINUS 305
#define ASSIGN 306
#define INTEGER_CONSTANT 307
#define FLOAT_CONSTANT 308
#define STRING_LITERAL 309
#define CHARACTER_CONSTANT 310
#define ESCAPE_CONSTANT 311
#define IDENTIFIER 312
#define TYPE_IDENTIFIER 313




/* Copy the first part of user declarations.  */
#line 1 "kim.y"

    #define YYSTYPE_IS_DECLARED 1
    typedef long YYSTYPE;
    #include "type.h"
    #include "func.h"
  
    extern int line_no, syntax_err;
    extern A_NODE *root;
    extern int current_level;
    extern A_ID *current_id;
    extern A_TYPE *int_type, *float_type, *char_type, *void_type, *string_type;
    int yyerror(const char *);
    int yylex();



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
#line 236 "y.tab.c"

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
#define YYLAST   464

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    15,    20,
      21,    25,    26,    28,    30,    33,    37,    39,    41,    44,
      47,    49,    51,    53,    54,    56,    58,    62,    64,    68,
      70,    74,    76,    80,    82,    84,    86,    87,    88,    96,
      97,    98,   105,   108,   110,   112,   114,   117,   121,   123,
     127,   129,   130,   137,   138,   144,   147,   149,   153,   155,
     156,   161,   164,   166,   168,   171,   173,   177,   182,   183,
     189,   190,   192,   194,   198,   200,   204,   207,   210,   211,
     213,   215,   217,   220,   224,   228,   233,   237,   242,   243,
     245,   247,   250,   252,   254,   256,   258,   260,   262,   267,
     271,   272,   278,   280,   283,   290,   298,   304,   310,   318,
     324,   330,   331,   333,   337,   340,   343,   344,   346,   348,
     352,   353,   355,   357,   359,   361,   363,   367,   369,   371,
     375,   377,   381,   383,   385,   387,   389,   393,   397,   399,
     403,   407,   411,   415,   417,   419,   423,   427,   429,   433,
     437,   441,   443,   448,   450,   453,   456,   459,   462,   465,
     468,   471,   474,   479,   481,   486,   491,   495,   499,   502,
     505,   507,   509,   511,   513,   515,   519
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    62,    -1,    61,    62,    -1,
      63,    -1,    68,    -1,    -1,    69,    93,    64,   108,    -1,
      -1,    93,    65,   108,    -1,    -1,    67,    -1,    68,    -1,
      67,    68,    -1,    69,    71,    48,    -1,    76,    -1,    70,
      -1,    76,    69,    -1,    70,    69,    -1,     5,    -1,    16,
      -1,    19,    -1,    -1,    72,    -1,    73,    -1,    72,    42,
      73,    -1,    93,    -1,    93,    51,    74,    -1,   119,    -1,
      38,    75,    39,    -1,    74,    -1,    75,    42,    74,    -1,
      77,    -1,    87,    -1,    58,    -1,    -1,    -1,    82,    57,
      78,    38,    79,    83,    39,    -1,    -1,    -1,    82,    80,
      38,    81,    83,    39,    -1,    82,    57,    -1,    17,    -1,
      20,    -1,    84,    -1,    83,    84,    -1,    76,    85,    48,
      -1,    86,    -1,    85,    42,    86,    -1,    93,    -1,    -1,
      11,    57,    88,    38,    90,    39,    -1,    -1,    11,    89,
      38,    90,    39,    -1,    11,    57,    -1,    91,    -1,    90,
      42,    91,    -1,    57,    -1,    -1,    57,    92,    51,   120,
      -1,    94,    95,    -1,    95,    -1,    44,    -1,    44,    94,
      -1,    57,    -1,    34,    93,    35,    -1,    95,    36,   118,
      37,    -1,    -1,    95,    34,    96,    97,    35,    -1,    -1,
      98,    -1,    99,    -1,    99,    42,    33,    -1,   100,    -1,
      99,    42,   100,    -1,    69,    93,    -1,    69,   101,    -1,
      -1,   102,    -1,   103,    -1,    94,    -1,    94,   103,    -1,
      34,   102,    35,    -1,    36,   118,    37,    -1,   103,    36,
     118,    37,    -1,    34,    97,    35,    -1,   103,    34,    97,
      35,    -1,    -1,   105,    -1,   106,    -1,   105,   106,    -1,
     107,    -1,   108,    -1,   110,    -1,   111,    -1,   112,    -1,
     115,    -1,     7,   119,    40,   106,    -1,     9,    40,   106,
      -1,    -1,    38,   109,    66,   104,    39,    -1,    48,    -1,
     120,    48,    -1,    13,    34,   120,    35,   106,     3,    -1,
      13,    34,   120,    35,   106,     4,   106,    -1,    18,    34,
     120,    35,   106,    -1,    21,    34,   120,    35,   106,    -1,
      10,   106,    21,    34,   120,    35,    48,    -1,    12,    34,
     113,    35,   106,    -1,   114,    48,   114,    48,   114,    -1,
      -1,   120,    -1,    14,   114,    48,    -1,     8,    48,    -1,
       6,    48,    -1,    -1,   117,    -1,   122,    -1,   117,    42,
     122,    -1,    -1,   119,    -1,   120,    -1,   121,    -1,   122,
      -1,   123,    -1,   135,    51,   122,    -1,   124,    -1,   125,
      -1,   124,    32,   125,    -1,   126,    -1,   125,    31,   126,
      -1,   127,    -1,   128,    -1,   129,    -1,   130,    -1,   129,
      29,   130,    -1,   129,    30,   130,    -1,   131,    -1,   130,
      25,   131,    -1,   130,    26,   131,    -1,   130,    27,   131,
      -1,   130,    28,   131,    -1,   132,    -1,   133,    -1,   132,
      49,   133,    -1,   132,    50,   133,    -1,   134,    -1,   133,
      44,   134,    -1,   133,    45,   134,    -1,   133,    46,   134,
      -1,   135,    -1,    34,   138,    35,   134,    -1,   136,    -1,
      22,   135,    -1,    23,   135,    -1,    47,   134,    -1,    44,
     134,    -1,    43,   134,    -1,    50,   134,    -1,    49,   134,
      -1,    15,   135,    -1,    15,    34,   138,    35,    -1,   137,
      -1,   136,    36,   120,    37,    -1,   136,    34,   116,    35,
      -1,   136,    41,    57,    -1,   136,    24,    57,    -1,   136,
      22,    -1,   136,    23,    -1,    57,    -1,    52,    -1,    53,
      -1,    55,    -1,    54,    -1,    34,   120,    35,    -1,    69,
     101,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    31,    32,    36,    37,    41,    41,    43,
      43,    48,    49,    53,    54,    58,    63,    64,    65,    66,
      70,    71,    72,    76,    77,    82,    83,    87,    88,    92,
      93,    97,    98,   102,   103,   104,   108,   109,   108,   112,
     112,   112,   116,   120,   121,   125,   126,   130,   135,   136,
     140,   144,   144,   146,   146,   148,   152,   153,   157,   158,
     158,   163,   164,   168,   169,   173,   174,   175,   177,   177,
     181,   182,   186,   187,   192,   193,   197,   198,   204,   205,
     209,   210,   211,   215,   216,   217,   218,   219,   223,   224,
     227,   228,   231,   232,   233,   234,   235,   236,   240,   241,
     245,   245,   249,   250,   254,   255,   256,   260,   261,   262,
     266,   269,   270,   274,   275,   276,   280,   281,   285,   286,
     290,   291,   295,   299,   303,   307,   308,   312,   316,   317,
     321,   322,   326,   330,   334,   338,   339,   341,   346,   347,
     348,   350,   351,   355,   359,   360,   361,   365,   366,   368,
     370,   375,   376,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   393,   394,   395,   397,   398,   399,   400,
     404,   406,   407,   408,   409,   410,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"then\"", "ELSE_SYM", "AUTO_SYM",
  "BREAK_SYM", "CASE_SYM", "CONTINUE_SYM", "DEFAULT_SYM", "DO_SYM",
  "ENUM_SYM", "FOR_SYM", "IF_SYM", "RETURN_SYM", "SIZEOF_SYM",
  "STATIC_SYM", "STRUCT_SYM", "SWITCH_SYM", "TYPEDEF_SYM", "UNION_SYM",
  "WHILE_SYM", "PLUSPLUS", "MINUSMINUS", "ARROW", "LSS", "GTR", "LEQ",
  "GEQ", "EQL", "NEQ", "AMPAMP", "BARBAR", "DOTDOTDOT", "LP", "RP", "LB",
  "RB", "LR", "RR", "COLON", "PERIOD", "COMMA", "EXCL", "STAR", "SLASH",
  "PERCENT", "AMP", "SEMICOLON", "PLUS", "MINUS", "ASSIGN",
  "INTEGER_CONSTANT", "FLOAT_CONSTANT", "STRING_LITERAL",
  "CHARACTER_CONSTANT", "ESCAPE_CONSTANT", "IDENTIFIER", "TYPE_IDENTIFIER",
  "$accept", "program", "translation_unit", "external_declaration",
  "function_definition", "@1", "@2", "declaration_list_opt",
  "declaration_list", "declaration", "declaration_specifiers",
  "storage_class_specifier", "init_declarator_list_opt",
  "init_declarator_list", "init_declarator", "initializer",
  "initializer_list", "type_specifier", "struct_specifier", "@3", "@4",
  "@5", "@6", "struct_or_union", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "enum_specifier", "@7", "@8", "enumerator_list", "enumerator", "@9",
  "declarator", "pointer", "direct_declarator", "@10",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator",
  "statement_list_opt", "statement_list", "statement", "labeled_statement",
  "compound_statement", "@11", "expression_statement",
  "selection_statement", "iteration_statement", "for_expression",
  "expression_opt", "jump_statement", "arg_expression_list_opt",
  "arg_expression_list", "constant_expression_opt", "constant_expression",
  "expression", "comma_expression", "assignment_expression",
  "conditional_expression", "logical_OR_expression",
  "logical_AND_expression", "bitwise_OR_expression",
  "bitwise_XOR_expression", "bitwise_AND_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "type_name", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    64,    63,    65,
      63,    66,    66,    67,    67,    68,    69,    69,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    78,    79,    77,    80,
      81,    77,    77,    82,    82,    83,    83,    84,    85,    85,
      86,    88,    87,    89,    87,    87,    90,    90,    91,    92,
      91,    93,    93,    94,    94,    95,    95,    95,    96,    95,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   107,   107,
     109,   108,   110,   110,   111,   111,   111,   112,   112,   112,
     113,   114,   114,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   120,   121,   122,   122,   123,   124,   124,
     125,   125,   126,   127,   128,   129,   129,   129,   130,   130,
     130,   130,   130,   131,   132,   132,   132,   133,   133,   133,
     133,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   137,   137,   137,   138
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     0,     0,     7,     0,
       0,     6,     2,     1,     1,     1,     2,     3,     1,     3,
       1,     0,     6,     0,     5,     2,     1,     3,     1,     0,
       4,     2,     1,     1,     2,     1,     3,     4,     0,     5,
       0,     1,     1,     3,     1,     3,     2,     2,     0,     1,
       1,     1,     2,     3,     3,     4,     3,     4,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       0,     5,     1,     2,     6,     7,     5,     5,     7,     5,
       5,     0,     1,     3,     2,     2,     0,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     1,     4,     4,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    53,    21,    43,    22,    44,     0,    63,    65,
      35,     0,     2,     3,     5,     6,    23,    17,    16,    33,
      39,    34,     9,     0,    62,    55,     0,     0,    64,     1,
       4,     0,    24,    25,    27,    19,    18,    42,     0,     0,
      61,    68,   120,     0,     0,    66,    15,     0,     0,     0,
       0,    40,   100,    10,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   174,   173,   170,     0,
     121,   122,   123,   124,   125,   127,   128,   130,   132,   133,
     134,   135,   138,   143,   144,   147,   151,   153,   163,     0,
      58,     0,    56,    26,    27,     0,    28,    29,     8,    37,
       0,    11,    78,     0,    71,    72,    74,     0,   161,     0,
     154,   155,    78,     0,     0,   158,   151,   157,   156,   160,
     159,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,     0,   116,
       0,     0,     0,     0,    54,     0,    31,     0,     0,     0,
       0,    45,    88,    12,    13,    23,    70,   120,    76,    81,
      77,    79,    80,    69,     0,     0,    70,    81,   176,   175,
       0,   129,   131,   136,   137,   139,   140,   141,   142,   145,
     146,   148,   149,   150,   126,   167,     0,   117,   118,     0,
     166,    52,     0,    57,    30,     0,     0,     0,    48,    50,
      41,    46,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,   102,     0,    89,    90,    92,    93,    94,    95,
      96,    97,     0,    14,     0,     0,     0,    82,    70,   120,
      73,    75,   162,   152,   165,     0,   164,    60,    32,    38,
       0,    47,   115,     0,   114,     0,     0,   111,     0,     0,
     112,     0,     0,   101,    91,   103,    86,    83,    84,     0,
       0,   119,    49,     0,    99,     0,     0,     0,     0,   113,
       0,     0,    87,    85,    98,     0,     0,   111,     0,     0,
       0,     0,   109,     0,     0,   106,   107,     0,   111,   104,
       0,   108,   110,   105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    49,    39,   152,   153,    15,
     102,    17,    31,    32,    33,    96,   147,    18,    19,    50,
     148,    38,   100,    20,   150,   151,   197,   198,    21,    43,
      26,    91,    92,   143,    22,    23,    24,    54,   224,   104,
     105,   106,   160,   161,   162,   213,   214,   215,   216,   217,
     101,   218,   219,   220,   266,   249,   221,   186,   187,    69,
      70,   222,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -238
static const yytype_int16 yypact[] =
{
     242,  -238,   -36,  -238,  -238,  -238,  -238,    56,     6,  -238,
    -238,    58,   242,  -238,  -238,  -238,    56,    26,    26,  -238,
      38,  -238,  -238,    -9,   -19,   125,   140,    48,  -238,  -238,
    -238,   142,   152,  -238,   -25,  -238,  -238,   163,   166,   176,
     -19,  -238,   354,   177,   150,  -238,  -238,    56,   337,   176,
     179,  -238,  -238,  -238,    26,   390,   407,   407,   169,   354,
     354,   354,   354,   354,  -238,  -238,  -238,  -238,  -238,   183,
    -238,  -238,  -238,  -238,  -238,   196,   198,  -238,  -238,  -238,
      45,   170,  -238,    42,   127,  -238,   181,   113,  -238,   150,
     187,    40,  -238,  -238,   190,   337,  -238,  -238,  -238,  -238,
      27,    26,    53,   199,  -238,   201,  -238,   169,  -238,   354,
    -238,  -238,    52,   209,   210,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,  -238,  -238,   193,   354,
     354,   194,   103,   197,  -238,   150,  -238,   117,    27,    56,
      82,  -238,   301,    26,  -238,    56,   220,   354,  -238,   105,
    -238,  -238,     5,  -238,    61,   217,   268,   110,  -238,  -238,
     354,   198,  -238,   170,   170,  -238,  -238,  -238,  -238,   127,
     127,  -238,  -238,  -238,  -238,  -238,   222,   213,  -238,   223,
    -238,  -238,   354,  -238,  -238,   337,   191,    72,  -238,  -238,
    -238,  -238,   215,   354,   221,   230,   301,   237,   238,   354,
     240,   241,  -238,   243,   301,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,   232,  -238,   246,   248,   252,     5,    26,   354,
    -238,  -238,  -238,  -238,  -238,   354,  -238,  -238,  -238,  -238,
      56,  -238,  -238,   250,  -238,   301,   270,   354,   354,   244,
    -238,   354,   354,  -238,  -238,  -238,  -238,  -238,  -238,   258,
     257,  -238,  -238,   301,  -238,   261,   262,   253,   263,  -238,
     271,   282,  -238,  -238,  -238,   354,   301,   354,   301,   301,
     301,   283,  -238,   255,   165,  -238,  -238,   272,   354,  -238,
     301,  -238,  -238,  -238
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -238,  -238,  -238,   284,  -238,  -238,  -238,  -238,  -238,   -82,
      11,  -238,  -238,  -238,   274,   -92,  -238,   -80,  -238,  -238,
    -238,  -238,  -238,  -238,   157,  -123,  -238,    85,  -238,  -238,
    -238,   239,   182,  -238,     2,    -1,   -21,  -238,   -53,  -238,
    -238,   167,   218,  -142,  -137,  -238,  -238,   -97,  -238,    15,
    -238,  -238,  -238,  -238,  -238,  -237,  -238,  -238,  -238,  -153,
     -43,   -42,  -238,  -127,  -238,  -238,   207,   211,  -238,  -238,
    -238,    75,   139,  -238,    46,   -27,     0,  -238,  -238,   225
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      71,   103,    40,   146,   226,    97,    71,    28,   184,    27,
     267,    16,   188,    -7,   225,    41,   113,    42,    34,   154,
     149,    25,   227,    16,   225,     7,    48,   201,    35,    36,
     227,     1,   115,   117,   118,   119,   120,     2,     2,   228,
     283,   229,     3,     4,     4,     5,     6,     6,     9,    94,
       8,   292,    97,    71,    53,   108,   110,   111,    29,   116,
     116,   116,   116,   116,    98,   113,     1,   113,   149,   112,
     149,   223,     2,   201,   124,   125,   260,     3,     4,   144,
       5,     6,   145,    45,    10,    10,   166,   156,   157,   157,
       7,   130,   131,     2,   230,    37,     8,     8,   189,     4,
       8,   159,     6,   238,   158,   181,   182,   183,   261,   246,
       9,   167,   155,     9,   240,    71,   149,   254,   112,    10,
     241,   200,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   136,   137,   138,    40,   156,
      10,   157,   191,   233,   166,   145,   157,   139,   264,   140,
     237,   199,    97,    71,   141,   159,   194,    94,    27,   195,
     243,    71,     9,   -51,   155,   167,   274,   250,   289,   290,
     116,   132,   133,   134,     1,   259,   179,   180,    44,   282,
       2,   284,   285,   286,    55,     3,     4,    71,     5,     6,
      46,    56,    57,   293,    47,   126,   127,   128,   129,   173,
     174,   -36,     2,    58,    51,   250,   268,    90,     4,   270,
     271,     6,    59,    60,    52,    89,    61,    99,    62,    63,
     121,    64,    65,    66,    67,     1,    68,    10,   122,   123,
     239,     2,   135,   281,   163,   250,     3,     4,   -59,     5,
       6,    48,   199,   164,   169,   170,   250,     1,   192,    10,
     185,   190,   232,     2,   156,   235,   157,   234,     3,     4,
     236,     5,     6,   242,     8,   175,   176,   177,   178,   244,
     245,   247,   248,     1,   251,   252,     7,     9,    10,     2,
     255,   256,   253,   257,     3,     4,     8,     5,     6,   258,
     263,   265,   269,   272,   273,   275,    30,   276,   278,     9,
      10,   277,   166,   288,   157,   196,   279,   202,   203,   204,
     205,   206,     8,   207,   208,   209,    55,   280,   287,   210,
     291,    93,   211,    56,    57,   262,    10,   193,   142,   171,
     168,   231,   165,     0,   172,    58,     0,     0,     0,    52,
       0,     0,     0,     0,    59,    60,     0,     0,    61,   212,
      62,    63,    55,    64,    65,    66,    67,     0,    68,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    58,     0,     0,     0,    95,    56,    57,     0,     0,
      59,    60,     0,     0,    61,     0,    62,    63,    58,    64,
      65,    66,    67,     0,    68,     0,     0,    59,    60,     0,
       0,    61,     0,    62,    63,    55,    64,    65,    66,    67,
       0,    68,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,   107,     0,     0,     0,     0,    56,
      57,     0,     0,    59,    60,     0,     0,    61,     0,    62,
      63,   109,    64,    65,    66,    67,     0,    68,     0,     0,
      59,    60,     0,     0,    61,     0,    62,    63,     0,    64,
      65,    66,    67,     0,    68
};

static const yytype_int16 yycheck[] =
{
      42,    54,    23,    95,   157,    48,    48,     8,   135,     7,
     247,     0,   139,    38,   156,    34,    58,    36,    16,   101,
     100,    57,   159,    12,   166,    34,    51,   150,    17,    18,
     167,     5,    59,    60,    61,    62,    63,    11,    11,    34,
     277,    36,    16,    17,    17,    19,    20,    20,    57,    47,
      44,   288,    95,    95,    39,    55,    56,    57,     0,    59,
      60,    61,    62,    63,    49,   107,     5,   109,   148,    58,
     150,   153,    11,   196,    29,    30,   229,    16,    17,    39,
      19,    20,    42,    35,    58,    58,    34,    34,    36,    36,
      34,    49,    50,    11,    33,    57,    44,    44,   140,    17,
      44,   102,    20,   195,   102,   132,   133,   134,   235,   206,
      57,   112,   101,    57,    42,   157,   196,   214,   107,    58,
      48,    39,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    22,    23,    24,   159,    34,
      58,    36,    39,   170,    34,    42,    36,    34,   245,    36,
     192,   149,   195,   195,    41,   156,    39,   155,   156,    42,
     203,   203,    57,    38,   153,   166,   263,   209,     3,     4,
     170,    44,    45,    46,     5,   228,   130,   131,    38,   276,
      11,   278,   279,   280,    15,    16,    17,   229,    19,    20,
      48,    22,    23,   290,    42,    25,    26,    27,    28,   124,
     125,    38,    11,    34,    38,   247,   248,    57,    17,   251,
     252,    20,    43,    44,    38,    38,    47,    38,    49,    50,
      37,    52,    53,    54,    55,     5,    57,    58,    32,    31,
      39,    11,    51,   275,    35,   277,    16,    17,    51,    19,
      20,    51,   240,    42,    35,    35,   288,     5,    51,    58,
      57,    57,    35,    11,    34,    42,    36,    35,    16,    17,
      37,    19,    20,    48,    44,   126,   127,   128,   129,    48,
      40,    34,    34,     5,    34,    34,    34,    57,    58,    11,
      48,    35,    39,    35,    16,    17,    44,    19,    20,    37,
      40,    21,    48,    35,    37,    34,    12,    35,    35,    57,
      58,    48,    34,    48,    36,   148,    35,     6,     7,     8,
       9,    10,    44,    12,    13,    14,    15,    35,    35,    18,
      48,    47,    21,    22,    23,   240,    58,   145,    89,   122,
     112,   164,   107,    -1,   123,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    47,    48,
      49,    50,    15,    52,    53,    54,    55,    -1,    57,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    34,    -1,    -1,    -1,    38,    22,    23,    -1,    -1,
      43,    44,    -1,    -1,    47,    -1,    49,    50,    34,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    43,    44,    -1,
      -1,    47,    -1,    49,    50,    15,    52,    53,    54,    55,
      -1,    57,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    34,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    43,    44,    -1,    -1,    47,    -1,    49,
      50,    34,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      43,    44,    -1,    -1,    47,    -1,    49,    50,    -1,    52,
      53,    54,    55,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    11,    16,    17,    19,    20,    34,    44,    57,
      58,    60,    61,    62,    63,    68,    69,    70,    76,    77,
      82,    87,    93,    94,    95,    57,    89,    93,    94,     0,
      62,    71,    72,    73,    93,    69,    69,    57,    80,    65,
      95,    34,    36,    88,    38,    35,    48,    42,    51,    64,
      78,    38,    38,   108,    96,    15,    22,    23,    34,    43,
      44,    47,    49,    50,    52,    53,    54,    55,    57,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    38,
      57,    90,    91,    73,    93,    38,    74,   119,   108,    38,
      81,   109,    69,    97,    98,    99,   100,    34,   135,    34,
     135,   135,    69,   120,   138,   134,   135,   134,   134,   134,
     134,    37,    32,    31,    29,    30,    25,    26,    27,    28,
      49,    50,    44,    45,    46,    51,    22,    23,    24,    34,
      36,    41,    90,    92,    39,    42,    74,    75,    79,    76,
      83,    84,    66,    67,    68,    69,    34,    36,    93,    94,
     101,   102,   103,    35,    42,   138,    34,    94,   101,    35,
      35,   125,   126,   130,   130,   131,   131,   131,   131,   133,
     133,   134,   134,   134,   122,    57,   116,   117,   122,   120,
      57,    39,    51,    91,    39,    42,    83,    85,    86,    93,
      39,    84,     6,     7,     8,     9,    10,    12,    13,    14,
      18,    21,    48,   104,   105,   106,   107,   108,   110,   111,
     112,   115,   120,    68,    97,   102,   118,   103,    34,    36,
      33,   100,    35,   134,    35,    42,    37,   120,    74,    39,
      42,    48,    48,   119,    48,    40,   106,    34,    34,   114,
     120,    34,    34,    39,   106,    48,    35,    35,    37,    97,
     118,   122,    86,    40,   106,    21,   113,   114,   120,    48,
     120,   120,    35,    37,   106,    34,    35,    48,    35,    35,
      35,   120,   106,   114,   106,   106,   106,    35,    48,     3,
       4,    48,   114,   106
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
#line 27 "kim.y"
    {root = makeNode(N_PROGRAM,NIL,(A_NODE*)(yyvsp[(1) - (1)]),NIL); checkForwardReference();}
    break;

  case 3:
#line 31 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 4:
#line 32 "kim.y"
    {(yyval) = (long)(linkDeclaratorList((A_ID*)(yyvsp[(1) - (2)]),(A_ID*)(yyvsp[(2) - (2)])));}
    break;

  case 5:
#line 36 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 6:
#line 37 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 7:
#line 41 "kim.y"
    {(yyval) = (long)setFunctionDeclaratorSpecifier((A_ID*)(yyvsp[(2) - (2)]),(A_SPECIFIER*) (yyvsp[(1) - (2)]));}
    break;

  case 8:
#line 42 "kim.y"
    {(yyval) = (long)setFunctionDeclaratorBody((A_ID*)(yyvsp[(3) - (4)]),(A_NODE*) (yyvsp[(4) - (4)])); current_id = (A_ID*)(yyvsp[(2) - (4)]);}
    break;

  case 9:
#line 43 "kim.y"
    {(yyval) = (long)setFunctionDeclaratorSpecifier((A_ID*)(yyvsp[(1) - (1)]), makeSpecifier(int_type, 0));}
    break;

  case 10:
#line 44 "kim.y"
    {(yyval) = (long)setFunctionDeclaratorBody((A_ID*)(yyvsp[(2) - (3)]),(A_NODE*) (yyvsp[(3) - (3)])); current_id = (A_ID*)(yyvsp[(1) - (3)]);}
    break;

  case 11:
#line 48 "kim.y"
    {(yyval) = NIL;}
    break;

  case 12:
#line 49 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 13:
#line 53 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 14:
#line 54 "kim.y"
    {(yyval) = (long) linkDeclaratorList((A_ID*)(yyvsp[(1) - (2)]), (A_ID*)(yyvsp[(2) - (2)]));}
    break;

  case 15:
#line 59 "kim.y"
    {(yyval) = (long)setDeclaratorListSpecifier((A_ID*)(yyvsp[(2) - (3)]),(A_SPECIFIER*)(yyvsp[(1) - (3)]));}
    break;

  case 16:
#line 63 "kim.y"
    {(yyval) = (long)makeSpecifier((A_TYPE*)(yyvsp[(1) - (1)]),0);}
    break;

  case 17:
#line 64 "kim.y"
    {(yyval) = (long)makeSpecifier(0,(yyvsp[(1) - (1)]));}
    break;

  case 18:
#line 65 "kim.y"
    {(yyval) = (long)updateSpecifier((A_SPECIFIER*)(yyvsp[(2) - (2)]),(A_TYPE*)(yyvsp[(1) - (2)]),0);}
    break;

  case 19:
#line 66 "kim.y"
    {(yyval) = (long)updateSpecifier((A_SPECIFIER*)(yyvsp[(2) - (2)]),0,(yyvsp[(1) - (2)]));}
    break;

  case 20:
#line 70 "kim.y"
    { (yyval) = S_AUTO;}
    break;

  case 21:
#line 71 "kim.y"
    { (yyval) = S_STATIC;}
    break;

  case 22:
#line 72 "kim.y"
    { (yyval) = S_TYPEDEF;}
    break;

  case 23:
#line 76 "kim.y"
    {(yyval) = (long)makeDummyIdentifier();}
    break;

  case 24:
#line 77 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 25:
#line 82 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 26:
#line 83 "kim.y"
    {(yyval) = (long)linkDeclaratorList((A_ID*)(yyvsp[(1) - (3)]),(A_ID*)(yyvsp[(3) - (3)]));}
    break;

  case 27:
#line 87 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 28:
#line 88 "kim.y"
    {(yyval) = (long)setDeclaratorInit((A_ID*)(yyvsp[(1) - (3)]), (A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 29:
#line 92 "kim.y"
    { (yyval) = (long)makeNode(N_INIT_LIST_ONE,NIL,(A_NODE*)(yyvsp[(1) - (1)]),NIL);}
    break;

  case 30:
#line 93 "kim.y"
    {(yyval)=(yyvsp[(2) - (3)]);}
    break;

  case 31:
#line 97 "kim.y"
    {(yyval) =(long) makeNode(N_INIT_LIST,(A_NODE*) (yyvsp[(1) - (1)]), NIL, makeNode(N_INIT_LIST_NIL,NIL,NIL,NIL));}
    break;

  case 32:
#line 98 "kim.y"
    {(yyval) = (long) makeNodeList(N_INIT_LIST, (A_NODE*)(yyvsp[(1) - (3)]), (A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 33:
#line 102 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 34:
#line 103 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 35:
#line 104 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 36:
#line 108 "kim.y"
    {(yyval) = (long)setTypeStructOrEnumIdentifier((yyvsp[(1) - (2)]), (char *)(yyvsp[(2) - (2)]), ID_STRUCT);}
    break;

  case 37:
#line 109 "kim.y"
    {(yyval) = (long)current_id; current_level++;}
    break;

  case 38:
#line 110 "kim.y"
    {checkForwardReference(); (yyval)=(long)setTypeField((A_TYPE*)(yyvsp[(3) - (7)]),(A_ID*)(yyvsp[(6) - (7)])); current_level--;
        current_id = (A_ID*)(yyvsp[(5) - (7)]);}
    break;

  case 39:
#line 112 "kim.y"
    {(yyval) = (long)makeType((yyvsp[(1) - (1)]));}
    break;

  case 40:
#line 112 "kim.y"
    {(yyval)=(long) current_id; current_level++;}
    break;

  case 41:
#line 114 "kim.y"
    {checkForwardReference(); (yyval) = (long)setTypeField((A_TYPE*)(yyvsp[(2) - (6)]),(A_ID*)(yyvsp[(5) - (6)]));
        current_level--; current_id = (A_ID*)(yyvsp[(4) - (6)]);}
    break;

  case 42:
#line 116 "kim.y"
    {(yyval) = (long)getTypeOfStructOrEnumIdentifier((yyvsp[(1) - (2)]), (char*)(yyvsp[(2) - (2)]), ID_STRUCT);}
    break;

  case 43:
#line 120 "kim.y"
    {(yyval) = T_STRUCT;}
    break;

  case 44:
#line 121 "kim.y"
    {(yyval) = T_UNION;}
    break;

  case 45:
#line 125 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 46:
#line 126 "kim.y"
    {(yyval) = (long)linkDeclaratorList((A_ID*)(yyvsp[(1) - (2)]),(A_ID*) (yyvsp[(2) - (2)]));}
    break;

  case 47:
#line 131 "kim.y"
    {(yyval) = (long)setStructDeclaratorListSpecifier((A_ID*)(yyvsp[(2) - (3)]), (A_TYPE*)(yyvsp[(1) - (3)]));}
    break;

  case 48:
#line 135 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 49:
#line 136 "kim.y"
    {(yyval) = (long)linkDeclaratorList((A_ID*)(yyvsp[(1) - (3)]),(A_ID*)(yyvsp[(3) - (3)]));}
    break;

  case 50:
#line 140 "kim.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 51:
#line 144 "kim.y"
    {(yyval) = (long)setTypeStructOrEnumIdentifier(T_ENUM, (char *)(yyvsp[(2) - (2)]), ID_ENUM);}
    break;

  case 52:
#line 145 "kim.y"
    {(yyval) = (long)setTypeField((A_TYPE*)(yyvsp[(3) - (6)]), (A_ID*)(yyvsp[(5) - (6)]));}
    break;

  case 53:
#line 146 "kim.y"
    {(yyval) = (long)makeType(T_ENUM);}
    break;

  case 54:
#line 147 "kim.y"
    {(yyval) = (long)setTypeField((A_TYPE*)(yyvsp[(2) - (5)]), (A_ID*)(yyvsp[(4) - (5)]));}
    break;

  case 55:
#line 148 "kim.y"
    {(yyval) =(long) getTypeOfStructOrEnumIdentifier(T_ENUM, (char *)(yyvsp[(2) - (2)]), ID_ENUM);}
    break;

  case 56:
#line 152 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 57:
#line 153 "kim.y"
    {(yyval)=(long)linkDeclaratorList((A_ID*)(yyvsp[(1) - (3)]),(A_ID*) (yyvsp[(3) - (3)]));}
    break;

  case 58:
#line 157 "kim.y"
    {(yyval) = (long)setDeclaratorKind(makeIdentifier((char*)(yyvsp[(1) - (1)])), ID_ENUM_LITERAL);}
    break;

  case 59:
#line 158 "kim.y"
    {(yyval) = (long)setDeclaratorKind(makeIdentifier((char*)(yyvsp[(1) - (1)])), ID_ENUM_LITERAL);}
    break;

  case 60:
#line 159 "kim.y"
    {(yyval) = (long)setDeclaratorInit((A_ID*)(yyvsp[(2) - (4)]), (A_NODE*)(yyvsp[(4) - (4)]));}
    break;

  case 61:
#line 163 "kim.y"
    {(yyval) = (long)setDeclaratorElementType((A_ID*)(yyvsp[(2) - (2)]),(A_TYPE*)(yyvsp[(1) - (2)]));}
    break;

  case 62:
#line 164 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 63:
#line 168 "kim.y"
    {(yyval) = (long)makeType(T_POINTER);}
    break;

  case 64:
#line 169 "kim.y"
    {(yyval) = (long)setTypeElementType((A_TYPE*)(yyvsp[(2) - (2)]),makeType(T_POINTER));}
    break;

  case 65:
#line 173 "kim.y"
    {(yyval) =(long) makeIdentifier((char*)(yyvsp[(1) - (1)]));}
    break;

  case 66:
#line 174 "kim.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 67:
#line 176 "kim.y"
    {(yyval) = (long)setDeclaratorElementType((A_ID*)(yyvsp[(1) - (4)]), setTypeExpr(makeType(T_ARRAY), (A_NODE*)(yyvsp[(3) - (4)])));}
    break;

  case 68:
#line 177 "kim.y"
    {(yyval) = (long)current_id;  current_level++;}
    break;

  case 69:
#line 177 "kim.y"
    {checkForwardReference();  current_id = (A_ID*)(yyvsp[(3) - (5)]); current_level--; (yyval) = (long)setDeclaratorElementType((A_ID*)(yyvsp[(1) - (5)]), setTypeField(makeType(T_FUNC),(A_ID*) (yyvsp[(4) - (5)])));}
    break;

  case 70:
#line 181 "kim.y"
    {(yyval) = NIL;}
    break;

  case 71:
#line 182 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:
#line 186 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 73:
#line 188 "kim.y"
    {(yyval)=(long)linkDeclaratorList((A_ID*)(yyvsp[(1) - (3)]),setDeclaratorKind(makeDummyIdentifier(),ID_PARM));}
    break;

  case 74:
#line 192 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 75:
#line 193 "kim.y"
    {(yyval)=(long)linkDeclaratorList((A_ID*)(yyvsp[(1) - (3)]),(A_ID*)(yyvsp[(3) - (3)]));}
    break;

  case 76:
#line 197 "kim.y"
    {(yyval) =(long) setParameterDeclaratorSpecifier((A_ID*)(yyvsp[(2) - (2)]),(A_SPECIFIER*)(yyvsp[(1) - (2)]));}
    break;

  case 77:
#line 199 "kim.y"
    {(yyval) = (long)setParameterDeclaratorSpecifier
    (setDeclaratorType(makeDummyIdentifier(),(A_TYPE*)(yyvsp[(2) - (2)])),(A_SPECIFIER*)(yyvsp[(1) - (2)]));}
    break;

  case 78:
#line 204 "kim.y"
    {(yyval) = NIL;}
    break;

  case 79:
#line 205 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 80:
#line 209 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 81:
#line 210 "kim.y"
    {(yyval) = (long)makeType(T_POINTER);}
    break;

  case 82:
#line 211 "kim.y"
    {(yyval)=(long)setTypeElementType((A_TYPE*)(yyvsp[(2) - (2)]),makeType(T_POINTER));}
    break;

  case 83:
#line 215 "kim.y"
    {(yyval)=(yyvsp[(2) - (3)]);}
    break;

  case 84:
#line 216 "kim.y"
    {(yyval) =(long) setTypeExpr(makeType(T_ARRAY),(A_NODE *)(yyvsp[(2) - (3)]));}
    break;

  case 85:
#line 217 "kim.y"
    {(yyval) =(long)setTypeElementType((A_TYPE*)(yyvsp[(1) - (4)]),setTypeExpr(makeType(T_ARRAY),(A_NODE*)(yyvsp[(3) - (4)])));}
    break;

  case 86:
#line 218 "kim.y"
    {(yyval) =(long) setTypeExpr(makeType(T_FUNC),(A_NODE*)(yyvsp[(2) - (3)]));}
    break;

  case 87:
#line 219 "kim.y"
    {(yyval) =(long)setTypeElementType((A_TYPE*)(yyvsp[(1) - (4)]),setTypeExpr(makeType(T_FUNC),(A_NODE*)(yyvsp[(3) - (4)])));}
    break;

  case 88:
#line 223 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
    break;

  case 89:
#line 224 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 90:
#line 227 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_LIST, (A_NODE *)(yyvsp[(1) - (1)]), NIL, makeNode(N_STMT_LIST_NIL,NIL, NIL, NIL));}
    break;

  case 91:
#line 228 "kim.y"
    {(yyval) = (long)makeNodeList(N_STMT_LIST, (A_NODE*)(yyvsp[(1) - (2)]), (A_NODE*)(yyvsp[(2) - (2)]));}
    break;

  case 92:
#line 231 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 93:
#line 232 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 94:
#line 233 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 95:
#line 234 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 96:
#line 235 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 97:
#line 236 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 98:
#line 240 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_LABEL_CASE, (A_NODE*)(yyvsp[(2) - (4)]), NIL, (A_NODE*)(yyvsp[(4) - (4)]));}
    break;

  case 99:
#line 241 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_LABEL_DEFAULT, NIL, (A_NODE*)(yyvsp[(3) - (3)]), NIL);}
    break;

  case 100:
#line 245 "kim.y"
    {(yyval) = (long)current_id; current_level++;}
    break;

  case 101:
#line 245 "kim.y"
    {checkForwardReference(); (yyval) = (long)makeNode(N_STMT_COMPOUND,(A_NODE*) (yyvsp[(3) - (5)]), NIL, (A_NODE*)(yyvsp[(4) - (5)])); current_id = (A_ID*)(yyvsp[(2) - (5)]); current_level--;}
    break;

  case 102:
#line 249 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_EMPTY,NIL,NIL,NIL);}
    break;

  case 103:
#line 250 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_EXPRESSION, NIL, (A_NODE*)(yyvsp[(1) - (2)]), NIL);}
    break;

  case 104:
#line 254 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_IF, (A_NODE*)(yyvsp[(3) - (6)]), NIL,(A_NODE*) (yyvsp[(5) - (6)]));}
    break;

  case 105:
#line 255 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_IF_ELSE,(A_NODE*) (yyvsp[(3) - (7)]), (A_NODE*)(yyvsp[(5) - (7)]), (A_NODE*)(yyvsp[(7) - (7)]));}
    break;

  case 106:
#line 256 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_SWITCH, (A_NODE*)(yyvsp[(3) - (5)]), NIL, (A_NODE*)(yyvsp[(5) - (5)]));}
    break;

  case 107:
#line 260 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_WHILE, (A_NODE*)(yyvsp[(3) - (5)]), NIL, (A_NODE*)(yyvsp[(5) - (5)]));}
    break;

  case 108:
#line 261 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_DO, (A_NODE*)(yyvsp[(2) - (7)]), NIL, (A_NODE*)(yyvsp[(5) - (7)]));}
    break;

  case 109:
#line 262 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_FOR, (A_NODE*)(yyvsp[(3) - (5)]), NIL, (A_NODE*)(yyvsp[(5) - (5)]));}
    break;

  case 110:
#line 266 "kim.y"
    {(yyval) = (long)makeNode(N_FOR_EXP, (A_NODE*)(yyvsp[(1) - (5)]),(A_NODE*) (yyvsp[(3) - (5)]), (A_NODE*)(yyvsp[(5) - (5)]));}
    break;

  case 111:
#line 269 "kim.y"
    {(yyval) = NIL;}
    break;

  case 112:
#line 270 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 113:
#line 274 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_RETURN, NIL,(A_NODE*) (yyvsp[(2) - (3)]), NIL);}
    break;

  case 114:
#line 275 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_CONTINUE, NIL, NIL, NIL);}
    break;

  case 115:
#line 276 "kim.y"
    {(yyval) = (long)makeNode(N_STMT_BREAK, NIL, NIL, NIL);}
    break;

  case 116:
#line 280 "kim.y"
    {(yyval)=(long)makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL);}
    break;

  case 117:
#line 281 "kim.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 118:
#line 285 "kim.y"
    {(yyval) = (long)makeNode(N_ARG_LIST,(A_NODE*)(yyvsp[(1) - (1)]),NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL));}
    break;

  case 119:
#line 286 "kim.y"
    {(yyval) = (long)makeNodeList(N_ARG_LIST,(A_NODE*)(yyvsp[(1) - (3)]),(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 120:
#line 290 "kim.y"
    {(yyval) = NIL;}
    break;

  case 121:
#line 291 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 122:
#line 295 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 123:
#line 299 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 124:
#line 303 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 125:
#line 307 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 126:
#line 308 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_ASSIGN,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 127:
#line 312 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 128:
#line 316 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 129:
#line 317 "kim.y"
    {(yyval)=(long)makeNode(N_EXP_OR,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 130:
#line 321 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 131:
#line 322 "kim.y"
    {(yyval)=(long)makeNode(N_EXP_AND,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 132:
#line 326 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 133:
#line 330 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 134:
#line 334 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 135:
#line 338 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 136:
#line 340 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_EQL,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 137:
#line 342 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_NEQ,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 138:
#line 346 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 139:
#line 347 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_LSS,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 140:
#line 349 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_GTR,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 141:
#line 350 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_LEQ,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 142:
#line 351 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_GEQ,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 143:
#line 355 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 144:
#line 359 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 145:
#line 360 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_ADD,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 146:
#line 361 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_SUB,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 147:
#line 365 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 148:
#line 367 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_MUL,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 149:
#line 369 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_DIV,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 150:
#line 371 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_MOD,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 151:
#line 375 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 152:
#line 376 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_CAST, (A_NODE*)(yyvsp[(2) - (4)]), NIL,(A_NODE*) (yyvsp[(4) - (4)]));}
    break;

  case 153:
#line 380 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 154:
#line 381 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_PRE_INC,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 155:
#line 382 "kim.y"
    {(yyval)=(long)makeNode(N_EXP_PRE_DEC,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 156:
#line 383 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_AMP,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 157:
#line 384 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_STAR,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 158:
#line 385 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_NOT,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 159:
#line 386 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_MINUS,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 160:
#line 387 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_PLUS,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 161:
#line 388 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_SIZE_EXP,NIL,(A_NODE*)(yyvsp[(2) - (2)]),NIL);}
    break;

  case 162:
#line 389 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_SIZE_TYPE,NIL,(A_NODE*)(yyvsp[(3) - (4)]),NIL);}
    break;

  case 163:
#line 393 "kim.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 164:
#line 394 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_ARRAY,(A_NODE*)(yyvsp[(1) - (4)]),NIL,(A_NODE*)(yyvsp[(3) - (4)]));}
    break;

  case 165:
#line 396 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_FUNCTION_CALL,(A_NODE*)(yyvsp[(1) - (4)]),NIL,(A_NODE*)(yyvsp[(3) - (4)]));}
    break;

  case 166:
#line 397 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_STRUCT,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 167:
#line 398 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_ARROW,(A_NODE*)(yyvsp[(1) - (3)]),NIL,(A_NODE*)(yyvsp[(3) - (3)]));}
    break;

  case 168:
#line 399 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_POST_INC,NIL,(A_NODE*)(yyvsp[(1) - (2)]),NIL);}
    break;

  case 169:
#line 400 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_POST_DEC,NIL,(A_NODE*)(yyvsp[(1) - (2)]),NIL);}
    break;

  case 170:
#line 405 "kim.y"
    {(yyval)=(long)makeNode(N_EXP_IDENT,NIL,(A_NODE*)getIdentifierDeclared((char*)(yyvsp[(1) - (1)])),NIL);}
    break;

  case 171:
#line 406 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_INT_CONST,NIL,(A_NODE*)(yyvsp[(1) - (1)]),NIL);}
    break;

  case 172:
#line 407 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_FLOAT_CONST,NIL,(A_NODE*)(yyvsp[(1) - (1)]),NIL);}
    break;

  case 173:
#line 408 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_CHAR_CONST,NIL,(A_NODE*)(yyvsp[(1) - (1)]),NIL);}
    break;

  case 174:
#line 409 "kim.y"
    {(yyval) = (long)makeNode(N_EXP_STRING_LITERAL,NIL,(A_NODE*)(yyvsp[(1) - (1)]),NIL);}
    break;

  case 175:
#line 410 "kim.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 176:
#line 414 "kim.y"
    {(yyval) =(long)setTypeNameSpecifier((A_TYPE*)(yyvsp[(2) - (2)]),(A_SPECIFIER*)(yyvsp[(1) - (2)]));}
    break;


/* Line 1267 of yacc.c.  */
#line 2651 "y.tab.c"
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


#line 418 "kim.y"

extern char *yytext;
    
int yyerror(const char *s) {
    //syntax_err++;
    printf("line %d: %s near %s \n", line_no, s, yytext);
    exit(1);
}
    
int yywrap(){
    return(1);
    }
   

