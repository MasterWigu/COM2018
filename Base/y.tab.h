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
extern YYSTYPE yylval;
