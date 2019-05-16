%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tabid.h"
#include "node.h"
extern int yylex();
extern int yyerror(char*);
static char buf[100]; /* error messages */
static int gt, pos, dim(Node*);
static void *gtr, *root;
static Node *name(Node*);
static void declareType(Node *typ, Node *init);
static void createFunc(int ret, Node* nm);
static void initFuncBody(char *funcName);

typedef struct fattrib{
	int attribNum;
	int *attribTypes;
	char **attribNames;
} *funcAttribs;

Node *tempNode;
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
%left '~'
%left '=' NE
%left '<' '>' GE LE
%left '+' '-'
%left '*' '/' '%'
%nonassoc ADDR UMINUS PTRR '!'
%nonassoc '[' '('

%token IFX UMINUS ADDR LOCAL INIT PUB PRIV CON TYPE MEM ATR NIL CONS DEF TYPEX PLCOM CSTR
%token DECL GLOBAL PTR PTRR FUNC PARAM BODY BPARAMS BPARAM ALLOC INSTR LOAD BSUB
%token INDEX CALL FACT NOT AINC ADEC BINC BDEC MUL DIV MOD ADD LT GT EQ AND OR ARG
%token INTEGERP NUMBERP STRINGP IDARGS COND EXP STOP ZERO

%type<n> decl def priv cons type initid params param optbody body bparams bparam updn stp optint instr instrs lvalue expr args


%%


file	: decl 									{ printNode($1, 0, yynames); }

decl   	:										{ $$ = nilNode(NIL); }
		| decl def								{ $$ = binNode(DECL, $1, $2); }
		;

def		: priv cons type ID initid ';'			{ $$ = binNode(INIT, binNode(DEF, binNode(TYPEX, binNode(PLCOM, $1, $2), $3), strNode(ID, $4)), $5); declareVar($3, $4, $5); }
		| priv cons type ID '(' params ')'		{ tempNode = binNode(DEF, binNode(TYPEX, binNode(PLCOM, $1, $2), $3), binNode(IDARGS, strNode(ID, $4), $6)); declareFunc($3, $4, $6); IDpush(); initFuncBody($4);}  optbody ';' { $$ = binNode(INIT, tempNode, $9); IDpop(); }
		| error ';'								{ $$ = nilNode(NIL); }
		| error '}'								{ $$ = nilNode(NIL); }
		;

priv	:										{ $$ = nilNode(NIL); }				
		| PUBLIC								{ $$ = nilNode(PUB); }
		;

cons 	:										{ $$ = nilNode(NIL); }
		| CONST									{ $$ = nilNode(CONS); }
		;



type	: INTEGER 								{ $$ = nilNode(INTEGER);  $$->info = INTEGER;}
		| NUMBER 								{ $$ = nilNode(NUMBER); $$->info = NUMBER; }
		| STRING 								{ $$ = nilNode(STRING); $$->info = STRING; }
		| INTEGER '*' 							{ $$ = nilNode(INTEGERP); $$->info = INTEGERP; }
		| NUMBER '*'							{ $$ = nilNode(NUMBERP); $$->info = NUMBERP; }
		| STRING '*'							{ $$ = nilNode(STRINGP); $$->info = STRINGP; }
		| VOID 									{ $$ = nilNode(VOID); $$->info = VOID; }
		;
		

initid	:										{ $$ = nilNode(NIL); $$->info = 0; }
		| ATR INT 								{ $$ = intNode(INT, $2); $$->info = INTEGER; }
		| ATR cons STR 							{ $$ = strNode(CSTR, $3); $$->info = STRING; }
		| ATR REAL 								{ $$ = realNode(REAL, $2); $$->info = NUMBER ;}
		| ATR ID 								{ $$ = strNode(ID, $2); $$->info = IDfind($2, 0); }
		;

params	:										{ $$ = nilNode(NIL); }
		| params ',' param 						{ $$ = binNode(PARAM, $1, $3); }
		| param 								{ $$ = binNode(PARAM, nilNode(NIL), $1); }
		;


param 	: type ID 								{ $$ = binNode(TYPE, $1, strNode(ID,$2));}
		;

bparam 	: type ID 								{ $$ = binNode(TYPE, $1, strNode(ID,$2)); declareVar($1, $2, 0); }
		;


optbody :										{ $$ = nilNode(NIL); }
		| body 									{ $$ = $1; }
		;

body	: '{' bparams instrs '}' 				{ $$ = binNode(BODY, $2, $3);}
		| error '}'								{ $$ = nilNode(NIL); }
		;

