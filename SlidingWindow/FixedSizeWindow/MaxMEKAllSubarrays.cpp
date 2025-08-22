/*
Maximum MEX (Minimum Excluded Value) from all subarrays of length K

Given an array arr[] consisting of N distinct integers and an integer K,
find the maximum MEX from all subarrays of length K.

Example:
Input: arr[] = {3, 2, 1, 4}, K = 2
Output: 3
Explanation:
All subarrays of length 2: {3,2}, {2,1}, {1,4}
MEX of {3,2} = 1
MEX of {2,1} = 3
MEX of {1,4} = 2
Maximum MEX = 3
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


int computeMEX(const unordered_set<int> &seen) {
    int mex = 1;
    while (seen.count(mex)) mex++;
    return mex;
}

/* Function to find maximum MEX from all subarrays of size K */
int MaxMEXSubarray(const vector<int> &nums, int K) {
    if (nums.empty() || K <= 0 || K > nums.size()) return 0;

    unordered_set<int> seen;
    int max_mex = 0;

    /* Initialize first window */
    for (int i = 0; i < K; i++) {
        seen.insert(nums[i]);
    }

    max_mex = max(max_mex, computeMEX(seen));

    /* Slide the window */
    for (int i = K; i < nums.size(); i++) {
        seen.erase(nums[i - K]); /* Remove leftmost element */
        seen.insert(nums[i]); /* Add new element */
        max_mex = max(max_mex, computeMEX(seen));
    }

    return max_mex;
}


int main() {
    vector<int> nums1 = {3, 1, 2, 4};
    int k1 = 2;
    cout << "Maximum MEX for first array: " << MaxMEXSubarray(nums1, k1) << endl;

    vector<int> nums2 = {6, 1, 3, 2, 4};
    int k2 = 3;
    cout << "Maximum MEX for second array: " << MaxMEXSubarray(nums2, k2) << endl;

    return 0;
}
