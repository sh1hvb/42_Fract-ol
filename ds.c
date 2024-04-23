
#include <stdio.h>
#include <math.h>
double myAtoDbl(const char *str) {
    double result = 0.0;
    double sign = 1.0;
    int i = 0;
    int decimal = 0; // Flag to track decimal point

    // Skip whitespace
    while (str[i] == ' ') {
        i++;
    }

    // Check for sign
    if (str[i] == '-') {
        sign = -1.0;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Convert digits to double
    while (str[i] != '\0') {
        if (str[i] == '.') {
            decimal = 1; // Set decimal flag
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (decimal) {
                // For digits after decimal point, adjust the result by multiplying by the appropriate power of 10
                result = result + (str[i] - '0') * pow(10, -decimal);
                decimal++;
            } else {
                result = result * 10.0 + (str[i] - '0');
            }
        } else {
            break; // Exit loop if non-numeric character encountered
        }
        i++;
    }

    return sign * result;
}

int main() {
    char str[] = "123.45";
    double num = myAtoDbl(str);
    printf("The double value is: %f\n", num);

    return 0;
}
