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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
extern int yylineno;
extern int yylex();
extern void yyerror(char*);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex


FILE *file; // To generate .j file for Jasmin

/* symbol table functions */
int lookup_symbol(char*);
void create_symbol();
void insert_symbol(int, char*, char*, char*, char*);
void dump_symbol();
void insert_attribute(int, char*);
void remove_symbol_parameter();
void undeclared_error();
void semantic_error();
void print_error_msg();
void clear_expression();
void print_test();

/* Global variables */
int scope_num = 0;
int if_insert_attribute = 0;
int is_function = 0;
int attribute_count = 0;
int need_dump = 0;
int syntax_error_flag = 0;
int if_undeclared = 0;
int if_print_error = 0;
int if_printed = 0;
char error_msg[5][256]; // For multiple error in a line
char** expression_id;
int* expression_id_exist;
char** expression_id_type;
int expression_id_num = 0;
int expression_id_type_num = 0;
int error_flag = 0;         // If error occurred, flag up
int declaration_has_value = 0;
int error_msg_count = 0;
char* now_function_type;    // For storing the function type now is insided
int relational_type = 0;   // For storing the relation type
int while_label = 0;  // For storing the while begin label
int while_true_label = 0;   // For storing the while true label
int while_false_label = 0;  // For storing the while false label
int if_label = 0;   // For storing the if begin label
int if_true_label = 0;  // For storing the if true label
int if_false_label = 0; // For storing the if false label
int argument_num = 0;   // For storing the argument num in this function call
float argument_spec[64][6];   // For storing the spec of each argument
int has_postfix = 0;    // For one more iload

// int now_variable_type = -1; // For storing the variable type now is accessing
// int now_variable_value = 0; // For storing the variable value now is accessing

/* Symbol table */
typedef struct data {
	int index;
	char* name;
	char* kind;
	char* type;
	int scope;
	char* attribute;
    float value;
	struct data* next;
	struct data* prev;
} Symbol_table;
Symbol_table* symbol_table_head;	// Head of linked list for dynamic storing symbols
Symbol_table* symbol_table_tail;	// Tail of linked list for dynamic storing symbols

/* code generation functions, just an example! */
void gencode_function(char*);
void gencode_variable_declaration(char*, char*);
void gencode_string_const(char*);
char* get_type_bytecode(char*);
float get_symbol_value(char*);
void set_symbol_value(char*, float);
int get_symbol_type(char*);
int get_symbol_index(char*);
int get_symbol_scope_num(char*);
int is_global_symbol(char*);
void gencode_load_value(float*);
Symbol_table* get_global_symbol(int);
void gencode_postfix(float*, int);
void gencode_store_global(char*, char*);
void gencode_unary_operator(float*, int);
void gencode_calculation(float*, float*, int);
void gencode_relational(float*, float*, int);
void gencode_print_function(float*);
int is_parameter_match(char*, int);
void gencode_call_function(char*);

/* For debugging colorful text */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#line 175 "y.tab.c" /* yacc.c:339  */

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
#line 111 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* str_val;
    /* 
        exp_spec[0]: type, 0: int, 1: float, 2: bool, 3: string
        exp_spec[1]: value, 0 for string
        exp_spec[2]: global: 0, local: 1, const: -1
        exp_spec[3]: global: index, local: stack_num, const: -1
        exp_spec[4]: if value is from id or not
        exp_spec[5]: if generated code or not
    */
    float exp_spec[6];
    /* 
        For while:
            nest_spec[0]: false_label
            nest_spec[1]: exit_label
        
        For if-else:
            nest_spec[0]: false_label
            nest_spec[1]: exit_label
     */
    int nest_spec[2];

