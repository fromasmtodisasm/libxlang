#pragma once

#define BASE_INDEX 257
typedef enum token_direct {PREV, CURR, NEXT}token_direct;
typedef enum token_type
{
	lcEND = BASE_INDEX,
	lcDELIM,
	lcSEMI,
	lcCOMMENT,
	lcKEYWORD,
	lcIDENT,
	lcNUMBER,
	lcSTRING,
	lcPLUS,
	lcMINUS,
	lcMUL,
	lcDIV,
	lcASSIGN,
	lcPLUS_ASSIGN,
	lcMINUS_ASSIGN,
	lcMUL_ASSIGN,
	lcDIV_ASSIGN,

	lcINC_OP,
	lcDEC_OP,
	lcPTR_OP,
	lcAND_OP,
	lcOR_OP ,
	lcLE_OP ,
	lcGE_OP ,
	lcEQ_OP ,
	lcNE_OP ,

	lcG_OP,
	lcN_OP,
	lcL_OP,


	lcLBRACE,
	lcRBRACE,
	lcBREAK,
	lcIF,
	lcELSE,
	lcFOR,
	lcDO,
	lcWHILE,
	lcCHAR,
	lcINT,
	lcRETURN,
	lcLBRACKET,
	lcRBRACKET,
	lcABORT,
	lcPRINT,
	lcREAD,

	lcBEGINBLOCK,
	lcENDBLOCK,
	lcFUNCTION,
	lcINTERPRETE,
	lcUNKNOWN
}token_type;
typedef enum token_category {
	catIDENT,
	catKEYWORD,
	catCONST,
	catOPERATOR,
	catDELIM
}token_category;
typedef struct token_t
{
	token_type type;
	void *text;
	token_category category;
	char *pos;
}token_t;
typedef struct context
{
	token_t curr_token;
	char *pos;
	int cur_line;
	struct context *prev, *next;
}context_t;

token_type is_keyword(char *name);
int lexerInit(char *src);
char * get_curpos();

token_t* get_token(token_direct direction);
/*
union
{
int int_number;
char *string;
float float_number
}value;
*/