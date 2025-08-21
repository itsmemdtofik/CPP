/**
 * <pre>
 * !Longest Mountain Subarray
 * Given an array arr[] with N elements, the task is to find out the longest sub-array
 * which has the shape of a mountain.
 *
 * @param Note: A mountain sub-array starts with an increasing sequence,
 * reaches a peak, and then follows a decreasing sequence.
 *
 * Input: arr = [2, 2, 2]
 * Output: 0
 * Explanation: No sub-array exists that shows the behavior of a mountain sub-array.
 *
 * Input: arr = [1, 3, 1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5]
 * Output: 11
 * Explanation: Longest sub-array Mountain [1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5] which have length 11
 *
 * !Approach: Using the Nested loops - O(N^2) Time and O(1) Space
 * We can solve this problem using nested loops: the outer loop iterates over the array,
 * while the inner loop finds the mountain length starting at the outer loop's index.
 * The inner loop first checks the increasing slope, then the decreasing slope.
 * If both exist, we update the maximum mountain length accordingly.
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>

class LongestMountainSubarray {
public:
    static int findLongestMountainSubarray(const std::vector<int> &arr) {
        int longestMountain = 0;
        const int n = arr.size();

        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            bool increasing = false, decreasing = false;

            /* Check increasing sequence */
            while (j < n && arr[j] > arr[j - 1]) {
                increasing = true;
                ++j;
            }

            /* Check decreasing sequence */
            while (j < n && arr[j] < arr[j - 1]) {
                decreasing = true;
                ++j;
            }

            /* If a mountain is found, update the max length */
            if (increasing && decreasing) {
                longestMountain = std::max(longestMountain, j - i);
            }
        }

        return longestMountain;
    }
};

int main() {
    const std::vector<int> arr1 = {1, 3, 1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5};
    std::cout << "Expected: 11 == "
            << LongestMountainSubarray::findLongestMountainSubarray(arr1)
            << std::endl;

    const std::vector<int> arr2 = {2, 2, 2};
    std::cout << "Expected: 0 == "
            << LongestMountainSubarray::findLongestMountainSubarray(arr2)
            << std::endl;

    return 0;
}
