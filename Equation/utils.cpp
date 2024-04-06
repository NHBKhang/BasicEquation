#include "utils.h"

void ResetColor() {
    SetConsoleColor(White);
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

float InputParseFloat(string inputText) {
    string input;

    while (true)
    {
        try {
            cout << inputText;
            getline(cin, input);

            if (SpecialCommand(input)) continue;

            return stof(input);
        }
        catch (const exception&) {
            PrintError("Nhap du lieu khong phu hop!!! Vui long nhap lai");

            continue;
        }
    }
}
void OutputStart() {
    SetConsoleColor(Green);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
