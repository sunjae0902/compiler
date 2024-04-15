CC = cc
LIBS = -ll
LEX = lex
YACC = yacc
YFLAGS = -v
CFLAGS = -DYYDEBUG=1

parser: y.tab.c lex.yy.c
	$(CC) -o parser y.tab.c lex.yy.c $(LIBS)
y.tab.c: kim.y
	$(YACC) $(YFLAGS) -d kim.y
lex.yy.c : kim.l
	$(LEX) kim.l

