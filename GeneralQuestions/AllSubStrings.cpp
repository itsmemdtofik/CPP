#include <iostream>
using namespace std;

/* 1️⃣ Using string slicing (substr) */
void getAllSubstring(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << s.substr(i, j - i) << endl; // s.substr(start, length)
        }
    }
}

/* 2️⃣ Using nested loop to build substring manually */
void getSubstringUsingNestedLoop(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string substring = "";
            for (int k = i; k <= j; k++) {
                substring += s[k]; /* build substring character by character */
            }
            cout << substring << endl;
        }
    }
}

int main() {
    string s = "abc";

    cout << "Using substr method:" << endl;
    getAllSubstring(s);

    cout << "\nUsing Nested Loop:" << endl;
    getSubstringUsingNestedLoop(s);

    return 0;
}
