#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Method 1: Using HashMap (unordered_map in C++) */
int getUniqueElementUsingHashMap(const vector<int> &arr) {
    unordered_map<int, int> freq;

    // Count occurrences
    for (int num: arr) {
        freq[num]++;
    }

    // Find the element with count = 1
    for (auto &pair: freq) {
        if (pair.second == 1) {
            return pair.first;
        }
    }

    return -1; // If no unique element found (edge case)
}

/* Method 2: Using XOR */
int getUniqueElementUsingXOR(const vector<int> &arr) {
    int result = 0;
    for (int num: arr) {
        result ^= num; // XOR cancels duplicates
    }
    return result;
}

int main() {
    cout << "Unique Element Using HashMap:" << endl;
    cout << getUniqueElementUsingHashMap({2, 3, 4, 2, 3}) << endl; // 4
    cout << getUniqueElementUsingHashMap({1, 1, 2, 2, 3}) << endl; // 3
    cout << getUniqueElementUsingHashMap({7}) << endl; // 7
    cout << getUniqueElementUsingHashMap({4, 1, 2, 1, 2}) << endl; // 4
    cout << getUniqueElementUsingHashMap({-1, -1, -2}) << endl; // -2

    cout << "\nUnique Element Using XOR:" << endl;
    cout << getUniqueElementUsingXOR({2, 3, 4, 2, 3}) << endl; // 4
    cout << getUniqueElementUsingXOR({1, 1, 2, 2, 3}) << endl; // 3
    cout << getUniqueElementUsingXOR({7}) << endl; // 7
    cout << getUniqueElementUsingXOR({4, 1, 2, 1, 2}) << endl; // 4
    cout << getUniqueElementUsingXOR({-1, -1, -2}) << endl; // -2

    return 0;
}
