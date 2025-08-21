/**
 * <pre>
 * !Move all zeros to end of an array.
 * Given an array of integers arr[], the task is to move all the zeros to
 * the end of the array while maintaining the relative order of all non-zero elements.
 *
 * Examples:
 * Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0
 * Output: arr[] = [1, 2, 4, 3, 5, 0, 0, 0
 * Explanation: There are three 0s that are moved to the end.
 *
 * Input: arr[] = [10, 20, 30]
 * Output: arr[] = [10, 20, 30]
 * Explanation: No change in array as there are no 0s.
 *
 * Input: arr[] = [0, 0]
 * Output: arr[] = [0, 0]
 * Explanation: No change in array as there are all 0s.
 * </pre>
 */
#include <iostream>
#include <vector>

using namespace std;

class MoveAllZerosToEnd {
public:
    static vector<int> usingList(const vector<int> &arr) {
        if (arr.empty()) {
            return {};
        }

        vector<int> result;
        int count = 0;

        for (int num: arr) {
            if (num == 0) {
                count++;
            } else {
                result.push_back(num);
            }
        }

        for (int i = 0; i < count; i++) {
            result.push_back(0);
        }

        return result;
    }


    static vector<int> pushZerosToEnd(vector<int> arr) {
        if (arr.empty()) {
            return arr;
        }

        int j = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                arr[j++] = arr[i];
            }
        }

        while (j < arr.size()) {
            arr[j++] = 0;
        }

        return arr;
    }


    static vector<int> pushZeroToEnd(vector<int> arr) {
        if (arr.size() < 2) {
            return arr;
        }

        int j = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        return arr;
    }


    static vector<int> usingTwoPointer(vector<int> arr) {
        int left = 0;
        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] != 0) {
                if (left != right) {
                    swap(arr[left], arr[right]);
                }
                left++;
            }
        }
        return arr;
    }
};

int main() {
    const vector<int> arr = {0, 2, 0, 4, 3, 0, 5, 0, 1};
    const vector<int> move = MoveAllZerosToEnd::usingList(arr);

    cout << "Moved All Zeros To End using usingList(): ";
    for (const int num: move)
        cout << num << " ";
    cout << endl;

    vector<vector<int> > testArrays = {
        {0},
        {5},
        {5, 5},
        {1, 2, 3, 4, 5},
        {10, 5, 2, 10, 5},
        {2, 2, 2, 2, 2},
        {1, -4, 3, -6, 7, 0},
        {10, 3, 5, 6, 20},
        {-10, -3, -5, -6, -20},
        {1, 2, 0, 4, 3, 0, 5, 0},
    };

    for (const auto arr1: testArrays) {
        vector<int> result = MoveAllZerosToEnd::usingTwoPointer(arr1);

        cout << "Moved to end : ";
        if (result.empty()) {
            cout << "None";
        } else {
            for (int num: result)
                cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
