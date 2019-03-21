/*
generated at Thu Mar 21 11:56:24 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yystmt_NT 1

static YYCONST char *yyntname[] = {
	0,
	"stmt",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "END",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 258 */ "INTVALUE",
	/* 259 */ "NUMVALUE",
	/* 260 */ "IDENTIFIER",
	/* 261 */ "STRVALUE",
	/* 262 */ "IF",
	/* 263 */ "THEN",
	/* 264 */ "ELSE",
	/* 265 */ "DO",
	/* 266 */ "WHILE",
	/* 267 */ "FOR",
	/* 268 */ "IN",
	/* 269 */ "UPTO",
	/* 270 */ "DOWNTO",
	/* 271 */ "STEP",
	/* 272 */ "BREAK",
	/* 273 */ "CONTINUE",
	/* 274 */ "PUBLIC",
	/* 275 */ "CONST",
	/* 276 */ "INT",
	/* 277 */ "STR",
	/* 278 */ "NUM",
	/* 279 */ "VOID",
	/* 280 */ "INC",
	/* 281 */ "DEC",
	/* 282 */ "GE",
	/* 283 */ "LE",
	/* 284 */ "EQ",
	/* 285 */ "NE",
	/* 286 */ "ASSIGN",
	/* 287 */ "LF",
	""
};

struct yystate {
	short cost[2];
	struct {
		unsigned int yystmt:1;
	} rule;
};

static short yynts_0[] = { 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"stmt: END",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_stmt[] = {
	0,
	1,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 1)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}


static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* END */
		/* stmt: END */
		yytrace(a, 1, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 1;
		}
		break;
	case 257: /* INTVALUE */
		return;
	case 258: /* NUMVALUE */
		return;
	case 259: /* IDENTIFIER */
		return;
	case 260: /* STRVALUE */
		return;
	case 261: /* IF */
		return;
	case 262: /* THEN */
		return;
	case 263: /* ELSE */
		return;
	case 264: /* DO */
		return;
	case 265: /* WHILE */
		return;
	case 266: /* FOR */
		return;
	case 267: /* IN */
		return;
	case 268: /* UPTO */
		return;
	case 269: /* DOWNTO */
		return;
	case 270: /* STEP */
		return;
	case 271: /* BREAK */
		return;
	case 272: /* CONTINUE */
		return;
	case 273: /* PUBLIC */
		return;
	case 274: /* CONST */
		return;
	case 275: /* INT */
		return;
	case 276: /* STR */
		return;
	case 277: /* NUM */
		return;
	case 278: /* VOID */
		return;
	case 279: /* INC */
		return;
	case 280: /* DEC */
		return;
	case 281: /* GE */
		return;
	case 282: /* LE */
		return;
	case 283: /* EQ */
		return;
	case 284: /* NE */
		return;
	case 285: /* ASSIGN */
		return;
	case 286: /* LF */
		return;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 1: /* stmt: END */
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[0];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* stmt: END */
#line 13 "diy.brg"
{	}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yystmt == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 14 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;
