#include <iostream>
#include <stdexcept>  // for invalid_argument
using namespace std;

long long getFactorial(int nums) {
    if (nums < 0) {
        throw invalid_argument("Factorial is only defined for non-negative integers");
    }

    long long fact = 1;
    for (int i = 2; i <= nums; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    try {
        cout << getFactorial(5) << endl; // Output: 120
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