bparams :										{ $$ = nilNode(NIL); }
		| bparams bparam ';'					{ $$ = binNode(BPARAMS, $1, $2); }
		;


updn 	: UPTO expr								{ $$ = uniNode(UPTO, $2); }
		| DOWNTO expr 							{ $$ = uniNode(DOWNTO, $2); }
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
		| FOR lvalue IN expr updn stp DO instr { $$ = binNode(FOR, binNode(COND, binNode(EXP, $2, $4), binNode(STOP, $5, $6)), uniNode(DO, $8)); }
		| expr ';'								{ $$ = $1; }
		| body 									{ $$ = $1; }
		| BREAK optint ';' 						{ $$ = uniNode(BREAK, $2); }
		| CONTINUE optint ';' 					{ $$ = uniNode(CONTINUE, $2); }
		| lvalue '#' expr ';' 					{ $$ = binNode(ALLOC, $3, $1); }
		| error ';'								{ $$ = nilNode(NIL); }
		;

instrs  :										{ $$ = nilNode(NIL); }
		| instrs instr 							{ $$ = binNode(INSTR, $1, $2); }
		;

lvalue	: ID 									{ $$ = strNode(ID, $1); $$->info = IDfind($1, 0); }
		| lvalue '[' expr ']' 					{ $$ = binNode(INDEX, $1, $3); $$->info = indexVar($1->info, $3->info);}
		| '*' ID 								{ $$ = uniNode(LOAD, strNode(ID, $2)); $$-> info = usePtr($2); }
		;

expr	: lvalue								{ $$ = uniNode(LOAD, $1); $$->info = $1->info; }	
		| '(' expr ')'							{ $$ = $2; $$->info = $2->info; }
		| INT 									{ $$ = intNode(INT, $1); if ($1 == 0) $$->info = ZERO; else $$->info = INTEGER; }
		| STR 									{ $$ = strNode(STR, $1); $$->info = STRING; }
		| REAL 									{ $$ = realNode(REAL, $1); $$->info = NUMBER; }
		| ID '(' args ')'	 					{ $$ = binNode(CALL, strNode(ID, $1), $3); $$->info = callFunc($1, $3); }
		| ID '(' ')'							{ $$ = binNode(CALL, strNode(ID, $1), nilNode(NIL)); $$->info = callFunc($1, 0); }
      	| '-' expr %prec UMINUS					{ $$ = uniNode(UMINUS, $2); if($2->info !=INTEGER && $2->info != ZERO && $2->info !=NUMBER) {yyerror("Invalid type for opperand '-x'"); $$->info = INTEGER;} else $$->info=$2->info; }
      	| expr '!'								{ $$ = uniNode(FACT, $1); if($1->info !=INTEGER && $1->info != ZERO) yyerror("Invalid type for opperand '!'"); $$->info = INTEGER; }
		| '&' lvalue %prec ADDR					{ $$ = uniNode(PTR, $2); $$->info = getMem($2->info); }
		| '~' expr								{ $$ = uniNode(NOT, $2); if($2->info !=INTEGER && $2->info != ZERO) yyerror("Invalid type for opperand '~'"); $$->info = INTEGER; }
		| lvalue INCR							{ $$ = uniNode(AINC, $1); if($1->info !=INTEGER && $1->info != ZERO) yyerror("Invalid type for opperand '++'"); $$->info = INTEGER; }
		| lvalue DECR 							{ $$ = uniNode(ADEC, $1); if($1->info !=INTEGER && $1->info != ZERO) yyerror("Invalid type for opperand '--'"); $$->info = INTEGER; }
		| INCR lvalue							{ $$ = uniNode(BINC, $2); if($2->info !=INTEGER && $2->info != ZERO) yyerror("Invalid type for opperand '++'"); $$->info = INTEGER; }
		| DECR lvalue							{ $$ = uniNode(BDEC, $2); if($2->info !=INTEGER && $2->info != ZERO) yyerror("Invalid type for opperand '--'"); $$->info = INTEGER; }
     	| expr '*' expr							{ $$ = binNode(MUL, $1, $3); $$->info = checkBinIntNum($1->info, $3->info, "*"); }
     	| expr '/' expr							{ $$ = binNode(DIV, $1, $3); $$->info = checkBinIntNum($1->info, $3->info, "/"); }
     	| expr '%' expr							{ $$ = binNode(MOD, $1, $3); $$->info = checkBinIntNum($1->info, $3->info, "%"); }
    	| expr '+' expr							{ $$ = binNode(ADD, $1, $3); $$->info = checkBinIntNum($1->info, $3->info, "+"); }
    	| expr '-' expr							{ $$ = binNode(BSUB, $1, $3); $$->info = checkBinIntNum($1->info, $3->info, "-"); }
		| expr '<' expr							{ $$ = binNode(LT, $1, $3); $$->info = checkBinIntNumStr($1->info, $3->info, "<"); }
		| expr '>' expr							{ $$ = binNode(GT, $1, $3); $$->info = checkBinIntNumStr($1->info, $3->info, ">"); }
		| expr GE expr							{ $$ = binNode(GE, $1, $3); $$->info = checkBinIntNumStr($1->info, $3->info, ">="); }
		| expr LE expr							{ $$ = binNode(LE, $1, $3); $$->info = checkBinIntNumStr($1->info, $3->info, "<="); }
		| expr '=' expr							{ $$ = binNode(EQ, $1, $3); $$->info = checkBinIntNumStr($1->info, $3->info, "="); }
		| expr NE expr							{ $$ = binNode(NE, $1, $3); $$->info = checkBinIntNumStr($1->info, $3->info, "<>"); }
    	| expr '&' expr							{ $$ = binNode(AND, $1, $3); if($1->info !=INTEGER && $1->info != ZERO || $3->info !=INTEGER && $3->info != ZERO) yyerror("Invalid types for opperand '&'"); $$->info = INTEGER; }
    	| expr '|' expr							{ $$ = binNode(OR, $1, $3); if($1->info !=INTEGER && $1->info != ZERO || $3->info !=INTEGER && $3->info != ZERO) yyerror("Invalid types for opperand '|'"); $$->info = INTEGER; }
		| lvalue ATR expr						{ $$ = binNode(ATR, $3, $1); $$->info = checkAtr($1->info, $3->info); }
        ;

