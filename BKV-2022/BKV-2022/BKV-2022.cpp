#include "stdafx.h"

void wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "Russian");

	Log::LOG log;
	Parm::PARM param;

	try
	{
		param = Parm::getparm(argc, argv);
		log = Log::getlog(param.log);
		In::IN 	in = In::getin(param.in);
		in = In::ImportLib(in);
		Log::WriteLine(log, "Тест: ", "без ошибок\n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, param);
		Log::WriteIn(log, in);

		LT::LexTable lextable;
		IT::IdTable	idTable;

		LexAnalyse(in, lextable, idTable);
		lextable.PrintLexTable(param.in);
		idTable.PrintIdTable(param.in);

		MFST::Mfst mfst(lextable, GRB::getGreibach());
		if (mfst.start(param, log))
		{
			mfst.savededucation();
			mfst.printrules(param, log);

			SemanticAnalyze(lextable, idTable);
			lextable.PrintLexTable(param.in, PARM_SA_DEFAULT_EXT);

			CG::ConstSegment CnstSeg(idTable.size);
			CG::DataSegment Data(idTable.size);
			CG::CodeSegment Code;

			CG::add(idTable, CnstSeg);
			CG::add(idTable, Data);
			CG::CodeSegmentGeneration(Code, lextable, idTable);
			CG::startGeneration(param.out, CnstSeg, Data, Code);
			Log::WriteLine(log, "Код сгенерирован\n", "");
		}
		Delete(lextable);
		Delete(idTable);

		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		if (e.id == 100 or e.id == 113) {
			cout << e.message;
		}
		else {
			Log::WriteError(log, e);
			log = Log::getlog(param.out);
			Log::WriteError(log, e);
		}
	}
}