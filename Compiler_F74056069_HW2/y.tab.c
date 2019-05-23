/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern int yylineno;
extern int yylex();
extern void yyerror(char*);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char*);
void create_symbol();
void insert_symbol(int, char*, char*, char*, char*);
void dump_symbol();
void insert_attribute(int, char*);
void remove_symbol_parameter();
void semantic_error();
void syntax_error();
void print_test();

int assign_flag = 0;
int error_flag = 0;
int type_flag = 0;
int scope_num = 0;
int id_flag = 0;
int if_insert_attribute = 0;
int is_function = 0;
int attribute_count = 0;
int need_dump = 0;
int if_syntax_error = 0;
int if_semantic_error = 0;
char error_msg[256];
char* now_expression_id;

typedef struct data {
	int index;
	char* name;
	char* kind;
	char* type;
	int scope;
	char* attribute;
	struct data* next;
	struct data* prev;
	
} Symbol_table;
Symbol_table* symbol_table_head;	// Head of linked list for dynamic storing symbols
Symbol_table* symbol_table_tail;	// Tail of linked list for dynamic storing symbols

/* For debugging colorful text */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


#line 127 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    INC = 263,
    DEC = 264,
    MT = 265,
    LT = 266,
    MTE = 267,
    LTE = 268,
    EQ = 269,
    NE = 270,
    ASGN = 271,
    ADDASGN = 272,
    SUBASGN = 273,
    MULASGN = 274,
    DIVASGN = 275,
    MODASGN = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    LB = 280,
    RB = 281,
    LCB = 282,
    RCB = 283,
    LSB = 284,
    RSB = 285,
    COMMA = 286,
    PRINT = 287,
    IF = 288,
    ELSE = 289,
    FOR = 290,
    WHILE = 291,
    VOID = 292,
    INT = 293,
    FLOAT = 294,
    STRING = 295,
    BOOL = 296,
    TRUE = 297,
    FALSE = 298,
    RET = 299,
    SEMICOLON = 300,
    I_CONST = 301,
    F_CONST = 302,
    STR_CONST = 303,
    ID = 304
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define INC 263
#define DEC 264
#define MT 265
#define LT 266
#define MTE 267
#define LTE 268
#define EQ 269
#define NE 270
#define ASGN 271
#define ADDASGN 272
#define SUBASGN 273
#define MULASGN 274
#define DIVASGN 275
#define MODASGN 276
#define AND 277
#define OR 278
#define NOT 279
#define LB 280
#define RB 281
#define LCB 282
#define RCB 283
#define LSB 284
#define RSB 285
#define COMMA 286
#define PRINT 287
#define IF 288
#define ELSE 289
#define FOR 290
#define WHILE 291
#define VOID 292
#define INT 293
#define FLOAT 294
#define STRING 295
#define BOOL 296
#define TRUE 297
#define FALSE 298
#define RET 299
#define SEMICOLON 300
#define I_CONST 301
#define F_CONST 302
#define STR_CONST 303
#define ID 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* str_val;

