#include "type.h"
#include <stdio.h>
#include <string.h>

float atof();
void semantic_analysis(A_NODE *);
void set_literal_address(A_NODE *);
int put_literal(A_LITERAL, int);
void sem_program(A_NODE *);
A_TYPE *sem_expression(A_NODE *);
int sem_statement(A_NODE *, int, A_TYPE *, BOOLEAN, BOOLEAN, BOOLEAN);
int sem_statement_list(A_NODE *, int, A_TYPE *, BOOLEAN, BOOLEAN, BOOLEAN);
void sem_for_expression(A_NODE *);
int sem_A_TYPE(A_TYPE *) ;
int sem_declaration_list(A_ID *, int);
int sem_declaration(A_ID *, int);
void sem_arg_expr_list(A_NODE *, A_ID *);
A_ID *getStructFieldIdentifier(A_TYPE *, char *);
A_ID *getPointerFieldIdentifier(A_TYPE *, char *);
A_NODE *convertScalarToInteger(A_NODE *);
A_NODE *convertUsualAssignmentConversion(A_TYPE *, A_NODE *);
A_NODE *convertUsualUnaryConversion(A_NODE *);
A_TYPE *convertUsualBinaryConversion(A_NODE *);
A_NODE *convertCastingConversion(A_NODE *,A_TYPE *);
BOOLEAN isAllowableAssignmentConversion(A_TYPE *, A_TYPE *, A_NODE *);
BOOLEAN isAllowableCastingConversion(A_TYPE *, A_TYPE *);
BOOLEAN isModifiableLvalue(A_NODE *);
BOOLEAN isConstantZeroExp(A_NODE *);
BOOLEAN isSameParameterType(A_ID *, A_ID *);
BOOLEAN _isPointerOrArrayType(A_TYPE *); // using only in the file
BOOLEAN isNotSameType(A_TYPE *, A_TYPE *);
BOOLEAN isCompatibleType(A_TYPE *, A_TYPE *);
BOOLEAN isCompatiblePointerType(A_TYPE *, A_TYPE *);
BOOLEAN isIntType(A_TYPE *);
BOOLEAN isFloatType(A_TYPE *);
BOOLEAN isArithmeticType(A_TYPE *);
BOOLEAN isAnyIntegerType(A_TYPE *);
BOOLEAN isIntegralType(A_TYPE *);
BOOLEAN isStructOrUnionType(A_TYPE *);
BOOLEAN isFunctionType(A_TYPE *);
BOOLEAN isScalarType(A_TYPE *);
BOOLEAN isPointerType(A_TYPE *);
BOOLEAN isArrayType(A_TYPE *);
BOOLEAN isStringType(A_TYPE *);
BOOLEAN isVoidType(A_TYPE *);
A_LITERAL checkTypeAndConvertLiteral(A_LITERAL, A_TYPE*, int);
A_LITERAL getTypeAndValueOfExpression(A_NODE *);
A_TYPE *setTypeElementType(A_TYPE *, A_TYPE *);
A_TYPE *makeType(T_KIND);
void setTypeSize(A_TYPE *, int);
void semantic_warning(int, int);
void semantic_error();
A_NODE *makeNode(NODE_NAME, A_NODE *, A_NODE *, A_NODE *);
extern A_TYPE *int_type, *float_type, *void_type, *string_type, *char_type;

int global_address = 12;
int semantic_err = 0;

#define LIT_MAX 100

A_LITERAL literal_table[LIT_MAX];

int literal_no=0;
int literal_size=0;

void semantic_analysis(A_NODE *node){
    sem_program(node);
    set_literal_address(node);
}

void set_literal_address(A_NODE *node){
    int i;
    for (i = 1;i <= literal_no; i++)
        literal_table[i].addr += node->value;
    node->value += literal_size;
}

void sem_program(A_NODE *node){
    int i;
    switch(node->name) {
        case N_PROGRAM:
            i = sem_declaration_list(node->clink, 12); // 심볼 테이블 목록을 모두 분석하고 각 지역 변수의 주소 설정 및 크기 계산 후 리턴
            node->value = global_address;
            break;
        default:
            semantic_error(90,node->line);
            break;
    }
}

int put_literal(A_LITERAL lit, int ll){
    float ff;
    if(literal_no >= LIT_MAX)
        semantic_error(93,ll);
    else
        literal_no++;
    
    literal_table[literal_no] = lit;
    literal_table[literal_no].addr = literal_size;
    if(lit.type->kind == T_ENUM)
        literal_size=4;
    else if(isStringType(lit.type))
        literal_size += strlen(lit.value.s)+1;
    if(literal_size % 4)
        literal_size = literal_size/4*4+4;
    return literal_no;
}


