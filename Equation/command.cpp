#include "command.h"

string CommandInput(string cmd = "") {
    string input;

    cout << "-> " << cmd;
    getline(cin, input);
    return TrimToLowerCase(input);
}

bool SpecialCommand(string& input) {
    string cmd = TrimToLowerCase(input);

    if (cmd._Equal("cls") || cmd._Equal("clear")) {
        system("cls");

        return true;
    }
    else if (cmd._Equal("exit") || cmd._Equal("quit")) {
        PrintMessage("Thoat chuong trinh");
        exit(0);
    }
    else if (cmd._Equal("command") || cmd._Equal("cmd")) {
        CommandPromptColor();

        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        string myInput;
        while (true) {
            myInput = CommandInput();

            if (myInput._Equal("exit") || myInput._Equal("quit")) {
                break;
            }
            else if (myInput._Equal("cls") || myInput._Equal("clear")) {
                system("cls");
            }
            else if (myInput._Equal("setcolor") || myInput._Equal("stclr")) {
                myInput = CommandInput("color: ");

                string color;
                if (myInput._Equal("red")) {
                    color = "red";
                    currentColor = Red;
                }
                else if (myInput._Equal("green")) {
                    color = "green";
                    currentColor = Green;
                }
                else {
                    color = "white";
                    currentColor = White;
                }
                PrintMessage("Set text color to " + color);
                ResetColor();
            }
            else if (myInput._Equal("setbg") || myInput._Equal("stbg")) {
                myInput = CommandInput("Bg-color: ");

                string color;
                if (myInput._Equal("white")) {
                    SetConsoleBackgroundColor(BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                }
                else if (myInput._Equal("green")) {
                    SetConsoleBackgroundColor(BACKGROUND_GREEN);
                }
                else {
                    SetConsoleBackgroundColor(0);
                }
                PrintMessage("Set background color to " + color);
                ResetColor();
            }
        }

        return true;
    }
    else if (cmd._Equal("khang")) {
        PrintMessage("Khong co gi de xem o day dau");
        ResetColor();

        return true;
    }

    return false;
}
