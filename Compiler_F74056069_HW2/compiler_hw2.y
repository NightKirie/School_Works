/*	Definition section */
%{
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
void print_test();

int assign_flag = 0;
int error_flag = 0;
int type_flag = 0;
int scope_num = 0;
int id_flag = 0;
int if_insert_attribute = 0;
int is_function = 0;
int attribute_count = 0;

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
%token SEMICOLON 

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST 
%token <f_val> F_CONST 
%token <str_val> STR_CONST 
%token <str_val> ID

/* Nonterminal with return, which need to sepcify type */
%type <str_val> type
%type <str_val> declarator init_declarator

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
	;

function_definition
	: function_definition_declarator compound_statement 
	;

function_definition_declarator
	: type declarator scope_start { 
		Symbol_table* find_function = symbol_table_tail;
		while(strcmp(find_function->kind, "function") && find_function != symbol_table_head) 
			find_function = find_function->prev;
		/* If this function doesn't have forward declaration, and have no parameter */
		if(find_function == symbol_table_head)
			insert_symbol(0, $2, "function", $1, "");
		/* If this function has forward declaration */
		else
			find_function->name = malloc(strlen($2) + 1);
			strcpy(find_function->name, $2);
			find_function->type = malloc(strlen($1) + 1);
			strcpy(find_function->type, $1);

		printf(ANSI_COLOR_MAGENTA "type: %s ID: %s Scope: %d, " ANSI_COLOR_RESET, $1, $2, scope_num);
	}
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

compound_statement
	: scope_end 
	| block_item_list scope_end
	;


scope_start
	: LCB	{ 
		 ++scope_num;
		printf(ANSI_COLOR_GREEN "%d scope start!!!" ANSI_COLOR_RESET "\n", scope_num);
	}
	;

scope_end 
	: RCB	{ 
		dump_symbol();
		printf(ANSI_COLOR_RED "%d scope end!!!" ANSI_COLOR_RESET "\n", scope_num); 
		--scope_num;
	}
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

statement
	: scope_start compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	| print_statement
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
	;

selection_statement
	: IF LB expression RB statement ELSE statement
	| IF LB expression RB statement
	;

iteration_statement
	: WHILE LB expression RB statement
	;

jump_statement
	: RET SEMICOLON
	| RET expression SEMICOLON
	;

print_statement
	: PRINT LB expression RB SEMICOLON
	;

declaration
	: type init_declarator SEMICOLON { 
		/* If it is function declaration, need to remove the parameter inside the symbol table */
		if(is_function) {
			if(if_insert_attribute) {
				remove_symbol_parameter();
				if_insert_attribute = 0;
				attribute_count = 0;
			}
			is_function = 0;
		}
		else {
			switch(lookup_symbol($2)) {
				/* For variable isn't in the symbol table or in the lower scope */
				case 0: case 1:
					insert_symbol(scope_num, $2, "variable", $1, "");
					break;
				/* For the variable is in the same scope, print error */
				case 2:
					printf("sdfsdfdsfdsfdsfdsfsdf\n");
					break;
			}
		}
		printf(ANSI_COLOR_YELLOW "type: %s ID: %s Scope: %d, " ANSI_COLOR_RESET, $1, $2, scope_num); 
	}
	;

type 
	: INT       {$$ = "int";}
    | FLOAT     {$$ = "float";}
    | BOOL      {$$ = "bool";}
    | STRING    {$$ = "string";}
    | VOID      {$$ = "void";}
	;

init_declarator
	: declarator ASGN initializer	{ $$ = $1; }	
	| declarator	{ $$ = $1; }
	;

declarator
	: ID 	{ is_function = 0; }
	| declarator LB parameter_list RB 		{ printf("I am function!"); is_function = 1; }
	| declarator LB RB						{ 
		printf("I am function!"); 
		is_function = 1; 
	}
	//| declarator LB identifier_list RB
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
	;

primary_expression
	: ID
	| constant
	| boolean
	| LB expression RB
	;

constant
	: I_CONST
	| F_CONST
	| STR_CONST
	;

boolean
	: TRUE
	| FALSE
	;

parameter_list
	: type declarator { 
		insert_attribute(scope_num, $1);
		insert_symbol(scope_num+1, $2, "variable", $1, "");
		printf(ANSI_COLOR_BLUE "type: %s ID: %s Scope: %d, " ANSI_COLOR_RESET, $1, $2, scope_num+1); 
	}
	| parameter_list COMMA type declarator { 
		insert_attribute(scope_num, $3);
		insert_symbol(scope_num+1, $4, "variable", $3, "");
		printf(ANSI_COLOR_BLUE "type: %s ID: %s Scope: %d, " ANSI_COLOR_RESET, $3, $4, scope_num+1); 
	}
	;

parameter_declaration
	: type declarator 
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

expression
	: assignment_expression
	| expression COMMA assignment_expression
	;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
	create_symbol();
    yyparse();
	printf("\nTotal lines: %d \n",yylineno);
	dump_symbol();
	print_test();
	--scope_num;
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
	while(symbol_lookup != symbol_table_head){
		/* If we find a variable/function previously defined at the same scope */
		if(strcmp(symbol_lookup->name, name) == 0 && symbol_lookup->scope == scope_num)
			return 2;	// For redeclared, as for undeclared only check if it's true
		/* If we find a variable/function previously defined at the lower scope */
		if(strcmp(symbol_lookup->name, name) == 0 && symbol_lookup->scope > scope_num)
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
		ssize_t dumped_line_length = snprintf(NULL, 0, "%-10d%-10s%-12s%-10s%-10d%-10s\n", symbol_dumped->index, symbol_dumped->name, 
														symbol_dumped->kind, symbol_dumped->type, 
														symbol_dumped->scope, symbol_dumped->attribute) + 1;
		/* Temporary store the line of this dumped symbol */
		char* dumped_line = (char*)malloc(dumped_line_length);
		snprintf(dumped_line, dumped_line_length, "%-10d%-10s%-12s%-10s%-10d%-10s\n", symbol_dumped->index, symbol_dumped->name, 
														symbol_dumped->kind, symbol_dumped->type, 
														symbol_dumped->scope, symbol_dumped->attribute);
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
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n%s",
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

void print_test() {
	Symbol_table* test = symbol_table_tail;
	while(test != symbol_table_head) {
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
			test->index, test->name, test->kind, test->type, test->scope, test->attribute);
		test = test->prev;
	}
}