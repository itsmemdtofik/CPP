#include <iostream>
using namespace std;

// Function to get sum of digits
int getSumOfDigits(int num) {
    num = abs(num); // Handle negative numbers
    int sum_digits = 0;
    while (num > 0) {
        sum_digits += num % 10;
        num /= 10;
    }
    return sum_digits;
}

int main() {
    int number = 12345;
    cout << "Sum of digits of " << number << " is: " << getSumOfDigits(number) << "\n";
    return 0;
}
