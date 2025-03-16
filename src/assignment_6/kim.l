digit [0-9]
letter [a-zA-Z_]
delim [ \t]
line [\n]
ws {delim}+

%{
#define YYSTYPE_IS_DECLARED 1
typedef long YYSTYPE;
#include <stdio.h>
#include "type.h"
#include "y.tab.h"
#include <string.h>

extern YYSTYPE yylval;
extern int line_no;
extern A_ID *current_id;
int checkIdentifier(char *);
char *makeString(char *);
%}

%%
{ws}     {}
{line}   {line_no++;}
auto      { return(AUTO_SYM); }
break     { return(BREAK_SYM);}
case      { return(CASE_SYM); }
continue  { return(CONTINUE_SYM); }
default   { return(DEFAULT_SYM); }
do        { return(DO_SYM); }
else      { return(ELSE_SYM); }
enum      { return(ENUM_SYM); }
for       { return(FOR_SYM); }
if        { return(IF_SYM); }
return    { return(RETURN_SYM); }
sizeof    { return(SIZEOF_SYM); }
static    { return(STATIC_SYM); }
struct    { return(STRUCT_SYM); }
switch    { return(SWITCH_SYM); }
typedef  { return(TYPEDEF_SYM); }
union     { return(UNION_SYM); }
while     { return(WHILE_SYM); }
"++"     { return(PLUSPLUS); }
"--"    { return(MINUSMINUS); }
"->"    { return(ARROW); }
"<"     { return(LSS); }
">"     { return(GTR); }
"<="    { return(LEQ); }
">="    { return(GEQ); }
"=="    { return(EQL); }
"!="    { return(NEQ); }
"&&"    { return(AMPAMP); }
"||"    { return(BARBAR); }
"..."    { return(DOTDOTDOT); }
"("    { return(LP); }
")"    { return(RP); }
"["     { return(LB); }
"]"     { return(RB); }
"{"     { return(LR); }
"}"    { return(RR); }
":"    { return(COLON); }
"."    { return(PERIOD); }
","    { return(COMMA); }
"!"    { return(EXCL); }
"*"    { return(STAR); }
"/"    { return(SLASH); }
"%"    { return(PERCENT); }
"&"    { return(AMP); }
";"    { return(SEMICOLON); }
"+"    { return(PLUS); }
"-"    { return(MINUS);}
"="    { return(ASSIGN);}
{digit}+    {yylval = atoi(yytext); return(INTEGER_CONSTANT);} // 정수값 저장
{digit}+\.{digit}+  {yylval = (unsigned long) makeString(yytext); return(FLOAT_CONSTANT);} // 토큰 스트링의 주소 저장
{letter}({letter}|{digit})*     {return checkIdentifier(yytext);} // 일반 / 타입 명칭 구분
\"([^"\n]|\\["\n])*\"     {yylval = (unsigned long) makeString(yytext); return(STRING_LITERAL);} // 토큰 스트링 주소 저장
\/\*([^*]|\*+[^*/])*\*+\/ {} // 여러줄 주석
\/\/[^\n]* {} // 한 줄 주석
\\(n|t|r|\\|\"|\') {return (ESCAPE_CONSTANT);} // 탈출 문자
\'([^'\n]|\\'|\\n)\' {yylval = *(yytext+1); return(CHARACTER_CONSTANT);} // 문자 값 저장
%%
    char *makeString(char *s){
        char *t;
        t=malloc(strlen(s)+1);
        strcpy(t,s);
        return t;
    }
    
    int checkIdentifier(char *s) {
        A_ID *_id;
        _id = current_id;
        while(_id){
            if(strcmp(_id->name, s)==0){
                break;
            }
            _id=_id->prev;
        }
        if(_id==0){ // 새 명칭
            yylval = (unsigned long)makeString(s);
            return IDENTIFIER;
        }
        else if (_id->kind == ID_TYPE){ // 타입 명칭
            yylval = (unsigned long)_id->type; // 타입 테이블 주소 저장
            return TYPE_IDENTIFIER;
        }
        else{ // 기존 명칭
            yylval = (unsigned long)_id->name; // 토큰 스트링의 주소 저장
            return IDENTIFIER;
        }
    }
    

    
