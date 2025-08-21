/**
 * <pre>
 * !Remove duplicate from sorted array.
 *
 * Given a sorted array arr[] of size n, the goal is to rearrange the array so
 * that all distinct elements appear at the beginning in sorted order
 * Additionally, return the length of this distinct sorted subarray.
 * Note: The elements after the distinct ones can be in any order and hold any
 * value, as they don’t affect the result.
 *
 * Examples:
 * Input: arr[] = [2, 2, 2, 2, 2]
 * Output: [2]
 * Explanation: All the elements are 2, So only keep one instance of 2.
 *
 * Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5]
 * Output: [1, 2, 3, 4, 5]
 *
 * Input: arr[] = [1, 2]
 * Output: [1, 2]
 * Explanation : No change as all elements are distinct.
 * </pre>
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class RemoveDuplicate {
public:
    /* Method 1: Remove duplicates manually (brute force) */
    static vector<int> removeDuplicate(const vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return arr;
        }

        vector<int> temp;
        for (int i = 0; i < arr.size(); i++) {
            bool isDuplicate = false;
            for (int j = 0; j < temp.size(); j++) {
                if (arr[i] == temp[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                temp.push_back(arr[i]);
            }
        }
        return temp;
    }

    /* Method 2: Remove duplicates from sorted array (two-pointer technique) */
    static int removeDuplicateArr(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j; // new length of array
    }

    /* Method 3: Using unordered_set (like HashSet in Java) */
    static vector<int> usingHashSet(const vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return arr;
        }

        unordered_set<int> set(arr.begin(), arr.end());
        vector<int> result(set.begin(), set.end());
        return result;
    }

    /* Method 4: Using vector (like ArrayList in Java) */
    static vector<int> removingUsingList(const vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return arr;
        }

        vector<int> list;
        for (int num: arr) {
            if (find(list.begin(), list.end(), num) == list.end()) {
                list.push_back(num);
            }
        }
        return list;
    }

    static int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int uniqueIndex = 0; /* Track the last unique element */

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = nums[i];
            }
        }

        return uniqueIndex + 1; /* length of array with unique elements */
    }
};

int main() {
    const vector<int> arr = {2, 2, 2, 2};
    const vector<int> arr1 = {1, 1, 2};
    vector<int> nums = {1, 1, 2};

    cout << "After removing duplicates (manual): ";
    const vector<int> result1 = RemoveDuplicate::removeDuplicate(arr);
    for (const int num: result1)
        cout << num << " ";
    cout << endl;

    cout << "Using HashSet: ";
    const vector<int> result2 = RemoveDuplicate::usingHashSet(arr1);
    for (const int num: result2)
        cout << num << " ";
    cout << endl;

    cout << "Using list: ";
    const vector<int> result3 = RemoveDuplicate::removingUsingList(arr1);
    for (const int num: result3)
        cout << num << " ";
    cout << endl;

    cout << "Sorted array (two-pointer method): ";
    const int newLen = RemoveDuplicate::removeDuplicateArr(nums);
    for (int i = 0; i < newLen; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
