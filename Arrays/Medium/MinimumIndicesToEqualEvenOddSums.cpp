/**
 * <pre>
 * !Ways to make sum of odd and even indexed elements equal by removing an array element
 * Given an array, arr[] of size n, the task is to find the count of array indices
 * such that removing an element from these indices makes the sum of even-indexed
 * and odd-indexed array elements equal.
 *
 * @param Examples:
 * Input: arr[] = [ 2, 1, 6, 4 ]
 * Output: 1
 * Explanation: Removing arr[1] from the array modifies arr[] to [ 2, 6, 4 ] such that, arr[0] + arr[2] = arr[1].
 * Therefore, the required output is 1.
 *
 * Input: arr[] = [ 1, 1, 1 ]
 * Output: 3
 * Explanation: Removing arr[0] from the given array modifies arr[] to [ 1, 1 ] such that arr[1] = arr[2]
 * Removing arr[1] from the given array modifies arr[] to [ 1, 1 ] such that arr[0] = arr[2]
 * Removing arr[2] from the given array modifies arr[] to [ 1, 1 ] such that arr[0] = arr[1]
 * Therefore, the required output is 3.
 *
 * !Approach: Using Nested Loop – O(n^2) Time and O(1) Space
 * The simplest approach to solve this problem is to traverse the array and for each array element,
 * check if removing the element from the array makes the sum of even-indexed and odd-indexed array elements equal or not.
 * If found to be true, then increment the count. Finally, print the count.
 * </pre>
 */
#include <iostream>
#include <vector>
using namespace std;

class MinimumIndicesToEqualEvenOddSums {
public:
    /**
     * Ways to make sum of odd and even indexed elements equal by removing an array element
     * Given an array, arr[] of size n, the task is to find the count of array indices
     * such that removing an element from these indices makes the sum of even-indexed
     * and odd-indexed array elements equal.
     */
    static int minimumIndicesToEqualEvenOdd(const vector<int> &arr) {
        const int n = arr.size();
        int count = 0;

        /* Traverse the arr and check if removing each element makes the sum of even and odd indexed elements equal */
        for (int i = 0; i < n; i++) {
            int evenSum = 0, oddSum = 0;
            int k = 0;

            /* Calculate the sum of even and odd indexed elements excluding arr[i] */
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue; /* Skip the current element */

                if (k % 2 == 0) {
                    evenSum += arr[j];
                } else {
                    oddSum += arr[j];
                }
                k++;
            }

            if (evenSum == oddSum) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    cout << "Expected: 1 == "
            << MinimumIndicesToEqualEvenOddSums::minimumIndicesToEqualEvenOdd({2, 1, 6, 4})
            << endl;

    cout << "Expected: 3 == "
            << MinimumIndicesToEqualEvenOddSums::minimumIndicesToEqualEvenOdd({1, 1, 1})
            << endl;

    return 0;
}
