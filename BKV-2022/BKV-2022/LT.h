#pragma once
#include "IT.h"

#define LEXEMA_FIXSIZE			 1			//фиксированный размер лексемы
#define	LT_MAXSIZE				1024		// максимальное количество строк в таблице лексем	
#define	LT_TI_NULLXDX			-1			// нет элемента таблицы идентификаторов				
#define	LEX_INTEGER				't'			// лексема для int
#define	LEX_BOOL				't'			// лексема для bool
#define	LEX_STRING				't'			// лексема для string
#define	LEX_CHAR				't'			// лексема для char

#define	LEX_IF					'c'			// лексема для if
	
#define LEX_MAIN				'i'			// лексема для main
#define LEX_COMPARE				'i'			// лексема для compare
#define	LEX_ADDSTR				'i'			// лексема для addstr
#define LEX_STRLEN				'i'			// лексема для strlen

#define	LEX_ID					'i'			// лексема для идентификатора
#define	LEX_LITERAL				'l'			// лексема для литерала
#define	LEX_FUNCTION			'f'			// лексема для function
#define	LEX_RETURN				'r'			// лексема для return
#define	LEX_OUT					'o'			// лексема для out
#define	LEX_SEMICOLON			';'			// лексема для ;
#define	LEX_COMMA				','			// лексема для ,
#define	LEX_LEFTBRACE			'{'			// лексема для {
#define	LEX_RIGHTBRACE			'}'			// лексема для }
#define	LEX_LEFTTHESIS			'('			// лексема для (
#define	LEX_RIGHTTHESIS			')'			// лексема для )
#define	LEX_PLUS				'v'			// лексема для +
#define	LEX_MINUS				'v'			// лексема для -
#define	LEX_STAR				'v'			// лексема для *
#define	LEX_DIRSLASH			'v'			// лексема для /
#define	LEX_EQUAL_SIGN			'='			// лексема для = 
#define	LEX_NOTEQUALITY_SIGN	'!'			// лексема для !=
#define	LEX_EQUALITY_SIGN		'~'			// лексема для ==
#define	LEX_LESS_SIGN			'<'			// лексема для <
#define	LEX_MORE_SIGN			'>'			// лексема для >
#define PLUS					'+'			// лексема для +
#define MINUS					'-'			// лексема для -
#define STAR					'*'			// лексема для *
#define DIRSLASH				'/'			// лексема для /

#define PARM_LEX L".lex.txt" 

namespace LT												
{
	struct Entry											
	{
		char lexema;										
		int sn;												
		int idxTI;											
		Entry();
		Entry(const char lex, int str_n, int idxTI);
	};

	struct LexTable											
	{
		int maxsize;										
		int size;											
		Entry* table;										
		Entry GetEntry(									
			int n										
		);
		void PrintLexTable(const wchar_t* in);			
		void PrintLexTable(const wchar_t* in, const wchar_t* name);
		LexTable();

		void PrintLexTableControle(const wchar_t* in, const wchar_t* name, IT::IdTable it);
	};

	void Add(											
		LexTable& lextable,								
		Entry entry										
	);


	void Delete(LexTable& lextable);					
};