
pond: pond.lex pond.y 
	  bison -d pond.y 
	  flex pond.lex 
	  cc -o $@ pond.tab.c lex.yy.c ev.c sym.c
