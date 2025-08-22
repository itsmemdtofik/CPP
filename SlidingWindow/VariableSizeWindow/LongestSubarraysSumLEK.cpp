/*
Maximum Subarray Size Having All Subarrays Sum ≤ K

Given an array of positive integers arr[] of size n and an integer K.
Find the maximum subarray size such that all subarrays of that size
have sum less than or equal to K.

Examples:
Input: arr[] = [1, 2, 3, 4], K = 8
Output: 2

Input: arr[] = [1, 2, 10, 4], K = 8
Output: -1
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/* 1️⃣ Brute-force approach: O(n^2) */
int maxSubarraySize_AllSumsLEK_BruteForce(vector<int> &nums, int K) {
    for (int num: nums) {
        /* Check if any element > K */
        if (num > K)
            return -1;
    }

    int n = nums.size();

    /* Try all window sizes from n down to 1 */
    for (int size = n; size >= 1; size--) {
        bool isValid = true;

        /* Compute sum of first window */
        int windowSum = accumulate(nums.begin(), nums.begin() + size, 0);
        if (windowSum > K)
            isValid = false;

        /* Slide window */
        for (int j = size; j < n && isValid; j++) {
            windowSum = windowSum + nums[j] - nums[j - size];
            if (windowSum > K)
                isValid = false;
        }

        if (isValid)
            return size;
    }

    return -1;
}

/* 2️⃣ Another brute-force sliding window approach: O(n^2) */
int maxSubarraySize_AllSumsLEK_SlidingWindow(vector<int> &nums, int K) {
    int n = nums.size();

    if (*max_element(nums.begin(), nums.end()) >= K)
        return -1;

    for (int size = n; size >= 1; size--) {
        bool isValid = true;
        int windowSum = accumulate(nums.begin(), nums.begin() + size, 0);
        if (windowSum >= K)
            isValid = false;

        for (int j = size; j < n && isValid; j++) {
            windowSum = windowSum + nums[j] - nums[j - size];
            if (windowSum >= K)
                isValid = false;
        }

        if (isValid)
            return size;
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int K = 8;
    int result = maxSubarraySize_AllSumsLEK_BruteForce(nums, K);
    cout << "Maximum subarray size (Brute-force) <= " << K << " is: " << result << endl;

    vector<int> nums1 = {1, 2, 10, 4};
    int K1 = 14;
    int result1 = maxSubarraySize_AllSumsLEK_SlidingWindow(nums1, K1);
    cout << "Maximum subarray size (Sliding window) <= " << K1 << " is: " << result1 << endl;

    return 0;
}
