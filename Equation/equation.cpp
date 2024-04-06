#include "equation.h"


void LinearEquation() {
    float a = InputParseFloat("Nhap he so a: ");
    float b = InputParseFloat("Nhap he so b: ");

    OutputStart();
    cout << a << "x " << (b > 0 ? "+ " : "- ") << abs(b) << " = 0\n";

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem." << endl;
        }
        else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    }
    else {
        cout << "=> x = " << -b / a << endl;
    }

    ResetColor();
}

void QuadraticEquation() {
    float a;
    do {
        a = InputParseFloat("Nhap he so a: ");

        if (a == 0) {
            PrintError("Day la phuong trinh bac nhat.Hay nhap lai!!!");
        }
    } while (a == 0);
    float b = InputParseFloat("Nhap he so b: ");
    float c = InputParseFloat("Nhap he so c: ");

    float delta = b * b - 4 * a * c;

    OutputStart();
    cout << a << "x^2 " << 
        (b > 0 ? "+ " : "- ") << abs(b) << "x " << 
        (c > 0 ? "+ " : "- ") << abs(c) << " = 0\n";

    float comp = sqrt(abs(delta));
    if (delta < 0) {
        cout << "=> x1 = " << -b / 2 * a << " + " << comp / 2 * a
             << "i, x2 = " << -b / 2 * a << " - " << comp / 2 * a << "i\n";
    }
    else if (delta == 0) {
        float x = -b / (2 * a);
        cout << "=> x = " << x << endl;
    }
    else {
        float x1 = (-b + comp) / (2 * a);
        float x2 = (-b - comp) / (2 * a);
        cout << "=> x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    ResetColor();
}

void SimultaneousEquations2Unknowns() {
    float a[2][3];

    for (int i = 0; i < 2; i++)
    {
        a[i][0] = InputParseFloat("Nhap he so a" + to_string(i + 1) + ": ");
        a[i][1] = InputParseFloat("Nhap he so b" + to_string(i + 1) + ": ");
        a[i][2] = InputParseFloat("Nhap he so c" + to_string(i + 1) + ": ");
    }

    OutputStart();
    cout << a[0][0] << "x " << (a[0][1] > 0 ? "+ " : "- ") << abs(a[0][1]) << "y = " << a[0][2] << endl;
    cout << a[1][0] << "x " << (a[1][1] > 0 ? "+ " : "- ") << abs(a[1][1]) << "y = " << a[1][2] << endl;

    float det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    float x = a[0][2] * a[1][1] - a[1][2] * a[0][1], y = a[0][0] * a[1][2] - a[1][0] * a[0][2];

    if (det == 0) {
        if (x != 0 || y != 0) {
            cout << "He phuong trinh vo nghiem.\n";
        }
        else {
            cout << "He phuong trinh vo so nghiem.\n";
        }
    }
    else {
        cout << "=> x = " << x / det << "\n";
        cout << "=> y = " << y / det << "\n";
    }

    ResetColor();
}