#include <iostream>
using namespace std;

/* 1️⃣ Using Bubble Sort */
bool isAnagramBubbleSort(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    auto bubbleSort = [](string &s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (s[j] > s[j + 1])
                    swap(s[j], s[j + 1]);
            }
        }
    };

    bubbleSort(s1);
    bubbleSort(s2);

    return s1 == s2;
}

/* 2️⃣ Using standard sort */
bool isAnagramSort(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

/* 3️⃣ Using HashMap (unordered_map) */
bool isAnagramHashMap(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    unordered_map<char, int> freq1, freq2;

    for (char c: s1) freq1[c]++;
    for (char c: s2) freq2[c]++;

    return freq1 == freq2;
}

int main() {
    vector<pair<string, string> > testCases = {
        {"listen", "silent"},
        {"hello", "world"},
        {"anagram", "nagaram"},
        {"rat", "car"}
    };

    cout << "Using Bubble Sort:" << endl;
    for (auto &p: testCases)
        cout << isAnagramBubbleSort(p.first, p.second) << endl;

    cout << "\nUsing std::sort:" << endl;
    for (auto &p: testCases)
        cout << isAnagramSort(p.first, p.second) << endl;

    cout << "\nUsing HashMap:" << endl;
    for (auto &p: testCases)
        cout << isAnagramHashMap(p.first, p.second) << endl;

    return 0;
}
