/**
 * <pre>
 * !Product of an Array Except Self.
 *
 * Given an array arr[] of n integers, construct a product array res[] (of the
 * same size) such that res[i] is equal to the product of all the elements of
 * arr[] except arr[i].
 *
 * Example:
 * Input: arr[] = [10, 3, 5, 6, 2]
 * Output: [180, 600, 360, 300, 900]
 *
 * Explanation:
 * For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
 * For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
 * For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
 * For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
 * For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.
 *
 * Input: arr[] = [12, 0]
 * Output: [0, 12]
 * Explanation: For i = 0, res[i] = 0 and For i = 1, res[i] = 12.
 * </pre>
 */
#include <iostream>
#include <vector>
using namespace std;

class ProductOfArrayExceptSelf {
public:
    /* Brute-force approach: O(n^2) */
    static vector<int> productOfArrayExceptSelf(const vector<int> &arr) {
        if (arr.empty())
            return {};

        const size_t n = arr.size();
        vector<int> result(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    result[i] *= arr[j];
                }
            }
        }
        return result;
    }

    /* Optimized Left & Right approach: O(n) */
    static vector<int> productOfArrayUsingLeftAndRight(const vector<int> &arr) {
        if (arr.empty())
            return {};

        const size_t n = arr.size();
        vector<int> left(n, 1), right(n, 1), result(n, 1);

        /* Step 1: Compute left products */
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * arr[i - 1];
        }

        /* Step 2: Compute right products */
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * arr[i + 1];
        }

        /* Step 3: Multiply left and right arrays */
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }

    static void printArray(const vector<int> &arr) {
        cout << "[";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
};

int main() {
    const vector<int> arr = {1, 2, 3, 4};
    const vector<int> arr1 = {10, 3, 5, 6, 2};

    cout << "Product of an array except self (brute-force): ";
    ProductOfArrayExceptSelf::printArray(ProductOfArrayExceptSelf::productOfArrayExceptSelf(arr));
    cout << endl;

    cout << "Product of an array except self (left & right optimized): ";
    ProductOfArrayExceptSelf::printArray(ProductOfArrayExceptSelf::productOfArrayUsingLeftAndRight(arr1));
    cout << endl;

    return 0;
}
