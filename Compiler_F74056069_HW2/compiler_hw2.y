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
%token ID SEMICOLON

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
	: external_declaration
	| program external_declaration
	;

primary_expression
	: ID
	| constant
	| LB expression RB
	;

postfix_expression
	: primary_expression
	| postfix_expression LSB expression RSB
	| postfix_expression LB RB
	| postfix_expression LB argument_expression_list RB
	| postfix_expression INC
	| postfix_expression DEC
	| LB type_name RB LCB initializer_list RCB
	| LB type_name RB LCB initializer_list COMMA RCB
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	;

unary_expression
	: postfix_expression
	| INC unary_expression
	| DEC unary_expression
	| unary_operator cast_expression
	;

unary_operator
	: ADD
	| SUB
	| NOT
	;

cast_expression
	: unary_expression
	| LB type_name RB cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression MUL cast_expression
	| multiplicative_expression DIV cast_expression
	| multiplicative_expression MOD cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	| additive_expression SUB multiplicative_expression
	;

relational_expression
	: additive_expression
	| relational_expression MT additive_expression
	| relational_expression LT additive_expression
	| relational_expression MTE additive_expression
	| relational_expression LTE additive_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
	;

logical_and_expression
	: equality_expression
	| logical_and_expression AND equality_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
	;

assignment_expression
	: logical_or_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: ASGN
	| MULASGN
	| DIVASGN
	| MODASGN
	| ADDASGN
	| SUBASGN
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
	;

declaration
	: declaration_specifiers SEMICOLON
	| declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers
	| type_specifier declaration_specifiers
	| type_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMMA init_declarator
	;

init_declarator
	: declarator EQ initializer
	| declarator
	;

type_specifier
	: VOID
	| CHAR
	| INT
	| FLOAT
	| BOOL
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

declarator
	: ID
	| LB declarator RB
	| declarator LSB RSB
	| declarator LSB assignment_expression RSB
	| declarator LB parameter_list RB
	| declarator LB RB
	| declarator LB identifier_list RB
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID
	| identifier_list COMMA ID
	;

type_name
	: specifier_qualifier_list
	;

initializer
	: LCB initializer_list RCB
	| LCB initializer_list COMMA RCB
	| assignment_expression
	;

initializer_list
	: initializer
	| initializer_list COMMA initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: LCB RCB
	| LCB block_item_list RCB
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
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
	| FOR LB expression_statement expression_statement RB statement
	| FOR LB expression_statement expression_statement expression RB statement
	| FOR LB declaration expression_statement RB statement
	| FOR LB declaration expression_statement expression RB statement
	;

jump_statement
	: RETURN COMMA
	| RETURN expression COMMA
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;	


/* actions can be taken when meet the token or rule */
type
    : INT { $<i_val>$ = $1; }
    | FLOAT { $<f_val>$ = $1; }
    | BOOL  { $<b_val>$ = $1; }
    | STRING { $<str_val>$ = $1; }
    | VOID { $<v_val>$ = $1; }
;

constant
    : I_CONST { $<i_val>$ = $1; }
    | F_CONST { $<f_val>$ = $1; }
    | STR_CONST { $<str_val>$ = $1; }

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
