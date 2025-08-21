/**
 * <pre>
 * !Rearrange Array Elements by Sign
 * Given an array arr[] of size n, the task is to rearrange it in
 * alternate positive and negative manner without changing the relative order of
 * positive and negative numbers. In case of extra positive/negative numbers, they appear at the end of the array.
 *
 * @param Note: The rearranged array should start with a positive number and 0 (zero) should be considered as a positive number.
 *
 * @param Examples:
 * Input:  arr[] = [1, 2, 3, -4, -1, 4]
 * Output: arr[] = [1, -4, 2, -1, 3, 4]
 *
 * Input:  arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
 * Output: arr[] = [5, -5, 2, -2, 4, -8, 7, 1, 8, 0]
 *
 * !Approach: Using two pointers - O(n) Time and O(n) Space
 * </pre>
 */
#include <iostream>
#include <vector>
using namespace std;

class RearrangeArrElementsBySign {
public:
    static void rearrangeArr(vector<int> &arr) {
        vector<int> positive;
        vector<int> negative;

        for (int num: arr) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }

        if (positive.empty())
            return;

        int i = 0, j = 0, k = 0;


        while (i < positive.size() && j < negative.size()) {
            arr[k++] = positive[i++];
            arr[k++] = negative[j++];
        }


        while (i < positive.size()) {
            arr[k++] = positive[i++];
        }


        while (j < negative.size()) {
            arr[k++] = negative[j++];
        }
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
    vector<int> arr1 = {1, 2, 3, -4, -1, 4};
    RearrangeArrElementsBySign::rearrangeArr(arr1);
    cout << "Expected: [1, -4, 2, -1, 3, 4] == ";
    RearrangeArrElementsBySign::printArray(arr1);
    cout << endl;

    vector<int> arr2 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    RearrangeArrElementsBySign::rearrangeArr(arr2);
    cout << "Expected: [5, -5, 2, -2, 4, -8, 7, 1, 8, 0] == ";
    RearrangeArrElementsBySign::printArray(arr2);
    cout << endl;

    vector<int> arr3 = {-1, -2, -3};
    RearrangeArrElementsBySign::rearrangeArr(arr3);
    cout << "Expected: [-1, -2, -3] == ";
    RearrangeArrElementsBySign::printArray(arr3);
    cout << endl;

    return 0;
}
