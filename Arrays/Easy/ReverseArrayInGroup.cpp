/**
 * <pre>
 * !Reverse an Array in groups of given size.
 * Given an array arr[] and an integer K, the task is to reverse every
 * subarray formed by consecutive K elements.
 * Examples:
 * Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9], K = 3
 * Output: 3, 2, 1, 6, 5, 4, 9, 8, 7
 *
 * Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], K = 5
 * Output: 5, 4, 3, 2, 1, 8, 7, 6
 *
 * Input: arr[] = [1, 2, 3, 4, 5, 6], K = 1
 * Output: 1, 2, 3, 4, 5, 6
 *
 * Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], K = 10
 * Output: 8, 7, 6, 5, 4, 3, 2, 1
 * </pre>
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> reverseArrayInGroupUsingTwoPointer(vector<int> &arr, int K) {
    if (arr.empty() || arr.size() < 3) {
        return arr;
    }

    for (int start = 0; start < arr.size(); start += K) {
        int left = start;
        int right = min(start + K - 1, static_cast<int>(arr.size()) - 1);

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    return arr;
}


vector<int> reverseArrInGroupUsingStack(vector<int> &arr, int K) {
    if (arr.empty() || arr.size() < 3) {
        return arr;
    }

    for (int start = 0; start < arr.size(); start += K) {
        stack<int> st;

        /* push group into stack */
        for (int end = start; end < start + K && end < arr.size(); end++) {
            st.push(arr[end]);
        }

        /* pop back reversed */
        int idx = start;
        while (!st.empty()) {
            arr[idx++] = st.top();
            st.pop();
        }
    }

    return arr;
}

int main() {
    int K = 3;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};


    const vector<int> result = reverseArrayInGroupUsingTwoPointer(arr, K);
    const vector<int> result1 = reverseArrInGroupUsingStack(arr, K);

    for (const int x: result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
