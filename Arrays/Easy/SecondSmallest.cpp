/**
* !Second Smallest
 * Q2. Find the second-smallest element in an array.
 * Important to take note of the word element
 * For example, [4,8, 9, 2, 1, 1] should return 1, not 2.
 * Also, if array.length is less than 2, just immediately return zero.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SecondSmallest {
public:
    static int findSecondSmallest(const vector<int> &arr) {
        if (arr.size() < 2) {
            return INT_MAX; /* returning INT_MAX to represent "None" */
        }

        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for (int num: arr) {
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else if (num < secondSmallest && num != smallest) {
                secondSmallest = num;
            }
        }

        if (secondSmallest == INT_MAX) {
            return INT_MAX; /* meaning "None" */
        }
        return secondSmallest;
    }
};

int main() {
    const vector<vector<int> > testArrays = {
        {},
        {5},
        {5, 5},
        {1, 2, 3, 4, 5},
        {10, 5, 2, 10, 5},
        {2, 2, 2, 2, 2},
        {4, 8, 9, 2, 1, 1}
    };

    for (auto &arr: testArrays) {
        const int result = SecondSmallest::findSecondSmallest(arr);
        cout << "Array: [";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
        }
        cout << "] => Second Smallest: "
                << (result == INT_MAX ? string("None") : to_string(result))
                << endl;
    }

    return 0;
}
