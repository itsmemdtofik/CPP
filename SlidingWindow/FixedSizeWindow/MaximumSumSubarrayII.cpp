/*
Maximum Sum Subarray

Given an array of integers nums and an integer k, find the maximum sum of any contiguous subarray of size k.

Example:
Input: nums = [2, 1, 5, 1, 3, 2], k = 3
Output: 9
Explanation: Subarray [5, 1, 3] has the maximum sum of 9.

Approach: Sliding Window - O(n) Time, O(1) Space
*/

#include <iostream>
#include <vector>
using namespace std;

/* Sliding window using left and right pointers (general approach) */
int maximumSum(vector<int> &nums, int K) {
    if (nums.empty() || K <= 0 || K > nums.size()) return 0;

    int left = 0, right = 0;
    int currentSum = 0;
    int maxSum = INT_MIN;

    while (right < nums.size()) {
        currentSum += nums[right];
        int window = (right - left) + 1;

        if (window < K) {
            right++;
        } else if (window == K) {
            maxSum = max(maxSum, currentSum);
            currentSum -= nums[left];
            left++;
            right++;
        }
    }

    return maxSum;
}

/* Sliding window using subtraction (i - window) for safe subtraction */
int slidingWindow(vector<int> &nums, int window) {
    if (nums.empty() || window <= 0 || window > nums.size()) return 0;

    int currentSum = 0;
    for (int i = 0; i < window; ++i) currentSum += nums[i];

    int maxSum = currentSum;

    for (int i = window; i < nums.size(); ++i) {
        currentSum = currentSum - nums[i - window] + nums[i];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}


int main() {
    vector<int> nums = {3, 8, 2, 5, 7, 6, 12};
    int k = 4;

    int result1 = maximumSum(nums, k);
    cout << "Maximum sum of subarray of size " << k << " (left-right sliding window): " << result1 << endl;

    int result2 = slidingWindow(nums, k);
    cout << "Maximum sum of subarray of size " << k << " (i-window subtraction sliding window): " << result2 << endl;

    return 0;
}
