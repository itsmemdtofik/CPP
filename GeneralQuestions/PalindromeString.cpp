#include <iostream>
using namespace std;

// Check palindrome using simple comparison
bool getPalindromeString(const string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

// Check palindrome with normalization (ignore case and non-alphanumeric)
bool getPalindromeStringNormalization(const string &s) {
    string normalized;
    for (char c: s) {
        if (isalnum(c)) {
            normalized += tolower(c);
        }
    }

    int n = normalized.size();
    for (int i = 0; i < n / 2; i++) {
        if (normalized[i] != normalized[n - 1 - i]) return false;
    }
    return true;
}

int main() {
    cout << boolalpha; // Print true/false instead of 1/0

    // Palindrome tests without normalization
    cout << "Using Slicing:" << endl;
    cout << getPalindromeString("racecar") << endl; // true
    cout << getPalindromeString("hello") << endl; // false
    cout << getPalindromeString("A man a plan a canal Panama") << endl; // false

    // Palindrome tests with normalization
    cout << "Using Normalization:" << endl;
    cout << getPalindromeStringNormalization("racecar") << endl; // true
    cout << getPalindromeStringNormalization("hello") << endl; // false
    cout << getPalindromeStringNormalization("A man a plan a canal Panama") << endl; // true

    return 0;
}
