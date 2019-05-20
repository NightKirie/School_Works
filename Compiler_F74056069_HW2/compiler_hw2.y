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
%token VOID INT FLOAT STRING BOOL
%token TRUE FALSE RET
%token SEMICOLON STR_COMMENT

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST 
%token <f_val> F_CONST 
%token <str_val> STR_CONST 
%token <str_val> ID

/* Nonterminal with return, which need to sepcify type */
%type <i_val> type

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
	: declaration 
	| function_definition
	| STR_COMMENT
	;

function_definition
	: type declarator declaration_list compound_statement
	| type declarator compound_statement
	;

/* stat 
	: declaration
	| function_stat
	| expression_stat
	| print_func
	| if_else_stat
	| while_stat
	| COMMENT
	; */

declaration
	: type init_declarator SEMICOLON
	;

type 
	: INT       {$$ = 1;}
    | FLOAT     {$$ = 2;}
    | BOOL      {$$ = 3;}
    | STRING    {$$ = 4;}
    | VOID      {$$ = 5;}
	;

init_declarator
	: declarator ASGN initializer
	| declarator
	;

declarator
	: ID
	| declarator LB parameter_list RB
	| declarator LB RB
	| declarator LB identifier_list RB
	;

initializer
	: assignment_expression
	;

assignment_expression
	: logical_or_expression
	| unary_expression assignment_operator assignment_expression
	;

logical_or_expression
	: logical_and_expression 
	| logical_or_expression OR logical_and_expression
	;

logical_and_expression
	: equality_expression
	| logical_and_expression AND equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
	;

relational_expression
	: additive_expression
	| relational_expression MT additive_expression
	| relational_expression LT additive_expression
	| relational_expression MTE additive_expression
	| relational_expression LTE additive_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	| additive_expression SUB multiplicative_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression MUL cast_expression
	| multiplicative_expression DIV cast_expression
	| multiplicative_expression MOD cast_expression
	;

cast_expression
	: unary_expression
	| LB specifier_qualifier_list RB cast_expression
	;

unary_expression
	: postfix_expression
	| INC unary_expression
	| DEC unary_expression
	| unary_operator cast_expression
	;

/* For positive/negative/not variable */
unary_operator
	: ADD
	| SUB
	| NOT
	;

postfix_expression
	: primary_expression
	| postfix_expression LB RB
	| postfix_expression LB argument_expression_list RB
	| postfix_expression INC
	| postfix_expression DEC
	| LB specifier_qualifier_list RB LCB initializer_list RCB
	| LB specifier_qualifier_list RB LCB initializer_list COMMA RCB
	;

primary_expression
	: ID
	| constant
	| STR_CONST
	| LB expression RB
	;

constant
	: I_CONST
	| F_CONST
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: type declarator
	| type
	;

identifier_list
	: ID
	| identifier_list COMMA ID
	;

assignment_operator
	: ASGN
	| MULASGN
	| DIVASGN
	| MODASGN
	| ADDASGN
	| SUBASGN
	;

specifier_qualifier_list
	: type specifier_qualifier_list
	| type
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	;

initializer_list
	: initializer
	| initializer_list COMMA initializer
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
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

/* val 
	: term
	| val ADD term
	| val SUB term
	;

term
	: initializer
	| term MUL initializer
	| term DIV initializer
	| term MOD initializer
	;

initializer
	: I_CONST 
	| F_CONST 
	| STR_CONST 
 	| ID 
	| group_stat
	; */

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
