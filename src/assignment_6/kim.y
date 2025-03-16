%{
    #define YYSTYPE_IS_DECLARED 1
    typedef long YYSTYPE;
    #include "type.h"
    #include "syntax.h"

    extern int line_no, syntax_err;
    extern A_NODE *root;
    extern int current_level;
    extern A_ID *current_id;
    extern A_TYPE *int_type, *float_type, *char_type, *void_type, *string_type;
    int yyerror(const char *);
    int yylex();

%}

%right "then" ELSE_SYM // solving ELSE_SYM's ambigious grammer

%token AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM ELSE_SYM ENUM_SYM FOR_SYM IF_SYM RETURN_SYM SIZEOF_SYM STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM // symbol
PLUSPLUS MINUSMINUS ARROW LSS GTR LEQ GEQ EQL NEQ AMPAMP BARBAR DOTDOTDOT LP RP LB RB LR RR COLON PERIOD COMMA EXCL STAR SLASH PERCENT AMP SEMICOLON PLUS MINUS ASSIGN  //operation
INTEGER_CONSTANT FLOAT_CONSTANT STRING_LITERAL CHARACTER_CONSTANT ESCAPE_CONSTANT IDENTIFIER TYPE_IDENTIFIER //constant, identifier
%start program

%%
    
program 
    : translation_unit {root = makeNode(N_PROGRAM,NIL,(A_NODE*)$1,NIL); checkForwardReference();}
    ;
    
translation_unit
    : external_declaration {$$ = $1;}
    | translation_unit external_declaration {$$ = (long)(linkDeclaratorList((A_ID*)$1,(A_ID*)$2));}
    ;
    
external_declaration
    : function_definition {$$ = $1;}
    | declaration {$$ = $1;}
    ;
    
function_definition
    : declaration_specifiers declarator {$$ = (long)setFunctionDeclaratorSpecifier((A_ID*)$2,(A_SPECIFIER*) $1);} compound_statement
    {$$ = (long)setFunctionDeclaratorBody((A_ID*)$3,(A_NODE*) $4); current_id = (A_ID*)$2;}
    | declarator {$$ = (long)setFunctionDeclaratorSpecifier((A_ID*)$1, makeSpecifier(int_type, 0));} compound_statement
    {$$ = (long)setFunctionDeclaratorBody((A_ID*)$2,(A_NODE*) $3); current_id = (A_ID*)$1;}
    ;

declaration_list_opt
    : /* empty */ {$$ = NIL;}
    | declaration_list {$$ = $1;}
    ;

declaration_list
    : declaration {$$ = $1;}
    | declaration_list declaration {$$ = (long) linkDeclaratorList((A_ID*)$1, (A_ID*)$2);}
    ;
    
declaration
    : declaration_specifiers init_declarator_list_opt SEMICOLON
    {$$ = (long)setDeclaratorListSpecifier((A_ID*)$2,(A_SPECIFIER*)$1);}
    ;
    
declaration_specifiers
    : type_specifier {$$ = (long)makeSpecifier((A_TYPE*)$1,0);}
    | storage_class_specifier {$$ = (long)makeSpecifier(0,$1);}
    | type_specifier declaration_specifiers {$$ = (long)updateSpecifier((A_SPECIFIER*)$2,(A_TYPE*)$1,0);}
    | storage_class_specifier declaration_specifiers {$$ = (long)updateSpecifier((A_SPECIFIER*)$2,0,$1);}
    ;
        
storage_class_specifier
    : AUTO_SYM { $$ = S_AUTO;}
    | STATIC_SYM { $$ = S_STATIC;}
    | TYPEDEF_SYM { $$ = S_TYPEDEF;}
    ;
    
init_declarator_list_opt
    : /* empty */ {$$ = (long)makeDummyIdentifier();}
    | init_declarator_list {$$ = $1;}
    ;
        
    
init_declarator_list
    : init_declarator {$$ = $1;}
    | init_declarator_list COMMA init_declarator {$$ = (long)linkDeclaratorList((A_ID*)$1,(A_ID*)$3);}
    ;
    
init_declarator
    : declarator {$$ = $1;}
    | declarator ASSIGN initializer {$$ = (long)setDeclaratorInit((A_ID*)$1, (A_NODE*)$3);}
    ;
    
initializer
    : constant_expression { $$ = (long)makeNode(N_INIT_LIST_ONE,NIL,(A_NODE*)$1,NIL);}
    | LR initializer_list RR {$$=$2;}
    ;
    
