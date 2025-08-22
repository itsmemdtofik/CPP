#include <iostream>
using namespace std;

// Function to reverse an array in-place
void getReverseArray(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

// Utility to print vector
void printVector(const vector<int> &v) {
    for (int x: v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1, 0, 3, 4, 5};

    getReverseArray(arr);

    printVector(arr); // Output: 5 4 3 0 1

    return 0;
}
