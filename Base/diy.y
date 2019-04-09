%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tabid.h"
#include "node.h"
extern int yylex();

extern int yylex(); /* -Wall */
static char buf[80]; /* error messages */
static int gt, pos, dim(Node*);
static void *gtr, *root;
static Node *name(Node*);
%}

%union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node */
};

%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC INCR DECR
%token ATR NE GE LE ELSE


%nonassoc IFX
%nonassoc ELSE
%right ATR
%left '|'
%left '&'
%nonassoc '~'
%left '=' NE
%left '<' '>' GE LE
%left '+' '-'
%left '*' '/' '%'
%nonassoc INC DEC ADDR UMINUS PTRR '!'
%nonassoc '[' '('

%token IFX UMINUS ADDR LOCAL INIT PUB PRIV CON TYPE MEM ATR NIL CONS DEF TYPEX PLCOM CSTR
%token DECL GLOBAL PTR PTRR FUNC PARAM BODY BPARAMS BPARAM ALLOC INSTR LOAD BSUB
%token INDEX CALL FACT NOT AINC ADEC BINC BDEC MUL DIV MOD ADD LT GT EQ AND OR ARG

%type<n> decl def priv cons type ptr initid params param optbody body bparams updn stp optint instr instrs lvalue expr args


%%


file	: decl 									{ printNode($1, 0, yynames); }

decl   	:										{ $$ = nilNode(NIL); }
		| decl def								{ $$ = binNode(DECL, $1, $2); }
		;

def		: priv cons type ptr initid ';'			{ $$ = binNode(DEF, binNode(TYPEX, binNode(PLCOM, $1, $2), binNode(TYPE, $3, $4)), $5); }
		;

priv	:										{ $$ = nilNode(NIL); }				
		| PUBLIC								{ $$ = nilNode(PUB); }
		;

cons 	:										{ $$ = nilNode(NIL); }
		| CONST									{ $$ = nilNode(CONS); }
		;


type	: INTEGER 								{ $$ = nilNode(INTEGER); }
		| STRING 								{ $$ = nilNode(STRING); }
		| NUMBER 								{ $$ = nilNode(NUMBER); }
		| VOID 									{ $$ = nilNode(VOID); }
		;
		

ptr 	:										{ $$ = nilNode(NIL); }
		| '*' 									{ $$ = nilNode(PTR); }
		;


initid	: ID									{ $$ = uniNode(INIT, strNode(ID, $1)); }
		| ID ATR INT 							{ $$ = binNode(INIT, strNode(ID, $1), intNode(INT, $3)); }
		| ID ATR cons STR 						{ $$ = binNode(INIT, strNode(ID, $1), binNode(CSTR, $3, strNode(STR, $4))); }
		| ID ATR REAL 							{ $$ = binNode(INIT, strNode(ID, $1), realNode(REAL, $3)); }
		| ID ATR ID 							{ $$ = binNode(INIT, strNode(ID, $1), strNode(ID, $3)); }
		| ID '(' params ')' optbody 			{ $$ = binNode(INIT, strNode(ID, $1), binNode(FUNC, $3, $5)); }
		;

params	:										{ $$ = nilNode(NIL); }
		| params ',' param 						{ $$ = binNode(PARAM, $1, $3); }
		| param 								{ $$ = uniNode(PARAM, $1); }
		;


param 	: type ptr ID 							{ $$ = binNode(TYPE, $1, binNode(MEM, $2, strNode(ID,$3))); }
		;


optbody :										{ $$ = nilNode(NIL); }
		| body 									{ $$ = $1; }
		;

body	: '{' bparams instrs '}' 				{ $$ = binNode(BODY, $2, $3); }
		;

bparams :										{ $$ = nilNode(NIL); }
		| bparams param ';'						{ $$ = binNode(BPARAMS, $1, $2); }
		//| param ';' 							{ $$ = uniNode(PARAM, $1); }
		;


updn 	: UPTO									{ $$ = nilNode(UPTO); }
		| DOWNTO 								{ $$ = nilNode(DOWNTO); }
		;

stp 	:										{ $$ = nilNode(NIL); }
		| STEP expr 							{ $$ = uniNode(STEP, $2); }
		;

optint 	:										{ $$ = nilNode(NIL); }
		| INT 									{ $$ = intNode(INT, $1); }
		;

