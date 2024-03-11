#include <stdio.h>

typedef enum
{
    INT,
    FLT
} kind;
enum
{
    NUMBER,
    PLUS,
    STAR,
    LP,
    RP,
    END
} token;

typedef struct
{
    kind t;
    union
    {
        int i;
        float f;
    } val;
} number;

number expression();
number term();
number factor();
void get_token();
void error(int);
void warning(int);

number num;
char c;
int isFirst = 1;
int hasError = 0;

int main()
{
    number result;
    printf("수식 입력: ");
    get_token();
    
    if (token != NUMBER)
        error(1);
    
    result = expression();
    
    if (token != END)
        error(3);
    else if(!hasError)
    {
        if (result.t == INT)
        {
            printf("%d\n\n", result.val.i);
        }
        else if (result.t == FLT)
        {
            printf("%f\n\n", result.val.f);
        }
        else
        {
            error(4);
        }
    }
    return 0;
}

number expression()
{
    number result;
    result = term();
    while (token == PLUS)
    {
        get_token();
        number tmp = term();
        if (result.t == INT && tmp.t == INT)
        {
            result.val.i += tmp.val.i;
        }
        else if (result.t == FLT && tmp.t == FLT)
        {
            result.val.f += tmp.val.f;
        }
        else if (result.t == FLT && tmp.t == INT)
        {
            result.val.f += tmp.val.i;
        }
        else if (result.t == INT && tmp.t == FLT)
        {
            result.val.f = result.val.i + tmp.val.f;
            result.t = FLT;
        }
        else
        {
            error(4);
        }
    }
    return result;
}

number term()
{
    number result;
    result = factor();
    
    while (token == STAR)
    {
        get_token();
        number tmp = factor();
        if (result.t == INT && tmp.t == INT)
        {
            result.val.i *= tmp.val.i;
        }
        else if (result.t == FLT && tmp.t == FLT)
        {
            result.val.f *= tmp.val.f;
        }
        else if (result.t == FLT && tmp.t == INT)
        {
            result.val.f *= tmp.val.i;
        }
        else if (result.t == INT && tmp.t == FLT)
        {
            result.val.f = result.val.i * tmp.val.f;
            result.t = FLT;
        }
        else
        {
            error(4);
        }
    }
    return result;
}

number factor()
{
    number result;
    
    if (token == NUMBER)
    {
        result = num;
        get_token();
    }
    else if (token == LP)
    {
        get_token();
        result = expression();
        if (token == RP)
            get_token();
        else
            error(2);
    }
    else
        error(1);
    return result;
}

void get_token() { // 수식을 읽으며 다음 토큰을 c에 저장한다.

    while (isFirst) {
        c = getchar();
        isFirst = 0;
    }

    if ((c >= '0' && c <= '9')) {
        int int_num = 0;
        float float_num = 0.0;
        
        token = NUMBER;
        num.t = INT;
        do {
            int_num = int_num * 10 + (c - '0');
            c = getchar();
        } while (c >= '0' && c <= '9');

        num.val.i = int_num;

        if (c == '.') {
            int digit = 0;
            num.t = FLT;
            num.val.f = num.val.i;
            float decimal = 0.1;

            do {
                c = getchar();
                if (c >= '0' && c <= '9') {
                    float_num += (c - '0') * decimal;
                    decimal *= 0.1;
                    digit++;
                }
            } while (c >= '0' && c <= '9');
            
            num.val.f += float_num;

            if (c == '.') {
                error(5);
            }
            if(digit > 6) warning(2);
        }
        return;
    }

    if (c == '+') {
        token = PLUS;
    } else if (c == '*') {
        token = STAR;
    } else if (c == '(') {
        token = LP;
    } else if (c == ')') {
        token = RP;
    } else if (c == '\n') {
        token = END;
        return;
    }
    c = getchar();
}


void error(int code) // 가능한 오류 메시지를 출력한다.
{
    switch (code)
    {
        case 1:
            printf("error: Invalid expression\n");
            break;
        case 2:
            printf("error: ')' is missing\n");
            break;
        case 3:
            printf("error: Unexpected end of line\n");
            break;
        case 4:
            printf("error: Type is undefined\n");
            break;
        case 5:
            printf("error: Unexpected '.'\n");
            break;
        default:
            break;
    }
	hasError = 1;
	return;
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


