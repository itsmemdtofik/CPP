/**
 * <pre>
 * !Finding some of the digits of a number until sum become single digit.
 *
 * Given an integer n, we need to repeatedly find the sum of its digits until
 * the result becomes a single-digit number.
 *
 * Examples:
 *
 * Input: n = 1234
 * Output: 1
 * Explanation:
 * Step 1: 1 + 2 + 3 + 4 = 10
 * Step 2: 1 + 0 = 1
 *
 *
 * Input: n = 5674
 * Output: 4
 * Explanation:
 * Step 1: 5 + 6 + 7 + 4 = 22
 * Step 2: 2 + 2 = 4
 * </pre>
 */

#include <iostream>
#include <vector>
#include <climits> /* for INT_MAX */
using namespace std;

int findSumOfDigit(const vector<int> &arr) {
    if (arr.empty()) {
        return 0;
    }

    long long sumArr = 0; /* use long to avoid overflow */
    int sumOfDigit = 0;

    for (const int num: arr) {
        sumArr += num;
    }

    while (sumArr != 0) {
        const int rem = sumArr % 10;
        sumOfDigit += rem;
        sumArr /= 10;
    }

    return sumOfDigit;
}

int main() {
    const vector<int> arr1 = {1, 2, 3, 4};
    const vector<int> arr2 = {5, 6, 7, 4};
    const vector<int> arr3 = {9, 6, 8, 4};
    const vector<int> arr4 = {1, 2, 3};
    const vector<int> arr5 = {INT_MAX, INT_MAX};
    const vector<int> arr6 = {10, -5, 20};

    cout << "The sum of digit is: ";
    cout << findSumOfDigit(arr1) << endl;
    cout << findSumOfDigit(arr2) << endl;
    cout << findSumOfDigit(arr3) << endl;
    cout << findSumOfDigit(arr4) << endl;
    cout << findSumOfDigit(arr5) << endl;
    cout << findSumOfDigit(arr6) << endl;

    return 0;
}
