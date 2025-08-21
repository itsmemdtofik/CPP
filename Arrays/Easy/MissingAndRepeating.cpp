/**
 * <pre>
 * !Missing and repeating in an array.
 * Given an unsorted array of size n. Array elements are in the range of 1 to n.
 * One number from set {1, 2, …n} is missing and one number occurs twice in the
 * array. Find these two numbers.
 *
 * Examples:
 *
 * Input: arr[] = {3, 1, 3}
 * Output: Missing = 2, Repeating = 3
 * Explanation: In the array, 2 is missing and 3 occurs twice
 *
 *
 * Input: arr[] = {4, 3, 6, 2, 1, 1}
 * Output: Missing = 5, Repeating = 1
 * </pre>
 */

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class MissingAndRepeatingArray {
public:
    /* Approach 1: Using visited array */
    static void missingAndRepeating(const vector<int> &number) {
        const size_t n = number.size();
        vector<bool> visited(n + 1, false);
        int repeating = -1, missing = -1;

        for (const int num: number) {
            if (visited[num]) {
                repeating = num;
            } else {
                visited[num] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                missing = i;
                break;
            }
        }

        cout << "Repeating : " << repeating << endl;
        cout << "Missing   : " << missing << endl;
    }

    /* Approach 2: Using HashSet for 1D Array */
    static pair<int, int> usingHashingFor1DArr(const vector<int> &number) {
        if (number.empty())
            return {-1, -1};

        unordered_set<int> seen;
        int repeating = -1;

        for (int num: number) {
            if (seen.count(num)) {
                repeating = num;
            } else {
                seen.insert(num);
            }
        }

        int missing = -1;
        for (int i = 1; i <= static_cast<int>(number.size()); i++) {
            if (!seen.count(i)) {
                missing = i;
                break;
            }
        }

        return {missing, repeating};
    }

    /* Approach 3: Using Hashing for 2D Array (matrix) */
    static pair<int, int> usingHashingFor2DArr(const vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {-1, -1};

        unordered_set<int> seen;
        const size_t rows = matrix.size(), cols = matrix[0].size();
        const size_t totalElements = rows * cols;
        int repeating = -1;

        for (auto &row: matrix) {
            for (int num: row) {
                if (seen.count(num)) {
                    repeating = num;
                } else {
                    seen.insert(num);
                }
            }
        }

        int missing = -1;
        for (int i = 1; i <= totalElements; i++) {
            if (!seen.count(i)) {
                missing = i;
                break;
            }
        }

        return {repeating, missing};
    }
};

int main() {
    const vector<int> arr = {7, 3, 4, 5, 5, 6, 2};
    MissingAndRepeatingArray::missingAndRepeating(arr);

    const vector<int> arr1 = {3, 1, 3};
    const vector<int> arr2 = {4, 3, 6, 2, 1, 1};

    auto result1 = MissingAndRepeatingArray::usingHashingFor1DArr(arr1);
    cout << "usingHashingFor1DArr : Missing = " << result1.first
            << ", Repeating = " << result1.second << endl;

    auto result2 = MissingAndRepeatingArray::usingHashingFor1DArr(arr2);
    cout << "usingHashingFor1DArr : Missing = " << result2.first
            << ", Repeating = " << result2.second << endl;

    vector<vector<int> > matrix = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}
    };

    const auto result3 = MissingAndRepeatingArray::usingHashingFor2DArr(matrix);
    cout << "usingHashingFor2DArr : Repeating element is : " << result3.first << endl;
    cout << "usingHashingFor2DArr : Missing number is : " << result3.second << endl;

    return 0;
}
