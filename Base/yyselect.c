/*
generated at Fri May 24 13:50:29 2019
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


static char *declared[100];
static int declrcnt;
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

void convertDouble(Node *n);
void doATR(Node *n);
void doATR2(Node *n);
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
#define yyfbase_NT 21
#define yyinfor_NT 22
#define yyflist_NT 23
#define yyfbegin_NT 24

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
	"fbase",
	"infor",
	"flist",
	"fbegin",
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
	short cost[25];
	struct {
		unsigned int yylist:2;
		unsigned int yybase:4;
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
		unsigned int yyfbase:1;
		unsigned int yyinfor:1;
		unsigned int yyflist:1;
		unsigned int yyfbegin:1;
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
static short yynts_24[] = { yyexpr_NT, yyfbase_NT, 0 };
static short yynts_25[] = { yyinfor_NT, yyflist_NT, 0 };
static short yynts_26[] = { yyfbegin_NT, yyexpr_NT, 0 };
static short yynts_27[] = { yybase_NT, yyexpr_NT, 0 };

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
	yynts_9,	/* 26 */
	yynts_14,	/* 27 */
	yynts_0,	/* 28 */
	yynts_15,	/* 29 */
	yynts_9,	/* 30 */
	yynts_0,	/* 31 */
	yynts_0,	/* 32 */
	yynts_0,	/* 33 */
	yynts_16,	/* 34 */
	yynts_17,	/* 35 */
	yynts_17,	/* 36 */
	yynts_17,	/* 37 */
	yynts_17,	/* 38 */
	yynts_9,	/* 39 */
	yynts_17,	/* 40 */
	yynts_17,	/* 41 */
	yynts_17,	/* 42 */
	yynts_17,	/* 43 */
	yynts_17,	/* 44 */
	yynts_17,	/* 45 */
	yynts_17,	/* 46 */
	yynts_9,	/* 47 */
	yynts_9,	/* 48 */
	yynts_18,	/* 49 */
	yynts_9,	/* 50 */
	yynts_19,	/* 51 */
	yynts_9,	/* 52 */
	yynts_20,	/* 53 */
	yynts_21,	/* 54 */
	yynts_21,	/* 55 */
	yynts_9,	/* 56 */
	yynts_22,	/* 57 */
	yynts_23,	/* 58 */
	yynts_0,	/* 59 */
	yynts_24,	/* 60 */
	yynts_25,	/* 61 */
	yynts_26,	/* 62 */
	yynts_27,	/* 63 */
	yynts_0,	/* 64 */
	yynts_0,	/* 65 */
	yynts_0,	/* 66 */
	yynts_12,	/* 67 */
	yynts_12,	/* 68 */
	yynts_12,	/* 69 */
	yynts_12,	/* 70 */
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
/* 26 */	"assign: expr",
/* 27 */	"expr: ATR(assign,lvalue)",
/* 28 */	"expr: ID",
/* 29 */	"base: ALLOC(alloc,lvalue)",
/* 30 */	"alloc: expr",
/* 31 */	"expr: INT",
/* 32 */	"expr: REAL",
/* 33 */	"expr: STR",
/* 34 */	"expr: CALL(ID,args)",
/* 35 */	"expr: ADD(expr,expr)",
/* 36 */	"expr: SUB(expr,expr)",
/* 37 */	"expr: MUL(expr,expr)",
/* 38 */	"expr: DIV(expr,expr)",
/* 39 */	"expr: FACT(expr)",
/* 40 */	"expr: MOD(expr,expr)",
/* 41 */	"expr: EQ(expr,expr)",
/* 42 */	"expr: NE(expr,expr)",
/* 43 */	"expr: LT(expr,expr)",
/* 44 */	"expr: LE(expr,expr)",
/* 45 */	"expr: GT(expr,expr)",
/* 46 */	"expr: GE(expr,expr)",
/* 47 */	"expr: UMINUS(expr)",
/* 48 */	"expr: NOT(expr)",
/* 49 */	"expr: AND(and,expr)",
/* 50 */	"and: expr",
/* 51 */	"expr: OR(or,expr)",
/* 52 */	"or: expr",
/* 53 */	"base: ELSE(if,base)",
/* 54 */	"if: IF(cond,base)",
/* 55 */	"base: IF(cond,base)",
/* 56 */	"cond: expr",
/* 57 */	"base: WHILE(do,expr)",
/* 58 */	"do: DO(begin,stmt)",
/* 59 */	"begin: START",
/* 60 */	"base: SC(expr,fbase)",
/* 61 */	"fbase: FOR(infor,flist)",
/* 62 */	"infor: IN(fbegin,expr)",
/* 63 */	"flist: SC(base,expr)",
/* 64 */	"fbegin: START",
/* 65 */	"brk: BREAK",
/* 66 */	"brk: CONTINUE",
/* 67 */	"expr: INCR(lvalue)",
/* 68 */	"expr: DECR(lvalue)",
/* 69 */	"expr: POSINC(lvalue)",
/* 70 */	"expr: POSDEC(lvalue)",
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
	29,
	53,
	55,
	57,
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
	65,
	66,
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
	27,
	28,
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
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	51,
	67,
	68,
	69,
	70,
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
	26,
};

