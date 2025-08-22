#include <iostream>
using namespace std;

// Basic prime check using sqrt
bool getPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int num = 3; num * num <= number; num += 2) {
        if (number % num == 0) return false;
    }
    return true;
}

// Optimized prime check (6k ± 1)
bool getPrimeII(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    int i = 5, w = 2;
    while (i * i <= number) {
        if (number % i == 0) return false;
        i += w;
        w = 6 - w; // alternates between +2 and +4
    }
    return true;
}

int main() {
    cout << boolalpha; // Print true/false instead of 1/0

    // Basic prime tests
    cout << getPrime(2) << endl; // true
    cout << getPrime(17) << endl; // true
    cout << getPrime(100) << endl; // false
    cout << getPrime(1) << endl; // false

    // Optimized prime tests
    cout << getPrimeII(2) << endl; // true
    cout << getPrimeII(17) << endl; // true
    cout << getPrimeII(100) << endl; // false
    cout << getPrimeII(1) << endl; // false

    return 0;
}
