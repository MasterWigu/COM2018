/*
generated at Wed May 22 16:01:07 2019
by $Id: pburg.c,v 2.4 2014/02/12 17:04:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.4"
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

extern FILE *outfp;
char *dupstr(const char *s);

static long brklbl[20], brkcnt; /* break labels */
/* label _L0 is a break without a while/switch) */

static char *extrns[100]; /* emit externs at the end only */
static int extcnt;

int lbl;
char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strcpy(malloc(strlen(buf)+1),buf);
}

static void outstr(char *s) {
  while (*s) fprintf(outfp, pfCHAR, (unsigned char)*s++);
  fprintf(outfp, pfCHAR, 0);
}
static char *mkfunc(char *s) {
  static char buf[80];
  strcpy(buf, "_");
  strcat(buf, s);
  return buf;
}
#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);
static int doasm(Node *p) { return strcmp(LEFT_CHILD(LEFT_CHILD(p))->value.s, "asm") ? MAX_COST : 0 ; }
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yylist_NT 1
#define yybase_NT 2
#define yyexpr_NT 3
#define yyargs_NT 4
#define yylvalue_NT 5
#define yyassign_NT 6
#define yyand_NT 7
#define yyor_NT 8

static YYCONST char *yyntname[] = {
	0,
	"list",
	"base",
	"expr",
	"args",
	"lvalue",
	"assign",
	"and",
	"or",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "FACT",
 "", "", "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "PMS",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "COMMA",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "SC",
	/* 61 */ "LT",
	/* 62 */ "EQ",
	/* 63 */ "GT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "",
	/* 124 */ "BLK",
	/* 125 */ "OR",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "IFX",
	/* 282 */ "ELSE",
	/* 283 */ "ATR",
	/* 284 */ "NE",
	/* 285 */ "GE",
	/* 286 */ "LE",
	/* 287 */ "UMINUS",
	/* 288 */ "NOT",
	/* 289 */ "REF",
	/* 290 */ "LOCAL",
	/* 291 */ "POSINC",
	/* 292 */ "POSDEC",
	/* 293 */ "PTR",
	/* 294 */ "CALL",
	/* 295 */ "START",
	/* 296 */ "PARAM",
	/* 297 */ "NIL",
	""
};

