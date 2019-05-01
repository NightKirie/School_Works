/*	Definition section */
%{
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

int assign_flag = 0;
int error_flag = 0;
int type_flag = 0;
int scope_flag = 0;
int id_flag = 0;
int table_index = 0;

typedef struct data {
	int index;
	char* name;
	char* entry_type;
	char* data_type;
	int scope_level;
	char* format_parameter;
} Symbol_table
Symbol_table* symbol_table;		// Table for dynamic storing symbol

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* str_val;
    bool b_val;
    void v_val;
}


/* Token without return */
%token ADD SUB MUL DIV MOD INC DEC 
%token MT LT MTE LTE EQ NE 
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT 
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT 
%token IF ELSE FOR WHILE
%token TRUE FALSE RET
%token ID SEMICOLON NEWLINE

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST INT
%token <f_val> F_CONST FLOAT
%token <str_val> STR_CONST STRING
%token <b_val> BOOL
%token <v_val> VOID 

/* Nonterminal with return, which need to sepcify type */
%type <f_val> stat


/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat 
	{
		assign_flag = 0;
		error_flag = 0;
		type_flag = 0;
		id_flag = 0;
	}
    |  
;

stat 
	: declaration
	| function_stat
	| expression_stat
	| print_func
	| if_else_stat
	| compare_stat
	| while_stat

declaration
	: type ID ASGN val SEMICOLON NEWLINE 
	{
		
	}


%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
	printf("\nTotal lines: %d \n",yylineno);
	dump_symbol();

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
	if(symbol_table == NULL)
		symbol_table = malloc(sizeof(Symbol_table));
	else
		symbol_table = realloc(symbol_table, sizeof(symbol_table) + sizeof(Symbol_table));
}
void insert_symbol() 
{
	create_symbol();
}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