#line 271 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 288 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   104,   108,   109,   113,   117,   167,
     168,   173,   179,   185,   186,   190,   191,   195,   196,   197,
     198,   199,   200,   204,   205,   209,   210,   214,   218,   219,
     223,   227,   272,   273,   274,   275,   276,   280,   281,   285,
     289,   293,   300,   304,   305,   309,   310,   311,   312,   313,
     314,   315,   319,   320,   321,   325,   326,   327,   328,   332,
     333,   337,   338,   339,   340,   345,   346,   350,   358,   366,
     374,   382,   392,   397,   398,   399,   403,   404,   405,   409,
     410,   414,   418,   425,   426,   427,   428,   429,   430,   434,
     435,   439,   440,   444,   445
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD", "INC",
  "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN",
  "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "PRINT", "IF", "ELSE", "FOR",
  "WHILE", "VOID", "INT", "FLOAT", "STRING", "BOOL", "TRUE", "FALSE",
  "RET", "SEMICOLON", "I_CONST", "F_CONST", "STR_CONST", "ID", "$accept",
  "program", "external_declaration", "function_definition",
  "function_definition_declarator", "compound_statement", "scope_start",
  "scope_end", "block_item_list", "block_item", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "print_statement", "declaration", "type",
  "init_declarator", "declarator", "initializer", "assignment_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression", "constant",
  "boolean", "parameter_list", "assignment_operator",
  "specifier_qualifier_list", "argument_expression_list", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     233,  -120,  -120,  -120,  -120,  -120,    40,  -120,  -120,    81,
    -120,   -27,  -120,  -120,  -120,  -120,   196,   196,   141,  -120,
    -120,    14,    33,    58,  -120,  -120,     1,  -120,  -120,  -120,
    -120,  -120,  -120,    81,  -120,    81,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,   -27,  -120,   212,    61,    86,  -120,
     241,   207,  -120,     4,  -120,  -120,   -14,  -120,   -20,     5,
     207,  -120,  -120,   233,    78,    10,   207,   207,   207,  -120,
      -7,  -120,  -120,  -120,    12,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,  -120,  -120,  -120,  -120,
    -120,  -120,   207,  -120,  -120,  -120,  -120,   188,   207,  -120,
    -120,   207,    60,  -120,  -120,   207,  -120,    30,    31,    56,
    -120,    61,    61,    61,    61,    61,    61,    86,    86,  -120,
    -120,  -120,  -120,  -120,  -120,    79,  -120,  -120,  -120,  -120,
     -27,    85,  -120,    62,   128,   128,  -120,   207,    87,  -120,
     233,  -120,    99,  -120,  -120,   -27,   128,    87,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    36,    32,    33,    35,    34,     0,     2,     6,     0,
       5,     0,     1,     3,    65,    66,     0,     0,     0,    11,
      12,     0,     0,     0,    79,    80,     0,    23,    76,    77,
      78,    72,     7,     0,     9,     0,    13,    16,    18,    19,
      20,    21,    22,    15,     0,    93,    43,    45,    52,    55,
      59,     0,    61,    67,    73,    74,     0,    39,     0,    38,
       0,    62,    63,    90,     0,     0,     0,     0,     0,    28,
       0,    17,    10,    14,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    87,    88,    84,
      85,    86,     0,    64,    59,    70,    71,     0,     0,    24,
      31,     0,     0,     8,    89,     0,    75,     0,     0,     0,
      29,    46,    47,    48,    49,    50,    51,    53,    54,    56,
      57,    58,    44,    68,    91,     0,    94,    37,    42,    41,
       0,     0,    60,     0,     0,     0,    69,     0,    81,    40,
       0,    30,    26,    27,    92,     0,     0,    82,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,   109,  -120,  -120,   101,    76,   103,  -120,   104,
    -119,  -120,  -120,  -120,  -120,  -120,    54,     0,  -120,   -42,
    -120,   -78,  -120,   189,    13,   -50,    -9,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,    80,  -120,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    58,    59,
     127,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,   131,    92,    64,   125,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    93,    74,    65,    14,    15,    11,    61,    62,    16,
      17,    70,    95,    96,   122,   142,   143,    98,    63,   124,
     126,   101,    57,   128,    98,   100,    18,   148,   101,    97,
     102,    99,    19,   119,   120,   121,   106,   102,   110,    66,
      12,    98,    94,    24,    25,    65,    69,    28,    29,    30,
      31,   107,   108,   109,    10,   132,   133,   134,    67,   144,
      10,    98,    98,    63,    81,    82,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,     1,     2,     3,
       4,     5,   135,    68,    14,    15,   129,    98,   138,    16,
      17,    83,    84,    85,   117,   118,    94,     1,     2,     3,
       4,     5,   130,   147,   105,   136,    18,   141,    19,    20,
     137,   139,   102,    21,    22,    13,   140,    23,     1,     2,
       3,     4,     5,    24,    25,    26,    27,    28,    29,    30,
      31,    14,    15,   146,    71,   103,    16,    17,    72,    73,
     145,     0,     0,   104,    14,    15,     0,     0,     0,    16,
      17,     0,     0,    18,     0,    19,     0,     0,     0,     0,
      21,    22,     0,     0,    23,     0,    18,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,     1,     2,
       3,     4,     5,    24,    25,     0,     0,    28,    29,    30,
      31,    14,    15,     0,     0,     0,    16,    17,     0,    14,
      15,     0,     0,     0,    16,    17,     0,     0,     0,     0,
      14,    15,     0,    18,   123,    16,    17,     0,     0,     0,
       0,    60,    75,    76,    77,    78,    79,    80,     0,     0,
      24,    25,    18,     0,    28,    29,    30,    31,    24,    25,
       0,     0,    28,    29,    30,    31,     0,     0,     0,    24,
      25,     0,     0,    28,    29,    30,    31,    86,    87,    88,
      89,    90,    91,     0,   111,   112,   113,   114,   115,   116,
       1,     2,     3,     4,     5
};

