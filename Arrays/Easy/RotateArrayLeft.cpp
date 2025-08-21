/**
 * <pre>
 * !Rotate array by D positions to the left (counter-clockwise).
 *
 * Given an array of integers arr[] of size n, the task is to rotate the array
 * elements to the left by d positions.
 *
 * Examples:
 *
 * Input: arr[] = {1, 2, 3, 4, 5, 6}, d = 2
 * Output: {3, 4, 5, 6, 1, 2}
 * Explanation:
 * After first left rotation, arr[] becomes {2, 3, 4, 5, 6, 1}
 * After the second rotation, arr[] becomes {3, 4, 5, 6, 1, 2}
 *
 * Input: arr[] = {1, 2, 3}, d = 4
 * Output: {2, 3, 1}
 * Explanation:
 * After first left rotation, arr[] = {2, 3, 1}
 * After second left rotation, arr[] = {3, 1, 2}
 * After third left rotation, arr[] = {1, 2, 3}
 * After fourth left rotation, arr[] = {2, 3, 1}
 * </pre>
 */
#include <iostream>
#include <vector>
using namespace std;

/* Helper function to reverse elements in range [left, right] */
void reverse(vector<int> &arr, int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

/* Function to rotate array left by D positions */
vector<int> rotateArrayByDPosition(vector<int> &arr, int D) {
    if (arr.size() < 1) {
        return arr;
    }

    D = D % arr.size(); /* handle if D >= size */

    /* Step 1: Reverse first D elements */
    reverse(arr, 0, D - 1);

    /* Step 2: Reverse remaining elements */
    reverse(arr, D, arr.size() - 1);

    /* Step 3: Reverse whole array */
    reverse(arr, 0, arr.size() - 1);

    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int d = 2;

    const vector<int> rotated = rotateArrayByDPosition(arr, d);

    for (const int x: rotated) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
