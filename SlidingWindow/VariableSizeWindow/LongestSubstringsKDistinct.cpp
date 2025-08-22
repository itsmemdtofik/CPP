/*
Longest Substring with At Most K Distinct Characters

Given a string, find the length of the longest substring that contains
at most k distinct characters.

Example:
Input: s = "eceba", k = 2
Output: 3  (T = "ece")

Input: s = "aa", k = 1
Output: 2  (T = "aa")
*/

#include <iostream>
#include <unordered_set>
using namespace std;

/* 1️⃣ Brute-force solution: O(n^2) */
int longestKSubstring_BruteForce(const string &s, int K) {
    int result = -1;

    for (int i = 0; i < s.size(); i++) {
        unordered_set<char> seen;
        for (int j = i; j < s.size(); j++) {
            seen.insert(s[j]);
            if (seen.size() == K)
                result = max(result, j - i + 1);
            if (seen.size() > K)
                break;
        }
    }

    return result;
}

/* 2️⃣ Sliding window solution: O(n) */
int longestKSubstring_SlidingWindow(const string &s, int K) {
    if (s.empty() || K <= 0)
        return -1;

    unordered_map<char, int> freqMap;
    int left = 0;
    int max_len = -1;

    for (int right = 0; right < s.size(); right++) {
        char currentChar = s[right];
        freqMap[currentChar]++;

        /* Shrink window if number of unique characters exceeds K */
        while (freqMap.size() > K) {
            char leftChar = s[left];
            freqMap[leftChar]--;
            if (freqMap[leftChar] == 0)
                freqMap.erase(leftChar);
            left++;
        }

        if (freqMap.size() == K)
            max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    string s1 = "aabacbebebe";
    int k1 = 3;
    cout << "Brute-force: " << longestKSubstring_BruteForce(s1, k1) << endl;
    cout << "Sliding Window: " << longestKSubstring_SlidingWindow(s1, k1) << endl;

    string s2 = "aaaa";
    int k2 = 2;
    cout << "Brute-force: " << longestKSubstring_BruteForce(s2, k2) << endl;
    cout << "Sliding Window: " << longestKSubstring_SlidingWindow(s2, k2) << endl;

    string s3 = "aabaaab";
    int k3 = 2;
    cout << "Brute-force: " << longestKSubstring_BruteForce(s3, k3) << endl;
    cout << "Sliding Window: " << longestKSubstring_SlidingWindow(s3, k3) << endl;

    return 0;
}
