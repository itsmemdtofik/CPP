#include <iostream>
#include <vector>
using namespace std;

/* Method 1: Using sum formula - sum(1..n) - sum(arr) */
int getMissingNumber(const vector<int> &nums, int number) {
    int expectedSum = number * (number + 1) / 2;
    int actualSum = 0;
    for (int num: nums) actualSum += num;
    return expectedSum - actualSum;
}

/* Method 2: Subtract each element from total sum */
int getMissingNumberII(const vector<int> &arr, int n) {
    int total = n * (n + 1) / 2;
    for (int num: arr) {
        total -= num;
    }
    return total;
}

int main() {
    vector<int> nums = {1, 2, 4, 5, 6}; // Missing 3

    cout << "\nMissing Number:" << endl;
    cout << getMissingNumber(nums, 6) << endl; // Output: 3
    cout << getMissingNumberII(nums, 6) << endl; // Output: 3

    return 0;
}
