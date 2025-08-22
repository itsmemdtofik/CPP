/*
Sum of all subarrays of size K

Given an array arr[] and an integer K, calculate the sum of all subarrays of size K.

Example:
Input: arr = {1, 2, 3, 4, 5, 6}, K = 3
Output: 6 9 12 15
Explanation:
Subarray sums:
{1,2,3} = 6
{2,3,4} = 9
{3,4,5} = 12
{4,5,6} = 15
*/

#include <iostream>
#include <vector>
using namespace std;

/* Naive approach: O(n*k) */
vector<int> sumOfAllSubarray(vector<int> &nums, int k) {
    vector<int> result;

    for (int i = 0; i <= nums.size() - k; i++) {
        int currentSum = 0;
        for (int j = i; j < i + k; j++)
            currentSum += nums[j];
        result.push_back(currentSum);
    }

    return result;
}

/* Sliding window approach: O(n) */
vector<int> slidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    if (nums.empty() || k <= 0 || k > nums.size()) return result;

    int currentSum = 0;
    for (int i = 0; i < k; i++)
        currentSum += nums[i];
    result.push_back(currentSum);

    for (int i = k; i < nums.size(); i++) {
        currentSum = currentSum - nums[i - k] + nums[i];
        result.push_back(currentSum);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;

    vector<int> result = sumOfAllSubarray(nums, k);
    cout << "Sum of all subarrays of size k are: ";
    for (int x: result) cout << x << " ";
    cout << endl;

    vector<int> result1 = slidingWindow(nums, k);
    cout << "Sum of all subarrays of size k using sliding window are: ";
    for (int x: result1) cout << x << " ";
    cout << endl;

    return 0;
}
