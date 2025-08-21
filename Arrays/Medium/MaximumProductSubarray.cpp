/**
 * <pre>
 * !Maximum Product Subarray
 * Given an integer array, the task is to find the maximum product of any subarray.
 *
 * Input: arr[] = {-2, 6, -3, -10, 0, 2}
 * Output: 180
 * Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180
 *
 * Input: arr[] = {-1, -3, -10, 0, 60}
 * Output: 60
 * Explanation: The subarray with maximum product is {60}.
 *
 * !Approach: By using two nested loops – O(n) Time and O(1) Space
 *
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MaximumProductSubarray {
public:
    /* Method to find maximum product subarray */
    static int maximumProductSubarray(const std::vector<int> &arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Array must not be empty");
        }

        int maxProduct = arr[0];
        int minProduct = arr[0];
        int maxGlobal = arr[0];

        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                std::swap(maxProduct, minProduct);
            }

            maxProduct = std::max(arr[i], maxProduct * arr[i]);
            minProduct = std::min(arr[i], minProduct * arr[i]);

            maxGlobal = std::max(maxGlobal, maxProduct);
        }

        return maxGlobal;
    }
};

int main() {
    const std::vector<int> arr1 = {-2, 6, -3, -10, 0, 2};
    std::cout << "Maximum product: " << MaximumProductSubarray::maximumProductSubarray(arr1) << std::endl;

    const std::vector<int> arr2 = {-1, -3, -10, 0, 60};
    std::cout << "Maximum product: " << MaximumProductSubarray::maximumProductSubarray(arr2) << std::endl;

    const std::vector<int> arr3 = {2, 3, -2, 4};
    std::cout << "Maximum product: " << MaximumProductSubarray::maximumProductSubarray(arr3) << std::endl;

    const std::vector<int> arr4 = {-2, 0, -1};
    std::cout << "Maximum product: " << MaximumProductSubarray::maximumProductSubarray(arr4) << std::endl;

    return 0;
}