A_TYPE *sem_expression(A_NODE *node){ // 수식의 타입 결정 후 리턴
    A_TYPE *result=NIL,*t,*t1, *t2;
    A_ID *id;
    A_LITERAL lit;
    int i;
    BOOLEAN lvalue=FALSE;
    switch(node->name) {
        case N_EXP_IDENT: // 기본수식 명칭인 경우 수식의 타입은 Identifier의 타입과 같다
            id = node->clink;
            switch (id->kind) {
                case ID_VAR:
                case ID_PARM:
                    result = id->type;
                    if(!isArrayType(result)) // 배열이 아닌 경우만 lvalue
                        lvalue=TRUE;
                    break;
                case ID_FUNC:
                    result = id->type;
                    break;
                case ID_ENUM_LITERAL:
                    result = int_type;
                    break;
                default:
                    semantic_error(38, node->line, id->name);
                    break;
            }
            break;
        case N_EXP_INT_CONST:
            result = int_type;
            break;
        case N_EXP_FLOAT_CONST:
            lit.type = float_type;
            lit.value.f = atof(node->clink);
            node->clink = (A_NODE *)put_literal(lit, node->line);
            result = float_type;
            break;
        case N_EXP_CHAR_CONST:
            result = char_type;
            break;
        case N_EXP_STRING_LITERAL:
            lit.type = string_type;
            lit.value.s = node->clink;
            node->clink =  (A_NODE *)put_literal(lit, node->line);
            result = string_type;
            break;
        case N_EXP_ARRAY: // 후위수식
            t1 = sem_expression(node->llink);
            t2 = sem_expression(node->rlink);
            
            t=convertUsualBinaryConversion(node);
            t1 = node->llink->type;
            t2 = node->rlink->type;
            if(_isPointerOrArrayType(t1))
                result = t1->element_type;
            else
                semantic_error(32,node->line);
            if(!isIntegralType(t2))
                semantic_error(29, node->line);
            if(!isArrayType(result))
                lvalue = TRUE;
            break;
        case N_EXP_STRUCT:
            t = sem_expression(node->llink);
            id = getStructFieldIdentifier(t, node->rlink);
            if(id){
                result = id->type;
                if(node->llink->value && !isArrayType(result))
                    lvalue = TRUE;
            }
            else
                semantic_error(37, node->line);
            node->rlink = id;
            break;
        case N_EXP_ARROW:
                    t=sem_expression(node->llink);
                    id=getPointerFieldIdentifier(t,node->rlink);
                    if (id) {
                        result=id->type;
                        if (!isArrayType(result))
                            lvalue = TRUE;
                    }
                    else
                        semantic_error(37,node->line);
                    node->rlink=id;
                    break;
        case N_EXP_FUNCTION_CALL:
            t = sem_expression(node->llink);
            node->llink = convertUsualUnaryConversion(node->llink);
            t=node->llink->type;
            if(isPointerType(t) && isFunctionType(t->element_type))
            {
                sem_arg_expr_list(node->rlink, t->element_type->field);
                result=t->element_type->element_type;
            }
            else
                semantic_error(21, node->line);
            break;
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
            result = sem_expression(node->clink);
            if(!isScalarType(result))
                semantic_error(27,node->line);
            if(!isModifiableLvalue(node->clink))
                semantic_error(60,node->line);
            break;
        case N_EXP_CAST:
            result = node->llink->type;
            i = sem_A_TYPE(result);
            t=sem_expression(node->rlink);
            if(!isAllowableCastingConversion(result, t))
                semantic_error(58, node->line);
            break;
        case N_EXP_SIZE_TYPE:
            t = node->clink;
            i = sem_A_TYPE(t);
            if(isArrayType(t) && t->size == 0 || isFunctionType(t) || isVoidType(t))
                semantic_error(39,node->line);
            else
                node->clink =(A_NODE *) i;
            result=int_type;
            break;
        case N_EXP_SIZE_EXP:
            t = sem_expression(node->clink);
            if((node->clink->name != N_EXP_IDENT || ((A_ID*)node->clink->clink)->kind != ID_PARM) && (isArrayType(t) && t->size == 0 || isFunctionType(t)))
                semantic_error(39, node->line);
            else
                node->clink = (A_NODE *)t->size;
            result=int_type;
            break;
        case N_EXP_PLUS:
        case N_EXP_MINUS:
            t = sem_expression(node->clink);
            if (isArithmeticType(t)) {
                node->clink =  convertUsualUnaryConversion(node->clink); result=node->clink->type;}
            else
                semantic_error(13,node->line);
            break;
        case N_EXP_NOT:
            t = sem_expression(node->clink);
            if(isScalarType){
                node->clink = convertUsualUnaryConversion(node->clink);
                result = int_type;}
            else
                semantic_error(27, node->line);
            break;
        case N_EXP_AMP:
            t = sem_expression(node->clink);
            if(node->clink->value == TRUE || isFunctionType(t)){
                result = setTypeElementType(makeType(T_POINTER),t);
                result->size=4;}
            else
                semantic_error(60, node->line);
            break;
        case N_EXP_STAR:
            t = sem_expression(node->clink);
            node->clink = convertUsualUnaryConversion(node->clink);
            if(isPointerType(t)){
                result = t->element_type;
                if(isStructOrUnionType(result) || isScalarType(result))
                    lvalue = TRUE;
            }
            else
                semantic_error(31,node->line);
            break;
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
            result = sem_expression(node->clink);
            if(!isScalarType(result)) semantic_error(27,node->line);
            if(!isModifiableLvalue(node->clink))
                semantic_error(60,node->line);
            break;
        case N_EXP_MUL:
        case N_EXP_DIV:
            t1= sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isArithmeticType(t1) && isArithmeticType(t2))
                result = convertUsualBinaryConversion(node);
            else
                semantic_error(28,node->line);
            break;
        case N_EXP_MOD:
            t1= sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isIntegralType(t1) && isIntegralType(t2))
                result = convertUsualBinaryConversion(node);
            else
                semantic_error(29,node->line);
            result = int_type;
            break;
            
        case N_EXP_ADD:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) result=convertUsualBinaryConversion(node);
            else if (isPointerType(t1) && isIntegralType(t2))
                result = t1;
            else if (isIntegralType(t1) && isPointerType(t2))
                result=t2;
            else
                semantic_error(24,node-> line);
            break;
        case N_EXP_SUB:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) result=convertUsualBinaryConversion(node);
            else if (isPointerType(t1) && isIntegralType(t2))
                result = t1;
            else if (isCompatiblePointerType(t1,t2))
                result = t2;
            else
                semantic_error(24,node-> line);
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) result=convertUsualBinaryConversion(node);
            else if (!isCompatiblePointerType(t1,t2))
                semantic_error(40,node-> line);
            result=int_type;
            break;
        case N_EXP_NEQ:
        case N_EXP_EQL:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) result=convertUsualBinaryConversion(node);
            else if (!isCompatiblePointerType(t1,t2) &&
                     (!isPointerType(t1) || isConstantZeroExp(node->rlink)) && (!isPointerType(t2) || isConstantZeroExp(node->rlink)))
                semantic_error(40,node->line);
            result=int_type;
            break;
        case N_EXP_AND:
        case N_EXP_OR:
            t=sem_expression(node->llink);
            if (!isScalarType(t))
                node->llink = convertUsualUnaryConversion(node->llink);
            else
                semantic_error(27, node->line);
            t = sem_expression(node->rlink);
            if(!isScalarType(t))
                node->rlink = convertUsualUnaryConversion(node->rlink);
            else
                semantic_error(27, node->line);
            result=int_type;
            break;
        case N_EXP_ASSIGN:
            result = sem_expression(node->llink);
            if(!isModifiableLvalue(node->llink))
                semantic_error(60, node->line);
            t = sem_expression(node->rlink);
            if(isAllowableAssignmentConversion(result,t,node->rlink)){
                if(isArithmeticType(result) && isArithmeticType(t))
                    node->rlink = convertUsualAssignmentConversion(result,node->rlink);}
            else
                semantic_error(58,node->line);
            break;
        default:
            semantic_error(90,node->line);
            break;
    }
    node->type = result;
    node->value=lvalue;
    return result;
}

