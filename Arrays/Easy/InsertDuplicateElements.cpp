/**
 * <pre>
 * !Insert duplicate of K adjacent to it for its every occurrences in array.
 *
 * Given an array arr consisting of N integers and an integer K, the task is to
 * insert an adjacent K for every occurrence of it in the original sequence and
 * then truncate the array to the original length using an O(1) auxiliary space.
 *
 * Examples:
 *
 * Input: arr[] = {1, 0, 2, 3, 0, 4, 5, 0}, K = 0
 * Output: {1, 0, 0, 2, 3, 0, 0, 4}
 * Explanation:
 * The given array {1, 0, 2, 3, 0, 4, 5, 0} is modified to [1, 0, 0, 2, 3, 0, 0, 4]
 * after insertion of two 0’s and truncation of extra elements.
 *
 *
 * Input: arr[] = {7, 5, 8}, K = 8
 * Output: {7, 5, 8}
 * Explanation:
 * After inserting an adjacent 8 into the array, it got truncated to restore the
 * original size of the array.
 * </pre>
 */

#include <iostream>
#include <vector>
using namespace std;

class InsertDuplicateElement {
public:
    /**
     * Insert Duplicate element in an array
     * Approach:
     *  - Time Complexity: O(n)
     *  - Space Complexity: O(n)
     * Steps:
     * 1. Count occurrences of K
     * 2. Create a new array of size (arr.size() + count)
     * 3. Copy items, duplicating K when found
     */
    static vector<int> insertDuplicate(const vector<int> &numbers, int K) {
        if (numbers.size() < 2) {
            return numbers;
        }

        int count = 0;
        for (int val: numbers) {
            if (val == K)
                count++;
        }

        vector<int> newArray;
        newArray.reserve(numbers.size() + count);

        for (int val: numbers) {
            newArray.push_back(val);
            if (val == K) {
                newArray.push_back(K);
            }
        }

        return newArray;
    }

    static void printArray(const vector<int> &arr) {
        cout << "Elements are: ";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    const vector<int> arr1 = {7, 5, 8};
    constexpr int K1 = 8;

    const vector<int> arr2 = {1, 0, 2, 3, 0, 4, 5, 0};
    constexpr int K2 = 0;

    const vector<int> m = InsertDuplicateElement::insertDuplicate(arr1, K1);
    InsertDuplicateElement::printArray(m);

    const vector<int> n = InsertDuplicateElement::insertDuplicate(arr2, K2);
    InsertDuplicateElement::printArray(n);

    return 0;
}