#line 338 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 355 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

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
       0,   171,   171,   172,   173,   177,   178,   182,   186,   270,
     271,   276,   282,   293,   294,   298,   299,   303,   304,   305,
     306,   307,   308,   312,   313,   317,   323,   332,   349,   404,
     408,   426,   480,   491,   498,   525,   532,   611,   700,   701,
     702,   703,   704,   709,   713,   717,   724,   735,   736,   737,
     738,   739,   740,   744,   752,  1018,  1026,  1038,  1050,  1062,
    1074,  1086,  1101,  1109,  1124,  1143,  1151,  1167,  1189,  1215,
    1223,  1258,  1294,  1313,  1314,  1318,  1333,  1352,  1369,  1412,
    1457,  1505,  1524,  1543,  1565,  1573,  1581,  1593,  1601,  1612,
    1616,  1623,  1632,  1644
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
  "expression_statement", "selection_statement", "if_start", "if",
  "else_start", "iteration_statement", "while_start", "while",
  "jump_statement", "print_statement", "declaration", "type", "declarator",
  "initializer", "assignment_operator", "assignment_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "unary_operator",
  "postfix_expression", "primary_expression", "constant", "boolean",
  "parameter_list", "argument_expression_list", "expression", YY_NULLPTR
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

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -47,   -47,   -47,   -47,   -47,    30,   -47,   -47,   105,
     -47,   -34,   -47,   -47,   -47,   -47,   160,   160,   160,   -47,
     -47,    -8,     3,   -47,   -47,   -47,    17,   -47,   -47,   -47,
     -47,   -47,   -47,   105,   -47,   105,   -47,   -47,   -47,   -47,
       1,     4,   -47,     4,    14,   -47,   -47,   -47,   -34,   -47,
     161,    29,    50,   163,   160,   -47,     2,   -47,   -47,    -4,
     -47,    56,   -47,   -47,    19,   160,   160,   -47,    13,   -47,
     -47,   -47,     4,   -47,   -47,   -47,   160,    -7,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   -47,
     -47,   -47,   -47,   -47,   -47,   160,   -47,   -47,   -47,   152,
     -47,   160,    84,   -47,   -47,   -47,    51,    70,   -47,   -47,
      72,    29,   -47,    29,    29,    29,    29,    29,    50,    50,
     -47,   -47,   -47,   -47,   -47,   -47,   -12,    31,   -47,   -47,
     -34,    49,    54,   -47,   -47,   -47,   160,   -47,    75,   -47,
      66,   -47,   -47,   -34,    75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    42,    38,    39,    41,    40,     0,     2,     6,     0,
       5,     0,     1,     3,    73,    74,     0,     0,     0,    11,
      12,     0,     0,    32,    87,    88,     0,    23,    84,    85,
      86,    80,     7,     0,     9,     0,    13,    16,    18,    19,
      25,     0,    20,     0,     0,    21,    22,    15,     0,    93,
      53,    55,    62,    65,     0,    69,    75,    81,    82,     0,
      43,     0,    70,    71,     0,     0,     0,    33,     0,    17,
      10,    14,     0,    26,    27,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      51,    52,    48,    49,    50,     0,    72,    78,    79,     0,
      24,     0,     0,    37,     8,    83,     0,     0,    34,    29,
       0,    56,    65,    57,    58,    59,    60,    61,    63,    64,
      66,    67,    68,    54,    76,    91,     0,     0,    46,    45,
       0,     0,     0,    28,    31,    77,     0,    36,    89,    44,
       0,    35,    92,     0,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   106,   -47,   -47,    78,    55,    80,   -47,    82,
     -38,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,    16,     0,   -46,   -47,   -47,   -17,   -47,   108,   -11,
       7,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    73,    42,    43,    44,    45,
      46,    47,    48,    61,   127,    95,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   131,   126,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    64,    77,    74,    68,    75,    11,    14,    15,   101,
      97,    98,    16,    17,   135,    60,    10,    65,   102,   136,
      14,    15,    10,    62,    63,    16,    17,    99,    66,    18,
      12,    19,    84,    85,   109,    72,    21,    22,   103,    76,
      23,   100,    18,   106,   107,   105,    24,    25,    26,    27,
      28,    29,    30,    31,   110,    86,    87,    88,   108,    24,
      25,    96,    67,    28,    29,    30,    31,     1,     2,     3,
       4,     5,   101,   118,   119,   139,   137,   132,   123,   128,
     140,   102,   125,    19,   138,   112,   112,   112,   112,   112,
     112,   112,   112,   120,   121,   122,   133,   144,   134,   141,
     102,   103,   130,     1,     2,     3,     4,     5,    14,    15,
     129,    69,    13,    16,    17,    70,   104,    71,     0,   142,
       0,     1,     2,     3,     4,     5,     0,     0,     0,     0,
      18,     0,    19,    20,     0,     0,     0,    21,    22,     0,
     143,    23,     1,     2,     3,     4,     5,    24,    25,    26,
      27,    28,    29,    30,    31,    14,    15,     0,     0,     0,
      16,    17,     0,    14,    15,     0,     0,     0,    16,    17,
       0,    78,    79,    80,    81,    82,    83,    18,   124,    89,
      90,    91,    92,    93,    94,    18,   111,   113,   114,   115,
     116,   117,     0,     0,    24,    25,     0,     0,    28,    29,
      30,    31,    24,    25,     0,     0,    28,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
       0,    18,    48,    41,    26,    43,     6,     3,     4,    16,
       8,     9,     8,     9,    26,    49,     0,    25,    25,    31,
       3,     4,     6,    16,    17,     8,     9,    25,    25,    25,
       0,    27,     3,     4,    72,    34,    32,    33,    45,    25,
      36,    45,    25,    65,    66,    26,    42,    43,    44,    45,
      46,    47,    48,    49,    76,     5,     6,     7,    45,    42,
      43,    54,    45,    46,    47,    48,    49,    37,    38,    39,
      40,    41,    16,    84,    85,    26,    45,    26,    95,   101,
      31,    25,    99,    27,   130,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    26,   143,    26,    45,
      25,    45,   102,    37,    38,    39,    40,    41,     3,     4,
      26,    33,     6,     8,     9,    35,    61,    35,    -1,   136,
      -1,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    -1,    -1,    -1,    32,    33,    -1,
     140,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     3,     4,    -1,    -1,    -1,
       8,     9,    -1,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    10,    11,    12,    13,    14,    15,    25,    26,    16,
      17,    18,    19,    20,    21,    25,    78,    79,    80,    81,
      82,    83,    -1,    -1,    42,    43,    -1,    -1,    46,    47,
      48,    49,    42,    43,    -1,    -1,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,    39,    40,    41,    51,    52,    53,    54,
      71,    72,     0,    52,     3,     4,     8,     9,    25,    27,
      28,    32,    33,    36,    42,    43,    44,    45,    46,    47,
      48,    49,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    67,    68,    69,    70,    71,    72,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    88,
      49,    73,    80,    80,    76,    25,    25,    45,    88,    55,
      57,    59,    34,    65,    60,    60,    25,    73,    10,    11,
      12,    13,    14,    15,     3,     4,     5,     6,     7,    16,
      17,    18,    19,    20,    21,    75,    80,     8,     9,    25,
      45,    16,    25,    45,    56,    26,    88,    88,    45,    60,
      88,    78,    80,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    76,    26,    76,    87,    74,    88,    26,
      72,    86,    26,    26,    26,    26,    31,    45,    73,    26,
      31,    45,    76,    72,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    64,    65,
      66,    67,    68,    69,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    73,    73,    74,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     2,     3,     1,
       2,     1,     1,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     2,     4,     2,
       2,     4,     1,     2,     3,     5,     5,     3,     1,     1,
       1,     1,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     1,     1,     1,     3,     4,     2,     2,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       4,     1,     3,     1
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
#line 186 "compiler_hw3.y" /* yacc.c:1646  */
    { 		
		int is_duplicated = 0;
		int has_parameter = 0;
		Symbol_table* find_function = symbol_table_tail;
		/* Find duplicated */
		while(find_function != symbol_table_head) {
			/* If this function has forward declaration */
			if(!strcmp(find_function->name, (yyvsp[-1].str_val))) {
				is_duplicated = 1;
				Symbol_table* duplicated = find_function;
				/* Duplicated function must added after the forward delcaration */
				while(duplicated != symbol_table_tail) {
					if(!strcmp(duplicated->kind, "function") && !strcmp(duplicated->name, "")) {	
                        /* If forward declaration's return type is not the same as the function definition's */
                        if(strcmp((yyvsp[-2].str_val), find_function->type))        
                            semantic_error("function return type is not the same", "");  
                        /* If forward declaration's attribute is not the same as the function definition's */
                        if(strcmp(duplicated->attribute, find_function->attribute)) 
                            semantic_error("function formal parameter is not the same", "");    
                          
                        free(duplicated->kind);
                        free(duplicated->attribute);
						Symbol_table* prev = duplicated->prev;
						Symbol_table* next = duplicated->next;
						if(prev != NULL)
							prev->next = next;
						if(next != NULL)
							next->prev = prev;
						free(duplicated);
						break;
					}
					duplicated = duplicated->next;
				}
				break;
			}
			find_function = find_function->prev;
		}
		find_function = symbol_table_tail;
		/* Find function with parameter, has a template in symbol table, but no forward declaration */
		if(!is_duplicated) {
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
		}
		/* If no duplicated && no parameter, initialize the function */
		if(!is_duplicated && !has_parameter) 
			insert_symbol(0, (yyvsp[-1].str_val), "function", (yyvsp[-2].str_val), "");	
        /* Generate java bytecode */
        gencode_function(".method public static ");
        gencode_function((yyvsp[-1].str_val));
        /* If this is main function, generate specialized parameter */
        if(!strcmp((yyvsp[-1].str_val), "main")) 
            gencode_function("([Ljava/lang/String;)");
        else {
            gencode_function("(");
            if(has_parameter) {
                char* para_type = strtok(find_function->attribute, ", ");
                while(para_type != NULL) {
                    gencode_function(get_type_bytecode(para_type));
                    para_type = strtok(NULL, ", ");
                }
            }
            gencode_function(")");
        }
        gencode_function(get_type_bytecode((yyvsp[-2].str_val)));
        gencode_function("\n.limit stack 50\n");
		gencode_function(".limit locals 50\n");
        /* Copy the function return type for later usage */
        now_function_type = strdup((yyvsp[-2].str_val));
        attribute_count = 0;
		is_function = 0;
	}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		 ++scope_num;
	}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 282 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		/* if scope number before '}' is 1, and there string in now_function_type, then this '}' must be the end of the function */
        if(scope_num == 1 && strcmp(now_function_type, "")) {
            gencode_function(".end method\n");
            free(now_function_type);
        }
        need_dump = 1;
	}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 317 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* Gen if exit label */
        char exit_label[64];
        sprintf(exit_label, "IF_EXIT_%d:\n", (yyvsp[0].nest_spec)[1]);
        gencode_function(exit_label);
    }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 323 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* Gen if exit label */
        char exit_label[64];
        sprintf(exit_label, "IF_EXIT_%d:\n", (yyvsp[-1].nest_spec)[1]);
        gencode_function(exit_label);
    }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 332 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char exit_label[64];
        /* If if finish, goto if exit */
        sprintf(exit_label, "\tgoto IF_EXIT_%d\n", (yyvsp[-1].nest_spec)[1]);
        gencode_function(exit_label);
        
        /* Gen if false label */
        char false_label[64];
        sprintf(false_label, "IF_FALSE_%d:\n", (yyvsp[-1].nest_spec)[0]);
        gencode_function(false_label);

        /* store this if's false label, prevent nested if label error  */
        (yyval.nest_spec)[0] = (yyvsp[-1].nest_spec)[0];
    }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 349 "compiler_hw3.y" /* yacc.c:1646  */
    {
        switch(relational_type) {
            /* MT */
            case 0:
                gencode_function("\tifgt ");
                break;
            /* LT */
            case 1:
                gencode_function("\tiflt ");
                break;
            /* MTE */
            case 2:
                gencode_function("\tifge ");
                break;
            /* LTE */
            case 3:
                gencode_function("\tifle ");
                break;
            /* EQ */
            case 4:
                gencode_function("\tifeq ");
                break;
            /* NE */
            case 5:
                gencode_function("\tifne ");
                break;

        }
        char true_label[64];
        char false_label[64];

        /* Gen if if is true, go to true label */
        sprintf(true_label, "IF_TRUE_%d", if_true_label);
        gencode_function(true_label);
        gencode_function("\n");

        /* Gen if if is false, go to false label */
        sprintf(false_label, "\tgoto IF_FALSE_%d\n", if_false_label);
        gencode_function(false_label);

        /* True label start */
        gencode_function(true_label);
        gencode_function(":\n");

        /* Store this if's false & exit label, prevent nested if label error */
        (yyval.nest_spec)[0] = if_false_label;
        (yyval.nest_spec)[1] = if_label;

        ++if_label;
        ++if_true_label;
        ++if_false_label;
    }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 408 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char label[64];
        /* At the end of while, gen go back to while begin */
        sprintf(label, "\tgoto WHILE_BEGIN_%d\n", (yyvsp[-1].nest_spec)[1]);
        gencode_function(label);
        /* Gen while false label */
        sprintf(label, "WHILE_FALSE_%d:\n", (yyvsp[-1].nest_spec)[0]);
        gencode_function(label);
        /* If while false, goto while exit */
        sprintf(label, "\tgoto WHILE_EXIT_%d\n", (yyvsp[-1].nest_spec)[1]);
        gencode_function(label);
        /* Gen while exit label */
        sprintf(label, "WHILE_EXIT_%d:\n", (yyvsp[-1].nest_spec)[1]);
        gencode_function(label);
    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 426 "compiler_hw3.y" /* yacc.c:1646  */
    {
        switch(relational_type) {
            /* MT */
            case 0:
                gencode_function("\tifgt ");
                break;
            /* LT */
            case 1:
                gencode_function("\tiflt ");
                break;
            /* MTE */
            case 2:
                gencode_function("\tifge ");
                break;
            /* LTE */
            case 3:
                gencode_function("\tifle ");
                break;
            /* EQ */
            case 4:
                gencode_function("\tifeq ");
                break;
            /* NE */
            case 5:
                gencode_function("\tifne ");
                break;
        }
        
        char true_label[64];
        char false_label[64];

        /* Gen if while is true, go to true label */
        sprintf(true_label, "WHILE_TRUE_%d", while_true_label);
        gencode_function(true_label);
        gencode_function("\n");

        /* Gen if while is false, go to false label */
        sprintf(false_label, "\tgoto WHILE_FALSE_%d\n", while_false_label);
        gencode_function(false_label);

        /* True label start */
        gencode_function(true_label);
        gencode_function(":\n");

        /* Store this while's false & exit label, prevent nested while label error */
        (yyval.nest_spec)[0] = while_false_label;
        (yyval.nest_spec)[1] = (yyvsp[-3].nest_spec)[1];

        ++while_true_label;
        ++while_false_label;
    }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 480 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char label[64];
        sprintf(label, "WHILE_BEGIN_%d:\n", while_label);
        gencode_function(label);
        /* store this while's exit label, prevent nested while label error  */
        (yyval.nest_spec)[1] = while_label;
        ++while_label;
    }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 491 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* If the function return value in a void function, raise error */
        if(strcmp(now_function_type, "void"))
            semantic_error("Return value in a function returning void");
        else
            gencode_function("\treturn\n");
    }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 498 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_load_value((yyvsp[-1].exp_spec));
        if(!strcmp(now_function_type, "int")) {
            if((yyvsp[-1].exp_spec)[0] == 1)  
                gencode_function("\tf2i\n");    
            gencode_function("\tireturn\n");
        }
        else if(!strcmp(now_function_type, "float")) {
            if((yyvsp[-1].exp_spec)[0] == 0 || (yyvsp[-1].exp_spec)[0] == 2)  
                gencode_function("\ti2f\n");    
            gencode_function("\tfreturn\n");
        }
        else if(!strcmp(now_function_type, "bool")) {
            if((yyvsp[-1].exp_spec)[0] == 1)  
                gencode_function("\tf2i\n");    
            gencode_function("\tireturn\n");
        }
        else if(!strcmp(now_function_type, "string")) {
            gencode_function("\tareturn\n");
        }
        else {
            semantic_error("Return value isn't match function return type");
        }
    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 525 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_load_value((yyvsp[-2].exp_spec));
        gencode_print_function((yyvsp[-2].exp_spec));
    }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 532 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		declaration_has_value = 1;
        /* If it is function declaration */
		if(is_function) {
			if(lookup_symbol((yyvsp[-3].str_val))) {
				Symbol_table* find_function = symbol_table_tail;
                /* Find duplicated */
                while(find_function != symbol_table_head) {
                    /* If this function has forward declaration */
                    if(!strcmp(find_function->name, (yyvsp[-3].str_val))) {
                        Symbol_table* duplicated = find_function;
                        /* Duplicated function must added after the forward delcaration */
                        while(duplicated != symbol_table_tail) {
                            if(!strcmp(duplicated->kind, "function") && !strcmp(duplicated->name, "")) {	
                                free(duplicated->kind);
                                Symbol_table* prev = duplicated->prev;
                                Symbol_table* next = duplicated->next;
                                if(prev != NULL)
                                    prev->next = next;
                                if(next != NULL)
                                    next->prev = prev;
                                free(duplicated);
                                break;
                            }
                            duplicated = duplicated->next;
                        }
                        break;
                    }
                    find_function = find_function->prev;
                }
                semantic_error("Redeclared function", (yyvsp[-3].str_val));
			}
			/* If need to remove the parameter inside the symbol table */
			if(if_insert_attribute) {
			/* Remove the parameters */
				remove_symbol_parameter();
				/* Set the function declaration data in the symbol table */
				Symbol_table* find_function = symbol_table_tail;
				find_function->name = malloc(strlen((yyvsp[-3].str_val)) + 1);
				strcpy(find_function->name, (yyvsp[-3].str_val));
				find_function->type = malloc(strlen((yyvsp[-4].str_val)) + 1);
				strcpy(find_function->type, (yyvsp[-4].str_val));
				if_insert_attribute = 0;
				attribute_count = 0;
				is_function = 0;
			}
			/* If this function doesn't have any parameter, just insert the function */
			else {
				insert_symbol(scope_num, (yyvsp[-3].str_val), "function", (yyvsp[-4].str_val), "");
			}
		}
		/* For variable declaration */
		else {
			switch(lookup_symbol((yyvsp[-3].str_val))) {
				/* For variable isn't in the symbol table or in the lower scope */
				case 0: case 1:
                    /* Insert into symbol table first, for later gen code search */
					insert_symbol(scope_num, (yyvsp[-3].str_val), "variable", (yyvsp[-4].str_val), "");
                    /* If is local, need to gen load, and need to check type*/
                    if(!is_global_symbol((yyvsp[-3].str_val))) {
                        gencode_load_value((yyvsp[-1].exp_spec));
                        /* declarator is int, initializer is float */
                        if(!strcmp((yyvsp[-4].str_val), "int") && (yyvsp[-1].exp_spec)[0] == 1)
                            gencode_function("\tf2i\n");
                        /* declarator is float, initializer is int  */
                        else if(!strcmp((yyvsp[-4].str_val), "float") && (yyvsp[-1].exp_spec)[0] == 0)
                            gencode_function("\ti2f\n");
                    }
                    /* Set value into symbol table */
                    set_symbol_value((yyvsp[-3].str_val), (yyvsp[-1].exp_spec)[1]);
                    gencode_variable_declaration((yyvsp[-4].str_val), (yyvsp[-3].str_val));
					break;
				/* For the variable is in the same scope, print error */
				case 2:
					semantic_error("Redeclared variable", (yyvsp[-3].str_val));
					break;
			}
		}
	}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 611 "compiler_hw3.y" /* yacc.c:1646  */
    {
        declaration_has_value = 0;
        /* If it is function declaration */
		if(is_function) {
			if(lookup_symbol((yyvsp[-1].str_val))) {
				Symbol_table* find_function = symbol_table_tail;
                /* Find duplicated */
                while(find_function != symbol_table_head) {
                    /* If this function has forward declaration */
                    if(!strcmp(find_function->name, (yyvsp[-1].str_val))) {
                        Symbol_table* duplicated = find_function;
                        /* Duplicated function must added after the forward delcaration */
                        while(duplicated != symbol_table_tail) {
                            if(!strcmp(duplicated->kind, "function") && !strcmp(duplicated->name, "")) {	
                                free(duplicated->kind);
                                Symbol_table* prev = duplicated->prev;
                                Symbol_table* next = duplicated->next;
                                if(prev != NULL)
                                    prev->next = next;
                                if(next != NULL)
                                    next->prev = prev;
                                free(duplicated);
                                break;
                            }
                            duplicated = duplicated->next;
                        }
                        break;
                    }
                    find_function = find_function->prev;
                }
                semantic_error("Redeclared function", (yyvsp[-1].str_val));
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
                    /* Insert into symbol table first, for later gen code search */
					insert_symbol(scope_num, (yyvsp[-1].str_val), "variable", (yyvsp[-2].str_val), "");
                    /* If is not global, need to load */
                    if(!is_global_symbol((yyvsp[-1].str_val))) { 
                        char value[64];
                        /* Default value for int / bool is 0 */
                        if(!strcmp((yyvsp[-2].str_val), "int") || !strcmp((yyvsp[-2].str_val), "bool")) {
                            sprintf(value, "\tldc %d\n", 0);
                        }
                        /* Default value for int is 0.0 */
                        else if(!strcmp((yyvsp[-2].str_val), "float")) {
                            sprintf(value, "\tldc %f\n", 0.0);
                        }
                        /* Default value for string is "" */
                        else if(!strcmp((yyvsp[-2].str_val), "string")) {
                            sprintf(value, "\tldc \"\"\n");
                        }
                        gencode_function(value);
                    }
                    /* Set value into symbol table */
                    set_symbol_value((yyvsp[-1].str_val), 0.0);
                    gencode_variable_declaration((yyvsp[-2].str_val), (yyvsp[-1].str_val));
					break;
				/* For the variable is in the same scope, print error */
				case 2:
					semantic_error("Redeclared variable", (yyvsp[-1].str_val));
					break;
			}
		}
    }
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 700 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.str_val) = "int";}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 701 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.str_val) = "float";}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 702 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.str_val) = "bool";}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 703 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.str_val) = "string";}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 704 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.str_val) = "void";}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 709 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		is_function = 0; 
		(yyval.str_val) = (yyvsp[0].str_val); 
	}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 713 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		is_function = 1; 
		(yyval.str_val) = (yyvsp[-3].str_val); 
	}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 717 "compiler_hw3.y" /* yacc.c:1646  */
    {
		is_function = 1; 
		(yyval.str_val) = (yyvsp[-2].str_val); 
	}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 724 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
    }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 735 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "ASGN"; }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 736 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "MULASGN"; }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 737 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "DIVASGN"; }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 738 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "MODASGN"; }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 739 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "ADDASGN"; }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 740 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "SUBASGN"; }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 744 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
    }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 752 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!strcmp((yyvsp[-1].str_val), "ASGN")) {
            /* If $3 hasn't been loaded */
            if(!(yyvsp[0].exp_spec)[5])
                gencode_load_value((yyvsp[0].exp_spec));
            /* If $1 is global */
            if(!(yyvsp[-2].exp_spec)[2]){
                if((yyvsp[-2].exp_spec)[0] == 0 && (yyvsp[0].exp_spec)[1] == 1) 
                    gencode_function("\tf2i\n");
                if((yyvsp[-2].exp_spec)[0] == 1 && (yyvsp[0].exp_spec)[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol((yyvsp[-2].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)(yyvsp[-2].exp_spec)[0]) {
                    case 0: case 2:
                        if((yyvsp[0].exp_spec)[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if((yyvsp[0].exp_spec)[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[-2].exp_spec)[3]);
                gencode_function(stack_num);
            }  
        }
        else if(!strcmp((yyvsp[-1].str_val), "MULASGN")) {
            gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 2);
            /* Either var1 or var2 is float, return float */
            if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
                (yyval.exp_spec)[0] = 1;
            /* Both var1 and var2 are int */
            else
            (yyval.exp_spec)[0] = 0;
            (yyvsp[-2].exp_spec)[1] = (yyvsp[-2].exp_spec)[1] * (yyvsp[0].exp_spec)[1];
            (yyvsp[-2].exp_spec)[5] = 1;
            /* If $1 is global */
            if(!(yyvsp[-2].exp_spec)[2]){
                if((yyvsp[-2].exp_spec)[0] == 0 && (yyvsp[0].exp_spec)[1] == 1) 
                    gencode_function("\tf2i\n");
                if((yyvsp[-2].exp_spec)[0] == 1 && (yyvsp[0].exp_spec)[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol((yyvsp[-2].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)(yyvsp[-2].exp_spec)[0]) {
                    case 0: case 2:
                        if((yyvsp[0].exp_spec)[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if((yyvsp[0].exp_spec)[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[-2].exp_spec)[3]);
                gencode_function(stack_num);
            }   
        }
        else if(!strcmp((yyvsp[-1].str_val), "DIVASGN")) {
            /* If divisor is 0, raise error */
            if((yyvsp[0].exp_spec)[1] == 0) {
                semantic_error("Divided by Zero", "");
                (yyval.exp_spec)[1] = 0;
            }
            else {
                gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 3);
                /* Either var1 or var2 is float, return float */
                if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
                    (yyval.exp_spec)[0] = 1;
                /* Both var1 and var2 are int */
                else
                (yyval.exp_spec)[0] = 0;
                (yyvsp[-2].exp_spec)[1] = (yyvsp[-2].exp_spec)[1] / (yyvsp[0].exp_spec)[1];
                (yyvsp[-2].exp_spec)[5] = 1;
                /* If $1 is global */
                if(!(yyvsp[-2].exp_spec)[2]){
                    if((yyvsp[-2].exp_spec)[0] == 0 && (yyvsp[0].exp_spec)[1] == 1) 
                        gencode_function("\tf2i\n");
                    if((yyvsp[-2].exp_spec)[0] == 1 && (yyvsp[0].exp_spec)[1] == 0) 
                        gencode_function("\ti2f\n");
                    Symbol_table *global_symbol = get_global_symbol((yyvsp[-2].exp_spec)[3]);
                    gencode_store_global(global_symbol->name, global_symbol->type);
                }
                /* If $1 is local */
                else {
                    char stack_num[64];
                    switch((int)(yyvsp[-2].exp_spec)[0]) {
                        case 0: case 2:
                            if((yyvsp[0].exp_spec)[0] == 1)  
                                gencode_function("\tf2i\n");
                            gencode_function("\tistore ");
                            break;
                        case 1:
                            if((yyvsp[0].exp_spec)[0] == 0) 
                                gencode_function("\ti2f\n");
                            gencode_function("\tfstore ");
                            break;
                        case 3:
                            gencode_function("\tastore ");
                            break;
                    }
                    sprintf(stack_num, "%d\n", (int)(yyvsp[-2].exp_spec)[3]);
                    gencode_function(stack_num);
                }  
            } 
        }
        else if(!strcmp((yyvsp[-1].str_val), "MODASGN")) {
            /* Both $1 and $3 must to be int that can mod */
            if ((yyvsp[-2].exp_spec)[0] != 0 || (yyvsp[0].exp_spec)[0] != 0)
                semantic_error("Mod with non integer", "");
            
            /* If mod by 0, invalid */
            if ((yyvsp[0].exp_spec)[1] == 0) 
                semantic_error("Mod by Zero", "");
            /* If error occur, return with 0 */
            if((yyvsp[0].exp_spec)[1] == 0 || (yyvsp[-2].exp_spec)[0] != 1 || (yyvsp[0].exp_spec)[0] != 1) 
                (yyval.exp_spec)[1] = 0;
            else {    
                gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 4);
                /* Either var1 or var2 is float, return float */
                if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
                    (yyval.exp_spec)[0] = 1;
                /* Both var1 and var2 are int */
                else
                (yyval.exp_spec)[0] = 0;
                (yyvsp[-2].exp_spec)[1] = (int)(yyvsp[-2].exp_spec)[1] % (int)(yyvsp[0].exp_spec)[1];
                (yyvsp[-2].exp_spec)[5] = 1;
                /* If $1 is global */
                if(!(yyvsp[-2].exp_spec)[2]){
                    if((yyvsp[-2].exp_spec)[0] == 0 && (yyvsp[0].exp_spec)[1] == 1) 
                        gencode_function("\tf2i\n");
                    if((yyvsp[-2].exp_spec)[0] == 1 && (yyvsp[0].exp_spec)[1] == 0) 
                        gencode_function("\ti2f\n");
                    Symbol_table *global_symbol = get_global_symbol((yyvsp[-2].exp_spec)[3]);
                    gencode_store_global(global_symbol->name, global_symbol->type);
                }
                /* If $1 is local */
                else {
                    char stack_num[64];
                    switch((int)(yyvsp[-2].exp_spec)[0]) {
                        case 0: case 2:
                            if((yyvsp[0].exp_spec)[0] == 1)  
                                gencode_function("\tf2i\n");
                            gencode_function("\tistore ");
                            break;
                        case 1:
                            if((yyvsp[0].exp_spec)[0] == 0) 
                                gencode_function("\ti2f\n");
                            gencode_function("\tfstore ");
                            break;
                        case 3:
                            gencode_function("\tastore ");
                            break;
                    }
                    sprintf(stack_num, "%d\n", (int)(yyvsp[-2].exp_spec)[3]);
                    gencode_function(stack_num);
                }   
            }
        }
        else if(!strcmp((yyvsp[-1].str_val), "ADDASGN")) {
            gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 0);
            /* Either var1 or var2 is float, return float */
            if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
                (yyval.exp_spec)[0] = 1;
            /* Both var1 and var2 are int */
            else
            (yyval.exp_spec)[0] = 0;
            (yyvsp[-2].exp_spec)[1] = (yyvsp[-2].exp_spec)[1] + (yyvsp[0].exp_spec)[1];
            (yyvsp[-2].exp_spec)[5] = 1;
            /* If $1 is global */
            if(!(yyvsp[-2].exp_spec)[2]){
                if((yyvsp[-2].exp_spec)[0] == 0 && (yyvsp[0].exp_spec)[1] == 1) 
                    gencode_function("\tf2i\n");
                if((yyvsp[-2].exp_spec)[0] == 1 && (yyvsp[0].exp_spec)[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol((yyvsp[-2].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)(yyvsp[-2].exp_spec)[0]) {
                    case 0: case 2:
                        if((yyvsp[0].exp_spec)[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if((yyvsp[0].exp_spec)[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[-2].exp_spec)[3]);
                gencode_function(stack_num);
            }   
        }
        else if(!strcmp((yyvsp[-1].str_val), "SUBASGN")) {
            gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 1);
            /* Either var1 or var2 is float, return float */
            if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
                (yyval.exp_spec)[0] = 1;
            /* Both var1 and var2 are int */
            else
            (yyval.exp_spec)[0] = 0;
            (yyvsp[-2].exp_spec)[1] = (yyvsp[-2].exp_spec)[1] - (yyvsp[0].exp_spec)[1];
            (yyvsp[-2].exp_spec)[5] = 1;
            /* If $1 is global */
            if(!(yyvsp[-2].exp_spec)[2]){
                if((yyvsp[-2].exp_spec)[0] == 0 && (yyvsp[0].exp_spec)[1] == 1) 
                    gencode_function("\tf2i\n");
                if((yyvsp[-2].exp_spec)[0] == 1 && (yyvsp[0].exp_spec)[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol((yyvsp[-2].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)(yyvsp[-2].exp_spec)[0]) {
                    case 0: case 2:
                        if((yyvsp[0].exp_spec)[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if((yyvsp[0].exp_spec)[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[-2].exp_spec)[3]);
                gencode_function(stack_num);
            }   
        }
        
        
    }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1018 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
    }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1026 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = 2;
        if((yyvsp[-2].exp_spec)[1] > (yyvsp[0].exp_spec)[1])   
            (yyval.exp_spec)[1] = 1;
        else                
            (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_relational((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 0);
    }
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1038 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = 2;
        if((yyvsp[-2].exp_spec)[1] < (yyvsp[0].exp_spec)[1])   
            (yyval.exp_spec)[1] = 1;
        else                
            (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_relational((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 1);
    }
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1050 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = 2;
        if((yyvsp[-2].exp_spec)[1] >= (yyvsp[0].exp_spec)[1])   
            (yyval.exp_spec)[1] = 1;
        else                
            (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_relational((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 2);
    }
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1062 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = 2;
        if((yyvsp[-2].exp_spec)[1] <= (yyvsp[0].exp_spec)[1])   
            (yyval.exp_spec)[1] = 1;
        else                
            (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_relational((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 3);
    }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1074 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = 2;
        if((yyvsp[-2].exp_spec)[1] == (yyvsp[0].exp_spec)[1])   
            (yyval.exp_spec)[1] = 1;
        else                
            (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_relational((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 4);
    }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1086 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = 2;
        if((yyvsp[-2].exp_spec)[1] != (yyvsp[0].exp_spec)[1])   
            (yyval.exp_spec)[1] = 1;
        else                
            (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_relational((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 5);
    }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1101 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
    }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1109 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* Either var1 or var2 is float, return float */
        if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
            (yyval.exp_spec)[0] = 1;
        /* Both var1 and var2 are int */
        else
            (yyval.exp_spec)[0] = 0;
        
        (yyval.exp_spec)[1] = (yyvsp[-2].exp_spec)[1] + (yyvsp[0].exp_spec)[1]; 
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 0);
    }
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1124 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* Either var1 or var2 is float, return float */
        if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
            (yyval.exp_spec)[0] = 1;
        /* Both var1 and var2 are int */
        else
            (yyval.exp_spec)[0] = 0;
        
        (yyval.exp_spec)[1] = (yyvsp[-2].exp_spec)[1] - (yyvsp[0].exp_spec)[1]; 
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;

        gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 1);
    }
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1143 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
    }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1151 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* Either var1 or var2 is float, return float */
        if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
            (yyval.exp_spec)[0] = 1;
        /* Both var1 and var2 are int */
        else
            (yyval.exp_spec)[0] = 0;
        
        (yyval.exp_spec)[1] = (yyvsp[-2].exp_spec)[1] * (yyvsp[0].exp_spec)[1]; 
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;

        gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 2);
    }
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1167 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* If divisor is 0, raise error, return 0 */
        if((yyvsp[0].exp_spec)[0] == 0) {
            semantic_error("Divided by Zero", "");
            (yyval.exp_spec)[1] = 0;
        }
        else{
            (yyval.exp_spec)[1] = (yyvsp[-2].exp_spec)[1] / (yyvsp[0].exp_spec)[1]; 
        }
        /* Either var1 or var2 is float, return float */
        if((yyvsp[-2].exp_spec)[0] == 1 || (yyvsp[0].exp_spec)[0] == 1)
            (yyval.exp_spec)[0] = 1;
        /* Both var1 and var2 are int */
        else
            (yyval.exp_spec)[0] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;

        gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 3);
    }
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1189 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* Both $1 and $3 must to be int that can mod */
        if ((yyvsp[-2].exp_spec)[0] != 0 || (yyvsp[0].exp_spec)[0] != 0)
            semantic_error("Mod with non integer", "");
        
        /* If mod by 0, invalid */
        if ((yyvsp[0].exp_spec)[1] == 0) 
            semantic_error("Mod by Zero", "");
        
        /* If error occur, return with 0 */
        if((yyvsp[0].exp_spec)[1] == 0 || (yyvsp[-2].exp_spec)[0] != 1 || (yyvsp[0].exp_spec)[0] != 1) 
            (yyval.exp_spec)[1] = 0;
        /* Else return value after mod */
        else 
            (yyval.exp_spec)[1] = (int)(yyvsp[-2].exp_spec)[1] % (int)(yyvsp[0].exp_spec)[1]; 
        
        (yyval.exp_spec)[0] = 0;
        (yyval.exp_spec)[2] = -1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        gencode_calculation((yyvsp[-2].exp_spec), (yyvsp[0].exp_spec), 4);
    }
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1215 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
    }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1223 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0]; 
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1] + 1;
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];          
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = 0;      
        (yyval.exp_spec)[5] = 0;
        gencode_postfix((yyvsp[0].exp_spec), 1);
        /* If not loaded */
        if(!(yyvsp[0].exp_spec)[5]){
            /* If is global */
            if(!(yyvsp[0].exp_spec)[2]){
                Symbol_table *global_symbol = get_global_symbol((yyvsp[0].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
                gencode_load_value((yyval.exp_spec));
            }
            /* If is id */
            else if ((yyvsp[0].exp_spec)[4]) {
                char stack_num[64];
                switch((int)(yyvsp[0].exp_spec)[0]) {
                    case 0: case 2:
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[0].exp_spec)[3]);
                gencode_function(stack_num);
            }
        }
    }
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1258 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1] - 1;
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];          
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = 0;      
        (yyval.exp_spec)[5] = 0;
        gencode_postfix((yyvsp[0].exp_spec), 0);
        /* If not loaded */
        if(!(yyvsp[0].exp_spec)[5]){
            /* If is global */
            if(!(yyvsp[0].exp_spec)[2]){
                Symbol_table *global_symbol = get_global_symbol((yyvsp[0].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
                gencode_load_value((yyval.exp_spec));
            }
            /* If is id */
            else if ((yyvsp[0].exp_spec)[4]) {
                char stack_num[64];
                switch((int)(yyvsp[0].exp_spec)[0]) {
                    case 0: case 2:
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[0].exp_spec)[3]);
                gencode_function(stack_num);
            }
        }
        
    }
#line 2811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1294 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 1;
        if(!strcmp((yyvsp[-1].str_val), "add")) {          
            (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
            gencode_unary_operator((yyvsp[0].exp_spec), 1);
        }
        else if(!strcmp((yyvsp[-1].str_val), "sub")) {
            (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1] * -1;
            gencode_unary_operator((yyvsp[0].exp_spec), 0);
        }
    }
#line 2831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1313 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "add"; }
#line 2837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1314 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.str_val) = "sub"; }
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1318 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("variable");
		++expression_id_type_num;
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
	}
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1333 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("function");
		++expression_id_type_num;
        (yyval.exp_spec)[0] = (yyvsp[-2].exp_spec)[0];
        (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = 1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        char* name = get_global_symbol((yyvsp[-2].exp_spec)[3])->name;
        if(is_parameter_match(name, 0))
            gencode_call_function(name);

	}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1352 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("function");
		++expression_id_type_num;
        (yyval.exp_spec)[0] = (yyvsp[-3].exp_spec)[0];
        (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = 1;  
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0; 
        (yyval.exp_spec)[5] = 1;
        char* name = get_global_symbol((yyvsp[-3].exp_spec)[3])->name;
        if(is_parameter_match(name, 1))
            gencode_call_function(name);
	}
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1369 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("variable");
		++expression_id_type_num;
        (yyval.exp_spec)[0] = (yyvsp[-1].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[-1].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[-1].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[-1].exp_spec)[3];
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 0;
        //gencode_load_value($1);
        gencode_postfix((yyvsp[-1].exp_spec), 1);
        has_postfix = 1;
        /* After postfix, need to store the value back */
        char stack_num[32];
        /* Only id need to store back */
        if((yyvsp[-1].exp_spec)[4] == 1){
            /* If this is global */
            if(!(yyvsp[-1].exp_spec)[2]){
                Symbol_table *global_symbol = get_global_symbol((yyvsp[-1].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If this is local */
            else {
                switch((int)(yyvsp[-1].exp_spec)[0]) {
                    case 0: case 2:
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[-1].exp_spec)[3]);
                gencode_function(stack_num);
            }
        }
	}
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1412 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("variable");
		++expression_id_type_num;
        (yyval.exp_spec)[0] = (yyvsp[-1].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[-1].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[-1].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[-1].exp_spec)[3];
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 0;
        //gencode_load_value($1);
        gencode_postfix((yyvsp[-1].exp_spec), 0);
        has_postfix = 1;

        /* After postfix, need to store the value back */
        if((yyvsp[-1].exp_spec)[5] == 0){
            /* If this is global */
            if(!(yyvsp[-1].exp_spec)[2]){
                Symbol_table *global_symbol = get_global_symbol((yyvsp[-1].exp_spec)[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If this is local */
            else {
                char stack_num[64];
                switch((int)(yyvsp[-1].exp_spec)[0]) {
                    case 0: case 2:
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)(yyvsp[-1].exp_spec)[3]);
                gencode_function(stack_num);
            }
        }
	}
#line 3003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1457 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(expression_id_num == 0) {
			expression_id = (char **)malloc(sizeof(char *));
			expression_id_exist = (int *)malloc(sizeof(int));
		}
		else {
			expression_id = (char **)realloc(expression_id, sizeof(char *) * (expression_id_num+1));
			expression_id_exist = (int *)realloc(expression_id_exist, sizeof(int) * (expression_id_num+1));
		}
		expression_id[expression_id_num] = strdup((yyvsp[0].str_val));
		/* If not found symbol in symbol table */
        if(!lookup_symbol((yyvsp[0].str_val))) {
			expression_id_exist[expression_id_num] = 0;
			if_undeclared = 1;
		}
        /* If found symbol in symbol table */
		else {	
			expression_id_exist[expression_id_num] = 1;
            (yyval.exp_spec)[0] = get_symbol_type((yyvsp[0].str_val));
            (yyval.exp_spec)[2] = !is_global_symbol((yyvsp[0].str_val));
            (yyval.exp_spec)[3] = get_symbol_index((yyvsp[0].str_val));
            /* If this symbol's type is string */
            if((yyval.exp_spec)[0] == 3) {
                (yyval.exp_spec)[1] = 0;
                /* If is global variable */
                if(!(yyval.exp_spec)[2]) {
                    gencode_function("\tgetstatic compiler_hw3/");
                    gencode_function((yyvsp[0].str_val));
                    gencode_function(" Ljava/lang/String;\n");
                }
                /* If is local variable */
                else {
                    char stack_index[64];
                    sprintf(stack_index, "\taload %d\n", get_symbol_index((yyvsp[0].str_val)));
                    gencode_function(stack_index);
                }
                (yyval.exp_spec)[4] = 1;
                (yyval.exp_spec)[5] = 1;
            }
            /* If is other type symbol */
            else {
                (yyval.exp_spec)[1] = get_symbol_value((yyvsp[0].str_val));
                (yyval.exp_spec)[4] = 1;
                (yyval.exp_spec)[5] = 0;
            }
        }
		++expression_id_num;
	}
#line 3056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1505 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(expression_id_num == 0) {
			expression_id = (char **)malloc(sizeof(char *));
			expression_id_exist = (int *)malloc(sizeof(int));
		}
		else {
			expression_id = (char **)realloc(expression_id, sizeof(char *) * (expression_id_num+1));
			expression_id_exist = (int *)realloc(expression_id_exist, sizeof(int) * (expression_id_num+1));
		}
		expression_id[expression_id_num] = strdup("constant");
		expression_id_exist[expression_id_num] = 1;
		++expression_id_num;
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
	}
