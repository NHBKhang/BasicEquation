#include "format.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

string TrimToLowerCase(const string str) {
    istringstream iss(str);
    string firstElement;
    iss >> firstElement;

    // To lower case
    transform(firstElement.begin(), firstElement.end(), firstElement.begin(),
        [](unsigned char c) { return tolower(c); });

    return firstElement;
}
