/**
 * <pre>
 * !Minimum number of increment-other operations to make all array elements equal.
 * We are given an array consisting of n elements.
 * At each operation we can select any one element and increase rest of n-1 elements by 1.
 * We have to make all elements equal performing such operation as many times you wish.
 * Find the minimum number of operations needed for this.
 *
 * @param Examples:
 * Input: arr[] = [1, 2, 3]
 * Output: 3
 * Explanation:
 * Operation 1 : Increase all except 3rd, we get 2, 3, 3
 * Operation 2 : Increase all except 3rd, we get 3, 4, 3
 * Operation 3 : Increase all except 2nd, we get 4, 4, 4
 *
 * Input: arr[] = [4, 3, 4]
 * Output: 2
 * Explanation:
 * Operation 1 : Increase all except 3rd, we get 5, 4, 4
 * Operation 2 : Increase all except 1st, we get 5, 5, 5
 *
 * !Approach: Using Sorting – O(n^2logn) Time and O(1) Space
 * Increments all elements except the maximum one in each step until all elements become equal..
 * The array is modified in-place, and no extra space is used other than the input array.
 * </pre>
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumMovesToEqualizeArr {
public:
    /**
     * Minimum number of increment-other operations to make all array elements equal.
     * We are given an array consisting of n elements.
     * At each operation we can select any one element and increase rest of n-1 elements by 1.
     * We have to make all elements equal performing such operation as many times you wish.
     * Find the minimum number of operations needed for this.
     */
    static int minimumMovesToEqualize(vector<int> arr) {
        const int n = arr.size();
        int count = 0;
        sort(arr.begin(), arr.end());


        while (arr[0] != arr[n - 1]) {
            /* Increment all elements except the largest element */
            for (int i = 0; i < n - 1; i++) {
                arr[i]++;
            }
            count++;
            sort(arr.begin(), arr.end());
        }

        return count;
    }
};

int main() {
    cout << "Expected: 3 == "
            << MinimumMovesToEqualizeArr::minimumMovesToEqualize({1, 2, 3})
            << endl;

    cout << "Expected: 2 == "
            << MinimumMovesToEqualizeArr::minimumMovesToEqualize({4, 3, 4})
            << endl;

    return 0;
}
