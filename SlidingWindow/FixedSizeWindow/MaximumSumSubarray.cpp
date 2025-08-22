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
#include <algorithm>
using namespace std;

/* Sliding window approach */
int maxSumSubarray(const vector<int> &nums, int k) {
    if (nums.empty() || k <= 0 || k > nums.size()) return 0;

    int currentSum = 0;
    for (int i = 0; i < k; ++i) currentSum += nums[i];

    int maxSum = currentSum;

    for (int i = k; i < nums.size(); ++i) {
        currentSum = currentSum - nums[i - k] + nums[i];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

/* Brute-force (optional, O(n*k)) */
int maxSumSubarrayBruteForce(const vector<int> &nums, int k) {
    if (nums.empty() || k <= 0 || k > nums.size()) return 0;

    int maxSum = INT_MIN;
    for (int i = 0; i <= nums.size() - k; ++i) {
        int sum = 0;
        for (int j = i; j < i + k; ++j) sum += nums[j];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}


int main() {
    vector<int> nums = {3, 8, 2, 5, 7, 6, 12};
    int k = 4;

    int result1 = maxSumSubarray(nums, k);
    cout << "Maximum sum of subarray of size " << k << " (Sliding Window): " << result1 << endl;

    int result2 = maxSumSubarrayBruteForce(nums, k);
    cout << "Maximum sum of subarray of size " << k << " (Brute Force): " << result2 << endl;

    return 0;
}
