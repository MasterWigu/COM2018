LANG=diy
EXT=diy # file extension: .$(EXT)
LIB=lib # compiler library directory
UTIL=util # compiler library: lib$(LIB).a
RUN=run # runtime directory
EXS=exs # examples directory
CC=gcc
CFLAGS=-g -DYYDEBUG


$(LANG): initial.y $(LANG).l
	byacc -dv initial.y
	flex -l $(LANG).l
	$(LINK.c) -o $(LANG) $(ARCH) lex.yy.c y.tab.c
examples:: $(LANG)
	make -C $(EXS)

clean::
	make -C $(EXS) clean
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output yyselect.c *.asm *~
