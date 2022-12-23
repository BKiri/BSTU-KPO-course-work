#pragma once

extern "C"
{
	void _stdcall outstr(char*);
	void _stdcall outchar(char*);
	void _stdcall outbool(bool*);
	void _stdcall outint(int i);
	int _stdcall strl(char*);
	char* _stdcall cmpr(char* str1, char* str2);
	char* _stdcall strcon(char* str1, char* str2);
}