args	: expr									{ $$ = binNode(ARG, nilNode(NIL), $1); }
		| args ',' expr 						{ $$ = binNode(ARG, $1, $3); }
		;



%%

static void declareVar(Node *typ, char* id, Node *init) {

	if (typ->info == VOID) {
		sprintf(buf, "Variable %s cannot be of type VOID\n", id);
		yyerror(buf);
		return;
	}
	IDnew(OP_LABEL(typ), id, 0);
	if (init != 0 && init->info != 0 && OP_LABEL(typ) != init->info) {
		sprintf(buf, "Error assigning value to %s: Incompatible types.\n", id);
		yyerror(buf);
	}
}

static void declareFunc(Node *typ, char* id, Node* pars) {
	int type = 1000 + typ->info; /*type of function is 1000 + return type*/
	funcAttribs f = (funcAttribs) malloc(sizeof(struct fattrib));
	f->attribNum = 0;
	Node *aux;
	for (aux = pars; OP_LABEL(aux) != NIL; aux = LEFT_CHILD(aux)) {
		f->attribNum++;
	}
	f->attribNames = (char**) malloc(f->attribNum*sizeof(char*));
	f->attribTypes = (int*) malloc(f->attribNum*sizeof(int));
	f->attribNum = 0; /*lets use attribNum as index*/
	for (aux = pars; OP_LABEL(aux) != NIL; aux = LEFT_CHILD(aux)) {
		f->attribNames[f->attribNum] = RIGHT_CHILD(RIGHT_CHILD(aux))->value.s;
		f->attribTypes[f->attribNum] = LEFT_CHILD(RIGHT_CHILD(aux))->info;
		f->attribNum++;
	}
	IDnew(type, id, (long) f);
}


static int callFunc(char* name, Node *args) {
	/*when a function is called we need to check if it exists and the number and type of the arguments*/
	long f;
	int type = IDfind(name, &f) - 1000; /*we take 1000 to get the return type*/
	funcAttribs attr = (funcAttribs) f;
	int atNum = 0, i = 0;
	Node *aux;
	if (args != 0) {
		for (aux = args; OP_LABEL(aux) != NIL; aux = LEFT_CHILD(aux)) {
			atNum++;
		}
	}
	if (atNum != attr->attribNum) {
		sprintf(buf, "Error: Invalid number of arguments on call to function %s (expect %d, got %d\n", name, attr->attribNum, atNum);
		yyerror(buf);
	}
	if (args != 0) {
		for (aux = args; OP_LABEL(aux) != NIL; aux = LEFT_CHILD(aux)) {
			if (RIGHT_CHILD(aux)->info != attr->attribTypes[i]) {
				sprintf(buf, "Error: Invalid type of argument on call to function %s on position %d\n", name, i);
				yyerror(buf);
			}
		}
	}
	return type;
}