static const yytype_int16 yycheck[] =
{
       0,    51,    44,    18,     3,     4,     6,    16,    17,     8,
       9,    26,     8,     9,    92,   134,   135,    31,    18,    97,
      98,    16,    49,   101,    31,    45,    25,   146,    16,    25,
      25,    45,    27,    83,    84,    85,    26,    25,    45,    25,
       0,    31,    51,    42,    43,    60,    45,    46,    47,    48,
      49,    66,    67,    68,     0,   105,    26,    26,    25,   137,
       6,    31,    31,    63,     3,     4,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    37,    38,    39,
      40,    41,    26,    25,     3,     4,    26,    31,   130,     8,
       9,     5,     6,     7,    81,    82,   105,    37,    38,    39,
      40,    41,   102,   145,    26,    26,    25,    45,    27,    28,
      31,    26,    25,    32,    33,     6,    31,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     3,     4,    34,    33,    59,     8,     9,    35,    35,
     140,    -1,    -1,    63,     3,     4,    -1,    -1,    -1,     8,
       9,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    36,    -1,    25,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,     3,     4,    -1,    -1,    -1,     8,     9,    -1,     3,
       4,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
       3,     4,    -1,    25,    26,     8,     9,    -1,    -1,    -1,
      -1,    25,    10,    11,    12,    13,    14,    15,    -1,    -1,
      42,    43,    25,    -1,    46,    47,    48,    49,    42,    43,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    42,
      43,    -1,    -1,    46,    47,    48,    49,    16,    17,    18,
      19,    20,    21,    -1,    75,    76,    77,    78,    79,    80,
      37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,    39,    40,    41,    51,    52,    53,    54,
      66,    67,     0,    52,     3,     4,     8,     9,    25,    27,
      28,    32,    33,    36,    42,    43,    44,    45,    46,    47,
      48,    49,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    86,    49,    68,    69,
      25,    76,    76,    67,    84,    86,    25,    25,    25,    45,
      86,    55,    57,    59,    69,    10,    11,    12,    13,    14,
      15,     3,     4,     5,     6,     7,    16,    17,    18,    19,
      20,    21,    83,    75,    76,     8,     9,    25,    31,    45,
      45,    16,    25,    56,    84,    26,    26,    86,    86,    86,
      45,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    71,    26,    71,    85,    71,    70,    71,    26,
      67,    82,    75,    26,    26,    26,    26,    31,    69,    26,
      31,    45,    60,    60,    71,    67,    34,    69,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    66,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    79,    79,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    84,
      84,    85,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     2,     3,     1,
       2,     1,     1,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     7,     5,     5,     2,     3,
       5,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       4,     3,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     2,     2,     2,     1,     1,     1,     3,     4,
       2,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     4,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 117 "compiler_hw2.y" /* yacc.c:1646  */
    { 		
		int is_duplicated = 0;
		int has_parameter = 0;
		Symbol_table* find_function = symbol_table_tail;
		/* Find duplicated */
		while(find_function != symbol_table_head) {
			/* If this function has forward declaration */
			if(!strcmp(find_function->name, (yyvsp[-1].str_val))) {
				Symbol_table* duplicated = find_function->next;
				/* Duplicated function must added after the forward delcaration */
				while(duplicated != symbol_table_tail) {
					if(!strcmp(duplicated->kind, "function")) {
						free(duplicated->kind);
						Symbol_table* prev = duplicated->prev;
						Symbol_table* next = duplicated->next;
						if(prev != NULL)
							prev->next = next;
						if(next != NULL)
							next->prev = prev;
						free(duplicated);
						is_duplicated = 1;
						break;
					}
					duplicated = duplicated->next;
				}
				break;
			}
			find_function = find_function->prev;
		}
		find_function = symbol_table_tail;
		/* Find function with parameter, has a template in symbol table */
		while(find_function != symbol_table_head) {
			/* If this function has parameter, find the template */
			if(!strcmp(find_function->kind, "function") && !strcmp(find_function->name, "")) {
				find_function->name = malloc(strlen((yyvsp[-1].str_val)) + 1);
				strcpy(find_function->name, (yyvsp[-1].str_val));
				find_function->type = malloc(strlen((yyvsp[-2].str_val)) + 1);
				strcpy(find_function->type, (yyvsp[-2].str_val));
				has_parameter = 1;
				break;
			}
			find_function = find_function->prev;
		}
		/* If no duplicated && no parameter, initialize the function */
		if(!is_duplicated && !has_parameter) 
			insert_symbol(0, (yyvsp[-1].str_val), "function", (yyvsp[-2].str_val), "");		
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 173 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		 ++scope_num;
	}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		need_dump = 1;
	}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 227 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		/* If it is function declaration */
		if(is_function) {
			if(lookup_symbol((yyvsp[-1].str_val))) {
				if_semantic_error = 1;
				printf(ANSI_COLOR_RED"redeclared function\n"ANSI_COLOR_RESET);
			}
			/* If need to remove the parameter inside the symbol table */
			if(if_insert_attribute) {
			/* Remove the parameters */
				remove_symbol_parameter();
				/* Set the function declaration data in the symbol table */
				Symbol_table* find_function = symbol_table_tail;
				find_function->name = malloc(strlen((yyvsp[-1].str_val)) + 1);
				strcpy(find_function->name, (yyvsp[-1].str_val));
				find_function->type = malloc(strlen((yyvsp[-2].str_val)) + 1);
				strcpy(find_function->type, (yyvsp[-2].str_val));
				if_insert_attribute = 0;
				attribute_count = 0;
				is_function = 0;
			}
			/* If this function doesn't have any parameter, just insert the function */
			else {
				insert_symbol(scope_num, (yyvsp[-1].str_val), "function", (yyvsp[-2].str_val), "");
			}

		}
		/* For variable declaration */
		else {
			switch(lookup_symbol((yyvsp[-1].str_val))) {
				/* For variable isn't in the symbol table or in the lower scope */
				case 0: case 1:
					insert_symbol(scope_num, (yyvsp[-1].str_val), "variable", (yyvsp[-2].str_val), "");
					break;
				/* For the variable is in the same scope, print error */
				case 2:
					if_semantic_error = 1;
					printf(ANSI_COLOR_RED"redeclared variable\n"ANSI_COLOR_RESET);
					break;
			}
		}
	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 272 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.str_val) = "int";}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 273 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.str_val) = "float";}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 274 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.str_val) = "bool";}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 275 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.str_val) = "string";}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 276 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.str_val) = "void";}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 280 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.str_val) = (yyvsp[-2].str_val); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 281 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 285 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		is_function = 0; 
		(yyval.str_val) = (yyvsp[0].str_val); 
	}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 289 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		is_function = 1; 
		(yyval.str_val) = (yyvsp[-3].str_val); 
	}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 293 "compiler_hw2.y" /* yacc.c:1646  */
    {
		is_function = 1; 
		(yyval.str_val) = (yyvsp[-2].str_val); 
	}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 350 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(now_expression_id != NULL) {
			printf("not found: %s\n", now_expression_id);
			free(now_expression_id);
		}

		printf(ANSI_COLOR_BLUE"variable\n"ANSI_COLOR_RESET);
	}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 358 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(now_expression_id != NULL) {
			printf("not found: %s\n", now_expression_id);
			free(now_expression_id);
		}

		printf(ANSI_COLOR_BLUE"function\n"ANSI_COLOR_RESET);
	}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 366 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(now_expression_id != NULL) {
			printf("not found: %s\n", now_expression_id);
			free(now_expression_id);
		}

		printf(ANSI_COLOR_BLUE"function\n"ANSI_COLOR_RESET);
	}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 374 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(now_expression_id != NULL) {
			printf("not found: %s\n", now_expression_id);
			free(now_expression_id);
		}

		printf(ANSI_COLOR_BLUE"variable\n"ANSI_COLOR_RESET);
	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 382 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(now_expression_id != NULL) {
			printf("not found: %s\n", now_expression_id);
			free(now_expression_id);
		}

		printf(ANSI_COLOR_BLUE"variable\n"ANSI_COLOR_RESET);
	}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 392 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(!lookup_symbol((yyvsp[0].str_val)))
			now_expression_id = strdup((yyvsp[0].str_val));
		printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET, (yyvsp[0].str_val));
	}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 397 "compiler_hw2.y" /* yacc.c:1646  */
    {printf(ANSI_COLOR_RED"constant\n"ANSI_COLOR_RESET);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 398 "compiler_hw2.y" /* yacc.c:1646  */
    {printf(ANSI_COLOR_RED"boolean\n"ANSI_COLOR_RESET);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 399 "compiler_hw2.y" /* yacc.c:1646  */
    {printf(ANSI_COLOR_RED"compound_statement\n"ANSI_COLOR_RESET);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 414 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		insert_attribute(scope_num, (yyvsp[-1].str_val));
		insert_symbol(scope_num+1, (yyvsp[0].str_val), "parameter", (yyvsp[-1].str_val), "");
	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 418 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		insert_attribute(scope_num, (yyvsp[-1].str_val));
		insert_symbol(scope_num+1, (yyvsp[0].str_val), "parameter", (yyvsp[-1].str_val), "");
	}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1799 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 448 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
	create_symbol();
    yyparse();
	if(!if_syntax_error) {
		dump_symbol();
		printf("\nTotal lines: %d \n",yylineno);
		--scope_num;
	}
    return 0;
}

void yyerror(char *s)
{
	printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() 
{
	/* Initialize a dumb head of symbol table */
	symbol_table_head = (Symbol_table*)malloc(sizeof(Symbol_table));
	symbol_table_head->index = -1;
	symbol_table_head->name = NULL;
	symbol_table_head->kind = NULL;
	symbol_table_head->type = NULL;
	symbol_table_head->scope = -1;
	symbol_table_head->attribute = NULL;
	symbol_table_head->next = NULL;
	symbol_table_head->prev = NULL;
	symbol_table_tail = symbol_table_head;
}

void insert_symbol(int scope, char* name, char* kind, char* type, char* attribute) 
{
	Symbol_table* new_symbol = (Symbol_table*)malloc(sizeof(Symbol_table));
	/* If the prev symbol's scope isn't the same as the new symbol, reset index to 0 */
	if(scope != symbol_table_tail->scope) 
		new_symbol->index = 0;
	/* If the prev symbol's scope is the same as the new symbol, increase the index */
	else
		new_symbol->index = symbol_table_tail->index + 1;
	new_symbol->name = (char*)malloc(strlen(name)+1);
	strcpy(new_symbol->name, name);
	new_symbol->kind = (char*)malloc(strlen(kind)+1);
	strcpy(new_symbol->kind, kind);
	new_symbol->type = (char*)malloc(strlen(type)+1);
	strcpy(new_symbol->type, type);
	new_symbol->scope = scope;
	new_symbol->attribute = (char*)malloc(strlen(attribute)+1);
	strcpy(new_symbol->attribute, attribute);
	/* Concat new symbol to the tail of the symbol table, set the new tail to be this new symbol */
	new_symbol->prev = symbol_table_tail;
	new_symbol->next = NULL;
	symbol_table_tail->next = new_symbol;
	symbol_table_tail = new_symbol;
}

int lookup_symbol(char* name) {
	/* look back from tail to head, for better performance */
	Symbol_table* symbol_lookup = symbol_table_tail;
	while(symbol_lookup != symbol_table_head) {
		/* If we find a variable/function previously defined at the same scope */
		if(!strcmp(symbol_lookup->name, name) && symbol_lookup->scope == scope_num) 
			return 2;	// For redeclared, as for undeclared only check if it's true
		/* If we find a variable/function previously defined at the lower scope */
		if(!strcmp(symbol_lookup->name, name) && symbol_lookup->scope < scope_num)
			return 1;	// For redeclared, as for undeclared only check if it's true
		symbol_lookup = symbol_lookup->prev;
	}
	return 0;	// For variable/function not found
}

void dump_symbol() {
	Symbol_table* symbol_dumped = symbol_table_tail;
	char* print_out_dumped = NULL;	// For storing the dump variable's data, because we dump symbols from tail to head, need to reverse
	/* Only if the symbol's scope is equal to the scope_num, then we need to dump it */
	while(symbol_dumped->scope == scope_num && scope_num != -1) { 
		/* get the length of line of print out this dumped symbol's data */
		ssize_t dumped_line_length = snprintf(NULL, 0, "%-10d%-10s%-12s%-10s%-10d", symbol_dumped->index, symbol_dumped->name, 
														symbol_dumped->kind, symbol_dumped->type, 
														symbol_dumped->scope) + 1;
		/* Temporary store the line of this dumped symbol */
		char* dumped_line = (char*)malloc(dumped_line_length);
		snprintf(dumped_line, dumped_line_length, "%-10d%-10s%-12s%-10s%-10d", symbol_dumped->index, symbol_dumped->name, 
														symbol_dumped->kind, symbol_dumped->type, 
														symbol_dumped->scope);
		/* If this symbol has attribute */
		if(strcmp(symbol_dumped->attribute, "")) {
			dumped_line = (char*)realloc(dumped_line, strlen(dumped_line) + strlen(symbol_dumped->attribute) + 1);
			dumped_line_length += strlen(symbol_dumped->attribute);
			strcat(dumped_line, symbol_dumped->attribute);
		}

		/* Concat \n */
		dumped_line = (char*)realloc(dumped_line, strlen(dumped_line) + strlen("\n") + 1);
		dumped_line_length += strlen("\n");
		strcat(dumped_line, "\n");

		/* For copying first dumped symbol's data */
		if(print_out_dumped == NULL)
			print_out_dumped = strdup(dumped_line);
		/* For copying last dumped symbol, with putting new dumped symbol's data to the front of the string */	
		else {
			char* temp = strdup(print_out_dumped);
			print_out_dumped = (char*)malloc(dumped_line_length);
			strcpy(print_out_dumped, dumped_line);
			print_out_dumped = (char*)realloc(print_out_dumped, strlen(temp)+dumped_line_length);
			strcat(print_out_dumped, temp);
		}
		/* Free the last symbol in the symbol table */
		free(symbol_dumped->name);
		free(symbol_dumped->kind);
		free(symbol_dumped->type);
		free(symbol_dumped->attribute);
		Symbol_table* prev_symbol = symbol_dumped->prev;
		prev_symbol->next = NULL;
		symbol_dumped->prev = NULL;
		symbol_dumped->next = NULL;
		free(symbol_dumped);
		/* Set the next dump symbol to the dumped prev */
		symbol_dumped = prev_symbol;
		/* Reset the tail of the symbol table */
		symbol_table_tail = symbol_dumped;
	}
	/* If there are some dumped symbols need to print out */
	if(print_out_dumped != NULL) {
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n%s\n",
			"Index", "Name", "Kind", "Type", "Scope", "Attribute", print_out_dumped);
	}
}

void insert_attribute(int scope, char* type) {
	/* If the function of the parameters belong to hasn't been inserted to symbol table */
	if(attribute_count == 0)
		insert_symbol(scope, "", "function", "", type);
	/* If function is in the symbol table */
	else {
		Symbol_table* function_symbol = symbol_table_tail;
		while(function_symbol->scope != scope) 
			function_symbol = function_symbol->prev;
		char* append_attribute = (char*)malloc(sizeof(char) * 3);
		strcpy(append_attribute, ", ");
		append_attribute = (char*)realloc(append_attribute, strlen(append_attribute)+strlen(type)+1);
		strcat(append_attribute, type);
		function_symbol->attribute = realloc(function_symbol->attribute, strlen(function_symbol->attribute)+strlen(append_attribute)+1);
		strcat(function_symbol->attribute, append_attribute);
	}
	++attribute_count;
	if_insert_attribute = 1;
}

void remove_symbol_parameter() {
	Symbol_table* remove_parameter = symbol_table_tail;
	while(strcmp(remove_parameter->kind, "function")) {
		free(remove_parameter->name);
		free(remove_parameter->kind);
		free(remove_parameter->type);
		free(remove_parameter->attribute);
		Symbol_table* prev_symbol = remove_parameter->prev;
		prev_symbol->next = NULL;
		remove_parameter->prev = NULL;
		remove_parameter->next = NULL;
		free(remove_parameter);
		remove_parameter = prev_symbol;
		symbol_table_tail = remove_parameter;
	}
}

void semantic_error() {
}

void syntax_error() {

}

void print_test() {
	Symbol_table* test = symbol_table_head->next;
	while(test != NULL) {
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
			test->index, test->name, test->kind, test->type, test->scope, test->attribute);
		test = test->next;
	}
}