#line 3080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1524 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(expression_id_num == 0) {
			expression_id = (char **)malloc(sizeof(char *));
			expression_id_exist = (int *)malloc(sizeof(int));
		}
		else {
			expression_id = (char **)realloc(expression_id, sizeof(char *) * (expression_id_num+1));
			expression_id_exist = (int *)realloc(expression_id_exist, sizeof(int) * (expression_id_num+1));
		}
		expression_id[expression_id_num] = strdup("boolean");
		expression_id_exist[expression_id_num] = 1;
		++expression_id_num;
        (yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
	}
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1543 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(expression_id_num == 0) {
			expression_id = (char **)malloc(sizeof(char *));
			expression_id_exist = (int *)malloc(sizeof(int));
		}
		else {
			expression_id = (char **)realloc(expression_id, sizeof(char *) * (expression_id_num+1));
			expression_id_exist = (int *)realloc(expression_id_exist, sizeof(int) * (expression_id_num+1));
		}
		expression_id[expression_id_num] = strdup("compound_statement");
		expression_id_exist[expression_id_num] = 1;
		++expression_id_num;
        (yyval.exp_spec)[0] = (yyvsp[-1].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[-1].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[-1].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[-1].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[-1].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[-1].exp_spec)[5];
	}
#line 3128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1565 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.exp_spec)[0] = 0;
        (yyval.exp_spec)[1] = (yyvsp[0].i_val);
        (yyval.exp_spec)[2] = -1;
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 0;
    }
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1573 "compiler_hw3.y" /* yacc.c:1646  */
    {  
        (yyval.exp_spec)[0] = 1;
        (yyval.exp_spec)[1] = (yyvsp[0].f_val);
        (yyval.exp_spec)[2] = -1;
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 0;
    }
