/*
Longest Subarray With Sum K

Given an array arr[] of size n containing integers, find the length of the longest subarray having sum equal to K.

Examples:
Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: [10,5,2,7,1,-10] has sum 15, length 6.

Approaches:
1. Brute-force: O(n^2)
2. Sliding window: O(n), only for non-negative integers
3. Prefix Sum + Hashing: O(n), works for all integers including negatives
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 1️⃣ Brute-force approach: O(n^2) */
int longestSubarraySumK_BruteForce(vector<int> &nums, int K) {
    int result = 0;
    for (int left = 0; left < nums.size(); left++) {
        int currentSum = 0;
        for (int right = left; right < nums.size(); right++) {
            currentSum += nums[right];
            if (currentSum == K) {
                result = max(result, right - left + 1);
            }
        }
    }
    return result;
}

/* 2️⃣ Sliding window approach (for non-negative integers only): O(n) */
int longestSubarraySumK_SlidingWindow(vector<int> &nums, int K) {
    int left = 0, currentSum = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        currentSum += nums[right];
        while (currentSum > K && left <= right) {
            currentSum -= nums[left];
            left++;
        }
        if (currentSum == K) {
            maxLen = max(maxLen, right - left + 1);
        }
    }
    return maxLen;
}

/* 3️⃣ Prefix sum + Hashing approach (works for all integers): O(n) */
int longestSubarraySumK_PrefixHashing(vector<int> &nums, int K) {
    unordered_map<int, int> prefixMap; /* prefix_sum -> first index */
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        if (prefixSum == K)
            maxLen = i + 1;

        if (prefixMap.find(prefixSum - K) != prefixMap.end())
            maxLen = max(maxLen, i - prefixMap[prefixSum - K]);

        if (prefixMap.find(prefixSum) == prefixMap.end())
            prefixMap[prefixSum] = i; // store first occurrence
    }

    return maxLen;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, -10};
    int k = 15;

    int len1 = longestSubarraySumK_BruteForce(nums, k);
    cout << "Longest Subarray with sum K (Brute Force): " << len1 << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 9;
    int len2 = longestSubarraySumK_SlidingWindow(nums2, k2);
    cout << "Longest Subarray with sum K (Sliding Window, Non-negative): " << len2 << endl;

    int len3 = longestSubarraySumK_PrefixHashing(nums, k);
    cout << "Longest Subarray with sum K (Prefix Sum + Hashing): " << len3 << endl;

    return 0;
}