initializer_list
    : initializer {$$ =(long) makeNode(N_INIT_LIST,(A_NODE*) $1, NIL, makeNode(N_INIT_LIST_NIL,NIL,NIL,NIL));}
    | initializer_list COMMA initializer {$$ = (long) makeNodeList(N_INIT_LIST, (A_NODE*)$1, (A_NODE*)$3);}
    ;
      
type_specifier
    : struct_specifier {$$ = $1;}
    | enum_specifier {$$ = $1;}
    | TYPE_IDENTIFIER {$$ = $1;}
    ;
    
struct_specifier
    : struct_or_union IDENTIFIER {$$ = (long)setTypeStructOrEnumIdentifier($1, (char *)$2, ID_STRUCT);}
    LR {$$ = (long)current_id; current_level++;} struct_declaration_list RR
    {checkForwardReference(); $$=(long)setTypeField((A_TYPE*)$3,(A_ID*)$6); current_level--;
        current_id = (A_ID*)$5;}
    | struct_or_union {$$ = (long)makeType($1);} LR {$$=(long) current_id; current_level++;}
    struct_declaration_list RR
    {checkForwardReference(); $$ = (long)setTypeField((A_TYPE*)$2,(A_ID*)$5);
        current_level--; current_id = (A_ID*)$4;}
    | struct_or_union IDENTIFIER {$$ = (long)getTypeOfStructOrEnumIdentifier($1, (char*)$2, ID_STRUCT);}
    ;
    
struct_or_union
    : STRUCT_SYM {$$ = T_STRUCT;}
    | UNION_SYM {$$ = T_UNION;}
    ;
    
struct_declaration_list
    : struct_declaration {$$ = $1;}
    | struct_declaration_list struct_declaration {$$ = (long)linkDeclaratorList((A_ID*)$1,(A_ID*) $2);}
    ;
    
struct_declaration
    : type_specifier struct_declarator_list SEMICOLON
    {$$ = (long)setStructDeclaratorListSpecifier((A_ID*)$2, (A_TYPE*)$1);}
    ;
    
struct_declarator_list
    : struct_declarator {$$ = $1;}
    | struct_declarator_list COMMA struct_declarator {$$ = (long)linkDeclaratorList((A_ID*)$1,(A_ID*)$3);}
    ;
    
struct_declarator
    : declarator {$$=$1;}
    ;
    
enum_specifier
    : ENUM_SYM IDENTIFIER {$$ = (long)setTypeStructOrEnumIdentifier(T_ENUM, (char *)$2, ID_ENUM);}
    LR enumerator_list RR {$$ = (long)setTypeField((A_TYPE*)$3, (A_ID*)$5);}
    | ENUM_SYM {$$ = (long)makeType(T_ENUM);}
    LR enumerator_list RR {$$ = (long)setTypeField((A_TYPE*)$2, (A_ID*)$4);}
    | ENUM_SYM IDENTIFIER {$$ =(long) getTypeOfStructOrEnumIdentifier(T_ENUM, (char *)$2, ID_ENUM);}
    ;
    
enumerator_list
    : enumerator {$$ = $1;}
    | enumerator_list COMMA enumerator {$$=(long)linkDeclaratorList((A_ID*)$1,(A_ID*) $3);}
    ;
    
enumerator
    : IDENTIFIER {$$ = (long)setDeclaratorKind(makeIdentifier((char*)$1), ID_ENUM_LITERAL);}
    | IDENTIFIER {$$ = (long)setDeclaratorKind(makeIdentifier((char*)$1), ID_ENUM_LITERAL);}
    ASSIGN expression {$$ = (long)setDeclaratorInit((A_ID*)$2, (A_NODE*)$4);}
    ;
    
declarator
    : pointer direct_declarator {$$ = (long)setDeclaratorElementType((A_ID*)$2,(A_TYPE*)$1);}
    | direct_declarator {$$ = $1;}
    ;
    
pointer
    : STAR {$$ = (long)makeType(T_POINTER);}
    | STAR pointer {$$ = (long)setTypeElementType((A_TYPE*)$2,makeType(T_POINTER));}
    ;
    
direct_declarator
    : IDENTIFIER {$$ =(long) makeIdentifier((char*)$1);}
    | LP declarator RP {$$ = $2;}
    | direct_declarator LB constant_expression_opt RB
    {$$ = (long)setDeclaratorElementType((A_ID*)$1, setTypeExpr(makeType(T_ARRAY), (A_NODE*)$3));}
    | direct_declarator LP {$$ = (long)current_id;  current_level++;} parameter_type_list_opt RP {checkForwardReference();  current_id = (A_ID*)$3; current_level--; $$ = (long)setDeclaratorElementType((A_ID*)$1, setTypeField(makeType(T_FUNC),(A_ID*) $4));}
    ;
    