#line 3154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1581 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.exp_spec)[0] = 3;
        (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 1;
        gencode_string_const((yyvsp[0].str_val));
    }
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1593 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.exp_spec)[0] = 2;
        (yyval.exp_spec)[1] = 1;
        (yyval.exp_spec)[2] = -1;
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 0;
    }
#line 3181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1601 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.exp_spec)[0] = 2;
        (yyval.exp_spec)[1] = 0;
        (yyval.exp_spec)[2] = -1;
        (yyval.exp_spec)[3] = -1;
        (yyval.exp_spec)[4] = 0;
        (yyval.exp_spec)[5] = 0;
    }
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1612 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		insert_attribute(scope_num, (yyvsp[-1].str_val));
		insert_symbol(scope_num+1, (yyvsp[0].str_val), "parameter", (yyvsp[-1].str_val), "");
	}
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1616 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		insert_attribute(scope_num, (yyvsp[-1].str_val));
		insert_symbol(scope_num+1, (yyvsp[0].str_val), "parameter", (yyvsp[-1].str_val), "");
	}
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1623 "compiler_hw3.y" /* yacc.c:1646  */
    {
        argument_spec[argument_num][0] = (yyvsp[0].exp_spec)[0];
        argument_spec[argument_num][1] = (yyvsp[0].exp_spec)[1];
        argument_spec[argument_num][2] = (yyvsp[0].exp_spec)[2];
        argument_spec[argument_num][3] = (yyvsp[0].exp_spec)[3];
        argument_spec[argument_num][4] = (yyvsp[0].exp_spec)[4];
        argument_spec[argument_num][5] = (yyvsp[0].exp_spec)[5];
        ++argument_num;
    }
