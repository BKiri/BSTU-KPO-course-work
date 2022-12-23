#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "lib.h"

#pragma warning(disable: 4996)

extern "C"
{
	static int N_SYSTEM = 10;
	char* _stdcall strcon(char* str1, char* str2)
	{
		char* buf = (char*)malloc(255);
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (!str1 || !str2)
		{
			std::cout << "ERROR: Null string in strcon function!!!" << std::endl;
			system("pause");
			ExitProcess(0);
		}
		int size = 0;
		for (; str2[size] != '\0'; size++)
			buf[size] = str2[size];
		for (int i = 0; str1[i] != '\0'; size++, i++)
			buf[size] = str1[i];
		buf[size] = '\0';
		return  buf;
	}
	int _stdcall strl(char* str1)
	{
		int length = strlen(str1);
		return  length;
	}
	char* _stdcall cmpr(char* str1, char* str2)
	{
		strcmp(str1, str2);
		return str1;
	}
	void _stdcall outstr(char* s)
	{
		if (s != nullptr)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			char* buf = (char*)malloc(255);
			int bufLength = 0;
			for (int iter = 0; s[iter] != '\0'; iter++)
			{
				if (bufLength != 0)
				{
					std::cout << buf; iter--;
				}
				else
				{
					std::cout << s[iter];
				}
				bufLength = 0;
				buf[bufLength] = '\0';
			}

		}
		else
			std::cout << "Empty line!";
	}
	void _stdcall outint(int i)
	{
		switch (N_SYSTEM)
		{
		case 10:
		{
			std::cout << std::dec << i;
			break;
		}
		case 16:
		{
			std::cout << "0x" << std::hex << i;
			break;
		}
		default:std::cout << i; break;
		}
	}
	void _stdcall outbool(bool* i)
	{
		if (*i == 0)
			std::cout << "false";
		else
			std::cout << "true";
	}
	void _stdcall outchar(char* i)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::cout << *i;
	}
}