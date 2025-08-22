#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Method 1: Using unordered_map (like defaultdict) */
unordered_map<int, int> getFrequencyMap(const vector<int> &nums) {
    unordered_map<int, int> freqMap;
    for (int num: nums) {
        freqMap[num]++; // auto-initializes to 0
    }
    return freqMap;
}

/* Method 2: Manual style (like dict with explicit checks) */
unordered_map<int, int> getFrequencyMapII(const vector<int> &arr) {
    unordered_map<int, int> freq;
    for (int num: arr) {
        if (freq.find(num) != freq.end()) {
            freq[num]++;
        } else {
            freq[num] = 1;
        }
    }
    return freq;
}

int main() {
    vector<int> data = {1, 2, 2, 3, 3, 3, 4};

    cout << "\nFrequency Map (Method 1):" << endl;
    auto freq1 = getFrequencyMap(data);
    for (auto &p: freq1) {
        cout << p.first << ": " << p.second << endl;
    }

    cout << "\nFrequency Map (Method 2):" << endl;
    auto freq2 = getFrequencyMapII(data);
    for (auto &p: freq2) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
