/**
 * <pre>
 * !Sort an array after applying the given equation
 * Given an integer array arr[] sorted in ascending order, along with three integers: A, B, and C.
 * The task is to transform each element x in the array using the quadratic function A*(x^2) + B*x + C.
 * After applying this transformation to every element, return the modified array in sorted order.
 *
 * @param Examples:
 * Input: arr[] = [-4, -2, 0, 2, 4], A = 1, B = 3, C = 5
 * Output: [3, 5, 9, 15, 33]
 * Explanation: After applying f(x) = 1 * x2 + 3 * x + 5 to each x, we get [9, 3, 5, 15, 33].
 * After sorting this array, the array becomes [3, 5, 9, 15, 33].
 *
 * Input: arr[] = [-3, -1, 2, 4], A = -1, B = 0, C = 0
 * Output: [-16, -9, -4, -1]
 * Explanation: After applying f(x) = -1*x2 to each x, we get [-9, -1, -4, -16 ].
 * After sorting this array, the array becomes  [-16, -9, -4, -1].
 *
 * Input: arr[] = [-1, 0, 1, 2, 3, 4], A = -1, B = 2, C = -1
 * Output: [-9, -4, -4, -1, -1, 0]
 *
 * !Approach: Apply the Equation and Sort – O(n*log(n)) Time and O(1) Space
 * The idea is to directly transform each element in the array, i.e. for each element x in arr[],
 * apply the given equation A*x2 + B*x + C in-place and then simply sort the array in ascending order.
 * </pre>
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TransformAndSortArr {
public:
    /* Evaluate quadratic function */
    static int evaluate(const int x, const int A, const int B, const int C) {
        return A * x * x + B * x + C;
    }

    /* Transform and sort array */
    static vector<int> sortArr(const vector<int> &arr, const int A, const int B, const int C) {
        vector<int> transformed;
        transformed.reserve(arr.size());
        for (const int x: arr) {
            transformed.push_back(evaluate(x, A, B, C));
        }

        sort(transformed.begin(), transformed.end());
        return transformed;
    }
};

int main() {
    const vector<int> arr1 = {-4, -2, 0, 2, 4};
    const vector<int> result1 = TransformAndSortArr::sortArr(arr1, 1, 3, 5);
    cout << "Expected : [3, 5, 9, 15, 33] == [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i != result1.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    const vector<int> arr2 = {-3, -1, 2, 4};
    const vector<int> result2 = TransformAndSortArr::sortArr(arr2, -1, 0, 0);
    cout << "Expected : [-16, -9, -4, -1] == [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i != result2.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
