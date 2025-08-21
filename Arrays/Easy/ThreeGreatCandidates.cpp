/**
 * <pre>
 * !Maximum product of a triplet (subsequence of size 3) in array.
 * !Approach
 * Step1: Find first and second and third-largest element.
 * Step2: Return of first * second * third.
 * Given an integer array, find a maximum product of a triplet in the array.
 *
 * Examples:
 * Input:  [10, 3, 5, 6, 20]
 * Output: 1200
 * Explanation: Multiplication of 10, 6 and 20
 *
 * Input:  [-10, -3, -5, -6, -20]
 * Output: -90
 *
 * Input:  [1, -4, 3, -6, 7, 0]
 * Output: 168
 * </pre>
 */

#include <iostream>
using namespace std;

class ThreeGreatCandidate {
public:
    static int productOfTriplet(const vector<int> &arr) {
        if (arr.size() < 3) {
            return 0;
        }

        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        for (const int val: arr) {
            if (val > first) {
                third = second;
                second = first;
                first = val;
            } else if (val > second && val != first) {
                third = second;
                second = val;
            } else if (val > third && val != first && val != second) {
                third = val;
            }
        }

        if (third == INT_MIN && second == INT_MIN && first == INT_MIN) {
            return 0;
        }

        return first * second * third;
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
        {1, -4, 3, -6, 7, 0},
        {10, 3, 5, 6, 20},
        {-10, -3, -5, -6, -20}
    };

    for (const auto &arr: testArrays) {
        const int result = ThreeGreatCandidate::productOfTriplet(arr);

        cout << "Array: [";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << ", ";
        }
        cout << "] => Product Of Triplet is: ";
        if (result == 0)
            cout << "None";
        else
            cout << result;
        cout << endl;
    }

    return 0;
}
