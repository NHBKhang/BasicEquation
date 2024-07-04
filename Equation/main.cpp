#include <iostream>
#include <stdexcept>
#include <string>
#include "color.h"
#include "utils.h"
#include "equation.h"

using namespace std;


int main() {
    int chon = -1, cont = -1;

    while (true) {
        SetConsoleColor(LightMagenta);
        cout << "\t\tGIAI PHUONG TRINH\n";
        ResetColor();
        cout << "For more information on a specific command, type HELP command-name\n";
        SetConsoleColor(LightMagenta);
        cout << "--------------------------------------------------\n";
        ResetColor();

        chon = int(InputParseDouble("1. Phuong trinh | 2. He phuong trinh | 3. Ket thuc\n-> "));

        if (chon == 1) {
            do {
                chon = int(InputParseDouble("1. ax + b = 0 | 2. ax^2 + bx + c = 0 | 3. ax^3 + bx^2 + cx + d = 0\n-> "));
            } while (chon < 0 || chon > 3);

            if (chon == 1) {
                LinearEquation();
            }
            else if (chon == 2) {
                QuadraticEquation();
            }
            else {
                CubicEquation();
            }
        }
        else if (chon == 2) {
            do {
                chon = int(InputParseDouble("1. ax + by = c | 2. ax + by + cz = d\n-> "));
            } while (chon < 0 || chon > 2);

            if (chon == 1) {
                SimultaneousEquations2Unknowns();
            }
            else {
                SimultaneousEquations3Unknowns();
            }
        }
        else if (chon == 3) {
            return 0;
        }
        else {
            continue;
        }


        do {
            cont = int(InputParseDouble("1. Tiep tuc | 2. Ket thuc\n-> "));

            if (cont == 2) {
                return 0;
            }
        } while (cont != 1 && cont != 2);
    }
}
