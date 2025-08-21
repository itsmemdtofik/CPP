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
using namespace std;

class MinSwapsToGroupAllOnesII {
public:
    /**
     * Minimum Swaps required to group all 1's together
     * Count total number of 1's, then find a subarray of length x with maximum 1s.
     * Minimum swaps = x - maxOnesInWindow
     */
    static int minimumSwaps(const vector<int> &arr) {
        int totalOnes = 0;
        for (const int num: arr) {
            if (num == 1)
                totalOnes++;
        }

        if (totalOnes == 0)
            return -1;

        const int windowSize = totalOnes;
        int maxOnesInWindow = 0;
        int currentOnes = 0;

        /* Initialize the first window */
        for (int i = 0; i < windowSize; i++) {
            if (arr[i] == 1)
                currentOnes++;
        }
        maxOnesInWindow = currentOnes;

        /* Slide the window through the array */
        for (int i = windowSize; i < arr.size(); i++) {
            if (arr[i - windowSize] == 1)
                currentOnes--;
            if (arr[i] == 1)
                currentOnes++;
            if (currentOnes > maxOnesInWindow)
                maxOnesInWindow = currentOnes;
        }

        return windowSize - maxOnesInWindow;
    }
};

int main() {
    cout << "Expected: 1 == "
            << MinSwapsToGroupAllOnesII::minimumSwaps({1, 0, 1, 0, 1})
            << endl;

    cout << "Expected: 2 == "
            << MinSwapsToGroupAllOnesII::minimumSwaps({1, 1, 0, 1, 0, 1, 1})
            << endl;

    cout << "Expected: -1 == "
            << MinSwapsToGroupAllOnesII::minimumSwaps({0, 0, 0})
            << endl;

    return 0;
}
