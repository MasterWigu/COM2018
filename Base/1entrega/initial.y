%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
extern int yylex();
extern void* yyin;
void yyerror(char *s);

#ifndef YYERRCODE
#define YYERRCODE 256
#endif
%}

%union {
	int i;		/* integer value */
	double d;	/* double value */
	char *s;	/* symbol name or string literal */
}

%token <i> INTVALUE
%token <s> NUMVALUE
%token <s> IDENTIFIER STRVALUE

%token IF THEN ELSE DO WHILE FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token PUBLIC CONST
%token INT STR NUM VOID
%token INC DEC GE LE EQ NE ASSIGN
%token IDENTIFIER
%token LF


%%
start:;


%%

int main(int argc, char *argv[]) {
	if (argc > 1)
		yyin=fopen(argv[1],"r");
	extern YYSTYPE yylval;
	int tk;
	while ((tk = yylex())) 
		if (tk > YYERRCODE) 
			printf("%d:\t%s\n", tk, yyname[tk]);
		else
			printf("%d:\t%c\n", tk, tk);

	return 0;
}