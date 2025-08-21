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
 * !Approach: Using Kadane's Algorithm - O(n) Time and O(1) Space
 * </pre>
 * @param args
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MaximumSubArrSum {
public:
    /* Method to find maximum subarray sum using Kadane's Algorithm */
    static int maximumSubarraySum(const std::vector<int> &arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Array must not be empty");
        }

        int maxCurrent = arr[0];
        int maxGlobal = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            maxCurrent = std::max(maxCurrent + arr[i], arr[i]);
            maxGlobal = std::max(maxGlobal, maxCurrent);
        }

        return maxGlobal;
    }
};

int main() {
    const std::vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    std::cout << "Maximum sum: "
            << MaximumSubArrSum::maximumSubarraySum(arr1) << std::endl;

    const std::vector<int> arr2 = {-2, -4};
    std::cout << "Maximum sum: "
            << MaximumSubArrSum::maximumSubarraySum(arr2) << std::endl;

    const std::vector<int> arr3 = {5, 4, 1, 7, 8};
    std::cout << "Maximum sum: "
            << MaximumSubArrSum::maximumSubarraySum(arr3) << std::endl;

    return 0;
}
