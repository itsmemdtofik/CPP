/**
 * <pre>
 * ! Perfect Square : Binary Search:Time complexity: O(log(n)) Space complexity: O(1)
 * ! Math.Sqrt: Time complexity: O(1), Space complexity: O(1)
 * </pre>
 */

#include <iostream>
#include <cmath>
using namespace std;

class PerfectSquareRoot {
public:
    /* Binary Search method: O(log(n)), O(1) space */
    static bool usingBinarySearch(const int num) {
        if (num < 0)
            return false;

        long left = 0, right = num;
        while (left <= right) {
            const long mid = left + (right - left) / 2;
            const long square = mid * mid;

            if (square == num)
                return true;
            if (square < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    /* Math sqrt method: O(1), O(1) space */
    static bool usingMathSqrt(const int num) {
        if (num < 0)
            return false;

        const int sqrtVal = static_cast<int>(sqrt(num));
        return sqrtVal * sqrtVal == num;
    }

    /* Count number of perfect squares in array */
    static int countPerfectSquare(int arr[], const int size) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (usingBinarySearch(arr[i])) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int arr[] = {4, 8, 16, 20, 25, 26};
    constexpr int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        if (PerfectSquareRoot::usingMathSqrt(arr[i])) {
            cout << arr[i] << " is a perfect square." << endl;
        } else {
            cout << arr[i] << " is not a perfect square." << endl;
        }
    }

    cout << "The Perfect Squares in the array: "
            << PerfectSquareRoot::countPerfectSquare(arr, size) << endl;

    return 0;
}