void sem_arg_expr_list(A_NODE *node, A_ID *id){
    A_TYPE *t;
    A_ID *a;
    int arg_size = 0;
    switch(node->name){
        case N_ARG_LIST:
            if(id==0)
                semantic_error(34, node->line);
            else{
                if(id->type){
                    t = sem_expression(node->llink);
                    node->llink = convertUsualUnaryConversion(node->llink);
                    if(isAllowableCastingConversion(id->type, node->llink->type))
                        node->llink=convertCastingConversion(node->llink, id->type);
                    else
                        semantic_error(59, node->line);
                    sem_arg_expr_list(node->rlink, id->link);}
                else{
                    t=sem_expression(node->llink);
                    sem_arg_expr_list(node->rlink,id);
                }
                arg_size = node->llink->type->size + node->rlink->value;}
            break;
        case N_ARG_LIST_NIL:
            if(id && id->type)
                semantic_error(35, node->line);
            break;
        default:
            semantic_error(90,node->line);
            break;
    }
    if(arg_size %4) arg_size = arg_size/4*4+4;
    node->value = arg_size;
    
}

BOOLEAN isModifiableLvalue(A_NODE *node){
    if(node->value == FALSE || isVoidType(node->type) ||  isFunctionType(node->type))
        return FALSE;
    else
        return TRUE;
}

