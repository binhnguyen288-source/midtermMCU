#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef char* string;

string suffixWithUnit(double number) {
    static const string suffixes[] = {
        " Yocto", " Zepto", " Atto", " Femto",
        " Pico", " Nano", " Micro", " Mili",
        "", 
        " Kilo", " Mega", " Giga", " Tera", 
        " Peta", " Exa", " Zetta", " Yotta"
    };
    string str = malloc(32); // 31 characters shall be enough?
    if (number == 0.0) {
        strcpy(str, "0");
        return str;
    }
    int n = floor(log10(fabs(number)) / 3);
    int lookup_idx = n + 8;
    if (lookup_idx < 0 || lookup_idx >= 17) {
        sprintf(str, "%lf", number);
        return str;
    }
    sprintf(str, "%.4lf", number * pow(1000, -n));
    strcat(str, suffixes[lookup_idx]);
    return str;
}

int main() {
    double num = 1.234e-23;
    for (int i = 0; i < 50; ++i) {
        string str = suffixWithUnit(num);
        printf("1.234 x 10^%d = %s\n", -23 + i, str);
        free(str);
        num *= 10;
    }
    return 0;
}