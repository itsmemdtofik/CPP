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
 * !Approach: Using Sliding Window Technique - O(n) Time and O(1) Space
 * </pre>
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

class MaximumConsecutiveOneFlipping {
public:
    /* Function to find maximum consecutive ones after flipping at most K zeros */
    static int maxConsecutiveOne(const std::vector<int> &arr, const int K) {
        int left = 0, right = 0;
        int maxLength = 0;
        int zeroCount = 0;
        const int n = arr.size();

        while (right < n) {
            /* Count zero in current window */
            if (arr[right] == 0) {
                zeroCount++;
            }

            /* Shrink window from left if number of zeros > K */
            while (zeroCount > K) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            /* Update maximum window size */
            maxLength = std::max(maxLength, right - left + 1);

            /* Optional debug: uncomment to match Java debug output */
            /* std::cout << "right = " << right << ", left = " << left << ", zeros = " << zeroCount << ", maxLen = " << maxLength << std::endl; */

            right++;
        }

        return maxLength;
    }
};

int main() {
    const std::vector<int> arr1 = {1, 0, 1};
    std::cout << "Expected: 3 == " << MaximumConsecutiveOneFlipping::maxConsecutiveOne(arr1, 1) << std::endl;

    const std::vector<int> arr2 = {1, 0, 0, 1, 0, 1, 0, 1};
    std::cout << "Expected: 5 == " << MaximumConsecutiveOneFlipping::maxConsecutiveOne(arr2, 2) << std::endl;

    const std::vector<int> arr3 = {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    std::cout << "Expected: 7 == " << MaximumConsecutiveOneFlipping::maxConsecutiveOne(arr3, 2) << std::endl;

    return 0;
}