#line 3226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1632 "compiler_hw3.y" /* yacc.c:1646  */
    {
        argument_spec[argument_num][0] = (yyvsp[0].exp_spec)[0];
        argument_spec[argument_num][1] = (yyvsp[0].exp_spec)[1];
        argument_spec[argument_num][2] = (yyvsp[0].exp_spec)[2];
        argument_spec[argument_num][3] = (yyvsp[0].exp_spec)[3];
        argument_spec[argument_num][4] = (yyvsp[0].exp_spec)[4];
        argument_spec[argument_num][5] = (yyvsp[0].exp_spec)[5];
        ++argument_num;
    }
#line 3240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1644 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.exp_spec)[0] = (yyvsp[0].exp_spec)[0];
        (yyval.exp_spec)[1] = (yyvsp[0].exp_spec)[1];
        (yyval.exp_spec)[2] = (yyvsp[0].exp_spec)[2];
        (yyval.exp_spec)[3] = (yyvsp[0].exp_spec)[3];
        (yyval.exp_spec)[4] = (yyvsp[0].exp_spec)[4];
        (yyval.exp_spec)[5] = (yyvsp[0].exp_spec)[5];
        if(if_undeclared) 
        	undeclared_error();
		clear_expression();
	}
#line 3256 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3260 "y.tab.c" /* yacc.c:1646  */
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
#line 1658 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
	create_symbol();

    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");

    yyparse();
    if(!syntax_error_flag) {
		if(buf[0] != '\0'){
            printf("%d: %s\n", yylineno+1, buf);
            ++yylineno;
        }     
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);		
	}
	--scope_num;

    fclose(file);
    if(error_flag) 
        remove("compiler_hw3.j");

    return 0;
}

