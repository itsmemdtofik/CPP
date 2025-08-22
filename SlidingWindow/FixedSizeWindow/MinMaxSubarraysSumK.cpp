/*
Sum of minimum and maximum elements of all subarrays of size k

Given an array of both positive and negative integers,
compute sum of minimum and maximum elements of all subarrays of size k.

Example:
Input: arr[] = {2, 5, -1, 7, -3, -1, -2}, K = 4
Output: 18
Explanation:
Subarrays of size 4:
{2,5,-1,7}   min+max = -1+7=6
{5,-1,7,-3}  min+max = -3+7=4
{-1,7,-3,-1} min+max = -3+7=4
{7,-3,-1,-2} min+max = -3+7=4
Sum = 6+4+4+4 = 18
Approach: Sliding Window + Deque
Time Complexity: O(n), Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
using namespace std;

int sumOfKSubArray(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0 || k <= 0 || k > n) return 0;

    deque<int> queueMin, queueMax;
    int totalSum = 0;

    /* Initialize first window */
    for (int i = 0; i < k; i++) {
        while (!queueMin.empty() && nums[queueMin.back()] >= nums[i]) queueMin.pop_back();
        while (!queueMax.empty() && nums[queueMax.back()] <= nums[i]) queueMax.pop_back();
        queueMin.push_back(i);
        queueMax.push_back(i);
    }

    for (int i = k; i < n; i++) {
        /* Add min + max of current window */
        totalSum += nums[queueMin.front()] + nums[queueMax.front()];

        /* Remove indices out of current window */
        while (!queueMin.empty() && queueMin.front() <= i - k) queueMin.pop_front();
        while (!queueMax.empty() && queueMax.front() <= i - k) queueMax.pop_front();

        /* Maintain min deque */
        while (!queueMin.empty() && nums[queueMin.back()] >= nums[i]) queueMin.pop_back();
        /* Maintain max deque */
        while (!queueMax.empty() && nums[queueMax.back()] <= nums[i]) queueMax.pop_back();

        queueMin.push_back(i);
        queueMax.push_back(i);
    }

    /* Add min + max for the last window */
    totalSum += nums[queueMin.front()] + nums[queueMax.front()];

    return totalSum;
}


int main() {
    vector<int> nums = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    int result = sumOfKSubArray(nums, k);
    cout << "Sum of minimum and maximum elements of all subarrays of size " << k << " is: " << result << endl;

    return 0;
}