static void initFuncBody(char *funcName) {
	long fp;
	int typ = IDfind(funcName, &fp);
	funcAttribs attr = (funcAttribs) fp;
	int i;
	for (i=0; i< attr->attribNum; i++) {
		IDnew(attr->attribTypes[i], attr->attribNames[i], 0);
	}
}

static int usePtr(char *id) {
	int type = IDfind(id, 0);
	if (type > 1000 || type == INTEGER || type == NUMBER || type == ZERO ) {
		sprintf(buf, "Error: %s is not a pointer.\n", id);
		yyerror(buf);
	}
	if (type == STRING || type == INTEGERP) 
		return INTEGER;
	if (type == STRINGP)
		return STRING;
	if (type == NUMBERP)
		return NUMBER;
	return 0;
}

static int getMem(int type) {
	if (type == INTEGERP || type == NUMBERP || type == STRINGP || type == VOID) {
		yyerror("Cannot make pointer out of pointer or void (& opperand).");
	}
	if (type == STRING)
		return STRINGP;
	if (type == NUMBER)
		return NUMBERP;
	if (type == INTEGER || type == ZERO)
		return INTEGERP;
	return 0;
}

static int indexVar(int type, int ptr) { 
	if (ptr != INTEGER && ptr != ZERO) {
		sprintf(buf, "Error: Invalid index value (not an integer).\n");
		yyerror(buf);
	}

	if (type > 1000 || type == INTEGER || type == NUMBER || type == ZERO) {
		sprintf(buf, "Error: Unable to index (not a pointer or string).\n");
		yyerror(buf);
	}

	if (type == STRING || type == INTEGERP) 
		return INTEGER;
	if (type == STRINGP)
		return STRING;
	if (type == NUMBERP)
		return NUMBER;
	return 0;
}

static int checkBinIntNum(int t1, int t2, char* opp) {

	if (t1%1000 == STRING || t1%1000 == STRINGP || t1 == VOID || t2%1000 == STRING || t2%1000 == STRINGP || t2 == VOID ) {
		sprintf(buf, "Invalid type for opperand %s.\n", opp);
		yyerror(buf);
	}
	if (t1%1000 == NUMBER || t2%1000 == NUMBER)
		return NUMBER;
	return t1;
}

static int checkBinIntNumStr(int t1, int t2, char* opp) {
	if (t1 %1000 != t2%1000) {
		if (t1 %1000 != NUMBER || t2%1000 != INTEGER) {
			if (t1 %1000 != INTEGER || t2%1000 != NUMBER) {
				if (t1 %1000 != NUMBER || t2%1000 != ZERO) {
					if (t1 %1000 != INTEGER || t2%1000 != ZERO) {
						if (t1 %1000 != ZERO || t2%1000 != INTEGER) {
							if (t1 %1000 != ZERO || t2%1000 != NUMBER) {
								if (t1 %1000 != STRING || t2%1000 != ZERO) {
									if (t1 %1000 != ZERO || t2%1000 != STRING) {
										sprintf(buf, "Incompatible types for opperand %s (types not equal).\n", opp);
										yyerror(buf);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (t1%1000 != INTEGER && t1%1000 != NUMBER && t1%1000 != STRING && t1%1000 != ZERO) {
		sprintf(buf, "Invalid type for opperand %s.\n", opp);
		yyerror(buf);
	}
	return INTEGER;
}

static int checkAtr(int t1, int t2) {
	if (t1 % 1000 != t2 % 1000 && (t1%1000 != NUMBER || t2%1000 != INTEGER) && (t2 != ZERO || t1%1000 != INTEGER) && (t2 != ZERO || t1%1000 != NUMBER)  && (t1%1000 != INTEGER || t2 != ZERO) && (t1%1000 != NUMBER || t2 != ZERO) && (t1%1000 != STRING || t2 != ZERO))
	 	if ((t1%1000 != STRINGP || t2 != ZERO) && (t1%1000 != NUMBERP || t2 != ZERO) && (t1%1000 != INTEGERP || t2 != ZERO)) { /*we can make a pointer equal 0*/
	 		if (t1%1000 != STRING || t2 != INTEGERP) /*since str[x]=int, we need to allow cast of integerp to string*/
	 			yyerror("Invalid types for opperand ':='");
	 	}
	return t1;
}




char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif



