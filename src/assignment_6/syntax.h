#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern char *yytext;

A_TYPE *int_type, *char_type, *void_type, *float_type, *string_type;
A_NODE *root;
A_ID *current_id = NIL;
int syntax_err = 0;
int line_no = 1;
int current_level = 0;
A_NODE *makeNode(NODE_NAME, A_NODE *, A_NODE *, A_NODE *);
A_NODE *makeNodeList(NODE_NAME, A_NODE *, A_NODE *);
A_ID *makeIdentifier(char *);
A_ID *makeDummyIdentifier();
A_TYPE *makeType(T_KIND);
A_SPECIFIER *makeSpecifier(A_TYPE *, S_KIND);
A_ID *searchIdentifier(char *, A_ID *);
A_ID *searchIdentifierAtCurrentLevel(char *, A_ID *);
A_SPECIFIER *updateSpecifier(A_SPECIFIER *, A_TYPE *, S_KIND);
void checkForwardReference();
void setDefaultSpecifier(A_SPECIFIER *);
A_ID *linkDeclaratorList(A_ID *, A_ID *);
A_ID *getIdentifierDeclared(char *);
A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND, char *, ID_KIND);
A_ID *setDeclaratorInit(A_ID *, A_NODE *);
A_ID *setDeclaratorKind(A_ID *, ID_KIND);
A_ID *setDeclaratorType(A_ID *, A_TYPE *);
A_ID *setDeclaratorElementType(A_ID *, A_TYPE *);
A_ID *setDeclaratorTypeAndKind(A_ID *, A_TYPE *, ID_KIND);
A_ID *setDeclaratorListSpecifier(A_ID *, A_SPECIFIER *);
A_ID *setFunctionDeclaratorSpecifier(A_ID *, A_SPECIFIER *);
A_ID *setFunctionDeclaratorBody(A_ID *, A_NODE *);
A_ID *setParameterDeclaratorSpecifier(A_ID *, A_SPECIFIER *);
A_ID *setStructDeclaratorListSpecifier(A_ID *, A_TYPE *);
A_TYPE *setTypeNameSpecifier(A_TYPE *, A_SPECIFIER *);
A_TYPE *setTypeElementType(A_TYPE *, A_TYPE *);
A_TYPE *setTypeField(A_TYPE *, A_ID *);
A_TYPE *setTypeExpr(A_TYPE *, A_NODE *);
A_TYPE *setTypeStructOrEnumIdentifier(T_KIND, char *, ID_KIND);
A_TYPE *setTypeAndKindOfDecalrator(A_TYPE *, ID_KIND, A_ID *);
BOOLEAN isNotSameFormalParameters(A_ID *, A_ID *);
BOOLEAN isNotSameType(A_TYPE *, A_TYPE *);
BOOLEAN isPointerOrArrayType(A_TYPE *);
void syntax_error();
void initialize();

A_NODE *makeNode(NODE_NAME n, A_NODE *a, A_NODE *b, A_NODE *c) {
    A_NODE *m = (A_NODE *)malloc(sizeof(A_NODE));
    m->name = n;
    m->llink = a;
    m->clink = b;
    m->rlink = c;
    m->type = NIL;
    m->line = line_no;
    m->value = 0;
    
    return m;
}

A_NODE *makeNodeList(NODE_NAME n, A_NODE *a, A_NODE *b) {
    A_NODE *m, *k;
    k = a;
    while(k->rlink)
        k = k->rlink;
    m = (A_NODE *)malloc(sizeof(A_NODE));
    m->name = k->name;
    m->llink = NIL;
    m->clink = NIL;
    m->rlink = NIL;
    m->type = NIL;
    m->line = line_no;
    m->value = 0;
    k->name = n;
    k->llink = b;
    k->rlink = m;
    
    return a;
}

A_ID *makeIdentifier(char *s) {
    A_ID *idt = (A_ID *)malloc(sizeof(A_ID));
    idt->name = s;
    idt->kind = 0;
    idt->specifier = 0;
    idt->level = current_level;
    idt->address = 0;
    idt->init = NIL;
    idt->type = NIL;
    idt->link = NIL;
    idt->line = line_no;
    idt->value = 0;
    idt->prev = current_id;
    current_id = idt;
    
    return idt;
}

