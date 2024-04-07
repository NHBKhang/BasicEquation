#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
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

#endif
