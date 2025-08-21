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

class MaximumProductSubarrayII {
public:
    /* Method to find maximum product subarray using O(n^2) approach */
    static int maximumProductSubarray(const std::vector<int> &arr) {
        const int n = arr.size();
        if (n == 0)
            return 0;

        int maxGlobal = arr[0];

        for (int i = 0; i < n; i++) {
            int maxCurrent = 1;
            for (int j = i; j < n; j++) {
                maxCurrent *= arr[j];
                maxGlobal = std::max(maxGlobal, maxCurrent);
            }
        }

        return maxGlobal;
    }
};

int main() {
    const std::vector<int> arr = {-2, 6, -3, -10, 0, 2};
    std::cout << "Maximum product: "
            << MaximumProductSubarrayII::maximumProductSubarray(arr) << std::endl;
    return 0;
}
