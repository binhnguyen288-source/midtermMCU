#include <string>
#include <cmath>
#include <iostream>

using namespace std;


string suffixWithUnit(double number) {
    static const string suffixes[] = {
        " Yocto", " Zepto", " Atto", " Femto",
        " Pico", " Nano", " Micro", " Mili",
        "", 
        " Kilo", " Mega", " Giga", " Tera", 
        " Peta", " Exa", " Zetta", " Yotta"
    };
    if (number == 0.0) return "0";
    int n = floor(log10(fabs(number)) / 3);
    int lookup_idx = n + 8;
    if (lookup_idx < 0 || lookup_idx >= 17) {
        return to_string(number);
    }
    return to_string(number * pow(1000, -n)) + suffixes[lookup_idx];
}

int main() {
    double num = 1.234e-23;
    for (int i = 0; i < 50; ++i) {
        string str = suffixWithUnit(num);
        printf("1.234 x 10^%d = %s\n", -23 + i, str.c_str());
        num *= 10;
    }
    return 0;
}