struct yystate {
	short cost[9];
	struct {
		unsigned int yylist:2;
		unsigned int yybase:1;
		unsigned int yyexpr:5;
		unsigned int yyargs:2;
		unsigned int yylvalue:2;
		unsigned int yyassign:1;
		unsigned int yyand:1;
		unsigned int yyor:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yylist_NT, yybase_NT, 0 };
static short yynts_2[] = { yyexpr_NT, 0 };
static short yynts_3[] = { yyargs_NT, yyexpr_NT, 0 };
static short yynts_4[] = { yyassign_NT, yylvalue_NT, 0 };
static short yynts_5[] = { yylvalue_NT, 0 };
static short yynts_6[] = { yyargs_NT, 0 };
static short yynts_7[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_8[] = { yyand_NT, yyexpr_NT, 0 };
static short yynts_9[] = { yyor_NT, yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_0,	/* 4 */
	yynts_3,	/* 5 */
	yynts_0,	/* 6 */
	yynts_0,	/* 7 */
	yynts_2,	/* 8 */
	yynts_2,	/* 9 */
	yynts_2,	/* 10 */
	yynts_4,	/* 11 */
	yynts_5,	/* 12 */
	yynts_5,	/* 13 */
	yynts_0,	/* 14 */
	yynts_0,	/* 15 */
	yynts_0,	/* 16 */
	yynts_6,	/* 17 */
	yynts_7,	/* 18 */
	yynts_7,	/* 19 */
	yynts_7,	/* 20 */
	yynts_7,	/* 21 */
	yynts_7,	/* 22 */
	yynts_7,	/* 23 */
	yynts_7,	/* 24 */
	yynts_7,	/* 25 */
	yynts_7,	/* 26 */
	yynts_7,	/* 27 */
	yynts_7,	/* 28 */
	yynts_7,	/* 29 */
	yynts_2,	/* 30 */
	yynts_2,	/* 31 */
	yynts_8,	/* 32 */
	yynts_2,	/* 33 */
	yynts_9,	/* 34 */
	yynts_2,	/* 35 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"list: NIL",
/* 2 */	"list: SC(list,base)",
/* 3 */	"base: expr",
/* 4 */	"args: NIL",
/* 5 */	"args: COMMA(args,expr)",
/* 6 */	"lvalue: ID",
/* 7 */	"lvalue: LOCAL",
/* 8 */	"expr: ATR(expr,LOCAL)",
/* 9 */	"expr: ATR(expr,ID)",
/* 10 */	"assign: expr",
/* 11 */	"expr: ATR(assign,lvalue)",
/* 12 */	"expr: PTR(lvalue)",
/* 13 */	"expr: REF(lvalue)",
/* 14 */	"expr: INT",
/* 15 */	"expr: REAL",
/* 16 */	"expr: STR",
/* 17 */	"expr: CALL(ID,args)",
/* 18 */	"expr: ADD(expr,expr)",
/* 19 */	"expr: SUB(expr,expr)",
/* 20 */	"expr: MUL(expr,expr)",
/* 21 */	"expr: DIV(expr,expr)",
/* 22 */	"expr: MOD(expr,expr)",
/* 23 */	"expr: OR(expr,expr)",
/* 24 */	"expr: EQ(expr,expr)",
/* 25 */	"expr: NE(expr,expr)",
/* 26 */	"expr: LT(expr,expr)",
/* 27 */	"expr: LE(expr,expr)",
/* 28 */	"expr: GT(expr,expr)",
/* 29 */	"expr: GE(expr,expr)",
/* 30 */	"expr: UMINUS(expr)",
/* 31 */	"expr: NOT(expr)",
/* 32 */	"expr: AND(and,expr)",
/* 33 */	"and: expr",
/* 34 */	"expr: OR(or,expr)",
/* 35 */	"or: expr",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_list[] = {
	0,
	1,
	2,
};

static short yydecode_base[] = {
	0,
	3,
};

static short yydecode_expr[] = {
	0,
	8,
	9,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
	27,
	28,
	29,
	30,
	31,
	32,
	34,
};

static short yydecode_args[] = {
	0,
	4,
	5,
};

static short yydecode_lvalue[] = {
	0,
	6,
	7,
};

static short yydecode_assign[] = {
	0,
	10,
};

static short yydecode_and[] = {
	0,
	33,
};

static short yydecode_or[] = {
	0,
	35,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 8)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyargs_NT:	return yydecode_args[((struct yystate *)state)->rule.yyargs];
	case yylvalue_NT:	return yydecode_lvalue[((struct yystate *)state)->rule.yylvalue];
	case yyassign_NT:	return yydecode_assign[((struct yystate *)state)->rule.yyassign];
	case yyand_NT:	return yydecode_and[((struct yystate *)state)->rule.yyand];
	case yyor_NT:	return yydecode_or[((struct yystate *)state)->rule.yyor];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_expr(NODEPTR_TYPE, int);

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 35, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 33, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 10, c + 1, p->cost[yyassign_NT]);
	if (c + 1 < p->cost[yyassign_NT]) {
		p->cost[yyassign_NT] = c + 1;
		p->rule.yyassign = 1;
	}
	yytrace(a, 3, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
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
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACT */
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 22, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: AND(and,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyand_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 24;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 40: /* PMS */
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 20, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 18, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 44: /* COMMA */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* args: COMMA(args,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 5, c + 0, p->cost[yyargs_NT]);
		if (c + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = c + 0;
			p->rule.yyargs = 2;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 19, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 21, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 59: /* SC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* list: SC(list,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 0;
		yytrace(a, 2, c + 0, p->cost[yylist_NT]);
		if (c + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = c + 0;
			p->rule.yylist = 2;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 24, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 16;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 28, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 123: /* BLK */
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 23, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 15;
			yyclosure_expr(a, c + 0);
		}
		/* expr: OR(or,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 25;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* expr: INT */
		yytrace(a, 14, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* expr: REAL */
		yytrace(a, 15, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		/* lvalue: ID */
		yytrace(a, 6, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
		}
		break;
	case 260: /* STR */
		/* expr: STR */
		yytrace(a, 16, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		break;
	case 262: /* WHILE */
		break;
	case 263: /* IF */
		break;
	case 264: /* THEN */
		break;
	case 265: /* FOR */
		break;
	case 266: /* IN */
		break;
	case 267: /* UPTO */
		break;
	case 268: /* DOWNTO */
		break;
	case 269: /* STEP */
		break;
	case 270: /* BREAK */
		break;
	case 271: /* CONTINUE */
		break;
	case 272: /* VOID */
		break;
	case 273: /* INTEGER */
		break;
	case 274: /* STRING */
		break;
	case 275: /* NUMBER */
		break;
	case 276: /* CONST */
		break;
	case 277: /* PUBLIC */
		break;
	case 278: /* INCR */
		break;
	case 279: /* DECR */
		break;
	case 280: /* IFX */
		break;
	case 281: /* ELSE */
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: ATR(expr,LOCAL) */
			OP_LABEL(RIGHT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 8, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: ATR(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 9, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 2;
				yyclosure_expr(a, c + 0);
			}
		}
		/* expr: ATR(assign,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 11, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 3;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 29, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 21;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 27, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 30, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 31, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 23;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 288: /* REF */
		yylabel(LEFT_CHILD(a),a);
		/* expr: REF(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 0;
		yytrace(a, 13, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 5;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 289: /* LOCAL */
		/* lvalue: LOCAL */
		yytrace(a, 7, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 2;
		}
		break;
	case 290: /* POSINC */
		break;
	case 291: /* POSDEC */
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: PTR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 12, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 4;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
			yytrace(a, 17, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 9;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		break;
	case 295: /* PARAM */
		break;
	case 296: /* NIL */
		/* list: NIL */
		yytrace(a, 1, 0 + 0, p->cost[yylist_NT]);
		if (0 + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = 0 + 0;
			p->rule.yylist = 1;
		}
		/* args: NIL */
		yytrace(a, 4, 0 + 0, p->cost[yyargs_NT]);
		if (0 + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = 0 + 0;
			p->rule.yyargs = 1;
		}
		break;
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
	case 16: /* expr: STR */
	case 15: /* expr: REAL */
	case 14: /* expr: INT */
	case 7: /* lvalue: LOCAL */
	case 6: /* lvalue: ID */
	case 4: /* args: NIL */
	case 1: /* list: NIL */
		break;
	case 34: /* expr: OR(or,expr) */
	case 32: /* expr: AND(and,expr) */
	case 29: /* expr: GE(expr,expr) */
	case 28: /* expr: GT(expr,expr) */
	case 27: /* expr: LE(expr,expr) */
	case 26: /* expr: LT(expr,expr) */
	case 25: /* expr: NE(expr,expr) */
	case 24: /* expr: EQ(expr,expr) */
	case 23: /* expr: OR(expr,expr) */
	case 22: /* expr: MOD(expr,expr) */
	case 21: /* expr: DIV(expr,expr) */
	case 20: /* expr: MUL(expr,expr) */
	case 19: /* expr: SUB(expr,expr) */
	case 18: /* expr: ADD(expr,expr) */
	case 11: /* expr: ATR(assign,lvalue) */
	case 5: /* args: COMMA(args,expr) */
	case 2: /* list: SC(list,base) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 35: /* or: expr */
	case 33: /* and: expr */
	case 10: /* assign: expr */
	case 3: /* base: expr */
		kids[0] = p;
		break;
	case 31: /* expr: NOT(expr) */
	case 30: /* expr: UMINUS(expr) */
	case 13: /* expr: REF(lvalue) */
	case 12: /* expr: PTR(lvalue) */
	case 9: /* expr: ATR(expr,ID) */
	case 8: /* expr: ATR(expr,LOCAL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 17: /* expr: CALL(ID,args) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[2];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* list: NIL */
#line 61 "diy.brg"

		break;
	case 2: /* list: SC(list,base) */
#line 62 "diy.brg"

		break;
	case 3: /* base: expr */
#line 65 "diy.brg"
{ fprintf(outfp, pfTRASH, pfWORD); }
		break;
	case 4: /* args: NIL */
#line 67 "diy.brg"
{ p->place = 0; }
		break;
	case 5: /* args: COMMA(args,expr) */
#line 68 "diy.brg"
{ p->place =  ((LEFT_CHILD(p)->place) + 1); }
		break;
	case 6: /* lvalue: ID */
#line 71 "diy.brg"
{ fprintf(outfp, pfADDR, p->value.s); }
		break;
	case 7: /* lvalue: LOCAL */
#line 72 "diy.brg"
{ fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4)); }
		break;
	case 8: /* expr: ATR(expr,LOCAL) */
#line 74 "diy.brg"
{ fprintf(outfp, pfDUP pfLOCA, RIGHT_CHILD(p)->value.i * (pfWORD/4)); }
		break;
	case 9: /* expr: ATR(expr,ID) */
#line 75 "diy.brg"
{ fprintf(outfp, pfDUP pfADDRA, RIGHT_CHILD(p)->value.s); }
		break;
	case 10: /* assign: expr */
#line 76 "diy.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 11: /* expr: ATR(assign,lvalue) */
#line 77 "diy.brg"
{ fprintf(outfp, pfSTORE); }
		break;
	case 12: /* expr: PTR(lvalue) */
#line 78 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 13: /* expr: REF(lvalue) */
#line 79 "diy.brg"
{ /* No code, but keep PTR to avoid missing LOADs */ }
		break;
	case 14: /* expr: INT */
#line 81 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 15: /* expr: REAL */
#line 82 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 16: /* expr: STR */
#line 83 "diy.brg"
{ lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 17: /* expr: CALL(ID,args) */
#line 84 "diy.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)(pfWORD*(RIGHT_CHILD(p)->place))); }
		break;
	case 18: /* expr: ADD(expr,expr) */
#line 86 "diy.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 19: /* expr: SUB(expr,expr) */
#line 87 "diy.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 20: /* expr: MUL(expr,expr) */
#line 88 "diy.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 21: /* expr: DIV(expr,expr) */
#line 89 "diy.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 22: /* expr: MOD(expr,expr) */
#line 90 "diy.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 23: /* expr: OR(expr,expr) */
#line 91 "diy.brg"
{ fprintf(outfp, pfOR); }
		break;
	case 24: /* expr: EQ(expr,expr) */
#line 93 "diy.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 25: /* expr: NE(expr,expr) */
#line 94 "diy.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 26: /* expr: LT(expr,expr) */
#line 95 "diy.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 27: /* expr: LE(expr,expr) */
#line 96 "diy.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 28: /* expr: GT(expr,expr) */
#line 97 "diy.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 29: /* expr: GE(expr,expr) */
#line 98 "diy.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 30: /* expr: UMINUS(expr) */
#line 99 "diy.brg"
{ fprintf(outfp, pfNEG); }
		break;
	case 31: /* expr: NOT(expr) */
#line 100 "diy.brg"
{ fprintf(outfp, pfIMM pfEQ, 0); }
		break;
	case 32: /* expr: AND(and,expr) */
#line 101 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 33: /* and: expr */
#line 102 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 34: /* expr: OR(or,expr) */
#line 103 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 35: /* or: expr */
#line 104 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yylist == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 112 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;


void externs() {
	int i;

	for (i = 0; i < extcnt; i++)
		if (extrns[i])
			fprintf(outfp, pfEXTRN, extrns[i]);
}


/*void declare(int pub, int cnst, Node *type, char *name, Node *value)*/
void variable(char *name, Node *type, Node *init, int cnst) {
	int i = 0, siz = 1;
	if (cnst)
		fprintf(outfp, pfRODATA pfALIGN pfLABEL pfGLOBL, name, name, pfOBJ);
	else
		fprintf(outfp, pfDATA pfALIGN pfLABEL pfGLOBL, name, name, pfOBJ);


	if (init) {
		printf("AAAAAAAAAAA %d\n", init->info);
		switch (init->info) {
			case 1: 
				fprintf(outfp, pfINTEGER, init->value.i);
				break;
			case 3: 
				fprintf(outfp, pfDOUBLE, init->value.r);
				break;
			case 2: { 
				char *l = mklbl(++lbl);
				fprintf(outfp, pfID, l);
				fprintf(outfp, pfDATA pfALIGN pfLABEL, l);
				outstr(init->value.s);
				break;
			} 
			case 7: { 
				char *l = mklbl(++lbl);
				fprintf(outfp, pfID, l);
				fprintf(outfp, pfRODATA pfALIGN pfLABEL, l);
				outstr(init->value.s);
				break;
			}
			default:
				fprintf(outfp, pfID, init->value.s);
				break;
		}   
	}
	else {
		printf("BBBBBBBBB\n");
		switch (type->value.i) {
			case 1: 
				fprintf(outfp, pfINTEGER, 0);
				break;
			case 2: 
				fprintf(outfp, pfINTEGER, 0); /*aka null pointer to string*/
				break;
			case 3:
				fprintf(outfp, pfDOUBLE, 0.0);
				break;
			default: /*only occurs when value.i > 10, aka pointers*/
				fprintf(outfp, pfINTEGER, 0); /*aka null pointer to string*/
				break;
		} 
	}

	for (i = 0; i < extcnt; i++)
		if (init && extrns[i] && strcmp(extrns[i], name) == 0) extrns[i] = 0;
}


void function(char *name, int enter, Node *body, int tVoid) {
	if (body->attrib == NIL) {
		extrns[extcnt++] = dupstr(mkfunc(name));
		return;
	}

	Node *stmt = LEFT_CHILD(body);

	int i;
	extern int errors, trace;
	extern char **yynames;
	if (errors) return;
	if (trace) printNode(stmt, 0, yynames);
	fflush(stdout);
	fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), enter * (pfWORD/4));
	yyselect(stmt);
	if (!tVoid)
		fprintf(outfp, pfLOCV pfPOP pfLEAVE pfRET, -4);
	else
		fprintf(outfp, pfPOP pfLEAVE pfRET);
	/*fprintf(outfp, pfLEAVE pfRET); /* just in case ... */
	freeNode(stmt);
	for (i = 0; i < extcnt; i++) {
		if (stmt->attrib != NIL && extrns[i] && strcmp(extrns[i], mkfunc(name)) == 0) extrns[i] = 0;
	}
}





#ifndef NOTRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost) {
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
	if (cost >= MAX_COST && bestcost >= MAX_COST) {
		extern char **yynames;
		fprintf(stderr, "0x%lx:%s NO MATCH %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
		printNode(p, 0, yynames);
	}
}
#endif

