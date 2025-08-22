#include <iostream>
using namespace std;

// Function to check if a number is perfect
bool getPerfectNumber(int number) {
    int sum = 0;
    for (int num = 1; num < number; num++) {
        if (number % num == 0) {
            sum += num;
        }
    }
    return sum == number;
}

int main() {
    cout << boolalpha; // Print true/false instead of 1/0

    cout << getPerfectNumber(15) << endl; // false
    cout << getPerfectNumber(16) << endl; // false
    cout << getPerfectNumber(100) << endl; // false
    cout << getPerfectNumber(10000) << endl; // false

    return 0;
}
