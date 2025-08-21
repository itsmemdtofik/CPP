/**
*Problem: Two Sum in an Unsorted Array
*Given:An unsorted array of integers values[].
*A target integer target.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Brute-force approach: Nested loops */
vector<int> usingNestedLoop(const vector<int> &values, const int target) {
    for (int start = 0; start < values.size(); start++) {
        for (int end = start + 1; end < values.size(); end++) {
            if (values[start] + values[end] == target) {
                return {start, end};
            }
        }
    }
    return {}; /* empty vector means no pair found */
}

/* Optimized approach: Hash map */
vector<int> usingHashMap(const vector<int> &values, const int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < values.size(); i++) {
        int complement = target - values[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[values[i]] = i;
    }
    return {};
}

int main() {
    const vector<int> values = {2, 7, 15, 11};
    constexpr int target = 26;

    const vector<int> result = usingHashMap(values, target);
    if (!result.empty()) {
        cout << "Indices (HashMap): " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found (HashMap)." << endl;
    }

    const vector<int> values1 = {2, 7, 11, 15};
    constexpr int target1 = 26;

    const vector<int> result1 = usingNestedLoop(values1, target1);
    if (!result1.empty()) {
        cout << "Indices (Nested Loop): " << result1[0] << ", " << result1[1] << endl;
    } else {
        cout << "No pair found (Nested Loop)." << endl;
    }

    return 0;
}
