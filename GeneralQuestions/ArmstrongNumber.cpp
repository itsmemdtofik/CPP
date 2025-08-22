#include <iostream>
using namespace std;


bool isArmstrong(int number) {
    if (number < 0) return false;

    int temp = number;
    int sum = 0;
    int digits = to_string(number).length();

    while (temp != 0) {
        int remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    return sum == number;
}

int main() {
    vector<int> testCases = {153, 9474, 123, -153};

    for (int num: testCases) {
        cout << num << " -> "
                << (isArmstrong(num) ? "True" : "False") << endl;
    }

    return 0;
}
