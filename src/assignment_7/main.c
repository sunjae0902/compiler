#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

void initialize();
void yyparse();
//void print_ast(A_NODE *);
//void print_sem_ast(A_NODE *);
void code_generation();
void semantic_analysis(A_NODE *);

extern FILE *yyin;
extern int syntax_err, semantic_err;
extern A_NODE *root;

FILE *fout;

void main(int argc, char *argv[])
{
    
    if (argc<2){
        printf("source file not given\n");
        exit(1);}
    if (strcmp(argv[1],"-o")==0)
        if (argc>3)
            if ((fout=fopen(argv[2],"w"))==NULL) {
                printf("can not open output file: %s\n",argv[3]);
                exit(1);}
            else ;
            else  { printf("out file not given\n");
                exit(1);}
            else if (argc==2)
                if ((fout=fopen("a.asm","w"))==NULL) {
                    printf("can not open output file: a.asm\n");
                    exit(1);
                }
    if ((yyin=fopen(argv[argc-1],"r"))==NULL){
        printf("can not open input file: %s\n",argv[argc-1]);
        exit(1);
    }
    printf("\nstart syntax analysis\n");
    initialize();
    yyparse();
    if (syntax_err) exit(1);
    // print_ast(root);
    
    printf("start semantic analysis\n");
    semantic_analysis(root);
    if (semantic_err) exit(1);
    // print_sem_ast(root);
    
    printf("start code generation\n");
    code_generation(root);
    
    fclose(fout);
    fclose(yyin);
    
    // a.asm 출력
    FILE *fr = fopen("a.asm", "r");
    if (fr == NULL) {
        perror("Fail to open asm file.\n");
    }
    char ch;
    while ((ch = fgetc(fr)) != EOF) {
        putchar(ch);
    }

    fclose(fr);
    
    
    exit(0);
}