/* stmbol table functions */
void yyerror(char *s)
{
    error_flag = 1;
    if(strstr(s, "syntax"))
		syntax_error_flag = 1;
	if(if_print_error) {
		if(!if_printed) {
			if(buf[0] == '\n')
                printf("%d:%s", yylineno, buf);
            else
                printf("%d: %s\n", yylineno+1, buf);
            if_printed = 1;
		}
		if_print_error = 0;
		printf("\n|-----------------------------------------------|\n");
        if(buf[strlen(buf)-1] != '\n')
            printf("| Error found in line %d: %s\n", yylineno+1, buf);
        else
            printf("| Error found in line %d: %s", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
	}
	
	printf("\n|-----------------------------------------------|\n");
    if(buf[strlen(buf)-1] != '\n')
        printf("| Error found in line %d: %s\n", yylineno+1, buf);
    else 
        printf("| Error found in line %d: %s", yylineno, buf);
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

void undeclared_error() {
	char errorMsg[256];
	for(int i = 0; i < expression_id_num; ++i) {
		if(!expression_id_exist[i]) {
			sprintf(errorMsg, "Undeclared %s", expression_id_type[expression_id_num-i-1]);
			if_undeclared = 0;
			semantic_error(errorMsg, expression_id[i]);
			break;
		}
	}
}

void semantic_error(char* errorMsg, char* name) {
	/* For other than redeclared or undeclared error */
    if(!strcmp(name, ""))
        sprintf(error_msg[error_msg_count], "%s", errorMsg);
    /* For redeclared or un declared error */
    else
        sprintf(error_msg[error_msg_count], "%s %s", errorMsg, name);
    ++error_msg_count;
	if_print_error = 1;
}

void print_error_msg() {
	if(if_print_error) {
		if_print_error = 0;
		for(int i = 0; i < error_msg_count; ++i) {
            yyerror(error_msg[i]);	
        }
	}
    error_msg_count = 0;
	if_print_error = 0;
}

void clear_expression() {
	if(expression_id_num != 0) {
		for(int i = expression_id_num-1; i >= 0; --i) {
			free(expression_id[i]);
			expression_id_exist[i] = 0;
			free(expression_id_type[expression_id_num-1-i]);
		}
		free(expression_id);
		free(expression_id_exist);
		free(expression_id_type);
		expression_id_num = 0;
		expression_id_type_num = 0;
	}
}

void print_test() {
	Symbol_table* test = symbol_table_head->next;
	while(test != NULL) {
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
			test->index, test->name, test->kind, test->type, test->scope, test->attribute);
		test = test->next;
	}
}

/* code generation functions */
void gencode_function(char* java_bytecode) {
    if(!error_flag) 
        fprintf(file, "%s", java_bytecode);  
}


void gencode_variable_declaration(char* type, char* name) {
    char java_bytecode[256];   // For temporary store code, later pass to gencode_function
    /* For global variable declaration, don't need to concern about type casting */
    if(scope_num == 0) {
        if(!strcmp(type, "int")) {
            if(declaration_has_value)
                sprintf(java_bytecode, ".field public static %s %s = %d\n", name, "I", yylval.i_val);
            else
                sprintf(java_bytecode, ".field public static %s %s = %d\n", name, "I", 0);
        }
        else if(!strcmp(type, "float")) {
            if(declaration_has_value)
                sprintf(java_bytecode, ".field public static %s %s = %f\n", name, "F", yylval.f_val);
            else
                sprintf(java_bytecode, ".field public static %s %s = %f\n", name, "F", 0.0);
        }
        else if(!strcmp(type, "bool")) {
            if(declaration_has_value)
                sprintf(java_bytecode, ".field public static %s %s = %d\n", name, "B", yylval.i_val);
            else
                sprintf(java_bytecode, ".field public static %s %s = %d\n", name, "B", 0);
        }
        else if(!strcmp(type, "string")) {
            /* String must have value */
            sprintf(java_bytecode, ".field public static %s %s = \"%s\"\n", name, "Ljava/lang/String;", yylval.str_val);
        }    
    }
    /* For local variable declaration */
    else {
        int stack_num = get_symbol_index(name);
        if(!strcmp(type, "int")) 
            gencode_function("\tistore ");
        else if(!strcmp(type, "float")) 
            gencode_function("\tfstore ");
        else if(!strcmp(type, "bool")) 
            gencode_function("\tistore ");
        else if(!strcmp(type, "string")) 
            gencode_function("\tastore ");
        sprintf(java_bytecode, "%d\n", stack_num);
    }

    /* If successfully generated some java bytecode, write it to file */
    if(strcmp(java_bytecode, ""))
        gencode_function(java_bytecode);
    
    declaration_has_value = 0;
    
}

void gencode_string_const(char* string_const){
    if(scope_num > 0) {
        gencode_function("\tldc \"");
        gencode_function(string_const);
        gencode_function("\"\n");
    }
}

char* get_type_bytecode(char* type) {
    if(!strcmp(type, "int"))
        return "I";
    else if(!strcmp(type, "float"))
        return "F";
    else if(!strcmp(type, "string"))
        return "[Ljava/lang/String;";
    else if(!strcmp(type, "void"))
        return "V";
    else if(!strcmp(type, "bool"))
        return "Z";
}

float get_symbol_value(char* name) {
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(!strcmp(symbol->name, name) && symbol->scope <= scope_num) 
            return symbol->value;
        symbol = symbol->prev;
    }
    return 0.0;
}

