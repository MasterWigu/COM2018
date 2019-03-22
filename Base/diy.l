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
int xterminator = 0;
%}

%x COM XSTR XSTRBACK XTERMINATOR

%%
"==".*"\n"   			{if (xterminator) {xterminator = 0; return *dupstr(";");}};

<INITIAL,COM>"=<"		yy_push_state(COM);

<COM>.|\n				{if (xterminator) {xterminator = 0; return *dupstr(";");}};
<COM>"=>"				yy_pop_state();


"if"					xterminator=1; return IF;
"then"					xterminator=1; return THEN;
"else"					xterminator=1; return ELSE;
"do"					xterminator=1; return DO;
"while"					xterminator=1; return WHILE;
"for"					xterminator=1; return FOR;
"in"					xterminator=1; return IN;
"upto"					xterminator=1; return UPTO;
"downto"				xterminator=1; return DOWNTO;
"step"					xterminator=1; return STEP;
"break"					xterminator=1; return BREAK;
"continue"				xterminator=1; return CONTINUE;

"public"				xterminator=1; return PUBLIC;
"const"					xterminator=1; return CONST;

"integer"				xterminator=1; return INT;
"string"				xterminator=1; return STR;
"number"				xterminator=1; return NUM;
"void"					xterminator=1; return VOID;


"++"					xterminator=0; return INC;
"--"					xterminator=0; return DEC;

">="					xterminator=0; return GE;
"<="					xterminator=0; return LE;

"="						xterminator=0; return EQ;
"<>"					xterminator=0; return NE;

":="					xterminator=0; return ASSIGN;


[a-zA-Z][a-zA-Z_0-9]* 				yylval.s = dupstr(yytext); xterminator = 1; return IDENTIFIER;



[1-9][0-9]*							{ errno = 0; yylval.i = strtol(yytext, 0, 10);
									if (errno == ERANGE) yyerror("integer overflow (decimal)");
									xterminator=1; return INTVALUE; }

0[0-9]*								{ errno = 0; yylval.i = strtol(yytext, 0, 10);
									if (errno == ERANGE) yyerror("integer overflow (octal)");
									xterminator=1; return INTVALUE; }

0b[01]*								{ errno = 0; yylval.i = strtol(yytext, 0, 2);
									if (errno == ERANGE) yyerror("integer overflow (binary)");
									xterminator=1; return INTVALUE; }

[0-9]+\.[0-9]+([Ee][+-]?[0-9]+)? 	{errno = 0; yylval.d = strtod(yytext, 0);
									if(errno == ERANGE) yyerror("number overflow");
									 return NUMVALUE;}



\"(.|\n|\t|\r|"\"")*\"				yylval.s = malloc(yyleng); *yylval.s = 0; yyless(1); yy_push_state(XSTR);
<XSTR>\"							yy_pop_state(); xterminator=1; return STRVALUE;
<XSTR>\\							yy_push_state(XSTRBACK);
<XSTR>\n 							strcat(yylval.s, "\n");
<XSTR>.								strcat(yylval.s, yytext);

<XSTRBACK>t							strcat(yylval.s, "\t"); yy_pop_state();
<XSTRBACK>n							strcat(yylval.s, "\n"); yy_pop_state();
<XSTRBACK>r							strcat(yylval.s, "\r"); yy_pop_state();
<XSTRBACK>\"						strcat(yylval.s, "\"");	yy_pop_state();
<XSTRBACK>"0"						;
<XSTRBACK>[0-9A-Fa-f][0-9A-Fa-f]	charToDouble(yytext);   yy_pop_state();
<XSTRBACK>[0-9A-Fa-f]				charToDouble(yytext);   yy_pop_state();

[)!]								xterminator = 1; return *yytext;

\;									xterminator = 0; return *dupstr(";");		
\n 									if (xterminator) {xterminator = 0; return *dupstr(";");}	

[-+*/%&|~<>(,\[\]{}#]				xterminator=0; return *yytext;		
[ \t\r]          					;
.									yyerror("Unknown character");

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