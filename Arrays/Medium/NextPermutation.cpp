/**
 * <pre>
 * ! Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
 *
 * Example: Permutations of [1, 2, 4] in lexicographical order:
 * [1, 2, 4]
 * [1, 4, 2]
 * [2, 1, 4]
 * [2, 4, 1]
 * [4, 1, 2]
 * [4, 2, 1]
 *
 * !Approach:
 * Step1. Find the first decreasing element from the end (pivot)
 * Step2. Find the smallest element larger than pivot to its right
 * Step3. Swap them
 * Step4. Reverse the suffix after the pivot
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NextPermutation {
public:
    static void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1)
            return;

        /* Step 1: Find the first decreasing element from the end (pivot) */
        size_t pivot = nums.size() - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
            pivot--;
        }

        /* If no pivot found, reverse the whole array */
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        /* Step 2: Find the smallest element larger than pivot to its right */
        size_t swapIndex = nums.size() - 1;
        while (nums[swapIndex] <= nums[pivot]) {
            swapIndex--;
        }

        /* Step 3: Swap pivot with swapIndex */
        swap(nums[pivot], nums[swapIndex]);

        /* Step 4: Reverse the suffix after pivot */
        reverse(nums.begin() + pivot + 1, nums.end());
    }

    static void printArray(const vector<int> &nums) {
        cout << "[";
        for (size_t i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i != nums.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
};

int main() {
    vector<int> arr1 = {1, 2, 3};
    NextPermutation::nextPermutation(arr1);
    cout << "Next permutation of [1, 2, 3]: ";
    NextPermutation::printArray(arr1);
    cout << endl;

    vector<int> arr2 = {3, 2, 1};
    NextPermutation::nextPermutation(arr2);
    cout << "Next permutation of [3, 2, 1]: ";
    NextPermutation::printArray(arr2);
    cout << endl;

    vector<int> arr3 = {1, 1, 5};
    NextPermutation::nextPermutation(arr3);
    cout << "Next permutation of [1, 1, 5]: ";
    NextPermutation::printArray(arr3);
    cout << endl;

    vector<int> arr4 = {1};
    NextPermutation::nextPermutation(arr4);
    cout << "Next permutation of [1]: ";
    NextPermutation::printArray(arr4);
    cout << endl;

    vector<int> arr5 = {2, 4, 1, 7, 5, 0};
    NextPermutation::nextPermutation(arr5);
    cout << "Next permutation of [2, 4, 1, 7, 5, 0]: ";
    NextPermutation::printArray(arr5);
    cout << endl;

    vector<int> arr6 = {1, 3, 2};
    NextPermutation::nextPermutation(arr6);
    cout << "Next permutation of [1, 3, 2]: ";
    NextPermutation::printArray(arr6);
    cout << endl;

    return 0;
}
