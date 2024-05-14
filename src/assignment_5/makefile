CC = cc
LIBS = -ll
LEX = lex
YACC = yacc
YFLAGS = -v
CFLAGS = -DYYDEBUG=1

parser: y.tab.c lex.yy.c main.c func.h
	$(CC) -Wall -g -o parser y.tab.c lex.yy.c print.c main.c
y.tab.c y.tab.h: kim.y
	$(YACC) $(YFLAGS) -d kim.y
lex.yy.c : kim.l
	$(LEX) kim.l

	

