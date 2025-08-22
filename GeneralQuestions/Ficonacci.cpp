#include <iostream>
using namespace std;

void getFibonacci(int nums) {
    long long a = 0, b = 1; // use long long for larger numbers

    for (int i = 0; i < nums; i++) {
        cout << a << " ";
        long long next = a + b; // compute next term
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    getFibonacci(10); // Output: 0 1 1 2 3 5 8 13 21 34
    return 0;
}
