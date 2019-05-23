/*
generated at Thu May 23 12:58:52 2019
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
#define yybloco_NT 3
#define yylistend_NT 4
#define yydecls_NT 5
#define yybrk_NT 6
#define yyparam_NT 7
#define yystmt_NT 8
#define yyexpr_NT 9
#define yyargs_NT 10
#define yylvalue_NT 11
#define yylvec_NT 12
#define yyassign_NT 13
#define yyalloc_NT 14
#define yyand_NT 15
#define yyor_NT 16
#define yyif_NT 17
#define yycond_NT 18
#define yydo_NT 19
#define yybegin_NT 20

static YYCONST char *yyntname[] = {
	0,
	"list",
	"base",
	"bloco",
	"listend",
	"decls",
	"brk",
	"param",
	"stmt",
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
	"do",
	"begin",
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
	short cost[21];
	struct {
		unsigned int yylist:2;
		unsigned int yybase:3;
		unsigned int yybloco:2;
		unsigned int yylistend:2;
		unsigned int yydecls:2;
		unsigned int yybrk:2;
		unsigned int yyparam:2;
		unsigned int yystmt:2;
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
		unsigned int yydo:1;
		unsigned int yybegin:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yylist_NT, yybase_NT, 0 };
static short yynts_2[] = { yylistend_NT, 0 };
static short yynts_3[] = { yylistend_NT, yydecls_NT, 0 };
static short yynts_4[] = { yylist_NT, 0 };
static short yynts_5[] = { yylist_NT, yybrk_NT, 0 };
static short yynts_6[] = { yydecls_NT, yyparam_NT, 0 };
static short yynts_7[] = { yybase_NT, 0 };
static short yynts_8[] = { yybrk_NT, 0 };
static short yynts_9[] = { yyexpr_NT, 0 };
static short yynts_10[] = { yybloco_NT, 0 };
static short yynts_11[] = { yyargs_NT, yyexpr_NT, 0 };
static short yynts_12[] = { yylvalue_NT, 0 };
static short yynts_13[] = { yylvec_NT, yyexpr_NT, 0 };
static short yynts_14[] = { yyassign_NT, yylvalue_NT, 0 };
static short yynts_15[] = { yyalloc_NT, yylvalue_NT, 0 };
static short yynts_16[] = { yyargs_NT, 0 };
static short yynts_17[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_18[] = { yyand_NT, yyexpr_NT, 0 };
static short yynts_19[] = { yyor_NT, yyexpr_NT, 0 };
static short yynts_20[] = { yyif_NT, yybase_NT, 0 };
static short yynts_21[] = { yycond_NT, yybase_NT, 0 };
static short yynts_22[] = { yydo_NT, yyexpr_NT, 0 };
static short yynts_23[] = { yybegin_NT, yystmt_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_0,	/* 7 */
	yynts_6,	/* 8 */
	yynts_0,	/* 9 */
	yynts_0,	/* 10 */
	yynts_7,	/* 11 */
	yynts_8,	/* 12 */
	yynts_9,	/* 13 */
	yynts_0,	/* 14 */
	yynts_10,	/* 15 */
	yynts_0,	/* 16 */
	yynts_0,	/* 17 */
	yynts_11,	/* 18 */
	yynts_0,	/* 19 */
	yynts_0,	/* 20 */
	yynts_12,	/* 21 */
	yynts_12,	/* 22 */
	yynts_12,	/* 23 */
	yynts_13,	/* 24 */
	yynts_12,	/* 25 */
	yynts_12,	/* 26 */
	yynts_9,	/* 27 */
	yynts_9,	/* 28 */
	yynts_9,	/* 29 */
	yynts_14,	/* 30 */
	yynts_0,	/* 31 */
	yynts_15,	/* 32 */
	yynts_9,	/* 33 */
	yynts_0,	/* 34 */
	yynts_0,	/* 35 */
	yynts_0,	/* 36 */
	yynts_16,	/* 37 */
	yynts_17,	/* 38 */
	yynts_17,	/* 39 */
	yynts_17,	/* 40 */
	yynts_17,	/* 41 */
	yynts_17,	/* 42 */
	yynts_17,	/* 43 */
	yynts_17,	/* 44 */
	yynts_17,	/* 45 */
	yynts_17,	/* 46 */
	yynts_17,	/* 47 */
	yynts_17,	/* 48 */
	yynts_17,	/* 49 */
	yynts_9,	/* 50 */
	yynts_9,	/* 51 */
	yynts_18,	/* 52 */
	yynts_9,	/* 53 */
	yynts_19,	/* 54 */
	yynts_9,	/* 55 */
	yynts_20,	/* 56 */
	yynts_21,	/* 57 */
	yynts_21,	/* 58 */
	yynts_9,	/* 59 */
	yynts_22,	/* 60 */
	yynts_23,	/* 61 */
	yynts_0,	/* 62 */
	yynts_0,	/* 63 */
	yynts_0,	/* 64 */
	yynts_12,	/* 65 */
	yynts_12,	/* 66 */
	yynts_12,	/* 67 */
	yynts_12,	/* 68 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"list: NIL",
/* 2 */	"list: SC(list,base)",
/* 3 */	"bloco: BLK(listend,NIL)",
/* 4 */	"bloco: BLK(listend,decls)",
/* 5 */	"listend: list",
/* 6 */	"listend: SC(list,brk)",
/* 7 */	"decls: NIL",
/* 8 */	"decls: SC(decls,param)",
/* 9 */	"param: PARAM(INTEGER,ID)",
/* 10 */	"param: PARAM(NUMBER,ID)",
/* 11 */	"stmt: base",
/* 12 */	"stmt: brk",
/* 13 */	"base: expr",
/* 14 */	"base: VOID",
/* 15 */	"base: bloco",
/* 16 */	"args: NIL",
/* 17 */	"args: VOID",
/* 18 */	"args: COMMA(args,expr)",
/* 19 */	"lvalue: ID",
/* 20 */	"lvalue: LOCAL",
/* 21 */	"expr: PTR(lvalue)",
/* 22 */	"expr: REF(lvalue)",
/* 23 */	"lvec: lvalue",
/* 24 */	"lvalue: INDEX(lvec,expr)",
/* 25 */	"lvalue: PTR(lvalue)",
/* 26 */	"expr: PTR(lvalue)",
/* 27 */	"expr: ATR(expr,LOCAL)",
/* 28 */	"expr: ATR(expr,ID)",
/* 29 */	"assign: expr",
/* 30 */	"expr: ATR(assign,lvalue)",
/* 31 */	"expr: ID",
/* 32 */	"base: ALLOC(alloc,lvalue)",
/* 33 */	"alloc: expr",
/* 34 */	"expr: INT",
/* 35 */	"expr: REAL",
/* 36 */	"expr: STR",
/* 37 */	"expr: CALL(ID,args)",
/* 38 */	"expr: ADD(expr,expr)",
/* 39 */	"expr: SUB(expr,expr)",
/* 40 */	"expr: MUL(expr,expr)",
/* 41 */	"expr: DIV(expr,expr)",
/* 42 */	"expr: MOD(expr,expr)",
/* 43 */	"expr: OR(expr,expr)",
/* 44 */	"expr: EQ(expr,expr)",
/* 45 */	"expr: NE(expr,expr)",
/* 46 */	"expr: LT(expr,expr)",
/* 47 */	"expr: LE(expr,expr)",
/* 48 */	"expr: GT(expr,expr)",
/* 49 */	"expr: GE(expr,expr)",
/* 50 */	"expr: UMINUS(expr)",
/* 51 */	"expr: NOT(expr)",
/* 52 */	"expr: AND(and,expr)",
/* 53 */	"and: expr",
/* 54 */	"expr: OR(or,expr)",
/* 55 */	"or: expr",
/* 56 */	"base: ELSE(if,base)",
/* 57 */	"if: IF(cond,base)",
/* 58 */	"base: IF(cond,base)",
/* 59 */	"cond: expr",
/* 60 */	"base: WHILE(do,expr)",
/* 61 */	"do: DO(begin,stmt)",
/* 62 */	"begin: START",
/* 63 */	"brk: BREAK",
/* 64 */	"brk: CONTINUE",
/* 65 */	"expr: INCR(lvalue)",
/* 66 */	"expr: DECR(lvalue)",
/* 67 */	"expr: POSINC(lvalue)",
/* 68 */	"expr: POSDEC(lvalue)",
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
	13,
	14,
	15,
	32,
	56,
	58,
	60,
};

