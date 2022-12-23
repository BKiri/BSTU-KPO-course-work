#pragma once

#include <iostream>
#include <fstream>
#include "In.h"
#include "IT.h"
#include "LT.h"

#define token_size 256

bool Funcs(char* token, const int strNumber, LT::LexTable& lextable, IT::IdTable& idTable, Flag_type_variable& flag_type_variable);
void LexAnalyse(const In::IN& source, LT::LexTable& lextable, IT::IdTable& idTable);
bool TokenAnalyse(char* token, const int strNumber, LT::LexTable& lextable, IT::IdTable& idTable);