static short yydecode_alloc[] = {
	0,
	30,
};

static short yydecode_and[] = {
	0,
	50,
};

static short yydecode_or[] = {
	0,
	52,
};

static short yydecode_if[] = {
	0,
	54,
};

static short yydecode_cond[] = {
	0,
	56,
};

static short yydecode_do[] = {
	0,
	58,
};

static short yydecode_begin[] = {
	0,
	59,
};

static short yydecode_fbase[] = {
	0,
	61,
};

static short yydecode_infor[] = {
	0,
	62,
};

static short yydecode_flist[] = {
	0,
	63,
};

static short yydecode_fbegin[] = {
	0,
	64,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 24)
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
	case yyfbase_NT:	return yydecode_fbase[((struct yystate *)state)->rule.yyfbase];
	case yyinfor_NT:	return yydecode_infor[((struct yystate *)state)->rule.yyinfor];
	case yyflist_NT:	return yydecode_flist[((struct yystate *)state)->rule.yyflist];
	case yyfbegin_NT:	return yydecode_fbegin[((struct yystate *)state)->rule.yyfbegin];
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
	yytrace(a, 56, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 52, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 50, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 30, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 26, c + 1, p->cost[yyassign_NT]);
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
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
	p->cost[24] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: FACT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 35: /* ALLOC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base: ALLOC(alloc,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyalloc_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 29, c + 0, p->cost[yybase_NT]);
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
		yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 49, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 23;
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
		yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
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
		yytrace(a, 36, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
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
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 0;
		yytrace(a, 8, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
		}
		/* base: SC(expr,fbase) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfbase_NT] + 0;
		yytrace(a, 60, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 8;
			yyclosure_base(a, c + 0);
		}
		/* flist: SC(base,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybase_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 63, c + 0, p->cost[yyflist_NT]);
		if (c + 0 < p->cost[yyflist_NT]) {
			p->cost[yyflist_NT] = c + 0;
			p->rule.yyflist = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 43, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 41, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 15;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
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
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylistend_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
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
		/* expr: OR(or,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 51, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 24;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* expr: INT */
		yytrace(a, 31, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 5;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* expr: REAL */
		yytrace(a, 32, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 6;
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
		yytrace(a, 28, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 4;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* expr: STR */
		yytrace(a, 33, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* do: DO(begin,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybegin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 58, c + 0, p->cost[yydo_NT]);
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
		yytrace(a, 57, c + 0, p->cost[yybase_NT]);
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
		yytrace(a, 54, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* base: IF(cond,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 55, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 6;
			yyclosure_base(a, c + 0);
		}
		break;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* fbase: FOR(infor,flist) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinfor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyflist_NT] + 1;
		yytrace(a, 61, c + 0, p->cost[yyfbase_NT]);
		if (c + 0 < p->cost[yyfbase_NT]) {
			p->cost[yyfbase_NT] = c + 0;
			p->rule.yyfbase = 1;
		}
		break;
	case 266: /* IN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* infor: IN(fbegin,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfbegin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyinfor_NT]);
		if (c + 0 < p->cost[yyinfor_NT]) {
			p->cost[yyinfor_NT] = c + 0;
			p->rule.yyinfor = 1;
		}
		break;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		/* brk: BREAK */
		yytrace(a, 65, 1 + 0, p->cost[yybrk_NT]);
		if (1 + 0 < p->cost[yybrk_NT]) {
			p->cost[yybrk_NT] = 1 + 0;
			p->rule.yybrk = 1;
			yyclosure_brk(a, 1 + 0);
		}
		break;
	case 271: /* CONTINUE */
		/* brk: CONTINUE */
		yytrace(a, 66, 1 + 0, p->cost[yybrk_NT]);
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
		yytrace(a, 67, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 25;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: DECR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 68, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 26;
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
		yytrace(a, 53, c + 0, p->cost[yybase_NT]);
		if (c + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = c + 0;
			p->rule.yybase = 5;
			yyclosure_base(a, c + 0);
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ATR(assign,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 27, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 42, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 16;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 46, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 44, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 21;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 48, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
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
		yytrace(a, 69, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 27;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* expr: POSDEC(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 70, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 28;
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
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
			yytrace(a, 34, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 8;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		/* begin: START */
		yytrace(a, 59, 1 + 0, p->cost[yybegin_NT]);
		if (1 + 0 < p->cost[yybegin_NT]) {
			p->cost[yybegin_NT] = 1 + 0;
			p->rule.yybegin = 1;
		}
		/* fbegin: START */
		yytrace(a, 64, 1 + 0, p->cost[yyfbegin_NT]);
		if (1 + 0 < p->cost[yyfbegin_NT]) {
			p->cost[yyfbegin_NT] = 1 + 0;
			p->rule.yyfbegin = 1;
		}
		break;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(INTEGER,ID) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* INTEGER */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = 0;
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
			c = 0;
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
		yytrace(a, 7, 0 + 0, p->cost[yydecls_NT]);
		if (0 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 0 + 0;
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
	case 66: /* brk: CONTINUE */
	case 65: /* brk: BREAK */
	case 64: /* fbegin: START */
	case 59: /* begin: START */
	case 33: /* expr: STR */
	case 32: /* expr: REAL */
	case 31: /* expr: INT */
	case 28: /* expr: ID */
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
	case 63: /* flist: SC(base,expr) */
	case 62: /* infor: IN(fbegin,expr) */
	case 61: /* fbase: FOR(infor,flist) */
	case 60: /* base: SC(expr,fbase) */
	case 58: /* do: DO(begin,stmt) */
	case 57: /* base: WHILE(do,expr) */
	case 55: /* base: IF(cond,base) */
	case 54: /* if: IF(cond,base) */
	case 53: /* base: ELSE(if,base) */
	case 51: /* expr: OR(or,expr) */
	case 49: /* expr: AND(and,expr) */
	case 46: /* expr: GE(expr,expr) */
	case 45: /* expr: GT(expr,expr) */
	case 44: /* expr: LE(expr,expr) */
	case 43: /* expr: LT(expr,expr) */
	case 42: /* expr: NE(expr,expr) */
	case 41: /* expr: EQ(expr,expr) */
	case 40: /* expr: MOD(expr,expr) */
	case 38: /* expr: DIV(expr,expr) */
	case 37: /* expr: MUL(expr,expr) */
	case 36: /* expr: SUB(expr,expr) */
	case 35: /* expr: ADD(expr,expr) */
	case 29: /* base: ALLOC(alloc,lvalue) */
	case 27: /* expr: ATR(assign,lvalue) */
	case 24: /* lvalue: INDEX(lvec,expr) */
	case 18: /* args: COMMA(args,expr) */
	case 8: /* decls: SC(decls,param) */
	case 6: /* listend: SC(list,brk) */
	case 4: /* bloco: BLK(listend,decls) */
	case 2: /* list: SC(list,base) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 70: /* expr: POSDEC(lvalue) */
	case 69: /* expr: POSINC(lvalue) */
	case 68: /* expr: DECR(lvalue) */
	case 67: /* expr: INCR(lvalue) */
	case 48: /* expr: NOT(expr) */
	case 47: /* expr: UMINUS(expr) */
	case 39: /* expr: FACT(expr) */
	case 25: /* lvalue: PTR(lvalue) */
	case 22: /* expr: REF(lvalue) */
	case 21: /* expr: PTR(lvalue) */
	case 3: /* bloco: BLK(listend,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 56: /* cond: expr */
	case 52: /* or: expr */
	case 50: /* and: expr */
	case 30: /* alloc: expr */
	case 26: /* assign: expr */
	case 23: /* lvec: lvalue */
	case 15: /* base: bloco */
	case 13: /* base: expr */
	case 12: /* stmt: brk */
	case 11: /* stmt: base */
	case 5: /* listend: list */
		kids[0] = p;
		break;
	case 34: /* expr: CALL(ID,args) */
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
#line 54 "diy.brg"

		break;
	case 2: /* list: SC(list,base) */
#line 55 "diy.brg"

		break;
	case 3: /* bloco: BLK(listend,NIL) */
#line 57 "diy.brg"

		break;
	case 4: /* bloco: BLK(listend,decls) */
#line 58 "diy.brg"

		break;
	case 5: /* listend: list */
#line 60 "diy.brg"

		break;
	case 6: /* listend: SC(list,brk) */
#line 61 "diy.brg"

		break;
	case 7: /* decls: NIL */
#line 64 "diy.brg"

		break;
	case 8: /* decls: SC(decls,param) */
#line 65 "diy.brg"

		break;
	case 9: /* param: PARAM(INTEGER,ID) */
#line 66 "diy.brg"

		break;
	case 10: /* param: PARAM(NUMBER,ID) */
#line 67 "diy.brg"

		break;
	case 11: /* stmt: base */
#line 71 "diy.brg"

		break;
	case 12: /* stmt: brk */
#line 72 "diy.brg"

		break;
	case 13: /* base: expr */
#line 74 "diy.brg"
{ if (p->info!=3) fprintf(outfp, pfTRASH, pfWORD); else fprintf(outfp, pfTRASH, 2*pfWORD);}
		break;
	case 14: /* base: VOID */
#line 75 "diy.brg"

		break;
	case 15: /* base: bloco */
#line 76 "diy.brg"

		break;
	case 16: /* args: NIL */
#line 78 "diy.brg"
{ p->place = 0; }
		break;
	case 17: /* args: VOID */
#line 79 "diy.brg"
{ p->place = 0; }
		break;
	case 18: /* args: COMMA(args,expr) */
#line 80 "diy.brg"
{ p->place =  ((LEFT_CHILD(p)->place) + RIGHT_CHILD(p)->info == 3 ? 2 : 1); }
		break;
	case 19: /* lvalue: ID */
#line 83 "diy.brg"
{ fprintf(outfp, pfADDR, p->value.s); }
		break;
	case 20: /* lvalue: LOCAL */
#line 84 "diy.brg"
{ fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4)); }
		break;
	case 21: /* expr: PTR(lvalue) */
#line 85 "diy.brg"
{ if (LEFT_CHILD(p)->info==3) fprintf(outfp, pfLOAD2); else if (LEFT_CHILD(p)->info==2) fprintf(outfp, pfLDCHR); else fprintf(outfp, pfLOAD); }
		break;
	case 22: /* expr: REF(lvalue) */
#line 86 "diy.brg"
{ /* No code, but keep PTR to avoid missing LOADs */ }
		break;
	case 23: /* lvec: lvalue */
#line 87 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 24: /* lvalue: INDEX(lvec,expr) */
#line 88 "diy.brg"
{ if(p->info==3)fprintf(outfp, pfIMM pfMUL pfADD, 2*pfWORD); else if (p->info == 2) fprintf(outfp, pfIMM pfMUL pfADD, 1); else fprintf(outfp, pfIMM pfMUL pfADD, pfWORD);}
		break;
	case 25: /* lvalue: PTR(lvalue) */
#line 89 "diy.brg"
{ fprintf(outfp, LEFT_CHILD(p)->info == 3  ? pfLOAD2 : pfLOAD); }
		break;
	case 26: /* assign: expr */
#line 95 "diy.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 27: /* expr: ATR(assign,lvalue) */
#line 96 "diy.brg"
{ doATR2(p); if (RIGHT_CHILD(p)->info == 3 )fprintf(outfp, pfSTORE2); else if (RIGHT_CHILD(p)->info == 2) fprintf(outfp, pfSTCHR); else fprintf(outfp, pfSTORE2); }
		break;
	case 28: /* expr: ID */
#line 97 "diy.brg"
{ fprintf(outfp, pfADDRV, p->value.s); }
		break;
	case 29: /* base: ALLOC(alloc,lvalue) */
#line 98 "diy.brg"
{ fprintf(outfp, pfSTORE); }
		break;
	case 30: /* alloc: expr */
#line 99 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 31: /* expr: INT */
#line 103 "diy.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 32: /* expr: REAL */
#line 104 "diy.brg"
{ fprintf(outfp, pfDATA pfALIGN pfLABEL pfDOUBLE, mklbl(++lbl), p->value.r); fprintf(outfp, pfTEXT pfALIGN pfADDR pfLOAD2, mklbl(lbl)); }
		break;
	case 33: /* expr: STR */
#line 105 "diy.brg"
{ lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 34: /* expr: CALL(ID,args) */
#line 106 "diy.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)(pfWORD*(RIGHT_CHILD(p)->place))); }
		break;
	case 35: /* expr: ADD(expr,expr) */
#line 108 "diy.brg"
{ convertDouble(p); fprintf(outfp, p->info!=3 ? pfADD : pfDADD); }
		break;
	case 36: /* expr: SUB(expr,expr) */
#line 109 "diy.brg"
{ convertDouble(p); fprintf(outfp, p->info!=3 ? pfSUB : pfDSUB); }
		break;
	case 37: /* expr: MUL(expr,expr) */
#line 110 "diy.brg"
{ convertDouble(p); fprintf(outfp, p->info!=3 ? pfMUL : pfDMUL); }
		break;
	case 38: /* expr: DIV(expr,expr) */
#line 111 "diy.brg"
{ convertDouble(p); fprintf(outfp, p->info!=3 ? pfDIV : pfDDIV); }
		break;
	case 39: /* expr: FACT(expr) */
#line 112 "diy.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc("factorial"), (int)(pfWORD*1)); extrns[extcnt++] = dupstr(mkfunc("factorial"));}
		break;
	case 40: /* expr: MOD(expr,expr) */
#line 113 "diy.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 41: /* expr: EQ(expr,expr) */
#line 114 "diy.brg"
{ convertDouble(p); if(p->info!=3) fprintf(outfp, pfDCMP pfIMM, 0); fprintf(outfp, pfEQ); }
		break;
	case 42: /* expr: NE(expr,expr) */
#line 115 "diy.brg"
{ convertDouble(p); if(p->info!=3) fprintf(outfp, pfDCMP pfIMM, 0); fprintf(outfp, pfNE); }
		break;
	case 43: /* expr: LT(expr,expr) */
#line 116 "diy.brg"
{ convertDouble(p); if(p->info!=3) fprintf(outfp, pfDCMP pfIMM, 0); fprintf(outfp, pfLT); }
		break;
	case 44: /* expr: LE(expr,expr) */
#line 117 "diy.brg"
{ convertDouble(p); if(p->info!=3) fprintf(outfp, pfDCMP pfIMM, 0); fprintf(outfp, pfLE); }
		break;
	case 45: /* expr: GT(expr,expr) */
#line 118 "diy.brg"
{ convertDouble(p); if(p->info!=3) fprintf(outfp, pfDCMP pfIMM, 0); fprintf(outfp, pfGT); }
		break;
	case 46: /* expr: GE(expr,expr) */
#line 119 "diy.brg"
{ convertDouble(p); if(p->info!=3) fprintf(outfp, pfDCMP pfIMM, 0); fprintf(outfp, pfGE); }
		break;
	case 47: /* expr: UMINUS(expr) */
#line 120 "diy.brg"
{ fprintf(outfp, p->info==1 ? pfNEG : pfDNEG); }
		break;
	case 48: /* expr: NOT(expr) */
#line 121 "diy.brg"
{ fprintf(outfp, pfIMM pfEQ, 0); }
		break;
	case 49: /* expr: AND(and,expr) */
#line 122 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 50: /* and: expr */
#line 123 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 51: /* expr: OR(or,expr) */
#line 124 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 52: /* or: expr */
#line 125 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 53: /* base: ELSE(if,base) */
#line 130 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 54: /* if: IF(cond,base) */
#line 131 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 55: /* base: IF(cond,base) */
#line 133 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 56: /* cond: expr */
#line 134 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place)); }
		break;
	case 57: /* base: WHILE(do,expr) */
#line 138 "diy.brg"
{ brkcnt--; fprintf(outfp, pfJNZ pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 58: /* do: DO(begin,stmt) */
#line 139 "diy.brg"
{ p->place = LEFT_CHILD(p)->place+1; }
		break;
	case 59: /* begin: START */
#line 140 "diy.brg"
{ brkcnt++; p->place = ++lbl; fprintf(outfp, pfLABEL, mklbl(lbl)); brklbl[brkcnt] = ++lbl ; }
		break;
	case 60: /* base: SC(expr,fbase) */
#line 143 "diy.brg"

		break;
	case 61: /* fbase: FOR(infor,flist) */
#line 144 "diy.brg"
{  brkcnt--; fprintf(outfp, pfJMP pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place), mklbl(LEFT_CHILD(p)->place));}
		break;
	case 62: /* infor: IN(fbegin,expr) */
#line 146 "diy.brg"
{ p->place = (brklbl[++brkcnt] = ++lbl); fprintf(outfp, pfJZ, mklbl(lbl)); }
		break;
	case 63: /* flist: SC(base,expr) */
#line 147 "diy.brg"

		break;
	case 64: /* fbegin: START */
#line 148 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfLABEL, mklbl(lbl)); }
		break;
	case 65: /* brk: BREAK */
#line 150 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[brkcnt- p->value.i +1])); }
		break;
	case 66: /* brk: CONTINUE */
#line 151 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[brkcnt]-1)); }
		break;
	case 67: /* expr: INCR(lvalue) */
#line 154 "diy.brg"
{ fprintf(outfp, pfDUP pfINCR pfLOAD, 1); }
		break;
	case 68: /* expr: DECR(lvalue) */
#line 155 "diy.brg"
{ fprintf(outfp, pfDUP pfDECR pfLOAD, 1); }
		break;
	case 69: /* expr: POSINC(lvalue) */
#line 156 "diy.brg"
{ fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1); }
		break;
	case 70: /* expr: POSDEC(lvalue) */
#line 157 "diy.brg"
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


#line 162 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;

void convertDouble(Node *node) {
	if (node->info == 3 && RIGHT_CHILD(node)->info == 1) {
		fprintf(outfp, pfI2D);
	}
	if (node->info == 3 && LEFT_CHILD(node)->info == 1) {
		/*when program reaches here, on top of the stack is always a double (so it occupies 2 places)*/
		fprintf(outfp, pfDPOP pfI2D pfDPUSH);
	}
}

void doATR(Node *node) { /*converts rvalue to the right number of bytes to match lvalue
	/*value is on top of stack*/
	if (LEFT_CHILD(node)->info != 3 && RIGHT_CHILD(node)->info == 3) /*when value is not double, and var type is double*/
		fprintf(outfp, pfI2D);
	if (LEFT_CHILD(node)->info == 3 && RIGHT_CHILD(node)->info != 3) /*when value is double, and var is not double*/
		fprintf(outfp, pfD2I);
	/*else types have the same number of bytes, we dont do anything*/
}

void doATR2(Node *node) { /*converts rvalue to the right number of bytes to match lvalue
	/*addr is on top of stack and then 2 copies of rvalue*/
	if (LEFT_CHILD(node)->info != 3 && RIGHT_CHILD(node)->info == 3) /*when value is not double, and var type is double*/
		fprintf(outfp, pfPOP pfTRASH pfI2D pfDUP2 pfPUSH, 4); /*we can store the value temporarly with POP because I2D and DUP doesnt change eax*/
	if (LEFT_CHILD(node)->info == 3 && RIGHT_CHILD(node)->info != 3) /*when value is double, and var is not double*/
		fprintf(outfp, pfPOP pfTRASH pfD2I pfDUP pfPUSH, 8);
	/*else types have the same number of bytes, we dont do anything*/
}

void externs() {
	int i;

	for (i = 0; i < extcnt; i++)
		if (extrns[i])
			fprintf(outfp, pfEXTRN, extrns[i]);
}


/*void declare(int pub, int cnst, Node *type, char *name, Node *value)*/
void variable(char *name, Node *type, Node *init, int cnst, int pub) {
	int i = 0, siz = 1;
	if (pub)
		fprintf(outfp, pfGLOBL, name, pfOBJ);
	if (cnst)
		fprintf(outfp, pfRODATA pfALIGN pfLABEL, name);
	else
		fprintf(outfp, pfDATA pfALIGN pfLABEL, name);


	if (init) {
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


void function(char *name, int enter, Node *body, int tVoid, int pub, int doub) {
	int i;
	if (body->attrib == NIL) {
		for (i = 0; i < declrcnt; i++) {
			if (declared[i] && strcmp(declared[i], mkfunc(name)) == 0) return;
		}
			extrns[extcnt++] = dupstr(mkfunc(name));
		return;
	}

	Node *stmt = LEFT_CHILD(body);

	extern int errors, trace;
	extern char **yynames;
	if (errors) return;
	if (trace) printNode(stmt, 0, yynames);
	fflush(stdout);
	if (pub)
		fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), enter * (pfWORD/4));
	else
		fprintf(outfp, pfTEXT pfALIGN pfLABEL pfENTER, mkfunc(name), enter * (pfWORD/4));
	yyselect(stmt);
	if (!tVoid)
		if (doub)
			fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP pfLEAVE pfRET, -4);
		else
			fprintf(outfp, pfLOCAL pfLOAD pfPOP pfLEAVE pfRET, -4);
	else
		fprintf(outfp, pfLEAVE pfRET);
	/*fprintf(outfp, pfLEAVE pfRET); /* just in case ... */
	freeNode(stmt);
	declared[declrcnt++] = dupstr(mkfunc(name));
	for (i = 0; i < extcnt; i++) {
		if (stmt->attrib != NIL && extrns[i] && strcmp(extrns[i], mkfunc(name)) == 0) extrns[i] = 0;
	}
}





#ifndef NOTRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost) {
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	//fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
	if (cost >= MAX_COST && bestcost >= MAX_COST) {
		extern char **yynames;
		//fprintf(stderr, "0x%lx:%s NO MATCH %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
		//printNode(p, 0, yynames);
	}
}
#endif