int sem_statement(A_NODE *node, int addr, A_TYPE *ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int local_size = 0,i;
    A_LITERAL lit;
    A_TYPE *t;
    switch(node->name){
        case N_STMT_LABEL_CASE:
            if(sw==FALSE)
                semantic_error(71, node->line);
            lit=getTypeAndValueOfExpression(node->llink);
            if(isIntegralType(lit.type))
                node->llink = (A_NODE*)lit.value.i;
            else
                semantic_error(51, node->line);
            local_size = sem_statement(node->rlink, addr, ret, sw, brk, cnt);
            break;
        case N_STMT_LABEL_DEFAULT:
            if(sw==FALSE)
                semantic_error(72, node->line);
            local_size = sem_statement(node->clink,addr, ret, sw, brk, cnt);
            break;
        case N_STMT_COMPOUND:
            if(node->llink)
                local_size = sem_declaration_list(node->llink,addr);
            local_size += sem_statement_list(node->rlink, local_size+addr, ret, sw, brk, cnt);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
                    t=sem_expression(node->clink);
                    break;
        case N_STMT_IF:
            t = sem_expression(node->llink);
            if(isScalarType(t))
                node->llink = convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line);
            local_size=sem_statement(node->rlink , addr, ret, sw, brk, cnt);
            break;
        case N_STMT_IF_ELSE:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink = convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line);
            local_size = sem_statement(node->clink, addr, ret, FALSE, brk, cnt);
            i = sem_statement(node->rlink, addr, ret, FALSE, brk,cnt);
            if(local_size<i)
                local_size=i;
            break;
        case N_STMT_SWITCH:
            t = sem_expression(node->llink);
            if(!isIntegralType(t))
                semantic_error(50,node->line);
            local_size = sem_statement(node->rlink, addr, ret, TRUE, TRUE, cnt);
            break;
        case N_STMT_WHILE:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink = convertScalarToInteger(node->llink);
            else
                semantic_error(50,node->line);
            local_size= sem_statement(node->rlink,addr,ret,FALSE,TRUE, TRUE);
            break;
        case N_STMT_DO:
            local_size= sem_statement(node->llink,addr,ret,FALSE,TRUE,TRUE);
            t=sem_expression(node->rlink);
            if(isScalarType(t))
                node->rlink=convertScalarToInteger(node->rlink);
            else
                semantic_error(50, node->line);
            break;
        case N_STMT_FOR:
            sem_for_expression(node->llink);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_CONTINUE:
            if(cnt==FALSE)
                semantic_error(74,node->line);
            break;
        case N_STMT_BREAK:
                    if (brk==FALSE)
                        semantic_error(73,node->line);
                    break;
        case N_STMT_RETURN:
            if(node->clink){
                t=sem_expression(node->clink);
                if(isAllowableCastingConversion(ret,t))
                    node->clink = convertCastingConversion(node->clink,ret);
                else
                    semantic_error(57,node->line);
            }
            break;
        default:
            semantic_error(90,node->line);
            break;
            
    }
    node->value = local_size;
    return local_size;
}

void sem_for_expression(A_NODE *node){
    A_TYPE *t;
    switch(node->name){
        case N_FOR_EXP:
            if(node->llink)
                t=sem_expression(node->llink);
            if(node->clink){
                t=sem_expression(node->clink);
                if(isScalarType(t))
                    node->clink=convertScalarToInteger(node->clink);
                else
                    semantic_error(49,node->line);
            }
            if(node->rlink)
                t=sem_expression(node->rlink);
            break;
        default:
            semantic_error(90,node->line);
            break;
    }
}

int sem_statement_list(A_NODE *node, int addr, A_TYPE *ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt){
    int size,i;
    switch(node->name){
        case N_STMT_LIST:
            size=sem_statement(node->llink, addr, ret, sw, brk, cnt);
            i=sem_statement_list(node->rlink, addr, ret, sw, brk, cnt);
            if(size<i)
                size=i;
            break;
        case N_STMT_LIST_NIL:
            size=0;
            break;
        default:
            semantic_error(90,node->line);
            break;
            
    }
    node->value=size;
    return size;
}

int sem_A_TYPE(A_TYPE *t){
    A_ID *id;
    A_TYPE *tt;
    A_LITERAL lit;
    int result = 0,i;
    if(t->check)
        return t->size;
    t->check=1;
    switch(t->kind){
        case T_NULL:
            semantic_error(80,t->line);
            break;
        case T_ENUM:
            i=0;
            id=t->field;
            while(id){
                if(id->init){
                    lit = getTypeAndValueOfExpression(id->init);
                    if(!isIntType(lit.type))
                        semantic_error(81, id->line);
                    i = lit.value.i;
                }
                id->init = (A_NODE*)i++; // 명칭 상수의 갑을 0부터 차례대로 할당하되 초기화 수식이 있다면 그 값을 계산하여 정수인지 확인하고 설정한다. 크기는 4로 한다
                id=id->link;
            }
            result = 4;
            break;
        case T_ARRAY: // 배열의 크기가 수식인 경우 해당 수식이 즉시 정수갑으로 계싼되고 0보다 큰지 확인한다. 배열의 요소 타입을 분석해서 타입이 void나 함수인겨웅 오류를 발생시키고, 아닌경우는 배열의 크기와 요소의 크기를 곱해서 배열의 크기를 결정한다.
            if(t->expr){
                lit = getTypeAndValueOfExpression(t->expr);
                if(!isIntType(lit.type) || lit.value.i <= 0){
                    semantic_error(82, t->line);
                    t->expr=0;
                }
                else
                    t->expr = (A_NODE*)lit.value.i;
            }
            i=sem_A_TYPE(t->element_type) * (int)t->expr;
            if(isVoidType(t->element_type) || isFunctionType(t->element_type))
                semantic_error(83, t->line);
            else
                result = i;
            break;
        case T_STRUCT:
            id = t->field; // 필드 목록을 차례로 검사하며 그 주소는 0부터 각 필드의 크기를 누적한 값으로 설정하고ㅡ 구조체의 크기는 모든 필드의 크기를 누적한 값으로 설정한다.
            while (id) {
                A_ID *nested_id = t->field; // 검사하고자 하는 타입의 구조체의 필드 목록
                while (nested_id){
                    if (nested_id->type && id->type && nested_id->type->kind == T_STRUCT && nested_id->type == id->type && nested_id != id) {
                        semantic_error(87, id->line); // self-reference error
                    }
                    nested_id = nested_id->prev;
                }
                result += sem_declaration(id, result);
                id = id->link;
            }
            break;
        case T_UNION: // 주소는 모두 0, 공용체의 크기는 가장 크기가 큰 필드의 값으로 설정한다.
            id=t->field;
            while(id){
                i=sem_declaration(id,0);
                if(i>result)
                    result = i;
                id=id->link;
            }
            break;
        case T_FUNC: // 함수의 리턴 타입을 분석하여 보이드나 함수형인 경우 오류이고, 파라미터를 분석하여 크기를 계산하고 첫 파라미터가 12번지부터 할당ㅇ될 수있도록 한다. 함수 몸체를 분석하면서 나타난ㄴ 파라미ㅓ를 포함한 모든 지역변수의 크기를 계산하여 저장한다.
            tt= t->element_type;
            i = sem_A_TYPE(tt);
            if(isArrayType(tt) || isFunctionType(tt))
                semantic_error(85, t->line);
            i=sem_declaration_list(t->field, 12)+12;
            if(t->expr){
                i=i+sem_statement(t->expr,i,t->element_type, FALSE, FALSE, FALSE);}
            t->local_var_size = i;
            break;
        case T_POINTER:
            i=sem_A_TYPE(t->element_type); // 엘리먼트의 타입을 재귀적으로 분석
            result=4;
            break;
        case T_VOID:
            break;
        default:
            semantic_error(90,t->line);
            break;
    }
    t->size = result;
    return result;
}



