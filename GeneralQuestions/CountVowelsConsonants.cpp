#include <iostream>
#include <string>
#include <cctype>   // for isalpha, tolower
using namespace std;

/* Function 1: Direct counting */
pair<int, int> getCountVowelsConsonant(const string &s) {
    int v = 0, c = 0;
    for (char ch: s) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                v++;
            } else {
                c++;
            }
        }
    }
    return {v, c};
}

/* Function 2: Enhanced version */
pair<int, int> count_vowels_consonants_enhanced(const string &s) {
    string letters = "";
    for (char ch: s) {
        if (isalpha(ch)) {
            letters.push_back(tolower(ch));
        }
    }

    int vowels = 0;
    for (char ch: letters) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
    }

    int consonants = letters.size() - vowels;
    return {vowels, consonants};
}

int main() {
    /* Tests for Function 1 */
    auto res1 = getCountVowelsConsonant("Hello World");
    cout << "(" << res1.first << ", " << res1.second << ")" << endl; // (3, 7)

    auto res2 = getCountVowelsConsonant("Python");
    cout << "(" << res2.first << ", " << res2.second << ")" << endl; // (1, 5)

    auto res3 = getCountVowelsConsonant("AEiou");
    cout << "(" << res3.first << ", " << res3.second << ")" << endl; // (5, 0)

    /* Tests for Function 2 */
    auto res4 = count_vowels_consonants_enhanced("Hello World");
    cout << "(" << res4.first << ", " << res4.second << ")" << endl; // (3, 7)

    auto res5 = count_vowels_consonants_enhanced("Python");
    cout << "(" << res5.first << ", " << res5.second << ")" << endl; // (1, 5)

    auto res6 = count_vowels_consonants_enhanced("AEiou");
    cout << "(" << res6.first << ", " << res6.second << ")" << endl; // (5, 0)

    return 0;
}
