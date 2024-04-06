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
        cout << "GIAI PHUONG TRINH" << endl;
        cout << "--------------------------------------------------" << endl;
        ResetColor();

        chon = int(InputParseFloat("1. Phuong trinh | 2. He phuong trinh | 3. Ket thuc\n-> "));

        if (chon == 1) {
            do {
                chon = int(InputParseFloat("1. ax + b = 0 | 2. ax^2 + bx + c = 0 | 3.ax^3 + bx^2 + cx + d = 0 \n-> "));
            } while (chon < 0 || chon > 3);

            if (chon == 1) {
                LinearEquation();
            }
            else if (chon == 2) {
                QuadraticEquation();
            }
            else {

            }
        }
        else if (chon == 2) {
            SimultaneousEquations2Unknowns();
        }
        else if (chon == 3) {
            return 0;
        }
        else {
            continue;
        }


        do {
            cont = int(InputParseFloat("1. Tiep tuc | 2. Ket thuc\n-> "));

            if (cont == 2) {
                return 0;
            }
        } while (cont != 1 && cont != 2);
    }
}
