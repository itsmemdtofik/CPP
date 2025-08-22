#include <iostream>
using namespace std;

// Method 1: Using direction (ascending or descending)
bool getSortedArray(const vector<int> &nums, bool ascending = true) {
    int direction = ascending ? 1 : -1;
    for (size_t i = 0; i + 1 < nums.size(); i++) {
        if (nums[i] * direction > nums[i + 1] * direction) {
            return false;
        }
    }
    return true;
}

// Method 2: Simple ascending check
bool getSortedArrayII(const vector<int> &arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> sorted_arr = {1, 2, 3, 4, 5};
    vector<int> unsorted_arr = {3, 1, 4, 2, 5};

    cout << "\nSorted Check:\n";
    cout << "sorted_arr (Method II): " << (getSortedArrayII(sorted_arr) ? "true" : "false") << "\n";
    cout << "unsorted_arr (Method I): " << (getSortedArray(unsorted_arr) ? "true" : "false") << "\n";

    return 0;
}
