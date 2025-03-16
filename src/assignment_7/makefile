CC = cc
LEX = lex
YACC = yacc

compiler: y.tab.c lex.yy.c semantic.c main.c gen.c
	$(CC) -w -g -o compiler y.tab.c lex.yy.c main.c semantic.c gen.c

y.tab.c y.tab.h: kim.y
	$(YACC) -d kim.y

lex.yy.c: kim.l
	$(LEX) kim.l
