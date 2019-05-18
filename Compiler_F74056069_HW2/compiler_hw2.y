/*	Definition section */
%{
#define MAX_SCOPE 100
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
int lookup_symbol();
void create_symbol();
void insert_symbol(int, char*, char*, char*, char*);
void dump_symbol();

int assign_flag = 0;
int error_flag = 0;
int type_flag = 0;
int scope_flag = 0;
int id_flag = 0;
int table_index[MAX_SCOPE];	// For each scope's table index

typedef struct data {
	int index;
	char* name;
	char* kind;
	char* type;
	int scope;
	char* attribute;
} Symbol_table;
Symbol_table* symbol_table[MAX_SCOPE];		// Table for dynamic storing symbol, static array for each scope

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* str_val;
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
%token ID SEMICOLON STR_COMMENT

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST INT BOOL VOID
%token <f_val> F_CONST FLOAT
%token <str_val> STR_CONST STRING ID

/* Nonterminal with return, which need to sepcify type */
%type <f_val> stat 
%type <f_val> external_declaration
%type <f_val> function_declaration
%type <f_val> declaration
%type <f_val> val
%type <f_val> term

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : external_declaration 
    | program external_declaration 
	| 
	;

external_declaration
	// : function_declaration
	: declaration
	;

stat 
	: declaration
	/* | function_stat
	| expression_stat
	| print_func
	| if_else_stat
	| while_stat
	| COMMENT */
	;

declaration
	: type ID ASGN val SEMICOLON  
	| type ID SEMICOLON 
	;

/* function_stat 
	: type ID LB parameter_stat RB compound_stat  
	| ID LB argument_stat RB SEMICOLON  
	;

parameter_stat
	: parameter_declaration
	| parameter_stat COMMA parameter_declaration
	|
	;

parameter_declaration
	: type ID ASGN val
	| type ID
	;

argument_stat
	: argument_declaration
	| argument_stat COMMA argument_declaration
	;

argument_declaration
	: ID ASGN val
	| ID ADDASGN val 
	| ID SUBASGN val 
	| ID MULASGN val 
	| ID DIVASGN val 
	| ID MODASGN val 
	| ID INC 
	| ID DEC 
	| val
	;


expression_stat
	: ID ASGN val SEMICOLON  
	| ID ADDASGN val SEMICOLON  
	| ID SUBASGN val SEMICOLON  
	| ID MULASGN val SEMICOLON  
	| ID DIVASGN val SEMICOLON 
	| ID MODASGN val SEMICOLON 
	| ID INC SEMICOLON 
	| ID DEC SEMICOLON 
	; */

val 
	: term
/* 	| val ADD term
	| val SUB term */
	;

term
	: initializer
/* 	| term MUL initializer
	| term DIV initializer
	| term MOD initializer */
	;

initializer
	: I_CONST 
	| F_CONST 
	| STR_CONST 
 	| ID 
/*	| group_stat */
	;

/* group_stat
	: LB val RB
	;

print_func
	: PRINT group SEMICOLON
	;

compound_stat
	: LCB
	| RCB
	;

if_else_stat
	: IF LB compare_stat RB LCB
	| RCB ELSE IF LB compare_stat RB LCB
	| RCB ELSE LCB 
    | ELSE IF LB compare_stat RB LCB 
    | ELSE LCB 
    | IF compare_stat LCB 
    | RCB ELSE IF compare_stat LCB 
    | ELSE IF compare_stat LCB 
	;

compare_stat
	: val MT val
    | val LT val
    | val MTE val
    | val LTE val
    | val EQ val
    | val NE val
	| I_CONST
	| F_CONST
	| STR_CONST
	| ID
	;

while_stat
	: WHILE LB compare_stat RB LCB 
	| WHILE LB compare_stat RB SEMICOLON
	| WHILE LB compare_stat RB stat
	; */

type 
	: INT { $<i_val>$ = $1; }
	| FLOAT { $<f_val>$ = $1; }
	| STRING { $<str_val>$ = $1; }
	| VOID { $<i_val>$ = $1; }
	| BOOL { $<i_val>$ = $1; }
	;




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
	// If the symbol table of this scope isn't initialized, append a size of Symbol_table to it
	// Also initialize the table index of this scope to 0 (first element)
	if(symbol_table[scope_flag] == NULL) {
		symbol_table[scope_flag] = malloc(sizeof(Symbol_table));
		table_index[scope_flag] = 0;
	}
	// If the symbol table of this scope exists, append a size of Symbol_table to it
	// Also increase the table index of this scope by 1 (next element)
	else {
		symbol_table[scope_flag]  = realloc(symbol_table[scope_flag] , sizeof(symbol_table[scope_flag]) + sizeof(Symbol_table));
		++table_index[scope_flag];
	}
}

void insert_symbol(int index, char* name, char* kind, char* type, char* attribute) 
{
	// Always create(append) symbol table before insert a symbol's data
	create_symbol();
	Symbol_table* symbol_data = &symbol_table[scope_flag][table_index[scope_flag]];
	symbol_data->index = table_index[scope_flag];
	symbol_data->name = malloc(strlen(name)+1);
	strcpy(symbol_data->name, name);
	symbol_data->kind = malloc(strlen(kind)+1);
	strcpy(symbol_data->kind, kind);
	symbol_data->type = malloc(strlen(type)+1);
	strcpy(symbol_data->type, type);
	symbol_data->scope = scope_flag;
	symbol_data->attribute = malloc(strlen(attribute)+1);
	strcpy(symbol_data->attribute, attribute);
}

int lookup_symbol() {}

void dump_symbol() {
    if(symbol_table[scope_flag] != NULL) {
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
			"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		while (symbol_table[scope_flag] != NULL) {
			// Always take first element to print out, then dump it
			Symbol_table* symbol_dumped = &symbol_table[scope_flag][0];
			printf("\n%-10d%-10s%-12s%-10s%-10d%-10s\n\n", symbol_dumped->index, symbol_dumped->name, 
														symbol_dumped->kind, symbol_dumped->type, 
														symbol_dumped->scope, symbol_dumped->attribute);
			free(symbol_dumped->name);
			free(symbol_dumped->kind);
			free(symbol_dumped->type);
			free(symbol_dumped->attribute);
			free(symbol_dumped);
		}
	}
}
