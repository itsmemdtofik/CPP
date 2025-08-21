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

class IntersectionOfIntervalLists {
public:
    static vector<vector<int> > computeIntersection(const vector<vector<int> > &A, const vector<vector<int> > &B) {
        vector<vector<int> > result;
        int i = 0, j = 0;
        const int m = A.size();
        const int n = B.size();

        while (i < m && j < n) {
            int lMax = max(A[i][0], B[j][0]);
            int rMin = min(A[i][1], B[j][1]);

            if (lMax <= rMin) {
                result.push_back({lMax, rMin});
            }

            if (A[i][1] < B[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }

    /* Utility function to print intervals */
    static void printIntervals(const vector<vector<int> > &intervals) {
        for (const auto &interval: intervals) {
            cout << "[" << interval[0] << ", " << interval[1] << "] ";
        }
        cout << endl;
    }
};

int main() {
    const vector<vector<int> > arr1 = {{0, 4}, {5, 10}, {13, 20}, {24, 25}};
    const vector<vector<int> > arr2 = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    const vector<vector<int> > intersections = IntersectionOfIntervalLists::computeIntersection(arr1, arr2);

    cout << "Intersection of intervals: ";
    IntersectionOfIntervalLists::printIntervals(intersections);

    return 0;
}
