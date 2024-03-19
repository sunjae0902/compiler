
/* 수식의 값 계산
 - 스택 구현.. (top,  status number)
 - value 배열은 struct의 배열 (type, value) == number의 type을 struct
 - 실수도 되게
 - shift 연산 시 상태번호만 푸시하고 number 값은 전역변수 num에 저장한다
 - 연산자 토큰을 읽으면 해당하는 토큰을 리턴한다.
 - reduce 연산 시 수식을 계산한다. (번호에 따라 switch문으로 처리)
 - 최종 계산 값은 스택의 바닥+1 자리에 저장됨. -> 출력
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define NUMBER 256
#define PLUS 257
#define STAR 258
#define LP 259
#define RP 260
#define END 261
#define EXPRESSION 0
#define TERM 1
#define FACTOR 2
#define ACC 999

typedef enum {INT, FLT} kind;
typedef struct{
    kind type;
    union{
        int intValue;
        float floatValue;
    } value;
} Number;


int action[12][6] = {
    {5,0,0,4,0,0},{0,6,0,0,0,ACC}, {0,-2,7,0,-2,-2},
    {0,-4,-4,0,-4,-4},{5,0,0,4,0,0},{0,-6,-6,0,-6,-6},
    {5,0,0,4,0,0},{5,0,0,4,0,0},{0,6,0,0,11,0},
    {0,-1,7,0,-1,-1},{0,-3,-3,0,-3,-3},{0,-5,-5,0,-5,-5}};
int go_to[12][3] = {
    {1,2,3},{0,0,0 },{0,0,0 },{0,0,0 },{8,2,3},{0,0,0 },
    {0,9,3},{0,0,10},{0,0,0},{0,0,0},{0,0,0},{0,}
};
int prod_left[7] = {0,EXPRESSION, EXPRESSION, TERM, TERM, FACTOR, FACTOR}; //   0 0 1 1 2 2
int prod_length[7] = {0,3,1,3,1,3,1};
int stack[1000];

Number result[1000];
Number yyval;
char yytext[32];
int top = 1, sym, isFirst = 1, parenCnt = 0;

int yylex(void); // get token
void yyparse(void); // run
void push(int);
void shift(int);
void reduce(int);
int yyerror(int);
void warning(int);

// additional function
Number calculateByDataType(Number, Number, int);


int main(int argc, const char * argv[]) {
    printf("수식 입력: ");
    yyparse();
    return 0;
}

void yyparse(){
    int i = 0;
    stack[++top] = 0;
    sym = yylex();
    if(sym == LP) parenCnt++;
    if(sym == RP) parenCnt--;
    do{
        i = action[stack[top]][sym-256];
        if(i == ACC){
            if(result[top].type == INT){
                printf("%d",result[top].value.intValue);
            }
            else{ printf("%f",result[top].value.floatValue);
            }
        }
        else if (i > 0) shift(i);
        else if (i < 0) reduce(-i);
        else if (parenCnt < 0) yyerror(1);
        else if (parenCnt > 0) yyerror(2);
        else yyerror(6);
    }while(i != ACC);
    
}

void push(int i){
    stack[++top] = i;
}

void shift(int i){
    push(i);
    result[top] = yyval;
    sym = yylex();
    if(sym == LP) parenCnt++;
    if(sym == RP) parenCnt--;
}

void reduce(int i){
    int old_top;
    top -= prod_length[i]; // 길이만큼 삭제
    old_top = top; // 삭제 후 상태번호
 
    push(go_to[stack[old_top]][prod_left[i]]);

    switch(i){
        case 1: result[top] = calculateByDataType(result[old_top+1], result[old_top+3], PLUS);
            break;
        case 2: result[top] = result[old_top+1];
            break;
        case 3: result[top] = calculateByDataType(result[old_top+1], result[old_top+3], STAR);
            break;
        case 4: result[top] = result[old_top+1];
            break;
        case 5: result[top] = result[old_top+2];
            break;
        case 6: result[top] = result[old_top+1];
            break;
        default:
            yyerror(6);// parsing table error
            break;
    }
}

Number calculateByDataType(Number r1, Number r2, int symbol){
    Number result;
    if(r1.type == INT && r2.type == INT){
        result.type = INT;
        if(symbol == PLUS) {
            result.value.intValue = r1.value.intValue + r2.value.intValue;
        }
        else {
            result.value.intValue = r1.value.intValue * r2.value.intValue;
        }
    }else if(r1.type == INT && r2.type == FLT){
        result.type = FLT;
        if(symbol == PLUS){
            result.value.floatValue = r1.value.intValue + r2.value.floatValue;
        }
        else{
            result.value.floatValue = r1.value.intValue * r2.value.floatValue;
        }
    }else if(r1.type == FLT && r2.type == INT){
        result.type = FLT;
        if(symbol == PLUS){
            result.value.floatValue = r1.value.floatValue + r2.value.intValue;
        }
        else{
            result.value.floatValue = r1.value.floatValue * r2.value.intValue;
        }
    } else{
        result.type = FLT;
        if(symbol == PLUS){
            result.value.floatValue = r1.value.floatValue + r2.value.floatValue;
        }
        else{
            result.value.floatValue = r1.value.floatValue * r2.value.floatValue;
        }
    }
    return result;
}

int yylex(){ // 심볼 상수 매크로 리턴
    static char ch = ' ';
    
    int i = 0;
    while (isFirst && (ch == ' ' || ch == '\t' || ch == '\n')) {
        ch = getchar(); 
        isFirst = 0;
        }

    if(isdigit(ch)){
        yyval.type = INT;
        do{
            yytext[i++] = ch;
            ch = getchar();
        }while(isdigit(ch));
        
        if(ch == '.'){
            yyval.type = FLT;
            yytext[i++] = '.';
            int digit = 0;
            
            do {
                ch = getchar();
                if (isdigit(ch)) {
                    yytext[i++] = ch;
                    digit++;
                }
            } while (isdigit(ch));
            if (ch == '.')  yyerror(5); //소수점 중복 에러
            if(digit > 6) warning(2);
        }
        yytext[i] = 0;
        
        if(yyval.type == INT){
            yyval.value.intValue = atoi(yytext);
        }
        else{
            yyval.value.floatValue = atof(yytext);
        }
        return NUMBER;
    }
    else{
        switch(ch){
            case '+': ch = getchar(); return PLUS;
            case '*': ch = getchar(); return STAR;
            case '(': ch = getchar(); return LP;
            case ')': ch = getchar(); return RP;
            case '\n': return END;
            default: return yyerror(3);
        }
    }
}


int yyerror(int code) // 가능한 오류 메시지를 출력한다.
{
    switch (code)
    {
        case 1:
            printf("error: Invalid Expression. Remove ')' or insert '('");
            break;
        case 2:
            printf("error: ')' is missing" );
            break;
        case 3:
            printf("error: Unexpected end of line\n");
            break;
        case 5:
            printf("error: Unexpected '.'\n");
            break;
        case 6:
            printf("error: The parsing table error\n");
        default:
            break;
    }
    exit(1);
}

void warning(int code){ // 가능한 경고 메시지를 출력한다.
   switch (code)
   {
       case 1: // int -> double
           printf("warning: implicit conversion from 'int' to 'double'\n");
           break;
       case 2: // double -> float
           printf("warning: conversion from 'double' to 'float' may lose precision\n");
       default:
           break;
   }

}