void set_symbol_value(char* name, float value) {
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(!strcmp(symbol->name, name) && (symbol->scope == scope_num || symbol->scope < scope_num)) {
            symbol->value = value;
            return;
        }
        symbol = symbol->prev;
    }
    return;
}

int get_symbol_type(char* name) {
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(!strcmp(symbol->name, name) && (symbol->scope == scope_num || symbol->scope < scope_num)) {
            if(!strcmp(symbol->type, "int"))
                return 0;
            else if(!strcmp(symbol->type, "float"))
                return 1;
            else if(!strcmp(symbol->type, "bool"))
                return 2;
            else if(!strcmp(symbol->type, "string"))
                return 3;
            else if(!strcmp(symbol->type, "void"))
                return 4;
        }
        symbol = symbol->prev;
    }
    return -1;
}

int get_symbol_index(char* name) {
    /* First get total local stack number */
    int local_num = 0;
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(symbol->scope != 0) {
            ++local_num;
        }
        symbol = symbol->prev;
    }

    int stack_index = 0;
    symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(symbol->scope != 0) {
            ++stack_index;
        }
        if(!strcmp(symbol->name, name) && symbol->scope <= scope_num) {
            if(symbol->scope != 0) 
                return local_num - stack_index;
            else    
                return symbol->index;
        }
        symbol = symbol->prev;
    }
    return -1;
}

int get_symbol_scope_num(char* name) {
    
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(!strcmp(symbol->name, name) && symbol->scope <= scope_num) {
            return symbol->scope;
        }
        symbol = symbol->prev;
    }
    return -1;
}

int is_global_symbol(char* name) {
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head) {
        if(!strcmp(symbol->name, name) && symbol->scope <= scope_num) {
            if(symbol->scope > 0)
                return 0;
            else 
                return 1;
        }
        symbol = symbol->prev;
    }
    return -1;
}

void gencode_load_value(float* var) {
    /* If this var hasn't been generated code yet' */
    if(!var[5]) {
        /* If this var is const */
        if(!var[4]) {
            char value[64];
            switch((int)var[0]) {
                /* For int */
                case 0: case 2:
                    sprintf(value, "\tldc %d\n", (int)var[1]);
                    gencode_function(value);
                    break;
                /* For float */
                case 1:
                    sprintf(value, "\tldc %f\n", (float)var[1]);
                    gencode_function(value);
                    break;
            }
        }
        /* If this var is id */
        else {   
            /* If this id is global variable */
            if(!var[2]) {
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table* global_symbol = get_global_symbol(var[3]);
                gencode_function(global_symbol->name);
                switch((int)var[0]) {
                    case 0:
                        gencode_function(" I\n");
                        break;
                    case 1:
                        gencode_function(" F\n");
                        break;
                    case 2:
                        gencode_function(" Z\n");
                        break;
                    case 3:
                        gencode_function(" Ljava/lang/String;\n");
                        break;
                }
            }
            /* If this id is local variable */
            else {
                char stack_num[64];
                switch((int)var[0]) {
                    /* Load int / bool from stack */
                    case 0: case 2:
                        sprintf(stack_num, "\tiload %d\n", (int)var[3]);
                        gencode_function(stack_num);
                        break;
                    /* Load float from stack */
                    case 1:
                        sprintf(stack_num, "\tfload %d\n", (int)var[3]);
                        gencode_function(stack_num);
                        break;
                    /* Load string from stack */
                    case 3:
                        sprintf(stack_num, "\taload %d\n", (int)var[3]);
                        gencode_function(stack_num);
                        break;
                }
            }
        }
    }
}

Symbol_table* get_global_symbol(int index) {
    Symbol_table* symbol = symbol_table_head->next;
    while(symbol != NULL) {
        if(symbol->index == index && symbol->scope == 0)
            return symbol;
        symbol = symbol->next;
    }
    return NULL;
}

/* Only int will have postfix */
void gencode_postfix(float* var, int post_type) {
    /* If this var hasn't been generated code yet' */
    if(!var[5]){
        /* If this is cosnt */
        if(!var[4]){
            char value[32];
            sprintf(value, "\tldc %d\n", (int)var[1]);
            gencode_function(value);          
        }
        /* If this is id */
        else{ 
            /* If this id is from global */
            if(!var[2]){
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table* global_symbol = get_global_symbol(var[3]);
                gencode_function(global_symbol->name);
                gencode_function(" I\n");
            }
            /* If this id is from local */
            else {
                char stack_num[32];
                sprintf(stack_num, "\tiload %d\n", (int)var[3]);
                gencode_function(stack_num);
            }
        }
    }
    gencode_function("\ticonst_1\n");
    if(post_type)
        gencode_function("\tiadd\n");
    else    
        gencode_function("\tisub\n");
}

void gencode_store_global(char* name, char* type){
    gencode_function("\tputstatic compiler_hw3/");
    gencode_function(name);
    if(!strcmp(type, "int"))
        gencode_function(" I\n");
    else if(!strcmp(type, "float"))
        gencode_function(" F\n");
    else if(!strcmp(type, "bool"))
        gencode_function(" Z\n");
    else if(!strcmp(type, "string"))
        gencode_function(" Ljava/lang/String;\n");
    else if(!strcmp(type, "void"))
        gencode_function(" V\n");
}

void gencode_unary_operator(float* var, int unary_type) {
    /* If hasn't been loaded */
    if(!var[5]){
        /* If this is const */
        if(!var[4]){
            char stack_num[64];
            if(var[0] == 0){
                sprintf(stack_num, "\tldc %d\n", (int)var[1]);
                gencode_function(stack_num);
            }  
            else if(var[0] == 1){
                sprintf(stack_num, "\tldc %f\n", (float)var[1]);
                gencode_function(stack_num);
            }
        }
        /* If this is id */
        else {
            /* If is global */
            if(!var[2]){
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table *global_symbol = get_global_symbol(var[3]);
                gencode_function(global_symbol->name);
                if(var[0] == 0){
                    gencode_function(" I\n");
                }  
                else if(var[0] == 1){
                    gencode_function(" F\n");
                }
            }
            /* If is local */
            else if(var[2]){
                char stack_num[64];
                /* for int */
                if(var[0] == 0){
                    sprintf(stack_num, "\tiload %d\n", (int)var[3]);
                    gencode_function(stack_num);
                }  
                /* for float */
                else if(var[0] == 1){
                    sprintf(stack_num, "\tfload %d\n", (int)var[3]);
                    gencode_function(stack_num);
                }
            }
        }
    }
    /* For negative */
    if(!unary_type){
        /* For int */
        if(var[0] == 0)
            gencode_function("\tineg\n");
        /* For float */
        else if(var[0] == 1)
            gencode_function("\tfneg\n");

    }  
}

