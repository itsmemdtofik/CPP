#include <iostream>
#include <vector>
using namespace std;

/*
Subarray with Given Sum

Given a 1-based indexing array arr[] of non-negative integers and an integer sum.
Return the left and right indexes (1-based) of that subarray.

Example:
Input: arr[] = [15, 2, 4, 8, 9, 5, 10, 23], target = 23
Output: [2, 5]  (Subarray: 2 + 4 + 8 + 9 = 23)
*/

/* 1️⃣ Brute-force O(n^2) */
pair<int, int> subarrayWithGivenSum_BruteForce(const vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        int current_sum = 0;
        for (int j = i; j < nums.size(); j++) {
            current_sum += nums[j];
            if (current_sum == target) {
                return {i + 1, j + 1}; /* 1-based indexing */
            }
        }
    }
    return {-1, -1};
}

/* 2️⃣ Sliding Window O(n) (works because all elements are non-negative) */
pair<int, int> subarrayWithGivenSum_SlidingWindow(const vector<int> &nums, int target) {
    int left = 0, current_sum = 0;

    for (int right = 0; right < nums.size(); right++) {
        current_sum += nums[right];

        while (current_sum > target && left < right) {
            current_sum -= nums[left];
            left++;
        }

        if (current_sum == target) {
            return {left + 1, right + 1}; /* 1-based indexing */
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;

    cout << "Using Brute-force O(n^2): ";
    auto res1 = subarrayWithGivenSum_BruteForce(arr, target);
    cout << res1.first << " " << res1.second << endl;

    cout << "Using Sliding Window O(n): ";
    auto res2 = subarrayWithGivenSum_SlidingWindow(arr, target);
    cout << res2.first << " " << res2.second << endl;

    return 0;
}
