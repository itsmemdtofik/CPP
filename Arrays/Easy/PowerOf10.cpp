/**
 * <pre>
 * !Power of Base:
 * Given an integer n, return true if it is a power of three. Otherwise, return false.
 * An integer n is a power of three, if there exists an integer x such that n == 3x.
 * Example 1:
 * Input: n = 27
 * Output: true
 * Explanation: 27 = 3
 *
 * Example 2:
 * Input: n = 0
 * Output: false
 * Explanation: There is no x where 3x = 0.
 *
 * Example 3:
 * Input: n = -1
 * Output: false
 * Explanation: There is no x where 3x = (-1).
 *
 * </pre>
 */

#include <iostream>
using namespace std;

class PowerOfBase {
public:
    static bool isPowerOfBase(int num, int base) {
        if (num <= 0 || base <= 1)
            return false;

        while (num % base == 0) {
            num /= base;
        }
        return num == 1;
    }
};

int main() {
    cout << boolalpha; /* print true/false instead of 1/0 */

    cout << PowerOfBase::isPowerOfBase(625, 5) << endl;
    cout << PowerOfBase::isPowerOfBase(0, 3) << endl;
    cout << PowerOfBase::isPowerOfBase(-1, 3) << endl;

    cout << PowerOfBase::isPowerOfBase(10, 10) << endl;
    cout << PowerOfBase::isPowerOfBase(100, 10) << endl;
    cout << PowerOfBase::isPowerOfBase(3, 10) << endl;

    return 0;
}
