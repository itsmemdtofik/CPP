#include <iostream>
using namespace std;

// Function to reverse a number
int reverseNumber(int num) {
    int reversedNumber = 0;
    int number = abs(num);
    while (number != 0) {
        int remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number = number / 10;
    }
    return reversedNumber;
}

// Function to check if a number is a palindrome
bool isPalindromeNumber(int number) {
    if (number < 0) return false; // Negative numbers are not palindrome
    return number == reverseNumber(number);
}

int main() {
    cout << boolalpha; // To print 'true' or 'false' instead of 1/0

    cout << isPalindromeNumber(12321) << endl; // true
    cout << isPalindromeNumber(12345) << endl; // false
    cout << isPalindromeNumber(-121) << endl; // false

    return 0;
}