A_ID *makeDummyIdentifier() {
    A_ID *idt = (A_ID*)malloc(sizeof(A_ID));
    idt->name="";
    idt->kind = 0;
    idt->specifier = 0;
    idt->level = current_level;
    idt->address = 0;
    idt->init = NIL;
    idt->type = NIL;
    idt->link = NIL;
    idt->line = line_no;
    idt->value = 0;
    idt->prev = 0;
    return idt;
}

A_TYPE *makeType(T_KIND k) {
    A_TYPE *t = (A_TYPE *)malloc(sizeof(A_TYPE));
    t->kind = k;
    t->size = 0;
    t->local_var_size = 0;
    t->element_type =NIL;
    t->field = NIL;
    t->expr = NIL;
    t->check = FALSE;
    t->prt = FALSE;
    t->line = line_no;
    return t;
}

A_SPECIFIER *makeSpecifier(A_TYPE *t, S_KIND s) {
    A_SPECIFIER *p = (A_SPECIFIER *)malloc(sizeof(A_SPECIFIER));
    p->type = t;
    p->stor = s;
    p->line = line_no;
    
    return p;
}

A_ID *searchIdentifier(char *s, A_ID *idt) {
    while(idt){
        if(strcmp(idt->name,s)==0)
            break;
        idt = idt->prev;
    }
    return idt;
}

A_ID *searchIdentifierAtCurrentLevel(char *s, A_ID *idt) {
    while(idt){
        if(idt->level < current_level)
            return NIL;
        if(strcmp(idt->name,s)==0)
            break;
        idt = idt->prev;
    }
    return idt;
}



void checkForwardReference() {
    A_ID *idt;
    A_TYPE *t;
    idt = current_id;
    while(idt){
        if(idt->level < current_level)
            break;
        t = idt->type;
        if(idt->kind == ID_NULL)
            syntax_error(31, idt->name);
        else if((idt->kind == ID_STRUCT || idt->kind == ID_ENUM) && t->field == NIL)
            syntax_error(32, idt->name);
        idt = idt->prev;
    }
}

void setDefaultSpecifier(A_SPECIFIER *p) {
    A_TYPE *t;
    if(p->type == NIL)
        p->type = int_type;
    if(p->stor == S_NULL)
        p->stor = S_AUTO;
}

A_SPECIFIER *updateSpecifier(A_SPECIFIER *p, A_TYPE *t, S_KIND s) {
    if(t)
        if(p->type)
            if(p->type==t)
                ;
            else
                syntax_error(24);
        
        else
            p->type = t;
    if(s){
        if(p->stor)
            if(s==p->stor)
                ;
            else
                syntax_error(24);
        else
            p->stor=s;
    }
    return p;
}

A_ID *linkDeclaratorList(A_ID *id1, A_ID *id2) {
    A_ID *m = id1;
    if(id1==NIL)
        return id2;
    while(m->link)
        m = m->link;
    m->link = id2;
    
    return id1;
}

A_ID *getIdentifierDeclared(char *s) {
    A_ID *idt;
    idt = searchIdentifier(s,current_id);
    if(idt==NIL)
        syntax_error(13,s);
    return idt;
}

A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND k, char *s, ID_KIND kk) {
    A_TYPE *t;
    A_ID *idt;
    idt = searchIdentifier(s, current_id);
    if(idt)
        if(idt->kind == kk && idt->type->kind == k)
            return idt->type;
        else
            syntax_error(11,s);
        
    t = makeType(k);
    idt = makeIdentifier(s);
    idt->kind = kk;
    idt->type = t;
    return t;
}

A_ID *setDeclaratorInit(A_ID *idt, A_NODE *n) {
    idt->init = n;
    return idt;
}

A_ID *setDeclaratorKind(A_ID *idt, ID_KIND k) {
    A_ID *a;
    a = searchIdentifierAtCurrentLevel(idt->name, idt->prev);
    if(a)
        syntax_error(12,idt->name);
    idt->kind = k;
    return idt;
}

A_ID *setDeclaratorType(A_ID *idt, A_TYPE *t) {
    idt->type = t;
    return idt;
}

A_ID *setDeclaratorElementType(A_ID *idt, A_TYPE *t) {
    A_TYPE *tt;
    if(idt->type == NIL)
        idt->type = t;
    else{
        tt = idt->type;
        while(tt->element_type)
            tt = tt->element_type;
        tt->element_type = t;
    }
    return idt;
}

