#include <iostream>
#include <unordered_set>
using namespace std;

// Function to remove duplicate characters using unordered_set
string getRemovalDuplicateStringUsingHashSet(const string &s) {
    unordered_set<char> seen;
    string result;

    for (char c: s) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

int main() {
    cout << getRemovalDuplicateStringUsingHashSet("hello") << endl; // Output: helo
    cout << getRemovalDuplicateStringUsingHashSet("apple") << endl; // Output: aple
    cout << getRemovalDuplicateStringUsingHashSet("mississippi") << endl; // Output: misp
    cout << getRemovalDuplicateStringUsingHashSet("abc") << endl; // Output: abc

    return 0;
}
