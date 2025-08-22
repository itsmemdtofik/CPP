#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int binaryToDecimalPower(const string &binary_str) {
    int decimal = 0;
    int length = binary_str.length();

    for (int i = 0; i < length; i++) {
        int bit = binary_str[i] - '0'; /* Convert char to int */
        int power = length - i - 1;
        decimal += bit * pow(2, power);
    }

    return decimal;
}


int binaryToDecimalBitShift(const string &binary_str) {
    int decimal = 0;
    for (char bit_char: binary_str) {
        int bit = bit_char - '0';
        decimal = (decimal << 1) | bit; /* Left shift and OR with new bit */
    }
    return decimal;
}

int main() {
    string test_cases[] = {"1010", "1111", "10000", "1", "0"};

    for (auto &binary: test_cases) {
        cout << "Binary: " << binary
                << " -> Decimal (Power method): " << binaryToDecimalPower(binary) << endl;
        cout << "Binary: " << binary
                << " -> Decimal (Bit shift method): " << binaryToDecimalBitShift(binary) << endl;
        cout << "---------------------------" << endl;
    }

    return 0;
}
