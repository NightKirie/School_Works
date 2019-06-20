/*	Definition section */
%{
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
%}

%union {
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
%type <str_val> declarator unary_operator assignment_operator
%type <exp_spec> boolean constant assignment_expression primary_expression 
%type <exp_spec> postfix_expression relational_expression unary_expression
%type <exp_spec> multiplicative_expression additive_expression 
%type <exp_spec> expression initializer
%type <nest_spec> while_start while if_start if 

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
		int is_duplicated = 0;
		int has_parameter = 0;
		Symbol_table* find_function = symbol_table_tail;
		/* Find duplicated */
		while(find_function != symbol_table_head) {
			/* If this function has forward declaration */
			if(!strcmp(find_function->name, $2)) {
				is_duplicated = 1;
				Symbol_table* duplicated = find_function;
				/* Duplicated function must added after the forward delcaration */
				while(duplicated != symbol_table_tail) {
					if(!strcmp(duplicated->kind, "function") && !strcmp(duplicated->name, "")) {	
                        /* If forward declaration's return type is not the same as the function definition's */
                        if(strcmp($1, find_function->type))        
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
					find_function->name = malloc(strlen($2) + 1);
					strcpy(find_function->name, $2);
					find_function->type = malloc(strlen($1) + 1);
					strcpy(find_function->type, $1);
					has_parameter = 1;
					break;
				}
				find_function = find_function->prev;
			}
		}
		/* If no duplicated && no parameter, initialize the function */
		if(!is_duplicated && !has_parameter) 
			insert_symbol(0, $2, "function", $1, "");	
        /* Generate java bytecode */
        gencode_function(".method public static ");
        gencode_function($2);
        /* If this is main function, generate specialized parameter */
        if(!strcmp($2, "main")) 
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
        gencode_function(get_type_bytecode($1));
        gencode_function("\n.limit stack 50\n");
		gencode_function(".limit locals 50\n");
        /* Copy the function return type for later usage */
        now_function_type = strdup($1);
        attribute_count = 0;
		is_function = 0;
	}
	;

compound_statement
	: scope_end 
	| block_item_list scope_end
	;


scope_start
	: LCB	{ 
		 ++scope_num;
	}
	;

scope_end 
	: RCB	{ 
		/* if scope number before '}' is 1, and there string in now_function_type, then this '}' must be the end of the function */
        if(scope_num == 1 && strcmp(now_function_type, "")) {
            gencode_function(".end method\n");
            free(now_function_type);
        }
        need_dump = 1;
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
	: if_start {
        /* Gen if exit label */
        char exit_label[64];
        sprintf(exit_label, "IF_EXIT_%d:\n", $1[1]);
        gencode_function(exit_label);
    }
    | if_start else_start {
        /* Gen if exit label */
        char exit_label[64];
        sprintf(exit_label, "IF_EXIT_%d:\n", $1[1]);
        gencode_function(exit_label);
    }
	;

if_start
    : if statement {
        char exit_label[64];
        /* If if finish, goto if exit */
        sprintf(exit_label, "\tgoto IF_EXIT_%d\n", $1[1]);
        gencode_function(exit_label);
        
        /* Gen if false label */
        char false_label[64];
        sprintf(false_label, "IF_FALSE_%d:\n", $1[0]);
        gencode_function(false_label);

        /* store this if's false label, prevent nested if label error  */
        $$[0] = $1[0];
    }
    ;

if
    : IF LB expression RB {
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
        $$[0] = if_false_label;
        $$[1] = if_label;

        ++if_label;
        ++if_true_label;
        ++if_false_label;
    }
    ;

else_start 
    : ELSE statement 
    ;

iteration_statement
	: while_start statement {
        char label[64];
        /* At the end of while, gen go back to while begin */
        sprintf(label, "\tgoto WHILE_BEGIN_%d\n", $1[1]);
        gencode_function(label);
        /* Gen while false label */
        sprintf(label, "WHILE_FALSE_%d:\n", $1[0]);
        gencode_function(label);
        /* If while false, goto while exit */
        sprintf(label, "\tgoto WHILE_EXIT_%d\n", $1[1]);
        gencode_function(label);
        /* Gen while exit label */
        sprintf(label, "WHILE_EXIT_%d:\n", $1[1]);
        gencode_function(label);
    }
	;

while_start
    : while LB expression RB {
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
        $$[0] = while_false_label;
        $$[1] = $1[1];

        ++while_true_label;
        ++while_false_label;
    }
    ;

while 
    : WHILE {
        char label[64];
        sprintf(label, "WHILE_BEGIN_%d:\n", while_label);
        gencode_function(label);
        /* store this while's exit label, prevent nested while label error  */
        $$[1] = while_label;
        ++while_label;
    }
    ;

jump_statement
	: RET SEMICOLON {
        /* If the function return value in a void function, raise error */
        if(strcmp(now_function_type, "void"))
            semantic_error("Return value in a function returning void");
        else
            gencode_function("\treturn\n");
    }
	| RET expression SEMICOLON {
        gencode_load_value($2);
        if(!strcmp(now_function_type, "int")) {
            if($2[0] == 1)  
                gencode_function("\tf2i\n");    
            gencode_function("\tireturn\n");
        }
        else if(!strcmp(now_function_type, "float")) {
            if($2[0] == 0 || $2[0] == 2)  
                gencode_function("\ti2f\n");    
            gencode_function("\tfreturn\n");
        }
        else if(!strcmp(now_function_type, "bool")) {
            if($2[0] == 1)  
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
	;

print_statement
	: PRINT LB expression RB SEMICOLON {
        gencode_load_value($3);
        gencode_print_function($3);
    }
	;

declaration
	: type declarator ASGN initializer SEMICOLON { 
		declaration_has_value = 1;
        /* If it is function declaration */
		if(is_function) {
			if(lookup_symbol($2)) {
				Symbol_table* find_function = symbol_table_tail;
                /* Find duplicated */
                while(find_function != symbol_table_head) {
                    /* If this function has forward declaration */
                    if(!strcmp(find_function->name, $2)) {
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
                semantic_error("Redeclared function", $2);
			}
			/* If need to remove the parameter inside the symbol table */
			if(if_insert_attribute) {
			/* Remove the parameters */
				remove_symbol_parameter();
				/* Set the function declaration data in the symbol table */
				Symbol_table* find_function = symbol_table_tail;
				find_function->name = malloc(strlen($2) + 1);
				strcpy(find_function->name, $2);
				find_function->type = malloc(strlen($1) + 1);
				strcpy(find_function->type, $1);
				if_insert_attribute = 0;
				attribute_count = 0;
				is_function = 0;
			}
			/* If this function doesn't have any parameter, just insert the function */
			else {
				insert_symbol(scope_num, $2, "function", $1, "");
			}
		}
		/* For variable declaration */
		else {
			switch(lookup_symbol($2)) {
				/* For variable isn't in the symbol table or in the lower scope */
				case 0: case 1:
                    /* Insert into symbol table first, for later gen code search */
					insert_symbol(scope_num, $2, "variable", $1, "");
                    /* If is local, need to gen load, and need to check type*/
                    if(!is_global_symbol($2)) {
                        gencode_load_value($4);
                        /* declarator is int, initializer is float */
                        if(!strcmp($1, "int") && $4[0] == 1)
                            gencode_function("\tf2i\n");
                        /* declarator is float, initializer is int  */
                        else if(!strcmp($1, "float") && $4[0] == 0)
                            gencode_function("\ti2f\n");
                    }
                    /* Set value into symbol table */
                    set_symbol_value($2, $4[1]);
                    gencode_variable_declaration($1, $2);
					break;
				/* For the variable is in the same scope, print error */
				case 2:
					semantic_error("Redeclared variable", $2);
					break;
			}
		}
	}
    | type declarator SEMICOLON {
        declaration_has_value = 0;
        /* If it is function declaration */
		if(is_function) {
			if(lookup_symbol($2)) {
				Symbol_table* find_function = symbol_table_tail;
                /* Find duplicated */
                while(find_function != symbol_table_head) {
                    /* If this function has forward declaration */
                    if(!strcmp(find_function->name, $2)) {
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
                semantic_error("Redeclared function", $2);
			}
			/* If need to remove the parameter inside the symbol table */
			if(if_insert_attribute) {
			/* Remove the parameters */
				remove_symbol_parameter();
				/* Set the function declaration data in the symbol table */
				Symbol_table* find_function = symbol_table_tail;
				find_function->name = malloc(strlen($2) + 1);
				strcpy(find_function->name, $2);
				find_function->type = malloc(strlen($1) + 1);
				strcpy(find_function->type, $1);
				if_insert_attribute = 0;
				attribute_count = 0;
				is_function = 0;
			}
			/* If this function doesn't have any parameter, just insert the function */
			else {
				insert_symbol(scope_num, $2, "function", $1, "");
			}
		}
		/* For variable declaration */
		else {
			switch(lookup_symbol($2)) {
				/* For variable isn't in the symbol table or in the lower scope */
				case 0: case 1:
                    /* Insert into symbol table first, for later gen code search */
					insert_symbol(scope_num, $2, "variable", $1, "");
                    /* If is not global, need to load */
                    if(!is_global_symbol($2)) { 
                        char value[64];
                        /* Default value for int / bool is 0 */
                        if(!strcmp($1, "int") || !strcmp($1, "bool")) {
                            sprintf(value, "\tldc %d\n", 0);
                        }
                        /* Default value for int is 0.0 */
                        else if(!strcmp($1, "float")) {
                            sprintf(value, "\tldc %f\n", 0.0);
                        }
                        /* Default value for string is "" */
                        else if(!strcmp($1, "string")) {
                            sprintf(value, "\tldc \"\"\n");
                        }
                        gencode_function(value);
                    }
                    /* Set value into symbol table */
                    set_symbol_value($2, 0.0);
                    gencode_variable_declaration($1, $2);
					break;
				/* For the variable is in the same scope, print error */
				case 2:
					semantic_error("Redeclared variable", $2);
					break;
			}
		}
    }
	;

type 
	: INT       {$$ = "int";}
    | FLOAT     {$$ = "float";}
    | BOOL      {$$ = "bool";}
    | STRING    {$$ = "string";}
    | VOID      {$$ = "void";}
	;


declarator
	: ID 	{ 
		is_function = 0; 
		$$ = $1; 
	}
	| declarator LB parameter_list RB 	{ 
		is_function = 1; 
		$$ = $1; 
	}
	| declarator LB RB	{
		is_function = 1; 
		$$ = $1; 
	}
	;

initializer
	: expression {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
    }
	;

assignment_operator
	: ASGN      { $$ = "ASGN"; }
	| MULASGN   { $$ = "MULASGN"; }
	| DIVASGN   { $$ = "DIVASGN"; }
	| MODASGN   { $$ = "MODASGN"; }
	| ADDASGN   { $$ = "ADDASGN"; }  
	| SUBASGN   { $$ = "SUBASGN"; }
	;

assignment_expression
	: relational_expression {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
    }
	| unary_expression assignment_operator assignment_expression {
        if(!strcmp($2, "ASGN")) {
            /* If $3 hasn't been loaded */
            if(!$3[5])
                gencode_load_value($3);
            /* If $1 is global */
            if(!$1[2]){
                if($1[0] == 0 && $3[1] == 1) 
                    gencode_function("\tf2i\n");
                if($1[0] == 1 && $3[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol($1[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)$1[0]) {
                    case 0: case 2:
                        if($3[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if($3[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)$1[3]);
                gencode_function(stack_num);
            }  
        }
        else if(!strcmp($2, "MULASGN")) {
            gencode_calculation($1, $3, 2);
            /* Either var1 or var2 is float, return float */
            if($1[0] == 1 || $3[0] == 1)
                $$[0] = 1;
            /* Both var1 and var2 are int */
            else
            $$[0] = 0;
            $1[1] = $1[1] * $3[1];
            $1[5] = 1;
            /* If $1 is global */
            if(!$1[2]){
                if($1[0] == 0 && $3[1] == 1) 
                    gencode_function("\tf2i\n");
                if($1[0] == 1 && $3[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol($1[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)$1[0]) {
                    case 0: case 2:
                        if($3[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if($3[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)$1[3]);
                gencode_function(stack_num);
            }   
        }
        else if(!strcmp($2, "DIVASGN")) {
            /* If divisor is 0, raise error */
            if($3[1] == 0) {
                semantic_error("Divided by Zero", "");
                $$[1] = 0;
            }
            else {
                gencode_calculation($1, $3, 3);
                /* Either var1 or var2 is float, return float */
                if($1[0] == 1 || $3[0] == 1)
                    $$[0] = 1;
                /* Both var1 and var2 are int */
                else
                $$[0] = 0;
                $1[1] = $1[1] / $3[1];
                $1[5] = 1;
                /* If $1 is global */
                if(!$1[2]){
                    if($1[0] == 0 && $3[1] == 1) 
                        gencode_function("\tf2i\n");
                    if($1[0] == 1 && $3[1] == 0) 
                        gencode_function("\ti2f\n");
                    Symbol_table *global_symbol = get_global_symbol($1[3]);
                    gencode_store_global(global_symbol->name, global_symbol->type);
                }
                /* If $1 is local */
                else {
                    char stack_num[64];
                    switch((int)$1[0]) {
                        case 0: case 2:
                            if($3[0] == 1)  
                                gencode_function("\tf2i\n");
                            gencode_function("\tistore ");
                            break;
                        case 1:
                            if($3[0] == 0) 
                                gencode_function("\ti2f\n");
                            gencode_function("\tfstore ");
                            break;
                        case 3:
                            gencode_function("\tastore ");
                            break;
                    }
                    sprintf(stack_num, "%d\n", (int)$1[3]);
                    gencode_function(stack_num);
                }  
            } 
        }
        else if(!strcmp($2, "MODASGN")) {
            /* Both $1 and $3 must to be int that can mod */
            if ($1[0] != 0 || $3[0] != 0)
                semantic_error("Mod with non integer", "");
            
            /* If mod by 0, invalid */
            if ($3[1] == 0) 
                semantic_error("Mod by Zero", "");
            /* If error occur, return with 0 */
            if($3[1] == 0 || $1[0] != 1 || $3[0] != 1) 
                $$[1] = 0;
            else {    
                gencode_calculation($1, $3, 4);
                /* Either var1 or var2 is float, return float */
                if($1[0] == 1 || $3[0] == 1)
                    $$[0] = 1;
                /* Both var1 and var2 are int */
                else
                $$[0] = 0;
                $1[1] = (int)$1[1] % (int)$3[1];
                $1[5] = 1;
                /* If $1 is global */
                if(!$1[2]){
                    if($1[0] == 0 && $3[1] == 1) 
                        gencode_function("\tf2i\n");
                    if($1[0] == 1 && $3[1] == 0) 
                        gencode_function("\ti2f\n");
                    Symbol_table *global_symbol = get_global_symbol($1[3]);
                    gencode_store_global(global_symbol->name, global_symbol->type);
                }
                /* If $1 is local */
                else {
                    char stack_num[64];
                    switch((int)$1[0]) {
                        case 0: case 2:
                            if($3[0] == 1)  
                                gencode_function("\tf2i\n");
                            gencode_function("\tistore ");
                            break;
                        case 1:
                            if($3[0] == 0) 
                                gencode_function("\ti2f\n");
                            gencode_function("\tfstore ");
                            break;
                        case 3:
                            gencode_function("\tastore ");
                            break;
                    }
                    sprintf(stack_num, "%d\n", (int)$1[3]);
                    gencode_function(stack_num);
                }   
            }
        }
        else if(!strcmp($2, "ADDASGN")) {
            gencode_calculation($1, $3, 0);
            /* Either var1 or var2 is float, return float */
            if($1[0] == 1 || $3[0] == 1)
                $$[0] = 1;
            /* Both var1 and var2 are int */
            else
            $$[0] = 0;
            $1[1] = $1[1] + $3[1];
            $1[5] = 1;
            /* If $1 is global */
            if(!$1[2]){
                if($1[0] == 0 && $3[1] == 1) 
                    gencode_function("\tf2i\n");
                if($1[0] == 1 && $3[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol($1[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)$1[0]) {
                    case 0: case 2:
                        if($3[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if($3[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)$1[3]);
                gencode_function(stack_num);
            }   
        }
        else if(!strcmp($2, "SUBASGN")) {
            gencode_calculation($1, $3, 1);
            /* Either var1 or var2 is float, return float */
            if($1[0] == 1 || $3[0] == 1)
                $$[0] = 1;
            /* Both var1 and var2 are int */
            else
            $$[0] = 0;
            $1[1] = $1[1] - $3[1];
            $1[5] = 1;
            /* If $1 is global */
            if(!$1[2]){
                if($1[0] == 0 && $3[1] == 1) 
                    gencode_function("\tf2i\n");
                if($1[0] == 1 && $3[1] == 0) 
                    gencode_function("\ti2f\n");
                Symbol_table *global_symbol = get_global_symbol($1[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If $1 is local */
            else {
                char stack_num[64];
                switch((int)$1[0]) {
                    case 0: case 2:
                        if($3[0] == 1)  
                            gencode_function("\tf2i\n");
                        gencode_function("\tistore ");
                        break;
                    case 1:
                        if($3[0] == 0) 
                            gencode_function("\ti2f\n");
                        gencode_function("\tfstore ");
                        break;
                    case 3:
                        gencode_function("\tastore ");
                        break;
                }
                sprintf(stack_num, "%d\n", (int)$1[3]);
                gencode_function(stack_num);
            }   
        }
        
        
    }
	;

relational_expression
	: additive_expression {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
    }
	| relational_expression MT additive_expression {
        $$[0] = 2;
        if($1[1] > $3[1])   
            $$[1] = 1;
        else                
            $$[1] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_relational($1, $3, 0);
    }
	| relational_expression LT additive_expression {
        $$[0] = 2;
        if($1[1] < $3[1])   
            $$[1] = 1;
        else                
            $$[1] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_relational($1, $3, 1);
    }
	| relational_expression MTE additive_expression {
        $$[0] = 2;
        if($1[1] >= $3[1])   
            $$[1] = 1;
        else                
            $$[1] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_relational($1, $3, 2);
    }
	| relational_expression LTE additive_expression {
        $$[0] = 2;
        if($1[1] <= $3[1])   
            $$[1] = 1;
        else                
            $$[1] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_relational($1, $3, 3);
    }
	| relational_expression EQ additive_expression {
        $$[0] = 2;
        if($1[1] == $3[1])   
            $$[1] = 1;
        else                
            $$[1] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_relational($1, $3, 4);
    }
	| relational_expression NE additive_expression {
        $$[0] = 2;
        if($1[1] != $3[1])   
            $$[1] = 1;
        else                
            $$[1] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_relational($1, $3, 5);
    }
	;

additive_expression
	: multiplicative_expression {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
    }
	| additive_expression ADD multiplicative_expression {
        /* Either var1 or var2 is float, return float */
        if($1[0] == 1 || $3[0] == 1)
            $$[0] = 1;
        /* Both var1 and var2 are int */
        else
            $$[0] = 0;
        
        $$[1] = $1[1] + $3[1]; 
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_calculation($1, $3, 0);
    }
	| additive_expression SUB multiplicative_expression {
        /* Either var1 or var2 is float, return float */
        if($1[0] == 1 || $3[0] == 1)
            $$[0] = 1;
        /* Both var1 and var2 are int */
        else
            $$[0] = 0;
        
        $$[1] = $1[1] - $3[1]; 
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;

        gencode_calculation($1, $3, 1);
    }
	;

multiplicative_expression
	: unary_expression {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
    }
	| multiplicative_expression MUL unary_expression {
        /* Either var1 or var2 is float, return float */
        if($1[0] == 1 || $3[0] == 1)
            $$[0] = 1;
        /* Both var1 and var2 are int */
        else
            $$[0] = 0;
        
        $$[1] = $1[1] * $3[1]; 
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;

        gencode_calculation($1, $3, 2);
    }
	| multiplicative_expression DIV unary_expression {
        /* If divisor is 0, raise error, return 0 */
        if($3[0] == 0) {
            semantic_error("Divided by Zero", "");
            $$[1] = 0;
        }
        else{
            $$[1] = $1[1] / $3[1]; 
        }
        /* Either var1 or var2 is float, return float */
        if($1[0] == 1 || $3[0] == 1)
            $$[0] = 1;
        /* Both var1 and var2 are int */
        else
            $$[0] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;

        gencode_calculation($1, $3, 3);
    }
	| multiplicative_expression MOD unary_expression {
        /* Both $1 and $3 must to be int that can mod */
        if ($1[0] != 0 || $3[0] != 0)
            semantic_error("Mod with non integer", "");
        
        /* If mod by 0, invalid */
        if ($3[1] == 0) 
            semantic_error("Mod by Zero", "");
        
        /* If error occur, return with 0 */
        if($3[1] == 0 || $1[0] != 1 || $3[0] != 1) 
            $$[1] = 0;
        /* Else return value after mod */
        else 
            $$[1] = (int)$1[1] % (int)$3[1]; 
        
        $$[0] = 0;
        $$[2] = -1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        gencode_calculation($1, $3, 4);
    }
	;

unary_expression
	: postfix_expression {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
    }
	| INC unary_expression {
        $$[0] = $2[0]; 
        $$[1] = $2[1] + 1;
        $$[2] = $2[2];          
        $$[3] = $2[3];
        $$[4] = 0;      
        $$[5] = 0;
        gencode_postfix($2, 1);
        /* If not loaded */
        if(!$2[5]){
            /* If is global */
            if(!$2[2]){
                Symbol_table *global_symbol = get_global_symbol($2[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
                gencode_load_value($$);
            }
            /* If is id */
            else if ($2[4]) {
                char stack_num[64];
                switch((int)$2[0]) {
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
                sprintf(stack_num, "%d\n", (int)$2[3]);
                gencode_function(stack_num);
            }
        }
    }
	| DEC unary_expression {
        $$[0] = $2[0];
        $$[1] = $2[1] - 1;
        $$[2] = $2[2];          
        $$[3] = $2[3];
        $$[4] = 0;      
        $$[5] = 0;
        gencode_postfix($2, 0);
        /* If not loaded */
        if(!$2[5]){
            /* If is global */
            if(!$2[2]){
                Symbol_table *global_symbol = get_global_symbol($2[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
                gencode_load_value($$);
            }
            /* If is id */
            else if ($2[4]) {
                char stack_num[64];
                switch((int)$2[0]) {
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
                sprintf(stack_num, "%d\n", (int)$2[3]);
                gencode_function(stack_num);
            }
        }
        
    }
	| unary_operator unary_expression { 
        $$[0] = $2[0];
        $$[2] = $2[2];
        $$[3] = $2[3];
        $$[4] = 0;
        $$[5] = 1;
        if(!strcmp($1, "add")) {          
            $$[1] = $2[1];
            gencode_unary_operator($2, 1);
        }
        else if(!strcmp($1, "sub")) {
            $$[1] = $2[1] * -1;
            gencode_unary_operator($2, 0);
        }
    }
	;

/* For positive/negative/not variable */
unary_operator
	: ADD { $$ = "add"; } 
	| SUB { $$ = "sub"; } 
	;

postfix_expression
	: primary_expression	{ 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("variable");
		++expression_id_type_num;
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
	}
    /* call function without argument */
	| primary_expression LB RB 	{ 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("function");
		++expression_id_type_num;
        $$[0] = $1[0];
        $$[1] = 0;
        $$[2] = 1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        char* name = get_global_symbol($1[3])->name;
        if(is_parameter_match(name, 0))
            gencode_call_function(name);

	}	
    /* call function with argument */
	| primary_expression LB argument_expression_list RB	{ 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("function");
		++expression_id_type_num;
        $$[0] = $1[0];
        $$[1] = 0;
        $$[2] = 1;  
        $$[3] = -1;
        $$[4] = 0; 
        $$[5] = 1;
        char* name = get_global_symbol($1[3])->name;
        if(is_parameter_match(name, 1))
            gencode_call_function(name);
	}	
	| primary_expression INC { 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("variable");
		++expression_id_type_num;
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = 0;
        $$[5] = 0;
        //gencode_load_value($1);
        gencode_postfix($1, 1);
        has_postfix = 1;
        /* After postfix, need to store the value back */
        char stack_num[32];
        /* Only id need to store back */
        if($1[4] == 1){
            /* If this is global */
            if(!$1[2]){
                Symbol_table *global_symbol = get_global_symbol($1[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If this is local */
            else {
                switch((int)$1[0]) {
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
                sprintf(stack_num, "%d\n", (int)$1[3]);
                gencode_function(stack_num);
            }
        }
	}	
	| primary_expression DEC	{ 
		if(expression_id_type_num == 0) 
			expression_id_type = (char **)malloc(sizeof(char *));		
		else 
			expression_id_type = (char **)realloc(expression_id_type, sizeof(char *) * (expression_id_type_num+1));
		expression_id_type[expression_id_type_num] = strdup("variable");
		++expression_id_type_num;
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = 0;
        $$[5] = 0;
        //gencode_load_value($1);
        gencode_postfix($1, 0);
        has_postfix = 1;

        /* After postfix, need to store the value back */
        if($1[5] == 0){
            /* If this is global */
            if(!$1[2]){
                Symbol_table *global_symbol = get_global_symbol($1[3]);
                gencode_store_global(global_symbol->name, global_symbol->type);
            }
            /* If this is local */
            else {
                char stack_num[64];
                switch((int)$1[0]) {
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
                sprintf(stack_num, "%d\n", (int)$1[3]);
                gencode_function(stack_num);
            }
        }
	}	

primary_expression 
	: ID	{ 
		if(expression_id_num == 0) {
			expression_id = (char **)malloc(sizeof(char *));
			expression_id_exist = (int *)malloc(sizeof(int));
		}
		else {
			expression_id = (char **)realloc(expression_id, sizeof(char *) * (expression_id_num+1));
			expression_id_exist = (int *)realloc(expression_id_exist, sizeof(int) * (expression_id_num+1));
		}
		expression_id[expression_id_num] = strdup($1);
		/* If not found symbol in symbol table */
        if(!lookup_symbol($1)) {
			expression_id_exist[expression_id_num] = 0;
			if_undeclared = 1;
		}
        /* If found symbol in symbol table */
		else {	
			expression_id_exist[expression_id_num] = 1;
            $$[0] = get_symbol_type($1);
            $$[2] = !is_global_symbol($1);
            $$[3] = get_symbol_index($1);
            /* If this symbol's type is string */
            if($$[0] == 3) {
                $$[1] = 0;
                /* If is global variable */
                if(!$$[2]) {
                    gencode_function("\tgetstatic compiler_hw3/");
                    gencode_function($1);
                    gencode_function(" Ljava/lang/String;\n");
                }
                /* If is local variable */
                else {
                    char stack_index[64];
                    sprintf(stack_index, "\taload %d\n", get_symbol_index($1));
                    gencode_function(stack_index);
                }
                $$[4] = 1;
                $$[5] = 1;
            }
            /* If is other type symbol */
            else {
                $$[1] = get_symbol_value($1);
                $$[4] = 1;
                $$[5] = 0;
            }
        }
		++expression_id_num;
	}
	| constant	{
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
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
	}
	| boolean	{
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
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
	}
	| LB assignment_expression RB	{
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
        $$[0] = $2[0];
        $$[1] = $2[1];
        $$[2] = $2[2];
        $$[3] = $2[3];
        $$[4] = $2[4];
        $$[5] = $2[5];
	}
	;

constant
	: I_CONST { 
        $$[0] = 0;
        $$[1] = $1;
        $$[2] = -1;
        $$[3] = -1;
        $$[4] = 0;
        $$[5] = 0;
    }
	| F_CONST {  
        $$[0] = 1;
        $$[1] = $1;
        $$[2] = -1;
        $$[3] = -1;
        $$[4] = 0;
        $$[5] = 0;
    }
	| STR_CONST { 
        $$[0] = 3;
        $$[1] = 0;
        $$[2] = -1;
        $$[3] = -1;
        $$[4] = 0;
        $$[5] = 1;
        gencode_string_const($1);
    }
	;

boolean
	: TRUE { 
        $$[0] = 2;
        $$[1] = 1;
        $$[2] = -1;
        $$[3] = -1;
        $$[4] = 0;
        $$[5] = 0;
    }
	| FALSE { 
        $$[0] = 2;
        $$[1] = 0;
        $$[2] = -1;
        $$[3] = -1;
        $$[4] = 0;
        $$[5] = 0;
    }
	;

parameter_list
	: type declarator { 
		insert_attribute(scope_num, $1);
		insert_symbol(scope_num+1, $2, "parameter", $1, "");
	}
	| parameter_list COMMA type declarator { 
		insert_attribute(scope_num, $3);
		insert_symbol(scope_num+1, $4, "parameter", $3, "");
	}
	;

argument_expression_list
	: assignment_expression {
        argument_spec[argument_num][0] = $1[0];
        argument_spec[argument_num][1] = $1[1];
        argument_spec[argument_num][2] = $1[2];
        argument_spec[argument_num][3] = $1[3];
        argument_spec[argument_num][4] = $1[4];
        argument_spec[argument_num][5] = $1[5];
        ++argument_num;
    }
	| argument_expression_list COMMA assignment_expression {
        argument_spec[argument_num][0] = $3[0];
        argument_spec[argument_num][1] = $3[1];
        argument_spec[argument_num][2] = $3[2];
        argument_spec[argument_num][3] = $3[3];
        argument_spec[argument_num][4] = $3[4];
        argument_spec[argument_num][5] = $3[5];
        ++argument_num;
    }
	;

expression
	: assignment_expression	{
		$$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
        $$[4] = $1[4];
        $$[5] = $1[5];
        if(if_undeclared) 
        	undeclared_error();
		clear_expression();
	}
	;


%%

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