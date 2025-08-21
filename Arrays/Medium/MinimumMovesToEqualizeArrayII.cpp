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
 * !Approach: Using Direct Formula – O(n) Time and O(1) Space
 * The optimized approach calculates the total sum of the array and identifies the smallest element.
 * It subtracts n * smallest element from the sum to find the minimum number of operations.
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

        return sum - n * minValue;
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
