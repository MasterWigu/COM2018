/*
generated at Thu May 23 00:25:25 2019
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
#define yylvec_NT 6
#define yyassign_NT 7
#define yyalloc_NT 8
#define yyand_NT 9
#define yyor_NT 10
#define yyif_NT 11
#define yycond_NT 12

static YYCONST char *yyntname[] = {
	0,
	"list",
	"base",
	"expr",
	"args",
	"lvalue",
	"lvec",
	"assign",
	"alloc",
	"and",
	"or",
	"if",
	"cond",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "FACT",
 "",
	/* 36 */ "ALLOC",
 "",
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
 "", "", "", "",
	/* 92 */ "INDEX",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "",
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
	short cost[13];
	struct {
		unsigned int yylist:2;
		unsigned int yybase:3;
		unsigned int yyexpr:5;
		unsigned int yyargs:2;
		unsigned int yylvalue:3;
		unsigned int yylvec:1;
		unsigned int yyassign:1;
		unsigned int yyalloc:1;
		unsigned int yyand:1;
		unsigned int yyor:1;
		unsigned int yyif:1;
		unsigned int yycond:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yylist_NT, yybase_NT, 0 };
static short yynts_2[] = { yyexpr_NT, 0 };
static short yynts_3[] = { yyargs_NT, yyexpr_NT, 0 };
static short yynts_4[] = { yylvalue_NT, 0 };
static short yynts_5[] = { yylvec_NT, yyexpr_NT, 0 };
static short yynts_6[] = { yyassign_NT, yylvalue_NT, 0 };
static short yynts_7[] = { yyalloc_NT, yylvalue_NT, 0 };
static short yynts_8[] = { yyargs_NT, 0 };
static short yynts_9[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_10[] = { yyand_NT, yyexpr_NT, 0 };
static short yynts_11[] = { yyor_NT, yyexpr_NT, 0 };
static short yynts_12[] = { yyif_NT, yybase_NT, 0 };
static short yynts_13[] = { yycond_NT, yybase_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_0,	/* 4 */
	yynts_0,	/* 5 */
	yynts_3,	/* 6 */
	yynts_0,	/* 7 */
	yynts_0,	/* 8 */
	yynts_4,	/* 9 */
	yynts_4,	/* 10 */
	yynts_4,	/* 11 */
	yynts_5,	/* 12 */
	yynts_4,	/* 13 */
	yynts_4,	/* 14 */
	yynts_2,	/* 15 */
	yynts_2,	/* 16 */
	yynts_2,	/* 17 */
	yynts_6,	/* 18 */
	yynts_0,	/* 19 */
	yynts_7,	/* 20 */
	yynts_2,	/* 21 */
	yynts_0,	/* 22 */
	yynts_0,	/* 23 */
	yynts_0,	/* 24 */
	yynts_8,	/* 25 */
	yynts_9,	/* 26 */
	yynts_9,	/* 27 */
	yynts_9,	/* 28 */
	yynts_9,	/* 29 */
	yynts_9,	/* 30 */
	yynts_9,	/* 31 */
	yynts_9,	/* 32 */
	yynts_9,	/* 33 */
	yynts_9,	/* 34 */
	yynts_9,	/* 35 */
	yynts_9,	/* 36 */
	yynts_9,	/* 37 */
	yynts_2,	/* 38 */
	yynts_2,	/* 39 */
	yynts_10,	/* 40 */
	yynts_2,	/* 41 */
	yynts_11,	/* 42 */
	yynts_2,	/* 43 */
	yynts_12,	/* 44 */
	yynts_13,	/* 45 */
	yynts_13,	/* 46 */
	yynts_2,	/* 47 */
	yynts_4,	/* 48 */
	yynts_4,	/* 49 */
	yynts_4,	/* 50 */
	yynts_4,	/* 51 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"list: NIL",
/* 2 */	"list: SC(list,base)",
/* 3 */	"base: expr",
/* 4 */	"args: NIL",
/* 5 */	"args: VOID",
/* 6 */	"args: COMMA(args,expr)",
/* 7 */	"lvalue: ID",
/* 8 */	"lvalue: LOCAL",
/* 9 */	"expr: PTR(lvalue)",
/* 10 */	"expr: REF(lvalue)",
/* 11 */	"lvec: lvalue",
/* 12 */	"lvalue: INDEX(lvec,expr)",
/* 13 */	"lvalue: PTR(lvalue)",
/* 14 */	"expr: PTR(lvalue)",
/* 15 */	"expr: ATR(expr,LOCAL)",
/* 16 */	"expr: ATR(expr,ID)",
/* 17 */	"assign: expr",
/* 18 */	"expr: ATR(assign,lvalue)",
/* 19 */	"expr: ID",
/* 20 */	"base: ALLOC(alloc,lvalue)",
/* 21 */	"alloc: expr",
/* 22 */	"expr: INT",
/* 23 */	"expr: REAL",
/* 24 */	"expr: STR",
/* 25 */	"expr: CALL(ID,args)",
/* 26 */	"expr: ADD(expr,expr)",
/* 27 */	"expr: SUB(expr,expr)",
/* 28 */	"expr: MUL(expr,expr)",
/* 29 */	"expr: DIV(expr,expr)",
/* 30 */	"expr: MOD(expr,expr)",
/* 31 */	"expr: OR(expr,expr)",
/* 32 */	"expr: EQ(expr,expr)",
/* 33 */	"expr: NE(expr,expr)",
/* 34 */	"expr: LT(expr,expr)",
/* 35 */	"expr: LE(expr,expr)",
/* 36 */	"expr: GT(expr,expr)",
/* 37 */	"expr: GE(expr,expr)",
/* 38 */	"expr: UMINUS(expr)",
/* 39 */	"expr: NOT(expr)",
/* 40 */	"expr: AND(and,expr)",
/* 41 */	"and: expr",
/* 42 */	"expr: OR(or,expr)",
/* 43 */	"or: expr",
/* 44 */	"base: ELSE(if,base)",
/* 45 */	"if: IF(cond,base)",
/* 46 */	"base: IF(cond,base)",
/* 47 */	"cond: expr",
/* 48 */	"expr: INCR(lvalue)",
/* 49 */	"expr: DECR(lvalue)",
/* 50 */	"expr: POSINC(lvalue)",
/* 51 */	"expr: POSDEC(lvalue)",
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
	20,
	44,
	46,
};

static short yydecode_expr[] = {
	0,
	9,
	10,
	14,
	15,
	16,
	18,
	19,
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
	33,
	34,
	35,
	36,
	37,
	38,
	39,
	40,
	42,
	48,
	49,
	50,
	51,
};

static short yydecode_args[] = {
	0,
	4,
	5,
	6,
};

static short yydecode_lvalue[] = {
	0,
	7,
	8,
	12,
	13,
};

static short yydecode_lvec[] = {
	0,
	11,
};

static short yydecode_assign[] = {
	0,
	17,
};

static short yydecode_alloc[] = {
	0,
	21,
};

static short yydecode_and[] = {
	0,
	41,
};

static short yydecode_or[] = {
	0,
	43,
};

static short yydecode_if[] = {
	0,
	45,
};

static short yydecode_cond[] = {
	0,
	47,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 12)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyargs_NT:	return yydecode_args[((struct yystate *)state)->rule.yyargs];
	case yylvalue_NT:	return yydecode_lvalue[((struct yystate *)state)->rule.yylvalue];
	case yylvec_NT:	return yydecode_lvec[((struct yystate *)state)->rule.yylvec];
	case yyassign_NT:	return yydecode_assign[((struct yystate *)state)->rule.yyassign];
	case yyalloc_NT:	return yydecode_alloc[((struct yystate *)state)->rule.yyalloc];
	case yyand_NT:	return yydecode_and[((struct yystate *)state)->rule.yyand];
	case yyor_NT:	return yydecode_or[((struct yystate *)state)->rule.yyor];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_lvalue(NODEPTR_TYPE, int);

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 47, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 43, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 41, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 21, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 17, c + 1, p->cost[yyassign_NT]);
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

