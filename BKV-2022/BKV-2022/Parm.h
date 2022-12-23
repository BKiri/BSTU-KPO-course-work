#pragma once
#define PARM_MAX_SIZE 300

#define PARM_IN		L"-in:"
#define PARM_OUT	L"-out:"
#define PARM_LOG	L"-log:"
#define PARM_LEX	L"-lex:"
#define PARM_IT     L"-it:"
#define PARM_SA     L"-sem:"

#define PARM_OUT_DEFAULT_EXT L".asm"
#define PARM_LOG_DEFAULT_EXT L".log.txt"
#define PARM_LEX_DEFAULT_EXT L".lex.txt"
#define PARM_IT_DEFAULT_EXT L".it.txt"
#define PARM_SA_DEFAULT_EXT L".sa.txt"

namespace Parm
{
	struct PARM
	{
		wchar_t in[PARM_MAX_SIZE];
		wchar_t out[PARM_MAX_SIZE];
		wchar_t log[PARM_MAX_SIZE];
		wchar_t lex[PARM_MAX_SIZE];
		wchar_t it[PARM_MAX_SIZE];
	};
	PARM getparm(int argc, wchar_t* argv[]);
}