instr 	: IF expr THEN instr %prec IFX 			{ $$ = binNode(IF, $2, $4); }
		| IF expr THEN instr ELSE instr 		{ $$ = binNode(ELSE, binNode(IF, $2, $4), $6); }
		| DO instr WHILE expr ';' 				{ $$ = binNode(DO, $2, uniNode(WHILE, $4)); }
		| FOR lvalue IN expr updn expr stp DO instr { $$ = nilNode(NIL); }
		| expr ';'								{ $$ = $1; }
		| body 									{ $$ = $1; }
		| BREAK optint ';' 						{ $$ = uniNode(BREAK, $2); }
		| CONTINUE optint ';' 					{ $$ = uniNode(CONTINUE, $2); }
		| lvalue '#' expr ';' 					{ $$ = binNode(ALLOC, $3, $1); }
		;

instrs  :										{ $$ = nilNode(NIL); }
		| instrs instr 							{ $$ = binNode(INSTR, $1, $2); }
		;

lvalue	: ID 									{ $$ = strNode(ID, $1); }
		| lvalue '[' expr ']' 					{ $$ = binNode(INDEX, $1, $3); }
		| '*' ID 								{ $$ = uniNode(LOAD, strNode(ID, $2)); }
		;

expr	: lvalue								{ $$ = uniNode(LOAD, $1); }	
		| '(' expr ')'							{ $$ = $2; }
		| INT 									{ $$ = intNode(INT, $1); }
		| STR 									{ $$ = strNode(STR, $1); }
		| REAL 									{ $$ = realNode(REAL, $1); }
		| expr '(' args ')'	 					{ $$ = binNode(CALL, $3, $1); }
		| expr '(' ')'							{ $$ = binNode(CALL, nilNode(NIL), $1); }
      	| '-' expr %prec UMINUS					{ $$ = uniNode(UMINUS, $2); }
      	| expr '!'								{ $$ = uniNode(FACT, $1); }
		| '&' lvalue %prec ADDR					{ $$ = uniNode(PTR, $2); }
		| '~' expr								{ $$ = uniNode(NOT, $2); }
		| lvalue INCR							{ $$ = uniNode(AINC, $1); }
		| lvalue DECR 							{ $$ = uniNode(ADEC, $1); }
		| INCR lvalue							{ $$ = uniNode(BINC, $2); }
		| DECR lvalue							{ $$ = uniNode(BDEC, $2); }
     	| expr '*' expr							{ $$ = binNode(MUL, $1, $3); }
     	| expr '/' expr							{ $$ = binNode(DIV, $1, $3); }
     	| expr '%' expr							{ $$ = binNode(MOD, $1, $3); }
    	| expr '+' expr							{ $$ = binNode(ADD, $1, $3); }
    	| expr '-' expr							{ $$ = binNode(BSUB, $1, $3); }
		| expr '<' expr							{ $$ = binNode(LT, $1, $3); }
		| expr '>' expr							{ $$ = binNode(GT, $1, $3); }
		| expr GE expr							{ $$ = binNode(GE, $1, $3); }
		| expr LE expr							{ $$ = binNode(LE, $1, $3); }
		| expr '=' expr							{ $$ = binNode(EQ, $1, $3); }
		| expr NE expr							{ $$ = binNode(NE, $1, $3); }
    	| expr '&' expr							{ $$ = binNode(AND, $1, $3); }
    	| expr '|' expr							{ $$ = binNode(OR, $1, $3); }
		| lvalue ATR expr						{ $$ = binNode(ATR, $3, $1); }
       	;

args	: expr									{ $$ = binNode(ARG, $1, nilNode(NIL)); }
		| args ',' expr 						{ $$ = binNode(ARG, $3, $1); }
		;

%%

static Node *name(Node *nm) {
  int typ = 2, pos = 0;
  if (!gt)
    typ = IDfind(nm->value.s, (long*)&pos);
  else { /* in a goto statment */
    root = IDroot(gtr);
    IDnew(0, nm->value.s, IDtest);
    gtr = IDroot(root);
    if (IDfind(nm->value.s, (long*)IDtest) < 0)
      typ = 2; /* reference to foward label */
    else
      typ = IDfind(nm->value.s, (long*)&pos);
  }
  /* check types */
  if (pos != 0)
    nm = intNode(LOCAL, pos);
  else
    nm = strNode(ADDR, nm->value.s);
  nm->info = typ;
  return nm;
}

static int dim(Node *n)
{
  if (n->type == nodeNil) return 1;
  return n->value.i;
}

int yyerror(const char*); /* declaration may depend on yacc's version/flavor */
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif



