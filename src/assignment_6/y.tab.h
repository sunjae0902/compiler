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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