static short yydecode_bloco[] = {
	0,
	3,
	4,
};

static short yydecode_listend[] = {
	0,
	5,
	6,
};

static short yydecode_decls[] = {
	0,
	7,
	8,
};

static short yydecode_brk[] = {
	0,
	63,
	64,
};

static short yydecode_param[] = {
	0,
	9,
	10,
};

static short yydecode_stmt[] = {
	0,
	11,
	12,
};

static short yydecode_expr[] = {
	0,
	21,
	22,
	26,
	27,
	28,
	30,
	31,
	34,
	35,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	51,
	52,
	54,
	65,
	66,
	67,
	68,
};

static short yydecode_args[] = {
	0,
	16,
	17,
	18,
};

static short yydecode_lvalue[] = {
	0,
	19,
	20,
	24,
	25,
};

static short yydecode_lvec[] = {
	0,
	23,
};

static short yydecode_assign[] = {
	0,
	29,
};

static short yydecode_alloc[] = {
	0,
	33,
};

static short yydecode_and[] = {
	0,
	53,
};

static short yydecode_or[] = {
	0,
	55,
};

static short yydecode_if[] = {
	0,
	57,
};

static short yydecode_cond[] = {
	0,
	59,
};

static short yydecode_do[] = {
	0,
	61,
};

