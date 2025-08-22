/*
Minimum Sum Subarray

Given an array of integers nums and an integer k, find the minimum sum of any contiguous subarray of size k.

Example:
Input: nums = [3, 8, 2, 5, 7, 6, 12], k = 4
Output: 18
Explanation: Subarray [3, 8, 2, 5] has the minimum sum of 18.

Approach: Sliding Window
Time Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

/* Naive sliding window (not fully optimized) */
int minimumSum(vector<int> &nums, int k) {
    if (nums.empty() || k <= 0 || k > nums.size()) return 0;

    int left = 0, right = 0;
    int currentSum = 0;
    int minimum = INT_MAX;

    while (right < nums.size()) {
        currentSum += nums[right];
        int window = right - left + 1;

        if (window < k) {
            right++;
        } else if (window == k) {
            minimum = min(minimum, currentSum);
            currentSum -= nums[left];
            left++;
            right++;
        }
    }

    return minimum;
}

/* Optimized sliding window */
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