int sem_declaration_list(A_ID *id, int addr){
    int i = addr;
    while(id){
        addr += sem_declaration(id, addr);
        id=id->link;
        
    }
    return (addr-i);
}

int sem_declaration(A_ID *id, int addr){
    A_TYPE *t;
    int size=0,i;
    A_LITERAL lit;
    switch(id->kind){
        case ID_VAR:
            i=sem_A_TYPE(id->type); // 선언문에서 타입의 크기 계산
            if(isArrayType(id->type) && id->type->expr==NIL)
                semantic_error(86,id->line);
            if(i%4) // 4의 배수로 맞춰주기
                i=i/4*4+4;
            if (id->specifier == S_STATIC) // static or global -> 크기를 누적해서 더해줌
                id->level = 0;
            if (id->level==0) {
                id->address=global_address;
                global_address += i;
            }
            else {
                id->address=addr; // 지역변수 -> 주소 설정, 크기 저장
                size=i; }
            break;
        case ID_FIELD: // 변수와 같다
            i = sem_A_TYPE(id->type);
            if(isFunctionType(id->type) || isVoidType(id->type))
                semantic_error(84, id->line);
            if(i%4)
                i=i/4*4+4;
            id->address = addr;
            size=i;
            break;
        case ID_FUNC:
            i=sem_A_TYPE(id->type);
            break;
        case ID_PARM:
            if(id->type){
                size=sem_A_TYPE(id->type);
                if(id->type==char_type)
                    id->type=int_type;
                else if(isArrayType(id->type)){ //파라미터 타입이 배열이거나 함수인경우 -> 포인터로 변환되므로 그 크기는 4로 설정
                    id->type->kind = T_POINTER;
                    id->type->size = 4;}
                else if(isFunctionType(id->type)){
                    t=makeType(T_POINTER);
                    t->element_type = id->type;
                    t->size=4;
                    id->type=t;
                }
                size=id->type->size;
                if(size%4)
                    size=size/4*4+4;
                id->address=addr;
            }
            break;
        case ID_TYPE:
            i=sem_A_TYPE(id->type);
            break;
        default:
            semantic_error(89,id->line,id->name);
            break;
    }
    return size;
}

A_ID *getStructFieldIdentifier(A_TYPE*t, char *s){
    A_ID *id=NIL;
    if(isStructOrUnionType(t)){
        id=t->field;
        while(id){
            if(strcmp(id->name,s) == 0)
                break;
            id=id->link;}
        return id;
    }
}

A_ID *getPointerFieldIdentifier(A_TYPE *t, char *s){
    A_ID *id=NIL;
    if(t && t->kind == T_POINTER){
        t=t->element_type;
        if(isStructOrUnionType(t)){
            id=t->field;
            while(id){
                if(strcmp(id->name,s) == 0)
                    break;
                id=id->link;
            }
        }
        
    }
    return id;
}

BOOLEAN isSameParameterType(A_ID *a, A_ID *b){
    while(a){
        if(b==NIL || isNotSameType(a->type, b->type))
            return FALSE;
        a=a->link;
        b=b->link;
    }
    if(b)
        return FALSE;
    else
        return TRUE;
}

