CC = cc
LEX = lex
YACC = yacc

analyzer: y.tab.c lex.yy.c semantic.c print.c main.c print_sem.c
	$(CC) -w -g -o analyzer y.tab.c lex.yy.c print.c main.c semantic.c print_sem.c

y.tab.c y.tab.h: kim.y
	$(YACC) -d kim.y

lex.yy.c: kim.l
	$(LEX) kim.l

	

