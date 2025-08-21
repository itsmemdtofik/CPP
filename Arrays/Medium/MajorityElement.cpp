/**
 * ! Majority Element in an Array.
 *
 * Given an array arr. Find the majority element in the array. If no majority
 * exists, return -1. A majority element in an array is an element that appears
 * strictly more than arr.size() / 2 times in the array.
 *
 * Examples :
 *
 * Input : arr[] = {1, 1, 2, 1, 3, 5, 1}
 * Output : 1
 * Explanation: Note that 1 appear 4 times which is more than 7 / 2 times
 *
 *
 * Input : arr[] = {3, 3, 4, 2, 4, 4, 2, 4}
 * Output : -1
 * Explanation: There is no element whose frequency is greater than the half of
 * the size of the array size.
 *
 *
 * Input : arr[] = {3}
 * Output : 3
 * Explanation: Appears more than n/2 times
 */
#include <iostream>
#include <vector>
#include <unordered_map>

class MajorityElement {
public:
    /* Brute-force approach: O(n^2) */
    static int findMajority(const std::vector<int> &arr) {
        const int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (arr[i] == arr[j])
                    count++;
            }
            if (count > n / 2)
                return arr[i];
        }
        return -1;
    }

    /* Using hashing (unordered_map) approach: O(n) */
    static int usingHashing(const std::vector<int> &arr) {
        std::unordered_map<int, int> freq;
        int n = arr.size();
        for (int num: arr) {
            freq[num]++;
            if (freq[num] > n / 2)
                return num;
        }
        return -1;
    }
};

int main() {
    const std::vector<int> arr1 = {1, 1, 1, 2, 3, 4, 4, 4};
    std::cout << "Majority element: " << MajorityElement::usingHashing(arr1) << std::endl;

    const std::vector<int> arr2 = {3, 3, 4, 2, 4, 4, 2, 4};
    std::cout << "Majority element: " << MajorityElement::usingHashing(arr2) << std::endl;

    const std::vector<int> arr3 = {3};
    std::cout << "Majority element: " << MajorityElement::usingHashing(arr3) << std::endl;

    return 0;
}
