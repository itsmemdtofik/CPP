/**
 * <pre>
 * !Fourth-Largest Number
 * !Time Complexity: O(n), Space Complexity: O(1)
 * Find the fourth-largest number in array
 * !Approach:
 * Step1: Traverse the array
 * Step2: Store the fourth = third, third = second, second = first, first = arr[i]
 * Step3: Return the fourth largest
 * </pre>
 */

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

int fourthLargest(const vector<int> &arr) {
    if (arr.size() < 4) {
        return INT_MIN; /* special value meaning "None" */
    }

    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;
    int fourth = INT_MIN;

    for (const int num: arr) {
        if (num > first) {
            fourth = third;
            third = second;
            second = first;
            first = num;
        } else if (num > second && num != first) {
            fourth = third;
            third = second;
            second = num;
        } else if (num > third && num != first && num != second) {
            fourth = third;
            third = num;
        } else if (num > fourth && num != first && num != second && num != third) {
            fourth = num;
        }
    }

    if (fourth == INT_MIN) {
        return INT_MIN;
    }

    return fourth;
}

int main() {
    const vector<vector<int> > testArrays = {
        {},
        {5},
        {5, 5},
        {1, 2, 3, 4, 5},
        {10, 5, 2, 10, 5},
        {2, 2, 2, 2, 2}
    };

    for (const auto &arr: testArrays) {
        const int result = fourthLargest(arr);
        cout << "Array: [ ";
        for (const int num: arr) cout << num << " ";
        cout << "] => Fourth Largest: ";
        if (result == INT_MIN) {
            cout << "None";
        } else {
            cout << result;
        }
        cout << endl;
    }

    return 0;
}
