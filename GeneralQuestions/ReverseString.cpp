#include <iostream>
using namespace std;

// 🔹 Method 1: Reverse String using Two Pointers
string reverseTwoPointer(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

// 🔹 Method 2: Reverse String using Loop
string reverseLoop(string s) {
    string reversed = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    return reversed;
}

// 🔹 Method 3: Reverse String using Built-in (equivalent to Python slicing)
string reverseSlice(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    vector<string> testStrings = {"hello", "Python", "racecar", ""};

    cout << "🔹 Using Two Pointer Method:\n";
    for (string s: testStrings) {
        cout << s << " -> " << reverseTwoPointer(s) << endl;
    }

    cout << "\n🔹 Using Loop Method:\n";
    for (string s: testStrings) {
        cout << s << " -> " << reverseLoop(s) << endl;
    }

    cout << "\n🔹 Using Built-in (Slice Equivalent):\n";
    for (string s: testStrings) {
        cout << s << " -> " << reverseSlice(s) << endl;
    }

    return 0;
}
