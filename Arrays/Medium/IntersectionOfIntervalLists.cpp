/**
 * <pre>
 * !Intersection of intervals given by two lists
 * Given two 2-D arrays which represent intervals.
 * Each 2-D array represents a list of intervals.
 * Each list of intervals is disjoint and sorted in increasing order.
 * Find the intersection or set of ranges that are common to both the lists.
 *
 * @param Note: Disjoint means no element is common in a list
 *
 * @param Examples:
 * Input   arr1[][] = {{0, 4}, {5, 10}, {13, 20}, {24, 25}}   arr2[][] = {{1, 5}, {8, 12}, {15, 24}, {25, 26}}
 * Output  {{1, 4}, {5, 5}, {8, 10}, {15, 20}, {24, 24}, {25, 25}}
 * Explanation  {1, 4} is the overlap of {0, 4} and {1, 5}. Similarly, {24, 24} is the overlap of {24, 25} and {15, 24}.
 *
 * Input  arr1[][] = {{0, 2}, {5, 10}, {12, 22}, {24, 25}}  arr2[][] = {{1, 4}, {9, 12}, {15, 24}, {25, 26}}
 * Output  {{1, 2}, {9, 10}, {12, 12}, {15, 22}, {24, 24}, {25, 25}}
 * Explanation  {1, 2} is the overlap of {0, 2} and {1, 4}. Similarly, {12, 12} is the overlap of {12, 22} and {9, 12}.
 *
 * !Approach: Using Two Pointer  – O(m + n) Time and O(1) Space
 * We use two-pointer to solve by following these steps:
 * Use two pointers, i and j, to traverse arr1 and arr2. For each pair, find the overlap:
 * l = max⁡(arr1[i][0],arr2[j][0]),
 * r = min⁡(arr1[i][1],arr2[j][1])
 * If l ≤ r, add [l, r] to the result. Move the pointer with the smaller endpoint to continue.
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void intersectionOfIntervals(const vector<vector<int> > &A, const vector<vector<int> > &B) {
    int i = 0, j = 0;
    const int m = A.size();
    const int n = B.size();

    while (i < m && j < n) {
        const int lMax = max(A[i][0], B[j][0]);
        const int rMin = min(A[i][1], B[j][1]);

        if (lMax <= rMin) {
            cout << "[" << lMax << ", " << rMin << "] ";
        }

        /* Move the pointer with the smaller endpoint */
        if (A[i][1] < B[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;
}

int main() {
    const vector<vector<int> > arr1 = {{0, 4}, {5, 10}, {13, 20}, {24, 25}};
    const vector<vector<int> > arr2 = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    intersectionOfIntervals(arr1, arr2);

    return 0;
}