static void yyclosure_lvalue(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 1, p->cost[yylvec_NT]);
	if (c + 1 < p->cost[yylvec_NT]) {
		p->cost[yylvec_NT] = c + 1;
		p->rule.yylvec = 1;
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
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACT */
		return;
	case 35: /* ALLOC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base: ALLOC(alloc,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyalloc_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 20, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 2;
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 30, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 16;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: AND(and,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyand_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 26;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 40: /* PMS */
		return;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 28, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 44: /* COMMA */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* args: COMMA(args,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 6, c + 0, p->cost[yyargs_NT]);
		if (c + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = c + 0;
			p->rule.yyargs = 3;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 27, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 29, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 15;
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
		yytrace(a, 34, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 36, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* lvalue: INDEX(lvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 12, c + 0, p->cost[yylvalue_NT]);
		if (c + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = c + 0;
			p->rule.yylvalue = 3;
			yyclosure_lvalue(a, c + 0);
		}
		break;
	case 123: /* BLK */
		return;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 31, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		/* expr: OR(or,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 27;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* expr: INT */
		yytrace(a, 22, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* expr: REAL */
		yytrace(a, 23, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		/* lvalue: ID */
		yytrace(a, 7, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
			yyclosure_lvalue(a, 1 + 0);
		}
		/* expr: ID */
		yytrace(a, 19, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* expr: STR */
		yytrace(a, 24, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		return;
	case 262: /* WHILE */
		return;
	case 263: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* if: IF(cond,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* base: IF(cond,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 46, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 4;
		}
		break;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		return;
	case 266: /* IN */
		return;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		return;
	case 271: /* CONTINUE */
		return;
	case 272: /* VOID */
		/* args: VOID */
		yytrace(a, 5, 0 + 0, p->cost[yyargs_NT]);
		if (0 + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = 0 + 0;
			p->rule.yyargs = 2;
		}
		break;
	case 273: /* INTEGER */
		return;
	case 274: /* STRING */
		return;
	case 275: /* NUMBER */
		return;
	case 276: /* CONST */
		return;
	case 277: /* PUBLIC */
		return;
	case 278: /* INCR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: INCR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 48, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 28;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: DECR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 49, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 29;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 280: /* IFX */
		return;
	case 281: /* ELSE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base: ELSE(if,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 44, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 3;
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: ATR(expr,LOCAL) */
			OP_LABEL(RIGHT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 15, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: ATR(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 16, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		/* expr: ATR(assign,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 18, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 23;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 21;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 24;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 25;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 288: /* REF */
		yylabel(LEFT_CHILD(a),a);
		/* expr: REF(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 0;
		yytrace(a, 10, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 2;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 289: /* LOCAL */
		/* lvalue: LOCAL */
		yytrace(a, 8, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 2;
			yyclosure_lvalue(a, 1 + 0);
		}
		break;
	case 290: /* POSINC */
		yylabel(LEFT_CHILD(a),a);
		/* expr: POSINC(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 50, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 30;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* expr: POSDEC(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 51, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 31;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: PTR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 9, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 1;
			yyclosure_expr(a, c + 0);
		}
		/* lvalue: PTR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 13, c + 0, p->cost[yylvalue_NT]);
		if (c + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = c + 0;
			p->rule.yylvalue = 4;
			yyclosure_lvalue(a, c + 0);
		}
		/* expr: PTR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 14, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 3;
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
			yytrace(a, 25, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 11;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		return;
	case 295: /* PARAM */
		return;
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
	case 24: /* expr: STR */
	case 23: /* expr: REAL */
	case 22: /* expr: INT */
	case 19: /* expr: ID */
	case 8: /* lvalue: LOCAL */
	case 7: /* lvalue: ID */
	case 5: /* args: VOID */
	case 4: /* args: NIL */
	case 1: /* list: NIL */
		break;
	case 46: /* base: IF(cond,base) */
	case 45: /* if: IF(cond,base) */
	case 44: /* base: ELSE(if,base) */
	case 42: /* expr: OR(or,expr) */
	case 40: /* expr: AND(and,expr) */
	case 37: /* expr: GE(expr,expr) */
	case 36: /* expr: GT(expr,expr) */
	case 35: /* expr: LE(expr,expr) */
	case 34: /* expr: LT(expr,expr) */
	case 33: /* expr: NE(expr,expr) */
	case 32: /* expr: EQ(expr,expr) */
	case 31: /* expr: OR(expr,expr) */
	case 30: /* expr: MOD(expr,expr) */
	case 29: /* expr: DIV(expr,expr) */
	case 28: /* expr: MUL(expr,expr) */
	case 27: /* expr: SUB(expr,expr) */
	case 26: /* expr: ADD(expr,expr) */
	case 20: /* base: ALLOC(alloc,lvalue) */
	case 18: /* expr: ATR(assign,lvalue) */
	case 12: /* lvalue: INDEX(lvec,expr) */
	case 6: /* args: COMMA(args,expr) */
	case 2: /* list: SC(list,base) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 47: /* cond: expr */
	case 43: /* or: expr */
	case 41: /* and: expr */
	case 21: /* alloc: expr */
	case 17: /* assign: expr */
	case 11: /* lvec: lvalue */
	case 3: /* base: expr */
		kids[0] = p;
		break;
	case 51: /* expr: POSDEC(lvalue) */
	case 50: /* expr: POSINC(lvalue) */
	case 49: /* expr: DECR(lvalue) */
	case 48: /* expr: INCR(lvalue) */
	case 39: /* expr: NOT(expr) */
	case 38: /* expr: UMINUS(expr) */
	case 16: /* expr: ATR(expr,ID) */
	case 15: /* expr: ATR(expr,LOCAL) */
	case 14: /* expr: PTR(lvalue) */
	case 13: /* lvalue: PTR(lvalue) */
	case 10: /* expr: REF(lvalue) */
	case 9: /* expr: PTR(lvalue) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 25: /* expr: CALL(ID,args) */
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
#line 47 "diy.brg"

		break;
	case 2: /* list: SC(list,base) */
#line 48 "diy.brg"

		break;
	case 3: /* base: expr */
#line 51 "diy.brg"
{ fprintf(outfp, pfTRASH, pfWORD); }
		break;
	case 4: /* args: NIL */
#line 53 "diy.brg"
{ p->place = 0; }
		break;
	case 5: /* args: VOID */
#line 54 "diy.brg"
{ p->place = 0; }
		break;
	case 6: /* args: COMMA(args,expr) */
#line 55 "diy.brg"
{ p->place =  ((LEFT_CHILD(p)->place) + 1); }
		break;
	case 7: /* lvalue: ID */
#line 58 "diy.brg"
{ fprintf(outfp, pfADDR, p->value.s); }
		break;
	case 8: /* lvalue: LOCAL */
#line 59 "diy.brg"
{ fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4)); }
		break;
	case 9: /* expr: PTR(lvalue) */
#line 60 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 10: /* expr: REF(lvalue) */
#line 61 "diy.brg"
{ /* No code, but keep PTR to avoid missing LOADs */ }
		break;
	case 11: /* lvec: lvalue */
#line 62 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 12: /* lvalue: INDEX(lvec,expr) */
#line 63 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, pfWORD); }
		break;
	case 13: /* lvalue: PTR(lvalue) */
#line 64 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 14: /* expr: PTR(lvalue) */
#line 65 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 15: /* expr: ATR(expr,LOCAL) */
#line 68 "diy.brg"
{ fprintf(outfp, pfDUP pfLOCA, RIGHT_CHILD(p)->value.i * (pfWORD/4)); }
		break;
	case 16: /* expr: ATR(expr,ID) */
#line 69 "diy.brg"
{ fprintf(outfp, pfDUP pfADDRA, RIGHT_CHILD(p)->value.s); }
		break;
	case 17: /* assign: expr */
#line 70 "diy.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 18: /* expr: ATR(assign,lvalue) */
#line 71 "diy.brg"
{ fprintf(outfp, pfSTORE); }
		break;
	case 19: /* expr: ID */
#line 72 "diy.brg"
{ fprintf(outfp, pfADDRV, p->value.s); }
		break;
	case 20: /* base: ALLOC(alloc,lvalue) */
#line 73 "diy.brg"
{ fprintf(outfp, pfSTORE); }
		break;
	case 21: /* alloc: expr */
#line 74 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 22: /* expr: INT */
#line 78 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 23: /* expr: REAL */
#line 79 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 24: /* expr: STR */
#line 80 "diy.brg"
{ lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 25: /* expr: CALL(ID,args) */
#line 81 "diy.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)(pfWORD*(RIGHT_CHILD(p)->place))); }
		break;
	case 26: /* expr: ADD(expr,expr) */
#line 83 "diy.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 27: /* expr: SUB(expr,expr) */
#line 84 "diy.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 28: /* expr: MUL(expr,expr) */
#line 85 "diy.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 29: /* expr: DIV(expr,expr) */
#line 86 "diy.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 30: /* expr: MOD(expr,expr) */
#line 87 "diy.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 31: /* expr: OR(expr,expr) */
#line 88 "diy.brg"
{ fprintf(outfp, pfOR); }
		break;
	case 32: /* expr: EQ(expr,expr) */
#line 89 "diy.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 33: /* expr: NE(expr,expr) */
#line 90 "diy.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 34: /* expr: LT(expr,expr) */
#line 91 "diy.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 35: /* expr: LE(expr,expr) */
#line 92 "diy.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 36: /* expr: GT(expr,expr) */
#line 93 "diy.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 37: /* expr: GE(expr,expr) */
#line 94 "diy.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 38: /* expr: UMINUS(expr) */
#line 95 "diy.brg"
{ fprintf(outfp, pfNEG); }
		break;
	case 39: /* expr: NOT(expr) */
#line 96 "diy.brg"
{ fprintf(outfp, pfIMM pfEQ, 0); }
		break;
	case 40: /* expr: AND(and,expr) */
#line 97 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 41: /* and: expr */
#line 98 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 42: /* expr: OR(or,expr) */
#line 99 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 43: /* or: expr */
#line 100 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 44: /* base: ELSE(if,base) */
#line 105 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 45: /* if: IF(cond,base) */
#line 106 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 46: /* base: IF(cond,base) */
#line 108 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 47: /* cond: expr */
#line 109 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place)); }
		break;
	case 48: /* expr: INCR(lvalue) */
#line 115 "diy.brg"
{ fprintf(outfp, pfDUP pfINCR pfLOAD, 1); }
		break;
	case 49: /* expr: DECR(lvalue) */
#line 116 "diy.brg"
{ fprintf(outfp, pfDUP pfDECR pfLOAD, 1); }
		break;
	case 50: /* expr: POSINC(lvalue) */
#line 117 "diy.brg"
{ fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1); }
		break;
	case 51: /* expr: POSDEC(lvalue) */
#line 118 "diy.brg"
{ fprintf(outfp, pfDUP pfLOAD pfSWAP pfDECR, 1); }
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


#line 123 "diy.brg"

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

