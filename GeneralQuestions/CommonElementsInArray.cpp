#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> getCommonElementInArray(const vector<int> &nums1, const vector<int> &nums2) {
    unordered_set<int> freq_map;
    for (int num: nums1) {
        freq_map.insert(num);
    }

    unordered_set<int> result_map;
    for (int num: nums2) {
        if (freq_map.find(num) != freq_map.end()) {
            result_map.insert(num);
        }
    }

    /* Convert set to vector */
    return vector<int>(result_map.begin(), result_map.end());
}

int main() {
    vector<int> result1 = getCommonElementInArray({1, 2, 3, 4}, {3, 4, 5, 6});
    for (int x: result1) cout << x << " ";
    cout << endl;

    vector<int> result2 = getCommonElementInArray({1, 1, 2}, {2, 2, 3});
    for (int x: result2) cout << x << " ";
    cout << endl;

    vector<int> result3 = getCommonElementInArray({}, {1, 2, 3});
    for (int x: result3) cout << x << " ";
    cout << endl;

    return 0;
}