parameter_type_list_opt
    : /* empty */ {$$ = NIL;}
    | parameter_type_list {$$ = $1;}
    ;
    
parameter_type_list
    : parameter_list {$$ = $1;}
    | parameter_list COMMA DOTDOTDOT
    {$$=(long)linkDeclaratorList((A_ID*)$1,setDeclaratorKind(makeDummyIdentifier(),ID_PARM));}
    ;
    
parameter_list
    : parameter_declaration  {$$ = $1;}
    | parameter_list COMMA parameter_declaration {$$=(long)linkDeclaratorList((A_ID*)$1,(A_ID*)$3);}
    ;
    
parameter_declaration
    : declaration_specifiers declarator  {$$ =(long) setParameterDeclaratorSpecifier((A_ID*)$2,(A_SPECIFIER*)$1);}
    | declaration_specifiers abstract_declarator_opt
    {$$ = (long)setParameterDeclaratorSpecifier
    (setDeclaratorType(makeDummyIdentifier(),(A_TYPE*)$2),(A_SPECIFIER*)$1);}
    ;

abstract_declarator_opt
    : /* empty */ {$$ = NIL;}
    | abstract_declarator {$$ = $1;}
    ;
    
abstract_declarator
    : direct_abstract_declarator {$$ = $1;}
    | pointer {$$ = (long)makeType(T_POINTER);}
    | pointer direct_abstract_declarator {$$=(long)setTypeElementType((A_TYPE*)$2,makeType(T_POINTER));}
    ;
    
direct_abstract_declarator
    : LP abstract_declarator RP {$$=$2;}
    | LB constant_expression_opt RB  {$$ =(long) setTypeExpr(makeType(T_ARRAY),(A_NODE *)$2);}
    | direct_abstract_declarator LB constant_expression_opt RB {$$ =(long)setTypeElementType((A_TYPE*)$1,setTypeExpr(makeType(T_ARRAY),(A_NODE*)$3));}
    | LP parameter_type_list_opt RP {$$ =(long) setTypeExpr(makeType(T_FUNC),(A_NODE*)$2);}
    | direct_abstract_declarator LP parameter_type_list_opt RP {$$ =(long)setTypeElementType((A_TYPE*)$1,setTypeExpr(makeType(T_FUNC),(A_NODE*)$3));}
    ;
    
