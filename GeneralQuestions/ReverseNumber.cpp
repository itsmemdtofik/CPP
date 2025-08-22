#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 🔹 Method 1: While Loop (Mathematical way)
int reverseWhile(int n) {
    int rev = 0;
    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}

// 🔹 Method 2: String Conversion
int reverseString(int n) {
    bool isNeg = (n < 0);
    string s = to_string(abs(n));
    reverse(s.begin(), s.end());
    int rev = stoi(s);
    return isNeg ? -rev : rev;
}

// 🔹 Method 3: Recursion
int helper(int n, int rev) {
    if (n == 0) return rev;
    return helper(n / 10, rev * 10 + n % 10);
}

int reverseRecursive(int n) {
    bool isNeg = (n < 0);
    int rev = helper(abs(n), 0);
    return isNeg ? -rev : rev;
}

// 🔹 Method 4: Using Stack
int reverseStack(int n) {
    bool isNeg = (n < 0);
    n = abs(n);

    stack<int> st;
    while (n > 0) {
        st.push(n % 10);
        n /= 10;
    }

    int rev = 0;
    while (!st.empty()) {
        rev = rev * 10 + st.top();
        st.pop();
    }
    return isNeg ? -rev : rev;
}


// 🔹 Main Program
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "\nReversing number " << num << " using different methods:\n";
    cout << "1. While Loop:     " << reverseWhile(num) << endl;
    cout << "2. String Method:  " << reverseString(num) << endl;
    cout << "3. Recursion:      " << reverseRecursive(num) << endl;
    cout << "4. Stack:          " << reverseStack(num) << endl;


    return 0;
}
