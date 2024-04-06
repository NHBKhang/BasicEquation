#include "command.h"

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
    else if (cmd._Equal("khang")) {
        PrintMessage("Khong co gi de xem o day dau");
        ResetColor();
    }

    return false;
}