statement_list_opt
    : /* empty */ {$$ = (long)makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
    | statement_list {$$ = $1;}
    
statement_list
    : statement {$$ = (long)makeNode(N_STMT_LIST, (A_NODE *)$1, NIL, makeNode(N_STMT_LIST_NIL,NIL, NIL, NIL));}
    | statement_list statement {$$ = (long)makeNodeList(N_STMT_LIST, (A_NODE*)$1, (A_NODE*)$2);}
    
statement
    : labeled_statement {$$ = $1;}
    | compound_statement {$$ = $1;}
    | expression_statement {$$ = $1;}
    | selection_statement {$$ = $1;}
    | iteration_statement {$$ = $1;}
    | jump_statement {$$ = $1;}
    ;
    
labeled_statement
    : CASE_SYM constant_expression COLON statement {$$ = (long)makeNode(N_STMT_LABEL_CASE, (A_NODE*)$2, NIL, (A_NODE*)$4);}
    | DEFAULT_SYM COLON statement {$$ = (long)makeNode(N_STMT_LABEL_DEFAULT, NIL, (A_NODE*)$3, NIL);}
    ;
    
compound_statement
    : LR {$$ = (long)current_id; current_level++;} declaration_list_opt statement_list_opt RR {checkForwardReference(); $$ = (long)makeNode(N_STMT_COMPOUND,(A_NODE*) $3, NIL, (A_NODE*)$4); current_id = (A_ID*)$2; current_level--;}
    ;
    
expression_statement
    : SEMICOLON {$$ = (long)makeNode(N_STMT_EMPTY,NIL,NIL,NIL);}
    | expression SEMICOLON {$$ = (long)makeNode(N_STMT_EXPRESSION, NIL, (A_NODE*)$1, NIL);}
    ;
    
selection_statement
    : IF_SYM LP expression RP statement "then" {$$ = (long)makeNode(N_STMT_IF, (A_NODE*)$3, NIL,(A_NODE*) $5);}
    | IF_SYM LP expression RP statement ELSE_SYM statement {$$ = (long)makeNode(N_STMT_IF_ELSE,(A_NODE*) $3, (A_NODE*)$5, (A_NODE*)$7);}
    | SWITCH_SYM LP expression RP statement {$$ = (long)makeNode(N_STMT_SWITCH, (A_NODE*)$3, NIL, (A_NODE*)$5);}
    ;
    
iteration_statement
    : WHILE_SYM LP expression RP statement {$$ = (long)makeNode(N_STMT_WHILE, (A_NODE*)$3, NIL, (A_NODE*)$5);}
    | DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  {$$ = (long)makeNode(N_STMT_DO, (A_NODE*)$2, NIL, (A_NODE*)$5);}
    | FOR_SYM LP for_expression RP statement {$$ = (long)makeNode(N_STMT_FOR, (A_NODE*)$3, NIL, (A_NODE*)$5);}
    ;
    
for_expression
    : expression_opt SEMICOLON expression_opt SEMICOLON expression_opt {$$ = (long)makeNode(N_FOR_EXP, (A_NODE*)$1,(A_NODE*) $3, (A_NODE*)$5);}
    
expression_opt
    : /* empty */ {$$ = NIL;}
    | expression {$$ = $1;}
    ;
    
jump_statement
    : RETURN_SYM expression_opt SEMICOLON {$$ = (long)makeNode(N_STMT_RETURN, NIL,(A_NODE*) $2, NIL);}
    | CONTINUE_SYM SEMICOLON  {$$ = (long)makeNode(N_STMT_CONTINUE, NIL, NIL, NIL);}
    | BREAK_SYM SEMICOLON  {$$ = (long)makeNode(N_STMT_BREAK, NIL, NIL, NIL);}
    ;
    
arg_expression_list_opt
    : /* empty */ {$$=(long)makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL);}
    | arg_expression_list {$$=$1;}
    ;
        
arg_expression_list
    : assignment_expression {$$ = (long)makeNode(N_ARG_LIST,(A_NODE*)$1,NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL));}
    | arg_expression_list COMMA assignment_expression {$$ = (long)makeNodeList(N_ARG_LIST,(A_NODE*)$1,(A_NODE*)$3);}
    ;
    
constant_expression_opt
    : /* empty */ {$$ = NIL;}
    | constant_expression {$$ = $1;}
    ;
    
constant_expression
    : expression {$$ = $1;}
    ;
    
expression
    : comma_expression {$$ = $1;}
    ;
    
comma_expression
    : assignment_expression {$$ = $1;}
    ;
    
