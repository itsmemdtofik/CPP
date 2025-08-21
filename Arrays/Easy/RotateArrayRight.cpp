/**
 * <pre>
 * !Rotate array by D positions to the right (clockwise).
 *
 * Given an array of integers arr[] of size n, the task is to rotate the array
 * elements to the right by d positions.
 *
 * Examples:
 *
 * Input: arr[] = {1, 2, 3, 4, 5, 6}, d = 2
 * Output: {5, 6, 1, 2, 3, 4}
 * Explanation:
 * After first right rotation:  {6, 1, 2, 3, 4, 5}
 * After second right rotation: {5, 6, 1, 2, 3, 4}
 *
 * Input: arr[] = {1, 2, 3}, d = 4
 * Output: {3, 1, 2}
 * Explanation:
 * After one right rotation:   {3, 1, 2}
 * After two right rotations:  {2, 3, 1}
 * After three right rotations:{1, 2, 3}
 * After four right rotations: {3, 1, 2}
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

/* Function to rotate array right by D positions */
vector<int> rotateArrayByDPosition(vector<int> &arr, int D) {
    if (arr.size() < 1) {
        return arr;
    }

    D = D % arr.size(); /* Handle if D >= size */

    /* Step 1: Reverse whole array */
    reverse(arr, 0, arr.size() - 1);

    /* Step 2: Reverse first D elements */
    reverse(arr, 0, D - 1);

    /* Step 3: Reverse remaining elements */
    reverse(arr, D, arr.size() - 1);

    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    constexpr int d = 2;

    const vector<int> rotated = rotateArrayByDPosition(arr, d);

    for (const int x: rotated) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
