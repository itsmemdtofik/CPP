/**
 * <pre>
 * !Minimum Swaps required to group all 1's together
 * Given an array of 0's and 1's, we need to write a program to
 * find the minimum number of swaps required to group all 1's present in the array together.
 *
 * @param Examples:
 * Input: arr[] = [1, 0, 1, 0, 1]
 * Output: 1
 * Explanation: Only 1 swap is required to group all 1's together. Swapping index 1 with 4 will
 * give arr[] = [1, 1, 1, 0, 0]
 *
 * Input: arr[] = [1, 1, 0, 1, 0, 1, 1]
 * Output: 2
 * Explanation: Only 2 swap is required to group all 1's together. Swapping index 0 with 2 and
 * 1 with 4 will  give arr[] = [0, 0, 1, 1, 1, 1, 1]
 *
 * Input: arr[] = [0, 0, 0]
 * Output: -1
 * Explanation: No 1s are present in the array, so return -1.
 *
 * !Approach: Using Nested loops - O(n^2) Time and O(n) Space
 * A simple solution is to first count total number of 1’s  in the array.
 * Suppose this count is x, now we need to find the subarray of length x with maximum number of 1’s.
 * And minimum swaps required will be the number of 0’s in this subarray of length x.
 * </pre>
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumMovesToEqualizeArrII {
public:
    /**
     * Minimum number of increment-other operations to make all array elements equal.
     * Optimized approach: total sum minus n * the smallest element
     */
    static int minimumMovesToEqualize(const vector<int> &arr) {
        const int n = arr.size();
        int sum = 0;


        const int minValue = *min_element(arr.begin(), arr.end());


        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        return (sum - (n * minValue));
    }
};

int main() {
    cout << "Expected: 3 == "
            << MinimumMovesToEqualizeArrII::minimumMovesToEqualize({1, 2, 3})
            << endl;

    cout << "Expected: 2 == "
            << MinimumMovesToEqualizeArrII::minimumMovesToEqualize({4, 3, 4})
            << endl;

    return 0;
}
