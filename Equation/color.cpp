#include "color.h"

// Function definition to set console text color
void SetConsoleColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void SetConsoleBackgroundColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    // Get the current text color
    WORD textColor = consoleInfo.wAttributes & 0x0F;

    // Set the background color
    for (int y = 0; y < consoleInfo.dwSize.Y; ++y) {
        for (int x = 0; x < consoleInfo.dwSize.X; ++x) {
            DWORD written = 0;
            FillConsoleOutputAttribute(hConsole, color | textColor, 1, { static_cast<SHORT>(x), static_cast<SHORT>(y) }, &written);
        }
    }

    // Set the cursor position back to the top left
    SetConsoleCursorPosition(hConsole, { 0, 0 });
}
