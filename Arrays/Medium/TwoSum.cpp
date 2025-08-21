/**
 *<pre>
 * !Two Sum in a Sorted Array
 * Given:A sorted array of integers nums[] in ascending order.
 * A target integer target.
 * </pre>
 */
#include <iostream>
#include <vector>
using namespace std;

class TwoSumSortedArray {
public:
    /* Brute-force two-pointer approach */
    static vector<int> usingTwoPointer(const vector<int> &nums, const int target) {
        const int n = nums.size();
        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                if (nums[left] + nums[right] == target) {
                    return {left, right};
                }
            }
        }
        return {}; // return empty vector if no pair found
    }

    /* Optimized two-pointer approach */
    static vector<int> optimizedUsingTwoPointer(const vector<int> &nums, const int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            const int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left, right};
            }
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

int main() {
    const vector<int> nums = {2, 7, 11, 15};
    constexpr int target = 26;
    const vector<int> result = TwoSumSortedArray::usingTwoPointer(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    const vector<int> nums1 = {2, 7, 11, 15};
    constexpr int target1 = 26;
    const vector<int> result1 = TwoSumSortedArray::optimizedUsingTwoPointer(nums1, target1);

    if (!result1.empty()) {
        cout << "Indices: " << result1[0] << ", " << result1[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}
