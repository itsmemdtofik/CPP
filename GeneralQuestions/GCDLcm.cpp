#include <iostream>
#include <cstdlib> // for abs()
using namespace std;

// Recursive GCD
int getGCD(int a, int b) {
    if (b == 0) return abs(a); // handle negatives
    return getGCD(b, a % b);
}

// LCM using GCD
int getLCM(int a, int b) {
    if (a == 0 || b == 0) return 0; // edge case
    return abs(a * b) / getGCD(a, b);
}

// Iterative GCD
int gcdIterative(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Iterative LCM
int lcmIterative(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / gcdIterative(a, b);
}

int main() {
    cout << getGCD(48, 18) << endl; // 6
    cout << getGCD(0, 5) << endl; // 5
    cout << getGCD(-15, 25) << endl; // 5

    cout << getLCM(12, 15) << endl; // 60
    cout << getLCM(0, 5) << endl; // 0
    cout << getLCM(-4, 6) << endl; // 12

    // Iterative versions
    cout << gcdIterative(48, 18) << endl; // 6
    cout << lcmIterative(-4, 6) << endl; // 12

    return 0;
}