static short yydecode_begin[] = {
	0,
	62,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 20)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yybloco_NT:	return yydecode_bloco[((struct yystate *)state)->rule.yybloco];
	case yylistend_NT:	return yydecode_listend[((struct yystate *)state)->rule.yylistend];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yybrk_NT:	return yydecode_brk[((struct yystate *)state)->rule.yybrk];
	case yyparam_NT:	return yydecode_param[((struct yystate *)state)->rule.yyparam];
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
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
	case yydo_NT:	return yydecode_do[((struct yystate *)state)->rule.yydo];
	case yybegin_NT:	return yydecode_begin[((struct yystate *)state)->rule.yybegin];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_list(NODEPTR_TYPE, int);
static void yyclosure_base(NODEPTR_TYPE, int);
static void yyclosure_bloco(NODEPTR_TYPE, int);
static void yyclosure_brk(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_lvalue(NODEPTR_TYPE, int);

static void yyclosure_list(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 5, c + 0, p->cost[yylistend_NT]);
	if (c + 0 < p->cost[yylistend_NT]) {
		p->cost[yylistend_NT] = c + 0;
		p->rule.yylistend = 1;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 0, p->cost[yystmt_NT]);
	if (c + 0 < p->cost[yystmt_NT]) {
		p->cost[yystmt_NT] = c + 0;
		p->rule.yystmt = 1;
	}
}

