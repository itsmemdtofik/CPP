#include <iostream>
#include <vector>
using namespace std;

/**
 * Generating All Subarrays
 *
 * Approach1: Generate in O(n²)
 *   - Fix starting point i
 *   - Expand subarray to j
 *   - Build incrementally & store in vector
 *
 * Approach2: Using three nested loops O(n³)
 */

/* Approach1: Using vector of vectors (O(n²)) */
vector<vector<int> > usingList(const vector<int> &numbers) {
    vector<vector<int> > subarrays;

    for (size_t i = 0; i < numbers.size(); i++) {
        vector<int> currentSubarray;

        for (size_t j = i; j < numbers.size(); j++) {
            currentSubarray.push_back(numbers[j]); /* expand */
            subarrays.push_back(currentSubarray); /* store copy */
        }
    }

    return subarrays;
}

/* Approach2: Using nested loops (O(n³)) - direct print */
void usingNestedLoop(const vector<int> &numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = i; j < numbers.size(); j++) {
            cout << "[ ";
            for (size_t k = i; k <= j; k++) {
                cout << numbers[k];
                if (k != j) cout << ", ";
            }
            cout << " ]" << endl;
        }
    }
}

int main() {
    const vector<int> arr = {1, 2, 3};

    cout << "Generating all subarrays in O(n^2) time and O(n) space:" << endl;
    const vector<vector<int> > subarrays = usingList(arr);
    for (const auto &sub: subarrays) {
        cout << "[ ";
        for (size_t i = 0; i < sub.size(); i++) {
            cout << sub[i];
            if (i != sub.size() - 1) cout << ", ";
        }
        cout << " ] ";
    }
    cout << endl;

    cout << "Generating sub-array using nested loops:" << endl;
    usingNestedLoop(arr);

    return 0;
}
