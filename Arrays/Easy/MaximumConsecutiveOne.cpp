/**
 * <pre>
 * !Maximum Consecutive one's or zero in binary array.
 * Given a binary array, find the count of a maximum number of consecutive 1s
 * present in the array.
 *
 * Examples :
 * Input: arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
 * Output: 4
 * Explanation: The maximum number of consecutive 1’s in the array is 4 from
 * index 8-11.
 *
 * Input: arr[] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
 * Output: 1
 * Explanation: The maximum number of consecutive 0’s in the array is 1 from
 * index 0-1.
 * </pre>
 */

#include <iostream>
#include <vector>
using namespace std;

class MaximumConsecutiveOne {
public:
    static int maximumConsecutiveOne(const vector<int> &arr) {
        if (arr.empty())
            return 0;

        int count = 0, result = 0;
        for (const int num: arr) {
            if (num == 1) {
                count++;
                result = max(result, count);
            } else {
                count = 0;
            }
        }
        return result;
    }
};

int main() {
    const vector<vector<int> > testCases = {
        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {}
    };

    vector<int> expectedResult = {1, 4, 0, 0};

    bool allTestsPassed = true;

    for (int i = 0; i < testCases.size(); i++) {
        const int result = MaximumConsecutiveOne::maximumConsecutiveOne(testCases[i]);
        const bool passed = result == expectedResult[i];

        cout << "Test Case " << (i + 1) << " - Max consecutive 1's: " << result;
        if (passed) {
            cout << " - Passed ✅" << endl;
        } else {
            cout << " - ❌ Failed (Expected: " << expectedResult[i] << ")" << endl;
            allTestsPassed = false;
        }
    }

    cout << "----------------------------------------" << endl;
    if (allTestsPassed)
        cout << "All test cases passed! 🎉" << endl;
    else
        cout << "Some test cases failed!" << endl;

    return 0;
}
