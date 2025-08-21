/**
 * <pre>
 * !Rearrange element by sign
 * !Time complexity: O(n), Space complexity: O(n)
 * Given an array arr[] of size n, the task is to rearrange it in alternate
 * positive and negative manner without changing the relative order of positive
 * and negative numbers. In case of extra positive/negative numbers, they appear
 * at the end of the array.
 *
 * Note: The rearranged array should start with a positive number and 0 (zero)
 * should be considered as a positive number.
 *
 * Examples:
 *
 * Input: arr[] = {1, 2, 3, -4, -1, 4}
 * Output: arr[] = {1, -4, 2, -1, 3, 4}
 *
 *
 * Input: arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
 * Output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
 *
 * Approach: There is two solution for this Stack and List
 * Step1: Create two list one for non-negative and one for negative.
 * Step2: Merge the positive and Negative list alternatively.
 * Step3: Handle remaining Positive and Negative Number.
 * Step4: Convert list back into an array.
 * Step5: Return the array
 * </pre>
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> rearrangeElementBySign(const vector<int> &values) {
    if (values.size() < 2)
        return values;

    vector<int> positiveList, negativeList;

    for (int num: values) {
        if (num >= 0)
            positiveList.push_back(num);
        else
            negativeList.push_back(num);
    }

    vector<int> mergeList;
    size_t i = 0, j = 0;
    while (i < positiveList.size() && j < negativeList.size()) {
        mergeList.push_back(positiveList[i++]);
        mergeList.push_back(negativeList[j++]);
    }

    while (i < positiveList.size()) {
        mergeList.push_back(positiveList[i++]);
    }
    while (j < negativeList.size()) {
        mergeList.push_back(negativeList[j++]);
    }

    return mergeList;
}

vector<int> rearrangeUsingStack(vector<int> nums) {
    stack<int> posStack, negStack;

    /* push elements into stacks (reverse order like Java code) */
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] >= 0)
            posStack.push(nums[i]);
        else
            negStack.push(nums[i]);
    }

    int mergeIndex = 0;
    bool turnPos = true;
    while (!posStack.empty() && !negStack.empty()) {
        if (turnPos) {
            nums[mergeIndex++] = posStack.top();
            posStack.pop();
        } else {
            nums[mergeIndex++] = negStack.top();
            negStack.pop();
        }
        turnPos = !turnPos;
    }

    /* Append remaining elements */
    while (!posStack.empty()) {
        nums[mergeIndex++] = posStack.top();
        posStack.pop();
    }
    while (!negStack.empty()) {
        nums[mergeIndex++] = negStack.top();
        negStack.pop();
    }

    return nums;
}

int main() {
    const vector<int> arr1 = {1, 2, 3, -4, -1, 4};
    const vector<int> result1 = rearrangeElementBySign(arr1);
    cout << "Rearranged Array 1: ";
    for (const int num: result1)
        cout << num << " ";
    cout << endl;


    const vector<int> arr2 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    const vector<int> result2 = rearrangeUsingStack(arr2);
    cout << "Rearranged Array 2: ";
    for (const int num: result2)
        cout << num << " ";
    cout << endl;

    return 0;
}