BOOLEAN isCompatibleType(A_TYPE *t1, A_TYPE *t2) {
    if (isArrayType(t1) && isArrayType(t2))
        if (t1->size==0 || t2->size==0 || t1->size==t2->size)
            return (isCompatibleType(t1->element_type,t2->element_type));
        else
            return FALSE;
    else if (isFunctionType(t1) && isFunctionType(t2))
        if (isSameParameterType(t1->field,t2->field))
            return(isCompatibleType(t1->element_type,t2->element_type));
        else
            return FALSE;
    else if (isPointerType(t1) && isPointerType(t2))
        return(isCompatibleType(t1->element_type,t2->element_type));
    else
        return (t1==t2);
}

BOOLEAN isCompatiblePointerType(A_TYPE *t1, A_TYPE *t2) {
    if (isPointerType(t1) && isPointerType(t2))
        return(isCompatibleType(t1->element_type,t2->element_type));
    else
        return(FALSE);
}

BOOLEAN isConstantZeroExp(A_NODE *node){
    if(node->name==N_EXP_INT_CONST && node->clink == 0)
        return TRUE;
    else
        return FALSE;
}

A_NODE *convertScalarToInteger(A_NODE *node){
    if(isFloatType(node->type)){
        semantic_warning(16, node->line);
        node = makeNode(N_EXP_CAST, int_type, NIL, node);
    }
    node->type=int_type;
    return node;
}

A_NODE *convertUsualAssignmentConversion(A_TYPE *t1, A_NODE *node){
    A_TYPE *t2;
    t2=node->type;
    if(!isCompatibleType(t1,t2)){
        semantic_warning(11, node->line);
        node=makeNode(N_EXP_CAST,t1, NIL, node);
        node->type=t1;
    }
    return node;
    
}

A_NODE *convertUsualUnaryConversion(A_NODE *node){ // char -> int, Funtion | Array-> Pointer
    A_TYPE *t;
    t=node->type;
    if(t==char_type){
        t=int_type;
        node = makeNode(N_EXP_CAST, t, NIL, node);
        node->type=t;
    }
    else if(isArrayType(t)){
        t=setTypeElementType(makeType(T_POINTER), t->element_type);
        t->size=4;
        node=makeNode(N_EXP_CAST, t, NIL, node);
        node->type=t;
    }
    else if(isFunctionType(t)){
        t=setTypeElementType(makeType(T_POINTER),t);
        t->size=4;
        node=makeNode(N_EXP_AMP, NIL, node, NIL);
        node->type=t;}
    return node;
}

A_TYPE *convertUsualBinaryConversion(A_NODE *node){
    A_TYPE *t1, *t2, *result=NIL;
    t1=node->llink->type;
    t2=node->rlink->type;
    if(isFloatType(t1) && !isFloatType(t2)){
        semantic_warning(14, node->line);
        node->rlink = makeNode(N_EXP_CAST, t1, NIL, node->rlink);
        node->rlink->type=t1;
        result = t1;}
    else if(!isFloatType(t1) && isFloatType(t2)){
        semantic_warning(14, node->line);
        node->llink = makeNode(N_EXP_CAST, t2, NIL, node->llink);
        node->llink->type = t2;
        result = t2;
    }
    else if(t1==t2)
        result = t1;
    else
        result = int_type;
    return result;
}

A_NODE *convertCastingConversion(A_NODE *node, A_TYPE *t1){
    A_TYPE *t2;
    t2=node->type;
    if(!isCompatibleType(t1,t2)){
        semantic_warning(12, node->line);
        node = makeNode(N_EXP_CAST, t1, NIL, node);
        node->type = t1;
    }
    return node;
    
}


BOOLEAN isAllowableAssignmentConversion(A_TYPE *t1, A_TYPE *t2, A_NODE *node){
    if(isArithmeticType(t1) && isArithmeticType(t2))
        return TRUE;
    else if (isStructOrUnionType(t1) && isCompatibleType(t1,t2))
        return TRUE;
    else if (isPointerType(t1) && (isConstantZeroExp(node) || isCompatiblePointerType(t1,t2)))
        return TRUE;
    else
        return FALSE;
    
}

