/*
Minimum Sum Subarray

Given an array of integers nums and an integer k, find the minimum sum of any contiguous subarray of size k.

Example:
Input: nums = [3, 8, 2, 5, 7, 6, 12], k = 4
Output: 12
Explanation: Subarray [2, 5, 7, 6] has the minimum sum of 20.

Approach: Sliding Window
Time Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

/* Naive / unsafe sliding window (uses i + k - 1 indexing) */
int minimumSum(vector<int> &nums, int k) {
    if (nums.empty() || k <= 0 || k > nums.size()) return 0;

    int currentSum = 0;
    for (int i = 0; i < k; i++) currentSum += nums[i];

    int minSum = currentSum;

    for (int i = 1; i <= nums.size() - k; i++) {
        currentSum = currentSum - nums[i - 1] + nums[i + k - 1];
        minSum = min(minSum, currentSum);
    }

    return minSum;
}

/* Optimized Safe sliding window */
int slidingWindow(vector<int> &nums, int k) {
    if (nums.empty() || k <= 0 || k > nums.size()) return 0;

    int currentSum = 0;
    for (int i = 0; i < k; i++) currentSum += nums[i];

    int minSum = currentSum;

    for (int i = k; i < nums.size(); i++) {
        currentSum = currentSum - nums[i - k] + nums[i];
        minSum = min(minSum, currentSum);
    }

    return minSum;
}

int main() {
    vector<int> nums = {3, 8, 2, 5, 7, 6, 12};
    int k = 4;

    int result = minimumSum(nums, k);
    cout << "Minimum sum of subarray of size " << k << " is: " << result << endl;

    int result1 = slidingWindow(nums, k);
    cout << "Minimum sum of subarray of size " << k << " using sliding window is: " << result1 << endl;

    return 0;
}
