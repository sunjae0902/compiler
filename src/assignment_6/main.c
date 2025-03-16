#include <stdio.h>
#include <stdlib.h>
#include "type.h"

extern int syntax_err, semantic_err;
extern A_NODE *root;
void initialize();
void print_ast(A_NODE*);
void print_sem_ast(A_NODE*);
void semantic_analysis(A_NODE *);
int yyparse();

int main() {
    
    initialize();
    
    yyparse();
    
    if (syntax_err) exit(1);
    
    print_ast(root);
    semantic_analysis(root);
    
    if (semantic_err) exit(1);
    print_sem_ast(root);
    exit(0);
}