A_ID *setDeclaratorTypeAndKind(A_ID *idt, A_TYPE *t, ID_KIND k) {
    idt = setDeclaratorElementType(idt,t);
    idt = setDeclaratorKind(idt,k);
    return idt;
}

A_ID *setFunctionDeclaratorSpecifier(A_ID *idt, A_SPECIFIER *p) {
    A_ID *a;
    if(p->stor)
        syntax_error(25);
    
    setDefaultSpecifier(p);
    
    if(idt->type == 0 || idt->type->kind != T_FUNC){
        syntax_error(21);
        return idt;
    }else{
        idt = setDeclaratorElementType(idt,p->type);
        idt->kind = ID_FUNC;
    }
    a = searchIdentifierAtCurrentLevel(idt->name, idt->prev);
    
    if(a)
        if(a->kind != ID_FUNC || a->type->expr)
            syntax_error(12,idt->name);
        else{
            if(isNotSameFormalParameters(a->type->field, idt->type->field))
                syntax_error(22,idt->name);
            if(isNotSameType(a->type->element_type, idt->type->element_type))
                syntax_error(26,idt->name);
        }
    a=idt->type->field;
    while(a){
        if(strlen(a->name))
            current_id = a;
        else if(a->type)
            syntax_error(23);
        a=a->link;
    }
    return idt;
    
}

A_ID *setFunctionDeclaratorBody(A_ID *idt, A_NODE *n) {
    idt->type->expr = n;
    return idt;
}


A_ID *setDeclaratorListSpecifier(A_ID *idt, A_SPECIFIER *p) {
    A_ID *a;
    setDefaultSpecifier(p);
    a=idt;
    while(a){
        if(strlen(a->name) && searchIdentifierAtCurrentLevel(a->name,a->prev))
            syntax_error(12,a->name);
        a = setDeclaratorElementType(a,p->type);
        if(p->stor == S_TYPEDEF)
            a->kind =ID_TYPE;
        else if(a->type->kind == T_FUNC)
            a->kind = ID_FUNC;
        else
            a->kind = ID_VAR;
        a->specifier = p->stor;
        if(a->specifier == S_NULL)
            a->specifier = S_AUTO;
        a=a->link;
    }
    return idt;
}

A_ID *setParameterDeclaratorSpecifier(A_ID *idt, A_SPECIFIER *p) {
    if(searchIdentifierAtCurrentLevel(idt->name, idt->prev))
        syntax_error(12,idt->name);
    if(p->stor || p->type == void_type)
        syntax_error(14);
    setDefaultSpecifier(p);
    idt=setDeclaratorElementType(idt,p->type);
    idt->kind = ID_PARM;
    return idt;
}

A_ID *setStructDeclaratorListSpecifier(A_ID *idt, A_TYPE *t){
    A_ID *a;
    a=idt;
    while(a){
        if(searchIdentifierAtCurrentLevel(a->name, a->prev))
            syntax_error(12,a->name);
        a=setDeclaratorElementType(a,t);
        a->kind  = ID_FIELD;
        a=a->link;
    }
    return idt;
}



A_TYPE *setTypeNameSpecifier(A_TYPE *t, A_SPECIFIER *p) {
    if(p->stor)
        syntax_error(20);
    setDefaultSpecifier(p);
    t=setTypeElementType(t, p->type);
    return t;
}

A_TYPE *setTypeElementType(A_TYPE *t, A_TYPE *s) {
    A_TYPE *q;
    if(t==NIL)
        return s;
    q=t;
    while(q->element_type)
        q=q->element_type;
    q->element_type=s;
    return t;
}

A_TYPE *setTypeField(A_TYPE *t, A_ID *n) {
    t->field = n;
    return t;
}

A_TYPE *setTypeExpr(A_TYPE *t, A_NODE *n) {
    t->expr = n;
    return t;
}
A_TYPE *setTypeStructOrEnumIdentifier(T_KIND k, char *s, ID_KIND kk){
    A_TYPE *t;
    A_ID *idt, *a;
    a=searchIdentifierAtCurrentLevel(s,current_id);
    if(a)
        if(a->kind == kk && a->type->kind == k)
            if(a->type->field)
                syntax_error(12,s);
            else
                return a->type;
        else
            syntax_error(12,s);
    idt=makeIdentifier(s);
    t=makeType(k);
    idt->type = t;
    idt->kind = kk;
    return t;
}

