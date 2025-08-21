/**
* !Approach 1: Two-pass method
 * Step1: Find the largest element
 * Step2: Find the largest element smaller than 'first'
 * Edge cases: empty array, single element, all elements same
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SecondLargest {
public:
    static int secondLargest(const vector<int> &arr) {
        if (arr.size() < 2) {
            return INT_MIN; /* Using INT_MIN to represent "None" */
        }

        int first = INT_MIN;
        int second = INT_MIN;

        /* Step 1: Find the largest element */
        for (int num: arr) {
            first = max(first, num);
        }

        /* Step 2: Find the second largest */
        for (int num: arr) {
            if (num < first) {
                second = max(second, num);
            }
        }

        return second == INT_MIN ? INT_MIN : second;
    }

    /**
     * !Approach 2: Single-pass method
     * Maintain 'first' and 'second' while iterating
     */
    static int secondLarge(const vector<int> &arr) {
        if (arr.size() < 2) {
            return INT_MIN;
        }

        int first = INT_MIN;
        int second = INT_MIN;

        for (const int num: arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second && num != first) {
                second = num;
            }
        }

        return second == INT_MIN ? INT_MIN : second;
    }
};

int main() {
    const vector<vector<int> > testArrays = {
        {},
        {5},
        {5, 5},
        {1, 2, 3, 4, 5},
        {10, 5, 2, 10, 5},
        {2, 2, 2, 2, 2}
    };

    for (auto &arr: testArrays) {
        const int result = SecondLargest::secondLargest(arr);
        cout << "Array: [";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
        }
        cout << "] => Second Largest: ";
        if (result == INT_MIN) {
            cout << "None";
        } else {
            cout << result;
        }
        cout << endl;
    }

    return 0;
}
