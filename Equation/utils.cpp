#include "utils.h"
#include "operators.h"

ConsoleColor currentColor = White;

void ResetColor() {
    SetConsoleColor(currentColor);
}

void PrintMessage(string message) {
    SetConsoleColor(LightBlue);
    cout << "MSG: " << message << endl;
    ResetColor();
}

void PrintError(string error) {
    SetConsoleColor(Red);
    cerr << "ERR: " << error << endl;
    ResetColor();
}

void CommandPromptColor() {
    SetConsoleColor(LightCyan);
    cout << "\t\tCommand Prompt" << endl;
}

double InputParseDouble(string inputText) {
    string input;

    while (true)
    {
        try {
            cout << inputText;
            getline(cin, input);

            if (SpecialCommand(input)) continue;
            else {
                if (!input.empty())
                    return Evaluate(input);
            }
        }
        catch (const exception& e) {
            PrintError("Nhap du lieu khong phu hop!!! Vui long nhap lai");
            PrintError(e.what());

            continue;
        }
    }
}
void OutputStart() {
    SetConsoleColor(Green);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void ReadFile(const string& filename, const bool encrypt) {
    ifstream file(filename);
    if (!file.is_open()) {
        PrintError("Unable to open file " + filename);
        return;
    }

    string line;
    while (getline(file, line)) {
        if (!encrypt) {
            cout << line << endl;
        }
        else {
            char key;
            cout << "Nhap password: ";
            cin >> key;
            cout << XOR(line, key) << endl;
        }
    }

    file.close();
}

void encryptFile(const string& filename, const char& key) {
    ifstream file(filename);
    if (!file.is_open()) {
        PrintError("Unable to open file " + filename);
        return;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string contents = buffer.str();
    file.close();

    if (contents.empty()) {
        cerr << "File " << filename << " is empty or could not be read." << endl;
        return;
    }

    // Encrypt contents using XOR with the key
    string encryptedContents = XOR(contents, key);

    // Write encrypted contents back to the file
    ofstream outFile(filename, ofstream::trunc);
    if (!outFile.is_open()) {
        cerr << "Unable to write to file " << filename << endl;
        return;
    }
    outFile << encryptedContents;
    outFile.close();

    cout << "File encrypted successfully." << endl;
}

void WriteFile(const string& filename, const bool encrypt) {
    if (encrypt) {
        char key;
        cout << "Nhap password: ";
        cin >> key;
        encryptFile(filename, key);
    }
}

string XOR(const string& s, char c) {
    string result;
    for (char ch : s) {
        result += ch ^ c;
    }
    return result;
}

