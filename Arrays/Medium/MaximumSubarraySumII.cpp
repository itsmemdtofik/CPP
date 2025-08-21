/**
 * <pre>
 * !Maximum Subarray Sum - Kadane's Algorithm
 * Given an array arr[], the task is to find the subarray that has the maximum sum and return its sum.
 *
 * @param Examples:
 * Input: arr[] = {2, 3, -8, 7, -1, 2, 3}
 * Output: 11
 * Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
 *
 * Input: arr[] = {-2, -4}
 * Output: -2
 * Explanation: The subarray {-2} has the largest sum -2.
 *
 * Input: arr[] = {5, 4, 1, 7, 8}
 * Output: 25
 * Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
 *
 * !Approach: By iterating over all subarrays - O(n^2) Time and O(1) Space
 * </pre>
 *
 * @param args
 */


#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class MaximumSubArrSumII {
public:
    /* Method to find maximum subarray sum by checking all subarrays */
    static int maximumSubarraySum(const std::vector<int> &arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Array must not be empty");
        }

        const int n = arr.size();
        int maxGlobal = arr[0];

        for (int i = 0; i < n; ++i) {
            int maxCurrent = 0;
            for (int j = i; j < n; ++j) {
                maxCurrent += arr[j];
                maxGlobal = std::max(maxGlobal, maxCurrent);
            }
        }

        return maxGlobal;
    }
};

int main() {
    const std::vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    std::cout << "Maximum sum 11: "
            << MaximumSubArrSumII::maximumSubarraySum(arr1) << std::endl;

    const std::vector<int> arr2 = {-2, -4};
    std::cout << "Maximum sum -2: "
            << MaximumSubArrSumII::maximumSubarraySum(arr2) << std::endl;

    const std::vector<int> arr3 = {5, 4, 1, 7, 8};
    std::cout << "Maximum sum 25: "
            << MaximumSubArrSumII::maximumSubarraySum(arr3) << std::endl;

    return 0;
}
