%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
void yyerror(char *s);
%}


%x COM STR

%%

<COM> .|\n				;
<COM> "=>"				yy_pop_state();



"=<"					yy_push_state(COM);
"==".*\n				;


"if"					return IF;
"then"					return THEN;
"else"					return ELSE;
"do"					return DO;
"while"					return WHILE;
"for"					return FOR;
"in"					return IN;
"upto"					return UPTO;
"downto"				return DOWNTO;
"step"					return STEP;
"break"					return BREAK;
"continue"				return CONTINUE;

"public"				return PUBLIC;
"const"					return CONST;

"integer"				return INT;
"string"				return STR;
"number"				return NUM;
"void"					return VOID;



"++"					return INC;
"--"					return DEC;
"!"						return DIY;

">="					return GE;
"<="					return LE;

"="						return EQ;
"<>"					return NE;

":="					return ASSIGN;



[a-zA-Z][a-zA-Z_0-9]* yylval.s = dupstr(yytext); return IDENTIFIER;


[1-9][0-9]*				{ errno = 0; yylval.i = strtol(yytext, 0, 10);
						if (errno == ERANGE) yyerror("integer overflow");
						return INTVALUE; }

0[0-9]*					{ errno = 0; yylval.i = strtol(yytext, 0, 8);
			  			if (errno == ERANGE) yyerror("integer overflow");
						return INTVALUE; }

0b[01]*					{ errno = 0; yylval.i = strtol(yytext, 0, 2);
						if (errno == ERANGE) yyerror("integer overflow");
						return INTVALUE; }

[0-9]+\.?[0-9]*([Ee][+-]?[0-9]+)? 	{errno = 0; yylval.d = strtod(yytext, nullptr);
									if(errno == ERANGE) yyerror("number overflow");
									return NUMVALUE;}

\"						BEGIN STR;
<STR>\"					BEGIN INITIAL; return STRVALUE;
<STR>\\"				strcat(yylval.s, "\"");
<STR>.|\n				strcat(yylval.s, yytext);


[-+*/%!&|~<>();,\[\]{}#]	return *yytext;

.			yyerror("Unknown character");
%%

int yywrap(void) { return 1; }
char *getyytext() { return yytext; }


