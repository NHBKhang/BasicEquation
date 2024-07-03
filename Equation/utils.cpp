#include "utils.h"
#include "operators.h"

ConsoleColor currentColor = White;

void ResetColor() {
    SetConsoleColor(currentColor);
}

void PrintMessage(string message) {
    SetConsoleColor(LightBlue);
    cout << "MSG: " << message << endl;
    ResetColor();
}

void PrintError(string error) {
    SetConsoleColor(Red);
    cout << "ERR: " << error << endl;
    ResetColor();
}

void CommandPromptColor() {
    SetConsoleColor(LightCyan);
    cout << "\t\tCommand Prompt" << endl;
}

double InputParseDouble(string inputText) {
    string input;

    while (true)
    {
        try {
            cout << inputText;
            getline(cin, input);

            if (SpecialCommand(input)) continue;
            else {
                if (!input.empty())
                    return Evaluate(input);
            }
        }
        catch (const exception& e) {
            PrintError("Nhap du lieu khong phu hop!!! Vui long nhap lai");
            PrintError(e.what());

            continue;
        }
    }
}
void OutputStart() {
    SetConsoleColor(Green);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
