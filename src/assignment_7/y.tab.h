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
     AUTO_SYM = 258,
     BREAK_SYM = 259,
     CASE_SYM = 260,
     CONTINUE_SYM = 261,
     DEFAULT_SYM = 262,
     DO_SYM = 263,
     ELSE_SYM = 264,
     ENUM_SYM = 265,
     FOR_SYM = 266,
     IF_SYM = 267,
     RETURN_SYM = 268,
     SIZEOF_SYM = 269,
     STATIC_SYM = 270,
     STRUCT_SYM = 271,
     SWITCH_SYM = 272,
     TYPEDEF_SYM = 273,
     UNION_SYM = 274,
     WHILE_SYM = 275,
     PLUSPLUS = 276,
     MINUSMINUS = 277,
     ARROW = 278,
     LSS = 279,
     GTR = 280,
     LEQ = 281,
     GEQ = 282,
     EQL = 283,
     NEQ = 284,
     AMPAMP = 285,
     BARBAR = 286,
     DOTDOTDOT = 287,
     LP = 288,
     RP = 289,
     LB = 290,
     RB = 291,
     LR = 292,
     RR = 293,
     COLON = 294,
     PERIOD = 295,
     COMMA = 296,
     EXCL = 297,
     STAR = 298,
     SLASH = 299,
     PERCENT = 300,
     AMP = 301,
     SEMICOLON = 302,
     PLUS = 303,
     MINUS = 304,
     ASSIGN = 305,
     INTEGER_CONSTANT = 306,
     FLOAT_CONSTANT = 307,
     STRING_LITERAL = 308,
     CHARACTER_CONSTANT = 309,
     ESCAPE_CONSTANT = 310,
     IDENTIFIER = 311,
     TYPE_IDENTIFIER = 312
   };
#endif
/* Tokens.  */
#define AUTO_SYM 258
#define BREAK_SYM 259
#define CASE_SYM 260
#define CONTINUE_SYM 261
#define DEFAULT_SYM 262
#define DO_SYM 263
#define ELSE_SYM 264
#define ENUM_SYM 265
#define FOR_SYM 266
#define IF_SYM 267
#define RETURN_SYM 268
#define SIZEOF_SYM 269
#define STATIC_SYM 270
#define STRUCT_SYM 271
#define SWITCH_SYM 272
#define TYPEDEF_SYM 273
#define UNION_SYM 274
#define WHILE_SYM 275
#define PLUSPLUS 276
#define MINUSMINUS 277
#define ARROW 278
#define LSS 279
#define GTR 280
#define LEQ 281
#define GEQ 282
#define EQL 283
#define NEQ 284
#define AMPAMP 285
#define BARBAR 286
#define DOTDOTDOT 287
#define LP 288
#define RP 289
#define LB 290
#define RB 291
#define LR 292
#define RR 293
#define COLON 294
#define PERIOD 295
#define COMMA 296
#define EXCL 297
#define STAR 298
#define SLASH 299
#define PERCENT 300
#define AMP 301
#define SEMICOLON 302
#define PLUS 303
#define MINUS 304
#define ASSIGN 305
#define INTEGER_CONSTANT 306
#define FLOAT_CONSTANT 307
#define STRING_LITERAL 308
#define CHARACTER_CONSTANT 309
#define ESCAPE_CONSTANT 310
#define IDENTIFIER 311
#define TYPE_IDENTIFIER 312




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