static void yyclosure_bloco(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 15, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 3;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_brk(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 12, c + 0, p->cost[yystmt_NT]);
	if (c + 0 < p->cost[yystmt_NT]) {
		p->cost[yystmt_NT] = c + 0;
		p->rule.yystmt = 2;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 59, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 55, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 53, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 33, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 29, c + 1, p->cost[yyassign_NT]);
	if (c + 1 < p->cost[yyassign_NT]) {
		p->cost[yyassign_NT] = c + 1;
		p->rule.yyassign = 1;
	}
	yytrace(a, 13, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_lvalue(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 23, c + 1, p->cost[yylvec_NT]);
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
	p->cost[13] =
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACT */
		return;
	case 35: /* ALLOC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base: ALLOC(alloc,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyalloc_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 4;
			yyclosure_base(a, c + 0);
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 52, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 18, c + 0, p->cost[yyargs_NT]);
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
		yytrace(a, 39, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 41, c + 0, p->cost[yyexpr_NT]);
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
			yyclosure_list(a, c + 0);
		}
		/* listend: SC(list,brk) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybrk_NT] + 0;
		yytrace(a, 6, c + 0, p->cost[yylistend_NT]);
		if (c + 0 < p->cost[yylistend_NT]) {
			p->cost[yylistend_NT] = c + 0;
			p->rule.yylistend = 2;
		}
		/* decls: SC(decls,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 1000;
		yytrace(a, 8, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 46, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 44, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 48, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 24, c + 0, p->cost[yylvalue_NT]);
		if (c + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = c + 0;
			p->rule.yylvalue = 3;
			yyclosure_lvalue(a, c + 0);
		}
		break;
	case 123: /* BLK */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* bloco: BLK(listend,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylistend_NT] + 0;
			yytrace(a, 3, c + 0, p->cost[yybloco_NT]);
			if (c + 0 < p->cost[yybloco_NT]) {
				p->cost[yybloco_NT] = c + 0;
				p->rule.yybloco = 1;
				yyclosure_bloco(a, c + 0);
			}
		}
		/* bloco: BLK(listend,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylistend_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 1000;
		yytrace(a, 4, c + 0, p->cost[yybloco_NT]);
		if (c + 0 < p->cost[yybloco_NT]) {
			p->cost[yybloco_NT] = c + 0;
			p->rule.yybloco = 2;
			yyclosure_bloco(a, c + 0);
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 43, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		/* expr: OR(or,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 27;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* expr: INT */
		yytrace(a, 34, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* expr: REAL */
		yytrace(a, 35, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		/* lvalue: ID */
		yytrace(a, 19, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
			yyclosure_lvalue(a, 1 + 0);
		}
		/* expr: ID */
		yytrace(a, 31, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* expr: STR */
		yytrace(a, 36, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* do: DO(begin,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybegin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 61, c + 0, p->cost[yydo_NT]);
		if (c + 0 < p->cost[yydo_NT]) {
			p->cost[yydo_NT] = c + 0;
			p->rule.yydo = 1;
		}
		break;
	case 262: /* WHILE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base: WHILE(do,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydo_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 7;
			yyclosure_base(a, c + 0);
		}
		break;
	case 263: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* if: IF(cond,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* base: IF(cond,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 58, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 6;
			yyclosure_base(a, c + 0);
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
		/* brk: BREAK */
		yytrace(a, 63, 1 + 0, p->cost[yybrk_NT]);
		if (1 + 0 < p->cost[yybrk_NT]) {
			p->cost[yybrk_NT] = 1 + 0;
			p->rule.yybrk = 1;
			yyclosure_brk(a, 1 + 0);
		}
		break;
	case 271: /* CONTINUE */
		/* brk: CONTINUE */
		yytrace(a, 64, 1 + 0, p->cost[yybrk_NT]);
		if (1 + 0 < p->cost[yybrk_NT]) {
			p->cost[yybrk_NT] = 1 + 0;
			p->rule.yybrk = 2;
			yyclosure_brk(a, 1 + 0);
		}
		break;
	case 272: /* VOID */
		/* base: VOID */
		yytrace(a, 14, 0 + 0, p->cost[yybase_NT]);
		if (0 + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = 0 + 0;
			p->rule.yybase = 2;
			yyclosure_base(a, 0 + 0);
		}
		/* args: VOID */
		yytrace(a, 17, 0 + 0, p->cost[yyargs_NT]);
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
		yytrace(a, 65, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 66, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 56, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 5;
			yyclosure_base(a, c + 0);
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: ATR(expr,LOCAL) */
			OP_LABEL(RIGHT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 27, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 28, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		/* expr: ATR(assign,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 30, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 45, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 49, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 47, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 50, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 51, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 22, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 2;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 289: /* LOCAL */
		/* lvalue: LOCAL */
		yytrace(a, 20, 1 + 0, p->cost[yylvalue_NT]);
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
		yytrace(a, 67, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 68, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 21, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 1;
			yyclosure_expr(a, c + 0);
		}
		/* lvalue: PTR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yylvalue_NT]);
		if (c + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = c + 0;
			p->rule.yylvalue = 4;
			yyclosure_lvalue(a, c + 0);
		}
		/* expr: PTR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 11;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		/* begin: START */
		yytrace(a, 62, 1 + 0, p->cost[yybegin_NT]);
		if (1 + 0 < p->cost[yybegin_NT]) {
			p->cost[yybegin_NT] = 1 + 0;
			p->rule.yybegin = 1;
		}
		break;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(INTEGER,ID) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* INTEGER */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = 1000;
			yytrace(a, 9, c + 0, p->cost[yyparam_NT]);
			if (c + 0 < p->cost[yyparam_NT]) {
				p->cost[yyparam_NT] = c + 0;
				p->rule.yyparam = 1;
			}
		}
		if (	/* param: PARAM(NUMBER,ID) */
			OP_LABEL(LEFT_CHILD(a)) == 275 && /* NUMBER */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = 1000;
			yytrace(a, 10, c + 0, p->cost[yyparam_NT]);
			if (c + 0 < p->cost[yyparam_NT]) {
				p->cost[yyparam_NT] = c + 0;
				p->rule.yyparam = 2;
			}
		}
		break;
	case 296: /* NIL */
		/* list: NIL */
		yytrace(a, 1, 0 + 0, p->cost[yylist_NT]);
		if (0 + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = 0 + 0;
			p->rule.yylist = 1;
			yyclosure_list(a, 0 + 0);
		}
		/* decls: NIL */
		yytrace(a, 7, 1 + 0, p->cost[yydecls_NT]);
		if (1 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 1 + 0;
			p->rule.yydecls = 1;
		}
		/* args: NIL */
		yytrace(a, 16, 0 + 0, p->cost[yyargs_NT]);
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
	case 64: /* brk: CONTINUE */
	case 63: /* brk: BREAK */
	case 62: /* begin: START */
	case 36: /* expr: STR */
	case 35: /* expr: REAL */
	case 34: /* expr: INT */
	case 31: /* expr: ID */
	case 20: /* lvalue: LOCAL */
	case 19: /* lvalue: ID */
	case 17: /* args: VOID */
	case 16: /* args: NIL */
	case 14: /* base: VOID */
	case 10: /* param: PARAM(NUMBER,ID) */
	case 9: /* param: PARAM(INTEGER,ID) */
	case 7: /* decls: NIL */
	case 1: /* list: NIL */
		break;
	case 61: /* do: DO(begin,stmt) */
	case 60: /* base: WHILE(do,expr) */
	case 58: /* base: IF(cond,base) */
	case 57: /* if: IF(cond,base) */
	case 56: /* base: ELSE(if,base) */
	case 54: /* expr: OR(or,expr) */
	case 52: /* expr: AND(and,expr) */
	case 49: /* expr: GE(expr,expr) */
	case 48: /* expr: GT(expr,expr) */
	case 47: /* expr: LE(expr,expr) */
	case 46: /* expr: LT(expr,expr) */
	case 45: /* expr: NE(expr,expr) */
	case 44: /* expr: EQ(expr,expr) */
	case 43: /* expr: OR(expr,expr) */
	case 42: /* expr: MOD(expr,expr) */
	case 41: /* expr: DIV(expr,expr) */
	case 40: /* expr: MUL(expr,expr) */
	case 39: /* expr: SUB(expr,expr) */
	case 38: /* expr: ADD(expr,expr) */
	case 32: /* base: ALLOC(alloc,lvalue) */
	case 30: /* expr: ATR(assign,lvalue) */
	case 24: /* lvalue: INDEX(lvec,expr) */
	case 18: /* args: COMMA(args,expr) */
	case 8: /* decls: SC(decls,param) */
	case 6: /* listend: SC(list,brk) */
	case 4: /* bloco: BLK(listend,decls) */
	case 2: /* list: SC(list,base) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 68: /* expr: POSDEC(lvalue) */
	case 67: /* expr: POSINC(lvalue) */
	case 66: /* expr: DECR(lvalue) */
	case 65: /* expr: INCR(lvalue) */
	case 51: /* expr: NOT(expr) */
	case 50: /* expr: UMINUS(expr) */
	case 28: /* expr: ATR(expr,ID) */
	case 27: /* expr: ATR(expr,LOCAL) */
	case 26: /* expr: PTR(lvalue) */
	case 25: /* lvalue: PTR(lvalue) */
	case 22: /* expr: REF(lvalue) */
	case 21: /* expr: PTR(lvalue) */
	case 3: /* bloco: BLK(listend,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 59: /* cond: expr */
	case 55: /* or: expr */
	case 53: /* and: expr */
	case 33: /* alloc: expr */
	case 29: /* assign: expr */
	case 23: /* lvec: lvalue */
	case 15: /* base: bloco */
	case 13: /* base: expr */
	case 12: /* stmt: brk */
	case 11: /* stmt: base */
	case 5: /* listend: list */
		kids[0] = p;
		break;
	case 37: /* expr: CALL(ID,args) */
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
	case 3: /* bloco: BLK(listend,NIL) */
#line 50 "diy.brg"

		break;
	case 4: /* bloco: BLK(listend,decls) */
#line 51 "diy.brg"
{printf("TEST %d\n", 3);}
		break;
	case 5: /* listend: list */
#line 53 "diy.brg"

		break;
	case 6: /* listend: SC(list,brk) */
#line 54 "diy.brg"

		break;
	case 7: /* decls: NIL */
#line 57 "diy.brg"
{printf("TEST %d\n", 3);}
		break;
	case 8: /* decls: SC(decls,param) */
#line 58 "diy.brg"
{printf("TEST %d\n", 3);}
		break;
	case 9: /* param: PARAM(INTEGER,ID) */
#line 59 "diy.brg"
{printf("TEST %d\n", 6);}
		break;
	case 10: /* param: PARAM(NUMBER,ID) */
#line 60 "diy.brg"
{printf("TEST %d\n", 6);}
		break;
	case 11: /* stmt: base */
#line 64 "diy.brg"

		break;
	case 12: /* stmt: brk */
#line 65 "diy.brg"

		break;
	case 13: /* base: expr */
#line 67 "diy.brg"
{ fprintf(outfp, pfTRASH, pfWORD); }
		break;
	case 14: /* base: VOID */
#line 68 "diy.brg"

		break;
	case 15: /* base: bloco */
#line 69 "diy.brg"

		break;
	case 16: /* args: NIL */
#line 71 "diy.brg"
{ p->place = 0; }
		break;
	case 17: /* args: VOID */
#line 72 "diy.brg"
{ p->place = 0; }
		break;
	case 18: /* args: COMMA(args,expr) */
#line 73 "diy.brg"
{ p->place =  ((LEFT_CHILD(p)->place) + 1); }
		break;
	case 19: /* lvalue: ID */
#line 76 "diy.brg"
{ fprintf(outfp, pfADDR, p->value.s); }
		break;
	case 20: /* lvalue: LOCAL */
#line 77 "diy.brg"
{ fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4)); }
		break;
	case 21: /* expr: PTR(lvalue) */
#line 78 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 22: /* expr: REF(lvalue) */
#line 79 "diy.brg"
{ /* No code, but keep PTR to avoid missing LOADs */ }
		break;
	case 23: /* lvec: lvalue */
#line 80 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 24: /* lvalue: INDEX(lvec,expr) */
#line 81 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, pfWORD); /*ONLY WORKS FOR INT*/}
		break;
	case 25: /* lvalue: PTR(lvalue) */
#line 82 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 26: /* expr: PTR(lvalue) */
#line 83 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 27: /* expr: ATR(expr,LOCAL) */
#line 86 "diy.brg"
{ fprintf(outfp, pfDUP pfLOCA, RIGHT_CHILD(p)->value.i * (pfWORD/4)); }
		break;
	case 28: /* expr: ATR(expr,ID) */
#line 87 "diy.brg"
{ fprintf(outfp, pfDUP pfADDRA, RIGHT_CHILD(p)->value.s); }
		break;
	case 29: /* assign: expr */
#line 88 "diy.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 30: /* expr: ATR(assign,lvalue) */
#line 89 "diy.brg"
{ fprintf(outfp, pfSTORE); }
		break;
	case 31: /* expr: ID */
#line 90 "diy.brg"
{ fprintf(outfp, pfADDRV, p->value.s); }
		break;
	case 32: /* base: ALLOC(alloc,lvalue) */
#line 91 "diy.brg"
{ fprintf(outfp, pfSTORE); }
		break;
	case 33: /* alloc: expr */
#line 92 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 34: /* expr: INT */
#line 96 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 35: /* expr: REAL */
#line 97 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 36: /* expr: STR */
#line 98 "diy.brg"
{ lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 37: /* expr: CALL(ID,args) */
#line 99 "diy.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)(pfWORD*(RIGHT_CHILD(p)->place))); }
		break;
	case 38: /* expr: ADD(expr,expr) */
#line 101 "diy.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 39: /* expr: SUB(expr,expr) */
#line 102 "diy.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 40: /* expr: MUL(expr,expr) */
#line 103 "diy.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 41: /* expr: DIV(expr,expr) */
#line 104 "diy.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 42: /* expr: MOD(expr,expr) */
#line 105 "diy.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 43: /* expr: OR(expr,expr) */
#line 106 "diy.brg"
{ fprintf(outfp, pfOR); }
		break;
	case 44: /* expr: EQ(expr,expr) */
#line 107 "diy.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 45: /* expr: NE(expr,expr) */
#line 108 "diy.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 46: /* expr: LT(expr,expr) */
#line 109 "diy.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 47: /* expr: LE(expr,expr) */
#line 110 "diy.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 48: /* expr: GT(expr,expr) */
#line 111 "diy.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 49: /* expr: GE(expr,expr) */
#line 112 "diy.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 50: /* expr: UMINUS(expr) */
#line 113 "diy.brg"
{ fprintf(outfp, pfNEG); }
		break;
	case 51: /* expr: NOT(expr) */
#line 114 "diy.brg"
{ fprintf(outfp, pfIMM pfEQ, 0); }
		break;
	case 52: /* expr: AND(and,expr) */
#line 115 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 53: /* and: expr */
#line 116 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 54: /* expr: OR(or,expr) */
#line 117 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 55: /* or: expr */
#line 118 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 56: /* base: ELSE(if,base) */
#line 123 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 57: /* if: IF(cond,base) */
#line 124 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 58: /* base: IF(cond,base) */
#line 126 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 59: /* cond: expr */
#line 127 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place)); }
		break;
	case 60: /* base: WHILE(do,expr) */
#line 131 "diy.brg"
{ brkcnt--; fprintf(outfp, pfJNZ pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 61: /* do: DO(begin,stmt) */
#line 132 "diy.brg"
{ p->place = LEFT_CHILD(p)->place+1; }
		break;
	case 62: /* begin: START */
#line 133 "diy.brg"
{ brkcnt++; p->place = ++lbl; fprintf(outfp, pfLABEL, mklbl(lbl)); brklbl[brkcnt] = ++lbl ; }
		break;
	case 63: /* brk: BREAK */
#line 137 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[brkcnt- p->value.i +1])); }
		break;
	case 64: /* brk: CONTINUE */
#line 138 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[brkcnt]-1)); }
		break;
	case 65: /* expr: INCR(lvalue) */
#line 141 "diy.brg"
{ fprintf(outfp, pfDUP pfINCR pfLOAD, 1); }
		break;
	case 66: /* expr: DECR(lvalue) */
#line 142 "diy.brg"
{ fprintf(outfp, pfDUP pfDECR pfLOAD, 1); }
		break;
	case 67: /* expr: POSINC(lvalue) */
#line 143 "diy.brg"
{ fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1); }
		break;
	case 68: /* expr: POSDEC(lvalue) */
#line 144 "diy.brg"
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


#line 149 "diy.brg"

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

