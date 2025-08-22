#include <iostream>
#include <string>
#include <algorithm>  // for reverse
using namespace std;

/* Method 1: Division approach */
string getDecimalToBinary(int decimal) {
    if (decimal == 0) return "0";

    string binary = "";
    int num = abs(decimal); // handle negative numbers

    while (num > 0) {
        binary.push_back((num % 2) + '0'); // remainder as char
        num /= 2;
    }

    reverse(binary.begin(), binary.end()); // reverse to get correct order

    return (decimal >= 0) ? binary : "-" + binary;
}

/* Method 2: Bit-shifting approach */
string getDecimalToBinaryUsingBitShifting(int decimal) {
    if (decimal == 0) return "0";

    string binary = "";
    int num = abs(decimal);

    while (num > 0) {
        binary.push_back((num & 1) + '0'); // least significant bit
        num >>= 1; // right shift (divide by 2)
    }

    reverse(binary.begin(), binary.end());

    return (decimal >= 0) ? binary : "-" + binary;
}

int main() {
    cout << "Using Division Method:" << endl;
    cout << getDecimalToBinary(10) << endl; // "1010"
    cout << getDecimalToBinary(15) << endl; // "1111"
    cout << getDecimalToBinary(0) << endl; // "0"
    cout << getDecimalToBinary(1) << endl; // "1"
    cout << getDecimalToBinary(-5) << endl; // "-101"

    cout << "\nUsing Bit Shifting Method:" << endl;
    cout << getDecimalToBinaryUsingBitShifting(10) << endl; // "1010"
    cout << getDecimalToBinaryUsingBitShifting(15) << endl; // "1111"
    cout << getDecimalToBinaryUsingBitShifting(0) << endl; // "0"
    cout << getDecimalToBinaryUsingBitShifting(1) << endl; // "1"
    cout << getDecimalToBinaryUsingBitShifting(-5) << endl; // "-101"

    return 0;
}
