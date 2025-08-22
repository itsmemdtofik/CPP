/*
First Negative Integer in every window of size k

Given an array and a positive integer k, find the first negative integer for
each window (contiguous subarray) of size k. If a window does not contain a
negative integer, then print 0 for that window.

Example:
Input: arr[] = [-8, 2, 3, -6, 1], k = 2
Output: [-8, 0, -6, -6]

Explanation:
Window [-8, 2] -> -8
Window [2, 3] -> 0
Window [3, -6] -> -6
Window [-6, 1] -> -6
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/* Brute-force approach: O(n*k) */
vector<int> firstNegativeBruteForce(const vector<int> &nums, int k) {
    vector<int> result;
    for (size_t i = 0; i <= nums.size() - k; ++i) {
        bool found = false;
        for (size_t j = i; j < i + k; ++j) {
            if (nums[j] < 0) {
                result.push_back(nums[j]);
                found = true;
                break;
            }
        }
        if (!found) result.push_back(0);
    }
    return result;
}

/* Optimized sliding window approach using deque: O(n) */
vector<int> firstNegativeSlidingWindow(const vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq; /* stores indices of negative numbers */

    for (size_t i = 0; i < nums.size(); ++i) {
        /* Remove indices out of the current window */
        while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();

        /* If current number is negative, store its index */
        if (nums[i] < 0) dq.push_back(i);

        /* When the window is fully formed */
        if (i >= k - 1) {
            if (!dq.empty()) result.push_back(nums[dq.front()]); /* first negative */
            else result.push_back(0); /* no negative */
        }
    }
    return result;
}


int main() {
    vector<int> nums = {-8, 2, 3, -6, 1};
    int k = 2;

    vector<int> result1 = firstNegativeBruteForce(nums, k);
    cout << "Brute-force result: ";
    for (int val: result1) cout << val << " ";
    cout << endl;

    vector<int> nums2 = {12, -1, -7, 8, -15, 30, 16, 28};
    int k2 = 3;
    vector<int> result2 = firstNegativeSlidingWindow(nums2, k2);

    cout << "Sliding window result: ";
    for (int val: result2) cout << val << " ";
    cout << endl;

    return 0;
}
