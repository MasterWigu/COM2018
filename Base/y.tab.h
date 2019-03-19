#define INTVALUE 257
#define NUMVALUE 258
#define IDENTIFIER 259
#define STRVALUE 260
#define IF 261
#define THEN 262
#define ELSE 263
#define DO 264
#define WHILE 265
#define FOR 266
#define IN 267
#define UPTO 268
#define DOWNTO 269
#define STEP 270
#define BREAK 271
#define CONTINUE 272
#define PUBLIC 273
#define CONST 274
#define INT 275
#define STR 276
#define NUM 277
#define VOID 278
#define INC 279
#define DEC 280
#define GE 281
#define LE 282
#define EQ 283
#define NE 284
#define ASSIGN 285
#define SEMICOLON 286
#define LF 287
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;		/* integer value */
	double d;	/* double value */
	char *s;	/* symbol name or string literal */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
