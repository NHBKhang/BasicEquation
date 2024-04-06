#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "color.h"
#include "command.h"

using namespace std;

void ResetColor();
void PrintError(string error);
void PrintMessage(string message);
float InputParseFloat(string inputText);
void OutputStart();

#endif