A_TYPE *setTypeAndKindOfDeclarator(A_TYPE *t, ID_KIND k, A_ID *idt) {
    if(searchIdentifierAtCurrentLevel(idt->name, idt->prev))
        syntax_error(12,idt->name);
    idt->type = t;
    idt->kind = k;
    return t;
}

BOOLEAN isNotSameFormalParameters(A_ID *a, A_ID *b) {
    if(a==NIL)
        return FALSE;
    while(a){
        if(b==NIL || isNotSameType(a->type, b->type))
            return TRUE;
        a=a->link;
        b=b->link;
    }
    if(b)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isNotSameType(A_TYPE *t1, A_TYPE *t2) {
    if(isPointerOrArrayType(t1) || isPointerOrArrayType(t2))
        return (isNotSameType(t1->element_type, t2->element_type));
    else
        return (t1 != t2);
}

BOOLEAN isPointerOrArrayType(A_TYPE *t) {
    if (t && ( t->kind == T_POINTER || t->kind == T_ARRAY))
            return TRUE;
        else
            return FALSE;
}

void initialize(){
    // 심볼, 타입 테이블 생성
    int_type = setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("int"));
    float_type = setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("float"));
    char_type = setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("char"));
    void_type = setTypeAndKindOfDeclarator(makeType(T_VOID), ID_TYPE, makeIdentifier("void"));
    string_type = setTypeElementType(makeType(T_POINTER), char_type);
    
    int_type->size = 4;
    float_type->size = 4;
    char_type->size = 1;
    void_type->size = 0;
    string_type->size = 4;
    
    int_type->check = TRUE;
    float_type->check = TRUE;
    char_type->check = TRUE;
    void_type->check = TRUE;
    string_type->check = TRUE;
    
    // 함수 정의
    
    setDeclaratorTypeAndKind(
                             makeIdentifier("printf"),
                             setTypeField(
                                          setTypeElementType(makeType(T_FUNC), void_type),
                                          linkDeclaratorList(
                                                             setDeclaratorTypeAndKind(makeDummyIdentifier(),string_type,ID_PARM),setDeclaratorKind(makeDummyIdentifier(),ID_PARM))),
                             ID_FUNC);
    
    setDeclaratorTypeAndKind(makeIdentifier("scanf"),
                             setTypeField(
                                          setTypeElementType(makeType(T_FUNC), void_type),
                                          linkDeclaratorList(
                                                             setDeclaratorTypeAndKind(makeDummyIdentifier(),string_type,ID_PARM),
                                                                                      setDeclaratorKind(makeDummyIdentifier(),ID_PARM))),
                             ID_FUNC);
    setDeclaratorTypeAndKind(makeIdentifier("malloc"), setTypeField(setTypeElementType(makeType(T_FUNC), string_type),
                                                                   linkDeclaratorList(
                                                                                      setDeclaratorTypeAndKind(makeDummyIdentifier(), int_type,ID_PARM),
                                                                                      setDeclaratorKind(makeDummyIdentifier(),ID_PARM))),
                             ID_FUNC);
    
    
}

void syntax_error(int i, char *s){
    syntax_err++;
    printf("line %d: syntax error: ",line_no);
    switch(i){
        case 11:
            printf("illegal referencing struct or union identifer %s",s);
            break;
        case 12:
            printf("redeclaration of identifier %s",s); break;
        case 13:
            printf("undefined identifier %s",s); break;
        case 14:
            printf("illegal type specifier in formal parameter"); break;
        case 20:
            printf("illegal storage class in type specifiers"); break;
        case 21:
            printf("illagal function declarator"); break;
        case 22:
            printf("confliction parm type in prototype function %s",s); break;
        case 23:
            printf("empty parameter name"); break;
        case 24:
            printf("illegal declaration specifiers"); break;
        case 25:
            printf("illegal function specifiers"); break;
        case 26:
            printf("illegal or conflicting return type in function %s",s); break;
        case 31:
            printf("undefined type for identifier %s",s); break;
        case 32:
            printf("incomplete forward reference for identifier %s",s); break;
        default:
            printf("unknown"); break;
            
    }
    if(strlen(yytext) == 0)
        printf(" at end\n");
    else
        printf(" near %s\n",yytext);
    return;
}
