/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3  (Substring: "abc")

Example 2:
Input: s = "bbbbb"
Output: 1  (Substring: "b")
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* 1️⃣ Sliding Window using Set */
int longestSubstring_Set(const string &s) {
    if (s.size() <= 1)
        return s.size();

    unordered_set<char> charSet;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.size()) {
        char currentChar = s[right];
        while (charSet.count(currentChar)) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(currentChar);
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

/* 2️⃣ Sliding Window using HashMap (more efficient) */
int longestSubstring_HashMap(const string &s) {
    if (s.size() <= 1)
        return s.size();

    unordered_map<char, int> charMap;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char currentChar = s[right];

        if (charMap.count(currentChar))
            left = max(left, charMap[currentChar] + 1);

        charMap[currentChar] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<string> testCases = {"abcabcbb", "bbbbb", "   "};

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": \"" << testCases[i] << "\"" << endl;
        cout << "Using Set + Sliding Window: " << longestSubstring_Set(testCases[i]) << endl;
        cout << "Using HashMap + Sliding Window: " << longestSubstring_HashMap(testCases[i]) << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
