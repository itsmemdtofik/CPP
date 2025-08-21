/**
 * <pre>
 * ! Minimize Height
 *
 * Given an array arr[] denoting heights of N towers and a positive integer K.
 *
 * For each tower, you must perform exactly one of the following operations
 * exactly once.
 *
 * Increase the height of the tower by K
 * Decrease the height of the tower by K
 * Find out the minimum possible difference between the height of the shortest
 * and tallest towers after you have modified each tower.
 *
 * You can find a slight modification of the problem here.
 * Note: It is compulsory to increase or decrease the height by K for each
 * tower. After the operation, the resultant array should not contain any
 * negative integers.
 *
 * Examples :
 *
 * Input: k = 2, arr[] = {1, 5, 8, 10}
 * Output: 5
 * Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6,
 * 8}.The difference between the largest and the smallest is 8-3 = 5.
 *
 * Input: k = 3, arr[] = {3, 9, 12, 16, 20}
 * Output: 11
 * Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6,
 * 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11.
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>


class MinimizeHeight {
public:
    static int minHeight(std::vector<int> &arr, const int k) {
        if (arr.empty())
            return -1;

        std::sort(arr.begin(), arr.end());

        const int n = arr.size();
        int result = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] >= k) {
                const int maxHeight = std::max(arr[i - 1] + k, arr[n - 1] - k);
                const int minHeight = std::min(arr[i] - k, arr[0] + k);
                result = std::min(result, maxHeight - minHeight);
            }
        }

        return result;
    }


    static void runTestCases() {
        const std::vector<std::pair<std::vector<int>, int> > testCases = {
            {{1, 5, 8, 10}, 2},
            {{3, 9, 12, 16, 20}, 3},
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<int> arr = testCases[i].first;
            const int k = testCases[i].second;
            const int result = minHeight(arr, k);
            std::cout << "Test case " << i + 1 << ": Minimized height difference = " << result << std::endl;
        }
    }
};

int main() {
    MinimizeHeight::runTestCases();
    return 0;
}
