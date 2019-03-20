%option stack noyywrap yylineno 8bit
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
char *dupstr(const char*s) { return strdup(s); }
void charToDouble(const char* text);
int yyerror(char *s) { printf("%s\n",s); return 1; }
%}


%x COM XSTR XSTRBACK XTERMINATOR

%%
"==".*"\n"   		;

<INITIAL,COM>"=<"		yy_push_state(COM);


<COM>.|\n				;
<COM>"=>"				yy_pop_state();


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

">="					return GE;
"<="					return LE;

"="						return EQ;
"<>"					return NE;

":="					return ASSIGN;

<XTERMINATOR>[;\n]				BEGIN INITIAL; return *dupstr(";");
<XTERMINATOR>. 					yyless(0); BEGIN INITIAL;

[a-zA-Z][a-zA-Z_0-9]* 		yylval.s = dupstr(yytext); BEGIN XTERMINATOR; return IDENTIFIER;



[1-9][0-9]*				{ errno = 0; yylval.i = strtol(yytext, 0, 10);
						if (errno == ERANGE) yyerror("integer overflow");
						BEGIN XTERMINATOR; return INTVALUE; }

0[0-9]*					{ errno = 0; yylval.i = strtol(yytext, 0, 10);
						if (errno == ERANGE) yyerror("integer overflow");
						BEGIN XTERMINATOR; return INTVALUE; }

0b[01]*					{ errno = 0; yylval.i = strtol(yytext, 0, 2);
						if (errno == ERANGE) yyerror("integer overflow");
						BEGIN XTERMINATOR; return INTVALUE; }

[0-9]+\.[0-9]+([Ee][+-]?[0-9]+)? 	{errno = 0; yylval.d = strtod(yytext, 0);
									if(errno == ERANGE) yyerror("number overflow");
									BEGIN XTERMINATOR; return NUMVALUE;}

\"									yy_push_state(XSTR); yylval.s = dupstr("");
<XSTR>\"							yy_pop_state(); return STRVALUE;
<XSTR>\\							yy_push_state(XSTRBACK);
<XSTR>.								strcat(yylval.s, yytext);

<XSTRBACK>t							strcat(yylval.s, "\t"); yy_pop_state();
<XSTRBACK>n							strcat(yylval.s, "\n"); yy_pop_state();
<XSTRBACK>r							strcat(yylval.s, "\r"); yy_pop_state();
<XSTRBACK>\"						strcat(yylval.s, "\"");	yy_pop_state();
<XSTRBACK>[0-9A-Fa-f][0-9A-Fa-f]		{charToDouble(yytext);
										yy_pop_state();}
<XSTRBACK>[0-9A-Fa-f]					{charToDouble(yytext);
										yy_pop_state();}



[)!]						BEGIN XTERMINATOR; return *yytext;


[-+*/%&|~<>(,\[\]{}#;]	return *yytext;


[ \n\t\r]          ;
.			yyerror("Unknown character");

%%


void charToDouble(const char* text) {
	errno = 0;
	double temp = strtol(yytext, 0, 16);
	char c = (char)temp;
	if (errno == ERANGE)
		yyerror("invalid char");
	else
		strncat(yylval.s, &c,1);
}