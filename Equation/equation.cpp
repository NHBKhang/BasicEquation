#include "equation.h"

const double M_PI = 3.141592;

double roundZero(double num, double threshold = 1e-5) {
    if (abs(num) < threshold) {
        return 0.0;
    }
    return num;
}

void LinearEquation() {
    double a = InputParseDouble("Nhap he so a: ");
    double b = InputParseDouble("Nhap he so b: ");

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
    double a = 0;
    do {
        a = InputParseDouble("Nhap he so a: ");

        if (a == 0) {
            PrintError("Day la phuong trinh bac nhat. Hay nhap lai!!!");
        }
    } while (a == 0);
    double b = InputParseDouble("Nhap he so b: ");
    double c = InputParseDouble("Nhap he so c: ");

    double delta = b * b - 4 * a * c;

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
        double x = -b / (2 * a);
        cout << "=> x = " << x << endl;
    }
    else {
        double x1 = (-b + comp) / (2 * a);
        double x2 = (-b - comp) / (2 * a);
        cout << "=> x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    ResetColor();
}

void CubicEquation() {
    double a = 0;
    do {
        a = InputParseDouble("Nhap he so a: ");

        if (a == 0) {
            PrintError("Day la phuong trinh bac hai. Hay nhap lai!!!");
        }
    } while (a == 0);
    double b = InputParseDouble("Nhap he so b: ");
    double c = InputParseDouble("Nhap he so c: ");
    double d = InputParseDouble("Nhap he so d: ");

    OutputStart();
    cout << a << "x^3 " <<
        (b > 0 ? "+ " : "- ") << abs(b) << "x^2 " <<
        (c > 0 ? "+ " : "- ") << abs(c) << "x " <<
        (d > 0 ? "+ " : "- ") << abs(d) << " = 0\n";

    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * pow(b, 3) - 9 * a * b * c + 27 * a * a * d) / (27 * pow(a, 3));
    double delta = pow(q / 2, 2) + pow(p / 3, 3);

    if (delta >= 0) {
        double u = cbrt(-q / 2 + sqrt(delta));
        double v = cbrt(-q / 2 - sqrt(delta));

        double x = roundZero(u + v - b / (3 * a));
        double xr = roundZero(-(u + v) / 2 - b / (3 * a));
        double xi = roundZero((u - v) * sqrt(3) / 2);

        if (xi == 0.0) {
            cout << "=> x1 = " << x
                << ", x2 = " << xr << endl;
        }
        else {
            cout << "=> x1 = " << x
                << ", x2 = " << xr << " + " << xi << "i"
                << ", x3 = " << xr << " - " << xi << "i" << endl;
        }
    }
    else {
        double r = sqrt(pow(-p / 3, 3));
        double theta = acos(-q / (2 * r));

        double x1 = roundZero(2 * cbrt(r) * cos(theta / 3) - b / (3 * a));
        double x2 = roundZero(2 * cbrt(r) * cos((theta + 2 * M_PI) / 3) - b / (3 * a));
        double x3 = roundZero(2 * cbrt(r) * cos((theta + 4 * M_PI) / 3) - b / (3 * a));

        cout << "=> x1 = " << x1
            << ", x2 = " << x2
            << ", x3 = " << x3 << endl;
    }

    ResetColor();
}

void SimultaneousEquations2Unknowns() {
    double a[2][3];

    for (int i = 0; i < 2; i++)
    {
        a[i][0] = InputParseDouble("Nhap he so a" + to_string(i + 1) + ": ");
        a[i][1] = InputParseDouble("Nhap he so b" + to_string(i + 1) + ": ");
        a[i][2] = InputParseDouble("Nhap he so c" + to_string(i + 1) + ": ");
    }

    OutputStart();
    cout << a[0][0] << "x " << (a[0][1] > 0 ? "+ " : "- ") << abs(a[0][1]) << "y = " << a[0][2] << endl;
    cout << a[1][0] << "x " << (a[1][1] > 0 ? "+ " : "- ") << abs(a[1][1]) << "y = " << a[1][2] << endl;

    double det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    double x = a[0][2] * a[1][1] - a[1][2] * a[0][1], y = a[0][0] * a[1][2] - a[1][0] * a[0][2];

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

void SimultaneousEquations3Unknowns() {
    double a[3][4];

    for (int i = 0; i < 3; i++)
    {
        a[i][0] = InputParseDouble("Nhap he so a" + to_string(i + 1) + ": ");
        a[i][1] = InputParseDouble("Nhap he so b" + to_string(i + 1) + ": ");
        a[i][2] = InputParseDouble("Nhap he so c" + to_string(i + 1) + ": ");
        a[i][3] = InputParseDouble("Nhap he so d" + to_string(i + 1) + ": ");
    }

    OutputStart();
    cout << a[0][0] << "x " << (a[0][1] > 0 ? "+ " : "- ") 
        << abs(a[0][1]) << "y " << (a[0][2] > 0 ? "+ " : "- ") 
        << abs(a[0][2]) << "z = " << a[0][3] << endl;
    cout << a[1][0] << "x " << (a[1][1] > 0 ? "+ " : "- ") 
        << abs(a[1][1]) << "y " << (a[1][2] > 0 ? "+ " : "- ") 
        << abs(a[1][2]) << "z = " << a[1][3] << endl;
    cout << a[2][0] << "x " << (a[2][1] > 0 ? "+ " : "- ")
        << abs(a[2][1]) << "y " << (a[2][2] > 0 ? "+ " : "- ")
        << abs(a[2][2]) << "z = " << a[2][3] << endl;


    ResetColor();
}