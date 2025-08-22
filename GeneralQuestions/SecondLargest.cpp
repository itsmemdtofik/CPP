#include <iostream>
using namespace std;

// 🔹 Method 1: Using two variables (handles duplicates)
int getSecondLargestNumber(const vector<int> &nums) {
    if (nums.size() < 2) return INT_MIN; // Not enough elements

    int first = INT_MIN, second = INT_MIN;
    for (int num: nums) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num < first) {
            second = num;
        }
    }
    return second;
}

// 🔹 Method 2: Slightly different logic (avoids duplicates)
int getSecondLargestNumberII(const vector<int> &arr) {
    int first = INT_MIN, second = INT_MIN;
    for (int num: arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num != first) {
            second = num;
        }
    }
    return second;
}

int main() {
    vector<int> arr = {1000, 2, 3, 10, 100, -100};

    cout << "Second largest number: " << getSecondLargestNumberII(arr) << endl; // Output: 100

    return 0;
}
