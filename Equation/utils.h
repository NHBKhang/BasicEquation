#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include "color.h"
#include "command.h"

using namespace std;

extern ConsoleColor currentColor;

void ResetColor();
void PrintError(string error);
void PrintMessage(string message);
void CommandPromptColor();
double InputParseDouble(string inputText);
void OutputStart();
void ReadFile(const string& filename);

#endif