assignment_expression
    : conditional_expression {$$ = $1;}
    | unary_expression ASSIGN assignment_expression {$$ = (long)makeNode(N_EXP_ASSIGN,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;
        
conditional_expression
    : logical_OR_expression {$$ = $1;}
    ;
        
logical_OR_expression
    : logical_AND_expression {$$ = $1;}
    | logical_OR_expression BARBAR logical_AND_expression {$$=(long)makeNode(N_EXP_OR,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;
            
logical_AND_expression
    : bitwise_OR_expression {$$ = $1;}
    | logical_AND_expression AMPAMP bitwise_OR_expression {$$=(long)makeNode(N_EXP_AND,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;

bitwise_OR_expression
    : bitwise_XOR_expression {$$ = $1;}
    ;
    
bitwise_XOR_expression
    : bitwise_AND_expression {$$ = $1;}
    ;
    
bitwise_AND_expression
    : equality_expression {$$ = $1;}
    ;
        
equality_expression
    : relational_expression {$$ = $1;}
    | equality_expression EQL relational_expression
    {$$ = (long)makeNode(N_EXP_EQL,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | equality_expression NEQ relational_expression
    {$$ = (long)makeNode(N_EXP_NEQ,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;
            
relational_expression
    : shift_expression {$$ = $1;}
    | relational_expression LSS shift_expression {$$ = (long)makeNode(N_EXP_LSS,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | relational_expression GTR shift_expression
    {$$ = (long)makeNode(N_EXP_GTR,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | relational_expression LEQ shift_expression {$$ = (long)makeNode(N_EXP_LEQ,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | relational_expression GEQ shift_expression {$$ = (long)makeNode(N_EXP_GEQ,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;
                
shift_expression
    : additive_expression {$$ = $1;}
    ;
    
additive_expression
    : multiplicative_expression {$$ = $1;}
    | additive_expression PLUS multiplicative_expression {$$ = (long)makeNode(N_EXP_ADD,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | additive_expression MINUS multiplicative_expression {$$ = (long)makeNode(N_EXP_SUB,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;
    
multiplicative_expression
    : cast_expression {$$ = $1;}
    | multiplicative_expression STAR cast_expression
    {$$ = (long)makeNode(N_EXP_MUL,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | multiplicative_expression SLASH cast_expression
    {$$ = (long)makeNode(N_EXP_DIV,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | multiplicative_expression PERCENT cast_expression
    {$$ = (long)makeNode(N_EXP_MOD,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    ;
    
cast_expression
    : unary_expression {$$ = $1;}
    | LP type_name RP cast_expression {$$ = (long)makeNode(N_EXP_CAST, (A_NODE*)$2, NIL,(A_NODE*) $4);}
    ;
    
unary_expression
    : postfix_expression {$$ = $1;}
    | PLUSPLUS unary_expression {$$ = (long)makeNode(N_EXP_PRE_INC,NIL,(A_NODE*)$2,NIL);}
    | MINUSMINUS unary_expression {$$=(long)makeNode(N_EXP_PRE_DEC,NIL,(A_NODE*)$2,NIL);}
    | AMP cast_expression {$$ = (long)makeNode(N_EXP_AMP,NIL,(A_NODE*)$2,NIL);}
    | STAR cast_expression {$$ = (long)makeNode(N_EXP_STAR,NIL,(A_NODE*)$2,NIL);}
    | EXCL cast_expression {$$ = (long)makeNode(N_EXP_NOT,NIL,(A_NODE*)$2,NIL);}
    | MINUS cast_expression{$$ = (long)makeNode(N_EXP_MINUS,NIL,(A_NODE*)$2,NIL);}
    | PLUS cast_expression {$$ = (long)makeNode(N_EXP_PLUS,NIL,(A_NODE*)$2,NIL);}
    | SIZEOF_SYM unary_expression {$$ = (long)makeNode(N_EXP_SIZE_EXP,NIL,(A_NODE*)$2,NIL);}
    | SIZEOF_SYM LP type_name RP {$$ = (long)makeNode(N_EXP_SIZE_TYPE,NIL,(A_NODE*)$3,NIL);}
    ;
    
postfix_expression
    : primary_expression {$$ = $1;}
    | postfix_expression LB expression RB {$$ = (long)makeNode(N_EXP_ARRAY,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | postfix_expression LP arg_expression_list_opt RP
    {$$ = (long)makeNode(N_EXP_FUNCTION_CALL,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | postfix_expression PERIOD IDENTIFIER {$$ = (long)makeNode(N_EXP_STRUCT,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | postfix_expression ARROW IDENTIFIER {$$ = (long)makeNode(N_EXP_ARROW,(A_NODE*)$1,NIL,(A_NODE*)$3);}
    | postfix_expression PLUSPLUS {$$ = (long)makeNode(N_EXP_POST_INC,NIL,(A_NODE*)$1,NIL);}
    | postfix_expression MINUSMINUS {$$ = (long)makeNode(N_EXP_POST_DEC,NIL,(A_NODE*)$1,NIL);}
    ;

primary_expression
    : IDENTIFIER 
    {$$=(long)makeNode(N_EXP_IDENT,NIL,(A_NODE*)getIdentifierDeclared((char*)$1),NIL);}
    | INTEGER_CONSTANT {$$ = (long)makeNode(N_EXP_INT_CONST,NIL,(A_NODE*)$1,NIL);}
    | FLOAT_CONSTANT {$$ = (long)makeNode(N_EXP_FLOAT_CONST,NIL,(A_NODE*)$1,NIL);}
    | CHARACTER_CONSTANT {$$ = (long)makeNode(N_EXP_CHAR_CONST,NIL,(A_NODE*)$1,NIL);}
    | STRING_LITERAL {$$ = (long)makeNode(N_EXP_STRING_LITERAL,NIL,(A_NODE*)$1,NIL);}
    | LP expression RP {$$ = $2;}
    ;

type_name
    : declaration_specifiers abstract_declarator_opt {$$ =(long)setTypeNameSpecifier((A_TYPE*)$2,(A_SPECIFIER*)$1);}
    ;

    
%%
extern char *yytext;
    
int yyerror(const char *s) {
    //syntax_err++;
    printf("line %d: %s near %s \n", line_no, s, yytext);
    exit(1);
}
    
int yywrap(){
    return(1);
    }
   
