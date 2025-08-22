/*
Count Distinct Elements In Every Window of Size K

Given an array arr[] of size n and an integer k, return the count of distinct numbers in all windows of size k.

Example:
Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output: [3, 4, 4, 3]

Approach: Sliding Window Technique - O(n) Time and O(k) Space
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* Brute-force approach: O(n*k) */
vector<int> countDistinctBruteForce(const vector<int> &nums, int k) {
    vector<int> result;
    for (size_t i = 0; i <= nums.size() - k; ++i) {
        unordered_set<int> seen;
        for (size_t j = i; j < i + k; ++j) {
            seen.insert(nums[j]);
        }
        result.push_back(seen.size());
    }
    return result;
}

/* Optimized sliding window approach: O(n) */
vector<int> countDistinctSlidingWindow(const vector<int> &nums, int k) {
    vector<int> result;
    unordered_map<int, int> freq;

    /* Count frequency of elements in the first window */
    for (int i = 0; i < k; ++i) freq[nums[i]]++;

    result.push_back(freq.size());

    for (int i = k; i < nums.size(); ++i) {
        /* Remove the element going out of the window */
        freq[nums[i - k]]--;
        if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);

        /* Add the new element coming into the window */
        freq[nums[i]]++;

        result.push_back(freq.size());
    }
    return result;
}


int main() {
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> result1 = countDistinctBruteForce(nums, k);
    cout << "Brute-force result: ";
    for (int val: result1) cout << val << " ";
    cout << endl;

    vector<int> result2 = countDistinctSlidingWindow(nums, k);
    cout << "Sliding window result: ";
    for (int val: result2) cout << val << " ";
    cout << endl;

    return 0;
}
