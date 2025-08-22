#include <iostream>
#include <unordered_set>
using namespace std;

// ✅ Using HashSet (preserves order)
vector<int> getDuplicateRemovalUsingHashSet(const vector<int> &nums) {
    unordered_set<int> seen;
    vector<int> result;

    for (int x: nums) {
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}

// ✅ Using Sorting (does not preserve order, but removes duplicates)
vector<int> getDuplicateRemovalUsingSorting(vector<int> arr) {
    if (arr.empty()) return {};

    sort(arr.begin(), arr.end()); // sort first
    vector<int> result = {arr[0]};

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

// ✅ Using Nested Loop (preserves original order)
vector<int> getDuplicateRemovalUsingNestedLoop(const vector<int> &arr) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        bool duplicate = false;
        for (int j = 0; j < result.size(); j++) {
            if (arr[i] == result[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

// Utility: print vector
void printVector(const vector<int> &v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "Using HashSet:" << endl;
    printVector(getDuplicateRemovalUsingHashSet({1, 2, 2, 3, 4, 4, 5})); // [1, 2, 3, 4, 5]
    printVector(getDuplicateRemovalUsingHashSet({5, 5, 5, 5, 5})); // [5]
    printVector(getDuplicateRemovalUsingHashSet({})); // []
    printVector(getDuplicateRemovalUsingHashSet({1, 2, 3, 2, 1})); // [1, 2, 3]

    cout << "\nUsing Sorting:" << endl;
    printVector(getDuplicateRemovalUsingSorting({1, 2, 2, 3, 4, 4, 5})); // [1, 2, 3, 4, 5]
    printVector(getDuplicateRemovalUsingSorting({5, 5, 5, 5, 5})); // [5]
    printVector(getDuplicateRemovalUsingSorting({})); // []
    printVector(getDuplicateRemovalUsingSorting({3, 1, 2, 2, 1})); // [1, 2, 3]

    cout << "\nUsing Nested Loop:" << endl;
    printVector(getDuplicateRemovalUsingNestedLoop({1, 2, 2, 3, 4, 4, 5})); // [1, 2, 3, 4, 5]
    printVector(getDuplicateRemovalUsingNestedLoop({5, 5, 5, 5, 5})); // [5]
    printVector(getDuplicateRemovalUsingNestedLoop({})); // []
    printVector(getDuplicateRemovalUsingNestedLoop({3, 1, 2, 2, 1})); // [3, 1, 2]

    return 0;
}
