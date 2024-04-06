#include "command.h"
#include "format.h"

bool SpecialCommand(string& input) {
    string cmd = TrimToLowerCase(input);

    if (cmd._Equal("cls")) {
        system("cls");

        return true;
    }
    else if (cmd._Equal("exit") || cmd._Equal("quit")) {
        exit(0);
    }

    return false;
}
