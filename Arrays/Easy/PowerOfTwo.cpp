/**
* Is Power Of Two : Time complexity O(1), Space complexity O(1)
 * Approach: Bitwise Operation
 * A number is a power of two if it has exactly one '1' in its binary representation.
 *
 * Example:
 * 2 -> 10 (Binary)
 * 4 -> 100 (Binary)
 * 8 -> 1000 (Binary)
 *
 * Example Walkthrough:
 * For 8:
 * Binary: 8 = 1000
 * 8 - 1 = 7 = 0111
 * 1000 & 0111 = 0000 → Returns true
 */

#include <iostream>
using namespace std;

class PowerOfTwo {
public:
    static bool isPowerOfTwo(const int num) {
        if (num <= 0)
            return false;

        return (num & (num - 1)) == 0;
    }
};

int main() {
    cout << "Is 8 power of 2 : " << boolalpha << PowerOfTwo::isPowerOfTwo(8) << endl;
    cout << "Is 7 power of 2 : " << boolalpha << PowerOfTwo::isPowerOfTwo(7) << endl;
    cout << "Is 16 power of 2 : " << boolalpha << PowerOfTwo::isPowerOfTwo(16) << endl;
    cout << "Is -2 power of 2 : " << boolalpha << PowerOfTwo::isPowerOfTwo(-2) << endl;

    return 0;
}
