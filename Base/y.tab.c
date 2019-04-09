/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "diy.y"
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
#line 17 "diy.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 49 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define REAL 258
#define ID 259
#define STR 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define FOR 265
#define IN 266
#define UPTO 267
#define DOWNTO 268
#define STEP 269
#define BREAK 270
#define CONTINUE 271
#define VOID 272
#define INTEGER 273
#define STRING 274
#define NUMBER 275
#define CONST 276
#define PUBLIC 277
#define INCR 278
#define DECR 279
#define ATR 280
#define NE 281
#define GE 282
#define LE 283
#define ELSE 284
#define IFX 285
#define INC 286
#define DEC 287
#define ADDR 288
#define UMINUS 289
#define PTRR 290
#define LOCAL 291
#define INIT 292
#define PUB 293
#define PRIV 294
#define CON 295
#define TYPE 296
#define MEM 297
#define NIL 298
#define CONS 299
#define DEF 300
#define TYPEX 301
#define PLCOM 302
#define CSTR 303
#define DECL 304
#define GLOBAL 305
#define PTR 306
#define FUNC 307
#define PARAM 308
#define BODY 309
#define BPARAMS 310
#define BPARAM 311
#define ALLOC 312
#define INSTR 313
#define LOAD 314
#define BSUB 315
#define INDEX 316
#define CALL 317
#define FACT 318
#define NOT 319
#define AINC 320
#define ADEC 321
#define BINC 322
#define BDEC 323
#define MUL 324
#define DIV 325
#define MOD 326
#define ADD 327
#define LT 328
#define GT 329
#define EQ 330
#define AND 331
#define OR 332
#define ARG 333
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    3,    3,    4,    4,    5,    5,
    5,    5,    6,    6,    7,    7,    7,    7,    7,    7,
    8,    8,    8,    9,   10,   10,   11,   12,   12,   13,
   13,   14,   14,   15,   15,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   17,   17,   18,   18,   18,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   20,   20,
};
static const YYINT yylen[] = {                            2,
    1,    0,    2,    6,    0,    1,    0,    1,    1,    1,
    1,    1,    0,    1,    1,    3,    4,    3,    3,    5,
    0,    3,    1,    3,    0,    1,    4,    0,    3,    1,
    1,    0,    2,    0,    1,    4,    6,    5,    9,    2,
    1,    3,    3,    4,    0,    2,    1,    4,    2,    1,
    3,    1,    1,    1,    4,    3,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    3,
};
static const YYINT yydefred[] = {                         2,
    0,    0,    6,    3,    0,    8,    0,   12,    9,   10,
   11,    0,   14,    0,    0,    0,    0,    0,    4,   16,
   18,   19,    0,    0,    0,   23,   17,    0,    0,    0,
   24,   28,   20,   26,   22,    0,    0,    0,   29,   52,
   54,   47,   53,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,   41,   46,    0,    0,
    0,    0,    0,    0,   35,    0,    0,    0,    0,    0,
    0,    0,   49,    0,   61,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58,    0,   40,    0,    0,    0,   42,   43,
   51,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   56,    0,    0,
    0,    0,    0,   48,   44,   55,    0,   38,    0,   30,
   31,    0,    0,   37,    0,    0,    0,    0,    0,   39,
};
static const YYINT yydgoto[] = {                          1,
    2,    4,    5,    7,   24,   14,   16,   25,   26,   33,
   57,   36,  132,  137,   66,   58,   38,   62,   60,  120,
};
static const YYINT yysindex[] = {                         0,
    0, -274,    0,    0, -240,    0, -227,    0,    0,    0,
    0,    7,    0, -216,  -34,    4, -226, -227,    0,    0,
    0,    0, -193,    7,  -25,    0,    0, -191,  -44, -227,
    0,    0,    0,    0,    0, -227,   23,  954,    0,    0,
    0,    0,    0, 1013,  646,  -29, -174, -174,  -29,  -29,
  -29,  646,  646, -175,  646,    0,    0,    0,  -10,  129,
 -177,  -71,  159,  -73,    0,   27,   29,   -2,   -2,   -2,
  510,   58,    0,  248,    0,    0,  646,  646,  646,  646,
  646,  646,  646,  646,  646,  646,  646,  646,  646,  646,
  646,  646,    0,  137,    0,  646, 1013,  646,    0,    0,
    0,  456,  296,  331,  200,  467,  467,  499,  510,  200,
  467,  467,   97,   97,  -18,  -18,  -18,    0,  456,  -20,
  384, -185,   98,    0,    0,    0,  646,    0, 1013,    0,
    0,  646,  456,    0,  414,  646, -159,  456, 1013,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    1,    0,    0, -221,    0,    0,    0,    0,    0,
    0, -150,    0,    0,   52,    0, -148,   20,    0,    0,
    0,    0,    0, -150,    0,    0,    0,    0,   54,    0,
    0,    0,    0,    0,    0,  990,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   55,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  425,    0,
    0,  -33,    0,    0,    0,    0,    0,   -3,   33,   63,
  959,  544,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  139,    0,    0,  793,  708,  758,  834,  970,  877,
  850,  919,  589,  683,  579,  616,  673,    0,   21,    0,
    0,  890,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,    0, -146,    0,    0, -145,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  100,  111,   95,    0,    0,  -13,    0,
   91,    0,    0,    0,   79,  -42,    0, 1038, 1234,    0,
};
#define YYTABLESIZE 1370
static const YYINT yytable[] = {                         50,
    1,   61,    3,   50,   50,   18,   50,   50,   50,   50,
   50,   50,   54,   50,   93,   29,   35,   78,   30,   78,
  126,   94,   37,  127,   79,   50,   50,   50,   50,   63,
   20,   21,   22,   63,   63,    6,   63,   63,   63,   63,
   63,   63,   15,   63,    8,    9,   10,   11,   13,    6,
    7,    7,    7,    7,  122,   63,   63,   63,   63,   50,
   21,   79,   19,   21,   79,   64,   27,   31,   80,   64,
   64,   80,   64,   64,   64,   64,   64,   64,   32,   64,
   78,   39,   65,   73,   96,   99,  134,  100,   78,   63,
   50,   64,   64,   64,   64,   59,  140,   94,  129,   59,
   59,  139,   59,   59,   59,   59,   59,   59,   13,   59,
   15,    7,   25,   34,   32,   33,   23,   12,   28,   34,
   63,   59,   59,   59,   59,   64,   67,    0,    0,   93,
   93,    0,    0,   92,   92,   84,   94,   94,   90,   90,
   88,    0,   89,   91,   91,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   59,   64,   86,   85,   87,
    0,   93,    0,    0,    0,   92,   84,    0,   94,    0,
   90,   88,    0,   89,   51,   91,   55,  118,   54,   78,
    0,   53,   78,    0,    0,    0,   59,   95,   86,   85,
   87,   93,   98,    0,    0,   92,   84,   78,   94,    0,
   90,   88,    0,   89,    0,   91,   75,   76,   77,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   86,   85,
   87,   83,    0,    0,    0,    0,    0,   50,    0,   42,
   50,   78,   93,   50,   50,   50,   92,    0,    0,   94,
    0,   90,   88,    0,   89,   17,   91,   50,   50,   50,
    0,    0,   83,    0,    0,    0,    0,   63,    0,   86,
   63,   87,   52,   63,   63,   63,    0,   75,   76,   77,
    0,    0,    5,    5,    5,    5,    5,   63,   63,   63,
   93,    0,   83,    0,   92,   84,    0,   94,  101,   90,
   88,    0,   89,   64,   91,    0,   64,    0,    0,   64,
   64,   64,    0,    0,    0,    0,    0,   86,   85,   87,
    0,    0,    0,   64,   64,   64,    0,    0,    0,    0,
    0,    0,    0,   59,    0,    0,   59,    0,   93,   59,
   59,   59,   92,   84,    0,   94,    0,   90,   88,    0,
   89,    0,   91,   59,   59,   59,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   86,   85,   87,    0,    0,
    0,    0,    0,   93,  130,  131,    0,   92,   84,    0,
   94,   83,   90,   88,    0,   89,    0,   91,   80,   81,
   82,    0,    0,    0,    0,    0,    0,    0,  124,  125,
   86,   85,   87,   40,   41,   42,   43,    0,    0,   78,
    0,    0,   78,    0,    0,   78,   78,   78,    0,   80,
   81,   82,    0,    0,   49,   50,   93,    0,    0,   83,
   92,   84,   97,   94,    0,   90,   88,    0,   89,    0,
   91,    0,    0,    0,    0,    0,    0,    0,    0,   80,
   81,   82,  128,   86,   85,   87,   93,    0,    0,    0,
   92,   84,    0,   94,   83,   90,   88,   50,   89,    0,
   91,   50,   50,    0,   50,    0,   50,   50,    0,   50,
    0,   50,    0,   86,   85,   87,    0,    0,    0,    0,
    0,   81,   82,   50,   50,   50,   50,    0,   93,    0,
    0,    0,   92,   84,    0,   94,    0,   90,   88,   93,
   89,    0,   91,   92,    0,    0,   94,   83,   90,   88,
    0,   89,    0,   91,    0,   86,   85,   87,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   80,   81,
   82,   93,    0,    0,    0,   92,   84,   83,   94,    0,
   90,   88,   93,   89,    0,   91,   92,    0,   50,   94,
    0,   90,   88,    0,   89,    0,   91,    0,   86,   85,
   87,    0,    0,    0,    0,    0,    0,    0,    0,   86,
   85,   87,    0,    0,    0,    0,   80,   81,   82,   83,
   57,   57,    0,    0,   57,   57,   57,   57,   57,    0,
   57,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   57,   57,   57,   57,    0,    0,    0,    0,
    0,   80,   81,   82,    0,   65,   65,    0,    0,   65,
   65,   65,   65,   65,    0,   65,   68,    0,    0,   68,
    0,   68,   68,   68,    0,    0,   57,   65,   65,   65,
   65,    0,    0,    0,    0,    0,    0,   68,   68,   68,
   68,    0,   66,   66,    0,    0,   66,   66,   66,   66,
   66,    0,   66,    0,   80,   81,   82,   57,    0,    0,
    0,   65,    0,    0,   66,   66,   66,   66,    0,    0,
    0,   68,  136,   51,    0,   55,    0,   54,    0,    0,
   53,    0,    0,    0,   80,   81,   82,    0,    0,    0,
    0,    0,   65,    0,    0,   50,   50,   50,   66,   67,
   67,    0,   68,   67,   67,   67,   67,   67,    0,   67,
   69,    0,    0,   69,    0,   69,   69,   69,    0,    0,
    0,   67,   67,   67,   67,    0,   80,   81,   82,   66,
    0,   69,   69,   69,   69,   72,    0,    0,   72,    0,
    0,   72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   67,   72,   72,   72,   72,
    0,   52,    0,    0,    0,   69,    0,    0,    0,   80,
   81,   82,    0,    0,    0,    0,    0,    0,    0,    0,
   80,   81,   82,    0,    0,   73,   67,    0,   73,    0,
   72,   73,    0,    0,   57,    0,   69,   57,    0,    0,
   57,   57,   57,    0,    0,    0,   73,   73,   73,   73,
    0,    0,    0,    0,   57,   57,   57,    0,    0,    0,
   75,   72,    0,   75,    0,    0,   75,    0,    0,   65,
    0,    0,   65,    0,    0,   65,   65,   65,    0,   68,
   73,   75,   68,   75,    0,   68,   68,   68,    0,   65,
   65,   65,    0,    0,    0,    0,    0,    0,    0,   68,
   68,   68,    0,    0,   77,    0,   66,   77,    0,   66,
    0,   73,   66,   66,   66,   75,    0,   70,    0,    0,
   70,    0,   77,   70,    0,    0,   66,   66,   66,    0,
    0,    0,   40,   41,   42,   43,    0,    0,   70,   70,
   70,   70,    0,    0,   74,    0,   75,   74,    0,    0,
   74,    0,    0,   49,   50,    0,   77,   36,    0,   36,
    0,   36,    0,   67,   36,   74,   67,   74,    0,   67,
   67,   67,   70,   69,    0,    0,   69,    0,    0,   69,
   69,   69,    0,   67,   67,   67,   71,   77,    0,   71,
    0,    0,   71,   69,   69,   69,    0,    0,   72,   74,
    0,   72,    0,   70,   72,   72,   72,   71,   71,   71,
   71,    0,    0,    0,    0,    0,    0,    0,   72,   72,
   72,   51,    0,   55,    0,   54,   60,    0,   53,   60,
   74,    0,   60,    0,    0,    0,    0,   76,    0,    0,
   76,   71,   36,   76,   36,   36,    0,   60,   73,    0,
    0,   73,    0,    0,   73,   73,   73,   45,   76,   45,
    0,   45,    0,    0,   45,    0,    0,    0,   73,   73,
   73,    0,   71,    0,    0,    0,    0,    0,    0,    0,
   51,   60,   55,   75,   54,    0,   75,   53,    0,   75,
   75,   75,   76,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   75,    0,   59,   32,    0,   56,   52,
    0,   59,   60,   64,    0,    0,   68,   69,   70,    0,
    0,    0,    0,   76,   77,    0,    0,   77,    0,    0,
   77,   77,   77,    0,    0,    0,    0,    0,    0,    0,
   70,    0,   45,   70,   45,   45,   70,   70,   70,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   70,   70,   70,    0,   59,   32,    0,   74,   52,    0,
   74,    0,    0,   74,   74,   74,   36,   36,   36,   36,
   36,   36,   36,    0,   36,    0,    0,   74,    0,   36,
   36,    0,    0,    0,    0,    0,   59,   36,   36,    0,
    0,    0,    0,    0,    0,    0,   59,    0,    0,   71,
    0,    0,   71,    0,    0,   71,   71,   71,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   71,
   71,   71,    0,    0,    0,    0,    0,    0,    0,    0,
   40,   41,   42,   43,   44,    0,   45,    0,   46,   60,
    0,    0,   60,   47,   48,   60,   60,   60,    0,    0,
   76,   49,   50,   76,    0,    0,   76,   76,   76,    0,
    0,    0,    0,    0,    0,    0,   45,   45,   45,   45,
   45,    0,   45,    0,   45,    0,    0,    0,    0,   45,
   45,    0,    0,    0,    0,    0,    0,   45,   45,   40,
   41,   42,   43,   44,    0,   45,    0,   46,   63,    0,
    0,    0,   47,   48,    0,   71,   72,    0,   74,    0,
   49,   50,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,  116,  117,    0,  119,    0,  121,
    0,  123,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  133,    0,    0,    0,    0,  135,    0,    0,    0,  138,
};
static const YYINT yycheck[] = {                         33,
    0,   44,  277,   37,   38,   40,   40,   41,   42,   43,
   44,   45,   42,   47,   33,   41,   30,   91,   44,   91,
   41,   40,   36,   44,   35,   59,   60,   61,   62,   33,
  257,  258,  259,   37,   38,  276,   40,   41,   42,   43,
   44,   45,  259,   47,  272,  273,  274,  275,   42,  276,
  272,  273,  274,  275,   97,   59,   60,   61,   62,   93,
   41,   41,   59,   44,   44,   33,  260,  259,   41,   37,
   38,   44,   40,   41,   42,   43,   44,   45,  123,   47,
   91,   59,  257,  259,  262,   59,  129,   59,   91,   93,
  124,   59,   60,   61,   62,   33,  139,   40,  284,   37,
   38,  261,   40,   41,   42,   43,   44,   45,  259,   47,
   59,  260,   59,   59,  261,  261,   17,    7,   24,   29,
  124,   59,   60,   61,   62,   93,   48,   -1,   -1,   33,
   33,   -1,   -1,   37,   37,   38,   40,   40,   42,   42,
   43,   -1,   45,   47,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,  124,   60,   61,   62,
   -1,   33,   -1,   -1,   -1,   37,   38,   -1,   40,   -1,
   42,   43,   -1,   45,   38,   47,   40,   41,   42,   41,
   -1,   45,   44,   -1,   -1,   -1,  124,   59,   60,   61,
   62,   33,  266,   -1,   -1,   37,   38,   59,   40,   -1,
   42,   43,   -1,   45,   -1,   47,  278,  279,  280,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,
   62,  124,   -1,   -1,   -1,   -1,   -1,  261,   -1,  259,
  264,   93,   33,  267,  268,  269,   37,   -1,   -1,   40,
   -1,   42,   43,   -1,   45,  280,   47,  281,  282,  283,
   -1,   -1,  124,   -1,   -1,   -1,   -1,  261,   -1,   60,
  264,   62,  126,  267,  268,  269,   -1,  278,  279,  280,
   -1,   -1,  272,  273,  274,  275,  276,  281,  282,  283,
   33,   -1,  124,   -1,   37,   38,   -1,   40,   41,   42,
   43,   -1,   45,  261,   47,   -1,  264,   -1,   -1,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,
   -1,   -1,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   33,  267,
  268,  269,   37,   38,   -1,   40,   -1,   42,   43,   -1,
   45,   -1,   47,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   33,  267,  268,   -1,   37,   38,   -1,
   40,  124,   42,   43,   -1,   45,   -1,   47,  281,  282,
  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   59,
   60,   61,   62,  257,  258,  259,  260,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,  281,
  282,  283,   -1,   -1,  278,  279,   33,   -1,   -1,  124,
   37,   38,  264,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,   59,   60,   61,   62,   33,   -1,   -1,   -1,
   37,   38,   -1,   40,  124,   42,   43,   33,   45,   -1,
   47,   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,  282,  283,   59,   60,   61,   62,   -1,   33,   -1,
   -1,   -1,   37,   38,   -1,   40,   -1,   42,   43,   33,
   45,   -1,   47,   37,   -1,   -1,   40,  124,   42,   43,
   -1,   45,   -1,   47,   -1,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,
  283,   33,   -1,   -1,   -1,   37,   38,  124,   40,   -1,
   42,   43,   33,   45,   -1,   47,   37,   -1,  124,   40,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,  281,  282,  283,  124,
   37,   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,   -1,   37,   38,   -1,   -1,   41,
   42,   43,   44,   45,   -1,   47,   38,   -1,   -1,   41,
   -1,   43,   44,   45,   -1,   -1,   93,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,
   62,   -1,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,  281,  282,  283,  124,   -1,   -1,
   -1,   93,   -1,   -1,   59,   60,   61,   62,   -1,   -1,
   -1,   93,  269,   38,   -1,   40,   -1,   42,   -1,   -1,
   45,   -1,   -1,   -1,  281,  282,  283,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,  281,  282,  283,   93,   37,
   38,   -1,  124,   41,   42,   43,   44,   45,   -1,   47,
   38,   -1,   -1,   41,   -1,   43,   44,   45,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,  281,  282,  283,  124,
   -1,   59,   60,   61,   62,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   59,   60,   61,   62,
   -1,  126,   -1,   -1,   -1,   93,   -1,   -1,   -1,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,   -1,   -1,   38,  124,   -1,   41,   -1,
   93,   44,   -1,   -1,  261,   -1,  124,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   59,   60,   61,   62,
   -1,   -1,   -1,   -1,  281,  282,  283,   -1,   -1,   -1,
   38,  124,   -1,   41,   -1,   -1,   44,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,  261,
   93,   59,  264,   61,   -1,  267,  268,  269,   -1,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,   -1,   -1,   41,   -1,  261,   44,   -1,  264,
   -1,  124,  267,  268,  269,   93,   -1,   38,   -1,   -1,
   41,   -1,   59,   44,   -1,   -1,  281,  282,  283,   -1,
   -1,   -1,  257,  258,  259,  260,   -1,   -1,   59,   60,
   61,   62,   -1,   -1,   38,   -1,  124,   41,   -1,   -1,
   44,   -1,   -1,  278,  279,   -1,   93,   38,   -1,   40,
   -1,   42,   -1,  261,   45,   59,  264,   61,   -1,  267,
  268,  269,   93,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   -1,  281,  282,  283,   38,  124,   -1,   41,
   -1,   -1,   44,  281,  282,  283,   -1,   -1,  261,   93,
   -1,  264,   -1,  124,  267,  268,  269,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,
  283,   38,   -1,   40,   -1,   42,   38,   -1,   45,   41,
  124,   -1,   44,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   93,  123,   44,  125,  126,   -1,   59,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   38,   59,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,  281,  282,
  283,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   38,   93,   40,  261,   42,   -1,  264,   45,   -1,  267,
  268,  269,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,   -1,   38,  123,   -1,  125,  126,
   -1,   44,  124,   46,   -1,   -1,   49,   50,   51,   -1,
   -1,   -1,   -1,  124,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  261,   -1,  123,  264,  125,  126,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,   -1,   97,  123,   -1,  261,  126,   -1,
  264,   -1,   -1,  267,  268,  269,  257,  258,  259,  260,
  261,  262,  263,   -1,  265,   -1,   -1,  281,   -1,  270,
  271,   -1,   -1,   -1,   -1,   -1,  129,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  139,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   -1,  263,   -1,  265,  261,
   -1,   -1,  264,  270,  271,  267,  268,  269,   -1,   -1,
  261,  278,  279,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,   -1,  263,   -1,  265,   -1,   -1,   -1,   -1,  270,
  271,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,  257,
  258,  259,  260,  261,   -1,  263,   -1,  265,   45,   -1,
   -1,   -1,  270,  271,   -1,   52,   53,   -1,   55,   -1,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
   87,   88,   89,   90,   91,   92,   -1,   94,   -1,   96,
   -1,   98,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  127,   -1,   -1,   -1,   -1,  132,   -1,   -1,   -1,  136,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 333
#define YYUNDFTOKEN 356
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR",
"DO","WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE",
"VOID","INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","ATR","NE",
"GE","LE","ELSE","IFX","INC","DEC","ADDR","UMINUS","PTRR","LOCAL","INIT","PUB",
"PRIV","CON","TYPE","MEM","NIL","CONS","DEF","TYPEX","PLCOM","CSTR","DECL",
"GLOBAL","PTR","FUNC","PARAM","BODY","BPARAMS","BPARAM","ALLOC","INSTR","LOAD",
"BSUB","INDEX","CALL","FACT","NOT","AINC","ADEC","BINC","BDEC","MUL","DIV",
"MOD","ADD","LT","GT","EQ","AND","OR","ARG",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : decl",
"decl :",
"decl : decl def",
"def : priv cons type ptr initid ';'",
"priv :",
"priv : PUBLIC",
"cons :",
"cons : CONST",
"type : INTEGER",
"type : STRING",
"type : NUMBER",
"type : VOID",
"ptr :",
"ptr : '*'",
"initid : ID",
"initid : ID ATR INT",
"initid : ID ATR cons STR",
"initid : ID ATR REAL",
"initid : ID ATR ID",
"initid : ID '(' params ')' optbody",
"params :",
"params : params ',' param",
"params : param",
"param : type ptr ID",
"optbody :",
"optbody : body",
"body : '{' bparams instrs '}'",
"bparams :",
"bparams : bparams param ';'",
"updn : UPTO",
"updn : DOWNTO",
"stp :",
"stp : STEP expr",
"optint :",
"optint : INT",
"instr : IF expr THEN instr",
"instr : IF expr THEN instr ELSE instr",
"instr : DO instr WHILE expr ';'",
"instr : FOR lvalue IN expr updn expr stp DO instr",
"instr : expr ';'",
"instr : body",
"instr : BREAK optint ';'",
"instr : CONTINUE optint ';'",
"instr : lvalue '#' expr ';'",
"instrs :",
"instrs : instrs instr",
"lvalue : ID",
"lvalue : lvalue '[' expr ']'",
"lvalue : '*' ID",
"expr : lvalue",
"expr : '(' expr ')'",
"expr : INT",
"expr : STR",
"expr : REAL",
"expr : expr '(' args ')'",
"expr : expr '(' ')'",
"expr : '-' expr",
"expr : expr '!'",
"expr : '&' lvalue",
"expr : '~' expr",
"expr : lvalue INCR",
"expr : lvalue DECR",
"expr : INCR lvalue",
"expr : DECR lvalue",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr '=' expr",
"expr : expr NE expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : lvalue ATR expr",
"args : expr",
"args : args ',' expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 184 "diy.y"

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



#line 702 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 55 "diy.y"
	{ printNode(yystack.l_mark[0].n, 0, yynames); }
break;
case 2:
#line 57 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 3:
#line 58 "diy.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 4:
#line 61 "diy.y"
	{ yyval.n = binNode(DEF, binNode(TYPEX, binNode(PLCOM, yystack.l_mark[-5].n, yystack.l_mark[-4].n), binNode(TYPE, yystack.l_mark[-3].n, yystack.l_mark[-2].n)), yystack.l_mark[-1].n); }
break;
case 5:
#line 64 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 6:
#line 65 "diy.y"
	{ yyval.n = nilNode(PUB); }
break;
case 7:
#line 68 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 8:
#line 69 "diy.y"
	{ yyval.n = nilNode(CONS); }
break;
case 9:
#line 73 "diy.y"
	{ yyval.n = nilNode(INTEGER); }
break;
case 10:
#line 74 "diy.y"
	{ yyval.n = nilNode(STRING); }
break;
case 11:
#line 75 "diy.y"
	{ yyval.n = nilNode(NUMBER); }
break;
case 12:
#line 76 "diy.y"
	{ yyval.n = nilNode(VOID); }
break;
case 13:
#line 80 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 14:
#line 81 "diy.y"
	{ yyval.n = nilNode(PTR); }
break;
case 15:
#line 85 "diy.y"
	{ yyval.n = uniNode(INIT, strNode(ID, yystack.l_mark[0].s)); }
break;
case 16:
#line 86 "diy.y"
	{ yyval.n = binNode(INIT, strNode(ID, yystack.l_mark[-2].s), intNode(INT, yystack.l_mark[0].i)); }
break;
case 17:
#line 87 "diy.y"
	{ yyval.n = binNode(INIT, strNode(ID, yystack.l_mark[-3].s), binNode(CSTR, yystack.l_mark[-1].n, strNode(STR, yystack.l_mark[0].s))); }
break;
case 18:
#line 88 "diy.y"
	{ yyval.n = binNode(INIT, strNode(ID, yystack.l_mark[-2].s), realNode(REAL, yystack.l_mark[0].r)); }
break;
case 19:
#line 89 "diy.y"
	{ yyval.n = binNode(INIT, strNode(ID, yystack.l_mark[-2].s), strNode(ID, yystack.l_mark[0].s)); }
break;
case 20:
#line 90 "diy.y"
	{ yyval.n = binNode(INIT, strNode(ID, yystack.l_mark[-4].s), binNode(FUNC, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 21:
#line 93 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 22:
#line 94 "diy.y"
	{ yyval.n = binNode(PARAM, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 23:
#line 95 "diy.y"
	{ yyval.n = uniNode(PARAM, yystack.l_mark[0].n); }
break;
case 24:
#line 99 "diy.y"
	{ yyval.n = binNode(TYPE, yystack.l_mark[-2].n, binNode(MEM, yystack.l_mark[-1].n, strNode(ID,yystack.l_mark[0].s))); }
break;
case 25:
#line 103 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 26:
#line 104 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 27:
#line 107 "diy.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 28:
#line 110 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 29:
#line 111 "diy.y"
	{ yyval.n = binNode(BPARAMS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 30:
#line 116 "diy.y"
	{ yyval.n = nilNode(UPTO); }
break;
case 31:
#line 117 "diy.y"
	{ yyval.n = nilNode(DOWNTO); }
break;
case 32:
#line 120 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 33:
#line 121 "diy.y"
	{ yyval.n = uniNode(STEP, yystack.l_mark[0].n); }
break;
case 34:
#line 124 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 35:
#line 125 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); }
break;
case 36:
#line 128 "diy.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 37:
#line 129 "diy.y"
	{ yyval.n = binNode(ELSE, binNode(IF, yystack.l_mark[-4].n, yystack.l_mark[-2].n), yystack.l_mark[0].n); }
break;
case 38:
#line 130 "diy.y"
	{ yyval.n = binNode(DO, yystack.l_mark[-3].n, uniNode(WHILE, yystack.l_mark[-1].n)); }
break;
case 39:
#line 131 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 40:
#line 132 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 41:
#line 133 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 42:
#line 134 "diy.y"
	{ yyval.n = uniNode(BREAK, yystack.l_mark[-1].n); }
break;
case 43:
#line 135 "diy.y"
	{ yyval.n = uniNode(CONTINUE, yystack.l_mark[-1].n); }
break;
case 44:
#line 136 "diy.y"
	{ yyval.n = binNode(ALLOC, yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 45:
#line 139 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 46:
#line 140 "diy.y"
	{ yyval.n = binNode(INSTR, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 47:
#line 143 "diy.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 48:
#line 144 "diy.y"
	{ yyval.n = binNode(INDEX, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 49:
#line 145 "diy.y"
	{ yyval.n = uniNode(LOAD, strNode(ID, yystack.l_mark[0].s)); }
break;
case 50:
#line 148 "diy.y"
	{ yyval.n = uniNode(LOAD, yystack.l_mark[0].n); }
break;
case 51:
#line 149 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 52:
#line 150 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); }
break;
case 53:
#line 151 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); }
break;
case 54:
#line 152 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); }
break;
case 55:
#line 153 "diy.y"
	{ yyval.n = binNode(CALL, yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 56:
#line 154 "diy.y"
	{ yyval.n = binNode(CALL, nilNode(NIL), yystack.l_mark[-2].n); }
break;
case 57:
#line 155 "diy.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 58:
#line 156 "diy.y"
	{ yyval.n = uniNode(FACT, yystack.l_mark[-1].n); }
break;
case 59:
#line 157 "diy.y"
	{ yyval.n = uniNode(PTR, yystack.l_mark[0].n); }
break;
case 60:
#line 158 "diy.y"
	{ yyval.n = uniNode(NOT, yystack.l_mark[0].n); }
break;
case 61:
#line 159 "diy.y"
	{ yyval.n = uniNode(AINC, yystack.l_mark[-1].n); }
break;
case 62:
#line 160 "diy.y"
	{ yyval.n = uniNode(ADEC, yystack.l_mark[-1].n); }
break;
case 63:
#line 161 "diy.y"
	{ yyval.n = uniNode(BINC, yystack.l_mark[0].n); }
break;
case 64:
#line 162 "diy.y"
	{ yyval.n = uniNode(BDEC, yystack.l_mark[0].n); }
break;
case 65:
#line 163 "diy.y"
	{ yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 66:
#line 164 "diy.y"
	{ yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 67:
#line 165 "diy.y"
	{ yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 68:
#line 166 "diy.y"
	{ yyval.n = binNode(ADD, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 69:
#line 167 "diy.y"
	{ yyval.n = binNode(BSUB, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 70:
#line 168 "diy.y"
	{ yyval.n = binNode(LT, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 71:
#line 169 "diy.y"
	{ yyval.n = binNode(GT, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 72:
#line 170 "diy.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 73:
#line 171 "diy.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 74:
#line 172 "diy.y"
	{ yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 75:
#line 173 "diy.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 76:
#line 174 "diy.y"
	{ yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 175 "diy.y"
	{ yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 176 "diy.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 79:
#line 179 "diy.y"
	{ yyval.n = binNode(ARG, yystack.l_mark[0].n, nilNode(NIL)); }
break;
case 80:
#line 180 "diy.y"
	{ yyval.n = binNode(ARG, yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
#line 1224 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
