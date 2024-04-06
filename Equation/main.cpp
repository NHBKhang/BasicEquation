#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "color.h"
#include "command.h"

using namespace std;


int InputParseInt(string inputText) {
    string input;

    while (true)
    {
        try {
            cout << inputText;
            getline(cin, input);

            if (SpecialCommand(input)) continue;

            return stoi(input);
        }
        catch (const exception&) {
            SetConsoleColor(Red);
            cout << "Nhap du lieu khong phu hop!!! Vui long nhap lai" << endl;
            SetConsoleColor(White);

            continue;
        }
    }
}


void PhuongTrinhBacNhat() {
    float a, b;

    a = InputParseInt("Nhap he so a: ");
    b = InputParseInt("Nhap he so b: ");

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem." << endl;
        }
        else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    }
    else {
        float x = -b / a;
        cout << "x = " << x << endl;
    }
}

void HePhuongTrinhHaiAn() {
    float a1, b1, c1, a2, b2, c2;
  
    cout << "Nhap he so a1: ";
    cin >> a1;
    cout << "Nhap he so b1: ";
    cin >> b1;
    cout << "Nhap he so c1: ";
    cin >> c1;
    cout << "Nhap he so a2: ";
    cin >> a2;
    cout << "Nhap he so b2: ";
    cin >> b2;
    cout << "Nhap he so c2: ";
    cin >> c2;

    if (a1 * b2 - a2 * b1 == 0) {
        cout << "He phuong trinh khong co nghiem.";
    }

    float x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    float y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main() {
    int chon = -1, cont = -1;

    while (true) {
        cout << "GIAI PHUONG TRINH" << endl;
        cout << "--------------------------------------------------" << endl;
        chon = InputParseInt("1. Phuong trinh | 2. He phuong trinh | 3. Ket thuc\n");

        if (chon == 1) {
            PhuongTrinhBacNhat();
        }
        else if (chon == 2) {
            HePhuongTrinhHaiAn();
        }
        else if (chon == 3) {
            return 0;
        }


        do {
            cont = InputParseInt("1. Tiep tuc | 2. Ket thuc\n");

            if (cont == 2) {
                return 0;
            }
        } while (cont != 1 && cont != 2);
    }
}
