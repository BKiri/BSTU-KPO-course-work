#pragma once
#include "IT.h"
#include "Error.h"
#include <iomanip>
#include <string.h>
#include "stdafx.h"
#include "LA.h"
namespace IT
{
	IT::IdTable::IdTable()
	{
		this->maxsize = TI_MAXSIZE;
		this->size = 0;
		this->table = new Entry[TI_MAXSIZE];
	}
	Entry::Entry()
	{
		this->parent_function[0] = '\0';
		this->parent_function_num = -1;
		this->id[0] = '\0';
		this->iddatatype = IT::IDDATATYPE::DEF;
		this->idtype = IT::IDTYPE::D;
		this->parmQuantity = 0;
	}
	Entry::Entry(const char* parent_function, const char* id, IDDATATYPE iddatatype, IDTYPE idtype)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];
		this->parent_function_num = -1;
		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
	}
	Entry::Entry(const char* parent_function, const char* id, IDDATATYPE iddatatype, IDTYPE idtype, int it)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];
		this->parent_function_num = -1;
		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
		this->value.vint = it;
	}
	Entry::Entry(const char* parent_function, const char* id, IDDATATYPE iddatatype, IDTYPE idtype, char it)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];
		this->parent_function_num = -1;
		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
		this->value.vchar = it;
	}
	Entry::Entry(const char* parent_function, const char* id, IDDATATYPE iddatatype, IDTYPE idtype, unsigned int it)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];
		this->parent_function_num = -1;
		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
		this->value.vuint = it;
	}
	Entry::Entry(const char* parent_function, const char* id, IDDATATYPE iddatatype, IDTYPE idtype, char* ch)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];
		this->parent_function_num = -1;
		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
		strcpy_s(this->value.vstr.str, 255, ch);
		this->value.vstr.len = strlen(ch);
	}
	Entry::Entry(const char* parent_function, const char* id, IDDATATYPE iddatatype, IDTYPE idtype, const char* ch)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];
		this->parent_function_num = -1;
		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
		strcpy_s(this->value.vstr.str, 255, ch);
		this->value.vstr.len = strlen(ch);
	}
	Entry::Entry(char* parent_function, int parent_function_number, char* id, IDDATATYPE iddatatype, IDTYPE idtype)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		this->parent_function_num = parent_function_number;
		i = 0;
		if (id)
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];

		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
	}
	Entry::Entry(const char* parent_function,char* id, IDDATATYPE iddatatype, IDTYPE idtype)
	{
		int i = 0;
		if (parent_function)
			for (i = 0; parent_function[i] != '\0'; i++)
				this->parent_function[i] = parent_function[i];
		this->parent_function[i] = '\0';
		this->parent_function_num = -1;
		i = 0;
		if (id[0] != '\0')
			for (i = 0; id[i] != '\0'; i++)
				this->id[i] = id[i];

		this->id[i] = '\0';
		this->iddatatype = iddatatype;
		this->idtype = idtype;
		this->parmQuantity = 0;
	}

	IdTable Create(int size)
	{
		IdTable id_table;
		id_table.size = size;
		id_table.maxsize = TI_MAXSIZE;
		id_table.table = new Entry[TI_MAXSIZE];
		return id_table;
	}

	char* IdTable::GetLexemaName()
	{
		char buffer[5] = { "l"};
		char buffer_count[5];
		_itoa_s(this->noname_lexema_count, buffer_count, 5);
		strcat_s(buffer, buffer_count);
		this->noname_lexema_count++;
		return buffer;
	}

	char* IdTable::GetForName(char* id,Flag_type_variable Type)
	{
		char buffer[255] = { "" };
		strcat_s(buffer, 255, id);
		return buffer;
	}
	char* IdTable::GetViewName()
	{
		char buffer[255] = { "for_" };
		char numberBuffer[3];
		_itoa_s(this->for_count, numberBuffer, 10);
		strcat_s(buffer, 255, numberBuffer);
		this->for_count++;
		return buffer;
	}
	void IdTable::Add(Entry entry)
	{
		if (strlen(entry.id) > ID_MAXSIZE && entry.idtype != IDTYPE::F)
			throw ERROR_THROW(121);

		if (this->size < this->maxsize)
		{
			if (entry.idtype != IDTYPE::F)
				entry.id[255] = '\0';
			this->table[this->size] = entry;

			switch (entry.iddatatype)
			{
			case IDDATATYPE::INT:
			{
				this->table[this->size].value.vint = TI_INT_DEFAULT; break;
			}
			case IDDATATYPE::STR:
			{
				this->table[this->size].value.vstr.str[0] = TI_STR_DEFAULT;
				this->table[this->size].value.vstr.len = 0; break;
			}
			case IDDATATYPE::CHAR:
			{
				this->table[this->size].value.vchar = '\0'; break;
			}
			case IDDATATYPE::BOOL:
			{
				this->table[this->size].value.vbool = false; break;
			}
			case IDDATATYPE::UINT:
			{
				this->table[this->size].value.vuint = 0; break;
			}
			}
			this->size++;
		}
		else
			throw ERROR_THROW(122);

	}
	Entry IdTable::GetEntry(int n)
	{
		if (n < this->size && n >= 0)
			return this->table[n];
	}
	int IdTable::IsId(const char id[ID_MAXSIZE])
	{
		for (int iter = 0; iter < this->size; iter++)
		{
			if ((strcmp(this->table[iter].id, id) == 0))
			return iter;
		}
		return TI_NULLIDX;
	}
	int IdTable::IsId(const char id[ID_MAXSIZE], Entry ide, int parent_function_number)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (strcmp(this->table[i].id, id) == 0 &&
				strcmp(this->table[i].parent_function, ide.id) == 0 &&
				parent_function_number == this->table[i].parent_function_num
				)
				return i;
		}
		return TI_NULLIDX;
	}
	int IdTable::IsId(const char id[ID_MAXSIZE], Entry ide)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (strcmp(this->table[i].id, id) == 0 &&
				strcmp(this->table[i].parent_function, ide.id) == 0 
				)
				return i;
		}
		return TI_NULLIDX;
	}
	int IdTable::IsId(const char id[ID_MAXSIZE], const char parent_function[ID_MAXSIZE + 5],int parent_function_number)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (strcmp(this->table[i].id, id) == 0 &&
				strcmp(this->table[i].parent_function, parent_function) == 0 &&
				this->table[i].parent_function_num == parent_function_number
				)
				return i;
		}
		return TI_NULLIDX;
	}
	void Delete(IdTable& idTable)
	{
		delete[] idTable.table;
		idTable.table = nullptr;
	}
	void IdTable::PrintIdTable(const wchar_t* in)
	{
		int i = 0;
		wchar_t id[300];
		for (; in[i] != '\0'; i++)
			id[i] = in[i];
		id[i] = '\0';
		wcscat_s(id, PARM_IT_DEFAULT_EXT);

		std::ofstream* idStream = new std::ofstream;
		idStream->open(id);

		if (idStream->is_open())
		{
			bool flagForFirst = false;

			*(idStream) << "Литералы" << std::endl;
			*(idStream) << "Идентификатор  Тип данных  Значение  Длина строки  " << std::endl;

			for (int i = 0; i < this->size; i++)
			{
				if (this->table[i].idtype == IT::IDTYPE::L)
				{
					std::cout.width(25);
					switch (this->table[i].iddatatype)
					{
					case 1:
					{
						*(idStream) << this->table[i].id << " INTGR " << this->table[i].value.vint << std::endl;
						break;
					}
					case 2:
					{
						*(idStream) << this->table[i].id << " STR " << this->table[i].value.vstr.str << " " << (int)this->table[i].value.vstr.len << std::endl;
						break;
					}
					}
				}
			}

			*(idStream) << endl;
			flagForFirst = false;
			*(idStream) << "Функции" << std::endl;
			*(idStream) << "Идентификатор Тип данных возврата  Количество переданных параметров  " << std::endl;

			for (int i = 0; i < this->size; i++)
			{
				if (this->table[i].idtype == IT::IDTYPE::F)
				{
					switch (this->table[i].iddatatype)
					{
					case 1:
					{
						*(idStream) << this->table[i].id << " INTGR " << this->table[i].parmQuantity << std::endl;
						break;
					}
					case 2:
					{
						*(idStream) << this->table[i].id << " STR " << this->table[i].parmQuantity << std::endl;
						break;
					}
					}
				}
			}
			*(idStream) << endl;
			flagForFirst = false;
			*(idStream) << "Переменные " << std::endl;
			*(idStream) << "Имя родительского блока  Идентификатор  Тип данных  Тип идентификатора  Значение  Длина строки  " << std::endl;

			for (int i = 0; i < this->size; i++)
			{
				if (this->table[i].idtype == IT::IDTYPE::V || this->table[i].idtype == IT::IDTYPE::VF)
				{


					switch (this->table[i].iddatatype)
					{
					case 1:
					{
						*(idStream) << this->table[i].parent_function << " " << this->table[i].id << " INTGR " << this->table[i].value.vint << std::endl;
						break;
					}
					case 2:
					{
						*(idStream) << this->table[i].parent_function << " " << this->table[i].id << " STR " << this->table[i].value.vstr.str << ' ' << (int)this->table[i].value.vstr.len << std::endl;
						break;
					}
					}

					flagForFirst = true;
				}
				if (this->table[i].idtype == IT::IDTYPE::VF)
				{


					switch (this->table[i].iddatatype)
					{
					case 1:
					{
						*(idStream) << this->table[i].parent_function << ' ' << this->table[i].id << " INTGR " << this->table[i].value.vint << ' ' << std::endl;
						break;
					}
					case 2:
					{
						*(idStream) << this->table[i].parent_function << ' ' << this->table[i].id << " STR " << this->table[i].value.vstr.str << ' ' << (int)this->table[i].value.vstr.len << std::endl;
						break;
					}
					}

					flagForFirst = true;
				}
				if (this->table[i].idtype == IT::IDTYPE::P)
				{

					switch (this->table[i].iddatatype)
					{
					case 1:
					{
						*(idStream) << this->table[i].parent_function << ' ' << this->table[i].id << " INTGR " << this->table[i].value.vint << std::endl;
						break;
					}
					case 2:
					{
						*(idStream) << this->table[i].parent_function << ' ' << this->table[i].id << " STR " << this->table[i].value.vstr.str << ' ' << (int)this->table[i].value.vstr.len << std::endl;
						break;
					}
					}
					flagForFirst = true;
				}
			}
			*(idStream) << endl;
		}
		else
			throw ERROR_THROW(128);
		idStream->close();
		delete idStream;
	}
}