void gencode_calculation(float* var1, float* var2, int cal_type) {
    /* If there's no code gen for var1 */
    if(!var1[5]){
        /* var1 is const */
        if(!var1[4]){
            char value[64];
            /* var1 is int */
            if(var1[0] == 0)
                sprintf(value, "\tldc %d\n", (int)var1[1]);
            /* var1 is float */ 
            else if(var1[0] == 1)
                sprintf(value, "\tldc %f\n", (float)var1[1]);
            gencode_function(value);
        }
        /* var1 is id */
        else if(var1[4]){
            /* var1 is global */
            if(!var1[2]){
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table *global_symbol = get_global_symbol(var1[3]);
                gencode_function(global_symbol->name);
                /* var1 is int */
                if(var1[0] == 0)
                    gencode_function(" I\n");
                /* var1 is float */
                else if(var1[0] == 1)
                    gencode_function(" F\n");
            }
            /* var1 is local */
            else if(var1[2]){
                char stack_num[64];
                /* var1 is int */
                if(var1[0] == 0)
                    gencode_function("\tiload ");
                /* var1 is float */
                else if(var1[0] == 1)
                    gencode_function("\tfload ");
                sprintf(stack_num, "%d\n", (int)var1[3]);
                gencode_function(stack_num);
            }
        }
    }
    /* If var1 is int, var2 is float, need to casting var1 */
    if(var1[0] == 0 && var2[0] == 1)
        gencode_function("\ti2f\n");

    /* If there's no code gen for var2 */
    if(!var2[5]){
        /* var2 is const */
        if(!var2[4]){
            gencode_function("\tldc ");
            char value[64];
            /* var2 is int */
            if(var2[0] == 0)
                sprintf(value, "%d\n", (int)var2[1]);
            /* var2 is float */ 
            else if(var2[0] == 1)
                sprintf(value, "%f\n", (float)var2[1]);
            gencode_function(value);
        }
        /* var2 is id */
        else if(var2[4]){
            /* var2 is global */
            if(!var2[2]){
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table *global_symbol = get_global_symbol(var2[3]);
                gencode_function(global_symbol->name);
                /* var2 is int */
                if(var2[0] == 0)
                    gencode_function(" I\n");
                /* var2 is float */
                else if(var2[0] == 1)
                    gencode_function(" F\n");
            }
            /* var2 is local */
            else if(var2[2]){
                char stack_num[64];
                /* var2 is int */
                if(var2[0] == 0)
                    gencode_function("\tiload ");
                /* var2 is float */
                else if(var2[0] == 1)
                    gencode_function("\tfload ");
                sprintf(stack_num, "%d\n", (int)var2[3]);
                gencode_function(stack_num);
            }
        }
    }
    /* If var1 is float, var2 is int, need to casting var2 */
    if(var1[0] == 1 && var2[0] == 0)
        gencode_function("\ti2f\n");

    /* Either var1 or var2 is float, calculating in float, mod can't calculate in float */
    if(var1[0] == 1 || var2[0] == 1){
        switch(cal_type) {
            case 0:
                gencode_function("\tfadd\n");
                break;
            case 1:
                gencode_function("\tfsub\n");
                break;
            case 2:
                gencode_function("\tfmul\n");
                break;
            case 3: 
                gencode_function("\tfdiv\n");
                break;
        }
    }
    /* Both var1 and var2 are int */
    else {
        switch(cal_type) {
            case 0:
                gencode_function("\tiadd\n");
                break;
            case 1:
                gencode_function("\tisub\n");
                break;
            case 2:
                gencode_function("\timul\n");
                break;
            case 3: 
                gencode_function("\tidiv\n");
                break;
            case 4:
                gencode_function("\tirem\n");
                break;
        }
    }
}

void gencode_relational(float* var1, float* var2, int rel_type) {
/* If there's no code gen for var1 */
    if(!var1[5]){
        /* var1 is const */
        if(!var1[4]){
            gencode_function("\tldc ");
            char value[64];
            /* var1 is int */
            if(var1[0] == 0)
                sprintf(value, "%d\n", (int)var1[1]);
            /* var1 is float */ 
            else if(var1[0] == 1)
                sprintf(value, "%f\n", (float)var1[1]);
            gencode_function(value);
        }
        /* var1 is id */
        else if(var1[4]){
            /* var1 is global */
            if(!var1[2]){
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table *global_symbol = get_global_symbol(var1[3]);
                gencode_function(global_symbol->name);
                /* var1 is int */
                if(var1[0] == 0)
                    gencode_function(" I\n");
                /* var1 is float */
                else if(var1[0] == 1)
                    gencode_function(" F\n");
            }
            /* var1 is local */
            else if(var1[2]){
                char stack_num[64];
                /* var1 is int */
                if(var1[0] == 0)
                    gencode_function("\tiload ");
                /* var1 is float */
                else if(var1[0] == 1)
                    gencode_function("\tfload ");
                sprintf(stack_num, "%d\n", (int)var1[3]);
                gencode_function(stack_num);
            }
        }
    }
    /* If var1 is int, var2 is float, need to casting var1 */
    if(var1[0] == 0 && var2[0] == 1)
        gencode_function("\ti2f\n");


    /* If there's no code gen for var2 */
    if(!var2[5]){
        /* var2 is const */
        if(!var2[4]){
            gencode_function("\tldc ");
            char value[64];
            /* var2 is int */
            if(var2[0] == 0)
                sprintf(value, "%d\n", (int)var2[1]);
            /* var2 is float */ 
            else if(var2[0] == 1)
                sprintf(value, "%f\n", (float)var2[1]);
            gencode_function(value);
        }
        /* var2 is id */
        else if(var2[4]){
            /* var2 is global */
            if(!var2[2]){
                gencode_function("\tgetstatic compiler_hw3/");
                Symbol_table *global_symbol = get_global_symbol(var2[3]);
                gencode_function(global_symbol->name);
                /* var2 is int */
                if(var2[0] == 0)
                    gencode_function(" I\n");
                /* var2 is float */
                else if(var2[1] == 1)
                    gencode_function(" F\n");
            }
            /* var2 is local */
            else if(var2[2]){
                char stack_num[64];
                /* var2 is int */
                if(var2[0] == 0)
                    gencode_function("\tiload ");
                /* var2 is float */
                else if(var2[0] == 1)
                    gencode_function("\tfload ");
                sprintf(stack_num, "%d\n", (int)var2[3]);
                gencode_function(stack_num);
            }
        }
    }
    /* If var1 is float, var2 is int, need to casting var2 */
    if(var1[0] == 1 && var2[0] == 0)
        gencode_function("\ti2f\n");

    /* Either var1 or var2 is float, calculating in float, and change back to int for relation */
    if(var1[0] == 1 || var2[0] == 1) {
        gencode_function("\tfsub\n\tf2i\n");
    }
    /* Both var1 and var2 are int */
    else
        gencode_function("\tisub\n");
    relational_type = rel_type;
}

void gencode_print_function(float* var){
    gencode_function("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
    gencode_function("\tswap\n");
    gencode_function("\tinvokevirtual java/io/PrintStream/println(");
    switch((int)var[0]) {
        /* print int / bool */
        case 0: case 2:
            gencode_function("I)V\n");
            break;
        /* print float */
        case 1:
            gencode_function("F)V\n");
            break;
        /* print string */
        case 3:
            gencode_function("Ljava/lang/String;)V\n");
            break;
    }
}

int is_parameter_match(char* name, int has_parameter) {
    Symbol_table* symbol = symbol_table_tail;
    while(symbol != symbol_table_head){
        /* If found function */
        if(!strcmp(symbol->name, name)){
            int parameter_num = 0;
            float parameter_type[64];
            /* If this function has paramters */
            if(has_parameter) {
                /* Get first parameter in list */
                char* para_type = strtok(symbol->attribute, ", ");
                /* Count parameter's number */
                while(para_type != NULL) {
                    if(!strcmp(para_type, "int")) 
                        parameter_type[parameter_num] = 0;
                    else if(!strcmp(para_type, "float")) 
                        parameter_type[parameter_num] = 1;
                    else if(!strcmp(para_type, "bool")) 
                        parameter_type[parameter_num] = 2;
                    else if(!strcmp(para_type, "string")) 
                        parameter_type[parameter_num] = 3;
                    ++parameter_num;
                    para_type = strtok(NULL, ", ");
                }
                /* If number of parameter and argument is not the same, raise error */
                if(parameter_num != argument_num) {
                    semantic_error("Number of passing arguments isn't match number of parameters\n", "");
                    argument_num = 0;
                    return 0;
                }
                for(int i = 0; i < argument_num; ++i) {
                    gencode_load_value(argument_spec[i]);
                    /* If parameter is float, argument is int or bool, do casting*/
                    if(parameter_type[i] == 1 && (argument_spec[i][0] == 0 || argument_spec[i][0] == 2)) 
                        gencode_function("\ti2f\n");
                    /* If parameter is int or bool, argument is float, do casting*/
                    else if((parameter_type[i] == 0 || parameter_type[i] == 2) && argument_spec[i][0] == 1) 
                        gencode_function("\tf2i\n");
                    /* If type of parameter and argument aren't the same, raise error */
                    else if(parameter_type[i] != argument_spec[i][0]) {
                        semantic_error("Type of passing arguments isn't match type of parameters", "");
                        argument_num = 0;
                        return 0;
                    }
                }
            }
            return 1;
        }
        symbol = symbol->prev;
    }
    return 1;
}

void gencode_call_function(char* name) {
    gencode_function("\tinvokestatic compiler_hw3/");
    gencode_function(name);
    gencode_function("(");
    Symbol_table* symbol = symbol_table_tail;
    /* Find the symbol of this function */
    while(symbol != symbol_table_head) {
        if(!strcmp(symbol->name, name) && !strcmp(symbol->kind, "function"))
            break;
        symbol = symbol->prev;
    }
    for(int i = 0; i < argument_num; ++i){
        switch((int)argument_spec[i][0]) {
            case 0:
                gencode_function("I");
                break;
            case 1:
                gencode_function("F");
                break;
            case 2:
                gencode_function("Z");
                break;
            case 3:
                gencode_function("Ljava/lang/String;");
                break;
        }
    }
    /* Reset the argument list */
    argument_num = 0;

    gencode_function(")");
    if(!strcmp(symbol->type, "int"))
        gencode_function("I\n");
    else if(!strcmp(symbol->type, "float"))
        gencode_function("F\n");
    else if(!strcmp(symbol->type, "bool"))
        gencode_function("Z\n");
    else if(!strcmp(symbol->type, "string"))
        gencode_function("Ljava/lang/String;\n");
    else if(!strcmp(symbol->type, "void"))
        gencode_function("V\n");

}
