/**
 * <pre>
 * !Maximum Consecutive Ones After Flipping Zeroes
 * Given a binary array arr[] and an integer k, find the maximum length of a subarray
 * containing all ones after flipping at most k zeroes to 1's.
 *
 * Examples: Input: arr[] = {1, 0, 1}, k = 1
 * Output: 3
 * Explanation: By flipping the zero at index 1, all the array elements become one.
 *
 * Input: arr[] = {1, 0, 0, 1, 0, 1, 0, 1}, k = 2
 * Output: 5
 * Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1's.
 *
 * !Approach: By Exploring All the Subarrays - O(n^2) Time and O(1) Space
 * A simple approach is to generate all possible subarrays using two nested loops. Then, for each subarray,
 * count the number of zeroes. If the count is less than or equal to k, we can convert all the elements
 * of the subarray to one by flipping all the zeroes. Finally, the length of longest subarray among all
 * such subarrays will be our answer.
 * </pre>
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

class MaximumConsecutiveOneFlippingII {
public:
    /* Brute-force method: Explore all subarrays */
    static int maxConsecutiveOne(const std::vector<int> &arr, const int k) {
        int maxLength = 0;
        const int n = arr.size();

        for (int i = 0; i < n; i++) {
            int zeroCount = 0;

            for (int j = i; j < n; j++) {
                if (arr[j] == 0)
                    zeroCount++;

                /* If zeroCount <= k, all zeroes can be flipped */
                if (zeroCount <= k) {
                    maxLength = std::max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};

int main() {
    const std::vector<int> arr1 = {1, 0, 1};
    std::cout << "Expected: 3 == " << MaximumConsecutiveOneFlippingII::maxConsecutiveOne(arr1, 1) << std::endl;

    const std::vector<int> arr2 = {1, 0, 0, 1, 0, 1, 0, 1};
    std::cout << "Expected: 5 == " << MaximumConsecutiveOneFlippingII::maxConsecutiveOne(arr2, 2) << std::endl;

    const std::vector<int> arr3 = {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    std::cout << "Expected: 7 == " << MaximumConsecutiveOneFlippingII::maxConsecutiveOne(arr3, 2) << std::endl;

    return 0;
}