BOOLEAN isAllowableCastingConversion(A_TYPE *t1, A_TYPE *t2){ // true-> 변환, 경고 메시지 // false-> error
    if(isAnyIntegerType(t1) && (isAnyIntegerType(t2) || isFloatType(t2) || isPointerType(t2)))
        return TRUE;
    else if (isFloatType(t1) && isArithmeticType(t2))
        return TRUE;
    else if (isPointerType(t1) && (isAnyIntegerType(t2) || isPointerType(t2)))
        return TRUE;
    else if (isVoidType(t1))
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isFloatType(A_TYPE *t){
    if(t==float_type)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isArithmeticType(A_TYPE *t){
    if(t && t->kind == T_ENUM)
        return TRUE;
    else
        return FALSE;
}
BOOLEAN isScalarType(A_TYPE *t){
    if(t && ((t->kind==T_ENUM) || (t->kind == T_POINTER)))
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isAnyIntegerType(A_TYPE *t){
    if(t && (t==int_type || t==char_type))
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isIntegralType(A_TYPE *t){
    if(t && t->kind==T_ENUM && t!= float_type)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isFunctionType(A_TYPE *t){
    if(t && t->kind==T_FUNC)
        return TRUE;
    else
        return FALSE;
}
BOOLEAN isStructOrUnionType(A_TYPE *t){
    if(t && (t->kind==T_STRUCT || t->kind == T_UNION))
        return TRUE;
    else
        return FALSE;
}

BOOLEAN _isPointerOrArrayType(A_TYPE *t) {
    if (t && ( t->kind==T_POINTER || t->kind == T_ARRAY))
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isPointerType(A_TYPE *t){
    if(t && t->kind==T_POINTER)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isIntType(A_TYPE *t){
    if(t && t==int_type)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isVoidType(A_TYPE *t){
    if(t && t==void_type)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isArrayType(A_TYPE *t){
    if(t && t->kind==T_ARRAY)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isStringType(A_TYPE *t){
    if(t && (t->kind == T_POINTER || t->kind == T_ARRAY) && t->element_type==char_type)
        return TRUE;
    else
        return FALSE;
}

A_LITERAL checkTypeAndConvertLiteral(A_LITERAL result, A_TYPE *t, int ll){
    if(result.type==int_type && t==int_type ||
       result.type == char_type && t==char_type ||
       result.type == float_type && t==float_type);
    
    else if(result.type == int_type && t==float_type){
        result.type = float_type;
        result.value.f = result.value.i;
    }
    else if(result.type==int_type && t==char_type){
        result.type=char_type;
        result.value.c=result.value.i;
    }
    else if(result.type == float_type && t==int_type){
        result.type == int_type;
        result.value.i=result.value.f;
    }
    else if(result.type==char_type && t==int_type){
        result.type=int_type;
        result.value.i=result.value.c;
    }
    else
        semantic_error(41,ll);
    return result;
}

A_LITERAL getTypeAndValueOfExpression(A_NODE *node){
    A_TYPE *t;
    A_ID *id;
    A_LITERAL result,r;
    result.type = NIL;
    switch(node->name){
        case N_EXP_IDENT:
            id=node->clink;
            if(id->kind != ID_ENUM_LITERAL)
                semantic_error(19,node->line, id->name);
            else {
                result.type=int_type;
                result.value.i = (int)id->init;
            }
            break;
        case N_EXP_INT_CONST:
            result.type = int_type;
            result.value.i = (int)node->clink;
            break;
        case N_EXP_CHAR_CONST :
                result.type=char_type;
                result.value.c=(char)node->clink;
                break;
        case N_EXP_FLOAT_CONST:
            result.type = float_type;
            result.value.f = atof(node->clink);
            break;
        case N_EXP_STRING_LITERAL:
        case N_EXP_FUNCTION_CALL:
        case N_EXP_STRUCT:
        case N_EXP_ARROW:
        case N_EXP_ARRAY:
        case N_EXP_POST_INC:
        case N_EXP_PRE_INC:
        case N_EXP_POST_DEC:
        case N_EXP_PRE_DEC:
        case N_EXP_AMP:
        case N_EXP_STAR:
        case N_EXP_NOT:
            semantic_error(18,node->line);
            break;
        case N_EXP_MINUS:
            result = getTypeAndValueOfExpression(node->clink);
            if(result.type==int_type)
                result.value.i = -result.value.i;
            else if(result.type==float_type)
                result.value.f=-result.value.f;
            else
                semantic_error(18,node->line);
            break;
        case N_EXP_SIZE_EXP:
            t=sem_expression(node->clink);
            result.type = int_type;
            result.value.i=t->size;
            break;
        case N_EXP_SIZE_TYPE:
            result.type=int_type;
            result.value.i = sem_A_TYPE(node->clink);
            break;
        case N_EXP_CAST:
            result=getTypeAndValueOfExpression(node->rlink);
            result = checkTypeAndConvertLiteral(result,(A_TYPE*)node->llink, node->line);
            break;
        case N_EXP_MUL:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type == int_type && r.type == int_type){
                result.type = int_type;
                result.value.i = result.value.i * r.value.i;
            }
            else if(result.type == int_type && r.type == float_type){
                result.type = float_type;
                result.value.f = result.value.i * r.value.f;
            }
            else if(result.type == float_type && r.type == int_type){
                result.type = float_type;
                result.value.f = result.value.f * r.value.i;
            }
            else if(result.type == float_type && r.type == float_type){
                result.type = float_type;
                result.value.f = result.value.f * r.value.f;
            }
            else
                semantic_error(18, node->line);
            break;
        case N_EXP_DIV:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type ==int_type){
                result.type = int_type;
                result.value.i = result.value.i/r.value.i;
            }
            else if(result.type==int_type && r.type == float_type){
                result.type = float_type;
                result.value.f=result.value.i/r.value.f;
            }
            else if(result.type == float_type && r.type == int_type){
                result.type = float_type;
                result.value.f=result.value.f/r.value.i;
            }
            else if(result.type==float_type && r.type == float_type){
                result.type = float_type;
                result.value.f = result.value.f/r.value.f;
            }
            else
                semantic_error(18,node->line);
            break;
        case N_EXP_MOD:
            result = getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->llink);
            if(result.type==int_type &&r.type == int_type)
                result.value.i=result.value.i%r.value.i;
            else
                semantic_error(18,node->line);
            break;
            
        case N_EXP_ADD:
            result = getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type == int_type){
                result.type = int_type;
                result.value.i = result.value.i+r.value.i;
            }
            else if(result.type==int_type && r.type == float_type){
                result.type=float_type;
                result.value.f=result.value.i+r.value.f;
            }
            else if(result.type==float_type && r.type == int_type){
                result.type=float_type;
                result.value.f=result.value.f+r.value.i;
            }
            else if(result.type==float_type && r.type == float_type){
                result.type=float_type;
                result.value.f=result.value.f+r.value.f;
            }
            else
                semantic_error(18, node->line);
            break;
            
        case N_EXP_SUB:
            result = getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type == int_type){
                result.type = int_type;
                result.value.i = result.value.i-r.value.i;
            }
            else if(result.type==int_type && r.type == float_type){
                result.type=float_type;
                result.value.f=result.value.i-r.value.f;
            }
            else if(result.type==float_type && r.type == int_type){
                result.type=float_type;
                result.value.f=result.value.f-r.value.i;
            }
            else if(result.type==float_type && r.type == float_type){
                result.type=float_type;
                result.value.f=result.value.f-r.value.f;
            }
            else
                semantic_error(18, node->line);
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
        case N_EXP_NEQ:
        case N_EXP_EQL:
        case N_EXP_AND:
        case N_EXP_OR:
        case N_EXP_ASSIGN:
            semantic_error(18,node->line);
            break;
        default:
            semantic_error(90,node->line);
            break;
    }
    return result;
}

void semantic_error(int i, int ll, char *s){
    semantic_err++;
    printf("*** semantic error at line %d\n",ll);
    switch(i){
        case 13:
            printf("arith type expr required in unary operation\n");
            break;
        case 18:
            printf("illegal constant expression\n");
            break;
        case 19:
            printf("illegal identifier %s in constant expression\n",s);
            break;
        case 21:
            printf("illegal type in function call expression\n");
            break;
        case 24:
            printf("incompatible type in additive expression\n");
            break;
        case 27:
            printf("scalar type expr required in expression\n");
            break;
        case 28:
            printf("arith type expression required in binary operation\n");
            break;
        case 29:
            printf("integral type expression required in expression\n");
            break;
        case 31:
            printf("pointer type expr required in pointer operation\n");
            break;
        case 32:
            printf("array type required in array expression\n");
            break;
        case 34:
            printf("too many arguments in function call\n");
            break;
        case 35:
            printf("too few arguments in function call\n");
            break;
        case 37:
            printf("illegal struct field identifier in struct reference expr\n");
            break;
        case 38:
            printf("illegal kind of identifier %s in expression\n");
            break;
        case 39:
            printf("illegal type size in sizeof operation\n");
            break;
        case 40:
            printf("illegal expression type in relational operation\n");
            break;
        case 41:
            printf("incompatible type in literal\n");
            break;
        case 49:
            printf("scalar type expr required in middle of for-expr\n");
            break;
            
    // expression & statement
        case 50:
            printf("integral type expression required in statement\n");
            break;
        case 51:
            printf("illegal expression type in case lable\n");
            break;
        case 57:
            printf("not permitted type conversion in return expression\n");
            break;
        case 58:
            printf("not permitted type casting in expression\n");
            break;
        case 59:
            printf("not permitted type conversion in argument\n");
            break;
            
    // not lvalue
        case 60:
            printf("expression is not an lvalue\n");
            break;
            
    // control error
        case 71:
            printf("case label not within a switch statement\n");
            break;
        case 72:
            printf("default label not within a switch statement\n");
            break;
        case 73:
            printf("break statement not within loop or switch stmt\n");
            break;
        case 74:
            printf("continue statement not within a loop\n");
            break;
            
    // errors in type & declarator
        case 80:
            printf("undefined type\n");
            break;
        case 81:
            printf("integer type expression required enumerator\n");
            break;
        case 82:
            printf("illegal array size or type\n");
            break;
        case 83:
            printf("illegal element type of array declarator\n");
            break;
        case 84:
            printf("illegal type in struct or union field\n");
            break;
        case 85:
            printf("invalid function return type\n");
            break;
        case 86:
            printf("illegal array size or empty array\n");
            break;
        case 87:
            printf("not permitted referencing incomplete type\n");
            break;
        case 89:
            printf("unknown identifier kind: %s\n",s);
            break;
 
        case 90:
            printf("fatal compiler error in parse result\n");
            break;
        case 93:
            printf("too many literals in source program\n");
            break;
        default:
            printf("unknown \n");
            break;
    }
}


void semantic_warning(int i, int ll){
    printf("---- warning at line %d:\n",ll);
    switch(i){
        case 11:
            printf("incompatible types in assignment expression\n");
            break;
        case 12:
            printf("incompatible types in argument or return expr\n");
            break;
        case 14:
            printf("incompatible types in binary expression\n");
            break;
        case 16:
            printf("integer type expression in required\n");
            break;
        default:
            printf("unknown \n");
            break;
    }
}
