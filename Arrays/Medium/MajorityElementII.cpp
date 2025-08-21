/**
 * <pre>
 * ! Majority Element II - An element that occur [arr.length / 3] times.
 *
 * Given an array arr[] consisting of n integers, the task is to find all the
 * array elements which occurs more than floor(n/3) times.
 * Note: The returned array of majority elements should be sorted.
 *
 * Examples:
 *
 * Input: arr[] = {2, 2, 3, 1, 3, 2, 1, 1}
 * Output: {1, 2}
 * Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3
 * = 2).
 *
 *
 * Input: arr[] = {-5, 3, -5}
 * Output: {-5}
 * Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 =
 * 1).
 *
 *
 * Input: arr[] = {3, 2, 2, 4, 1, 4}
 * Output: { }
 * Explanation: There is no majority element.
 * </pre>
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class MajorityElementII {
public:
    /* Function to find elements occurring more than floor(n/3) times */
    static std::vector<int> findMajorityElements(const std::vector<int> &arr) {
        std::unordered_map<int, int> freqMap;
        std::vector<int> result;
        const int n = arr.size();

        for (int num: arr) {
            freqMap[num]++;
        }

        for (const auto &entry: freqMap) {
            if (entry.second > n / 3) {
                result.push_back(entry.first);
            }
        }

        /* Sort the result as required */
        std::sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    const std::vector<int> arr1 = {1, 1, 1, 2, 3, 4, 4, 4};
    const std::vector<int> res1 = MajorityElementII::findMajorityElements(arr1);
    std::cout << "Expected [1, 4]: ";
    for (const int x: res1)
        std::cout << x << " ";
    std::cout << std::endl;

    const std::vector<int> arr2 = {-5, 3, -5};
    const std::vector<int> res2 = MajorityElementII::findMajorityElements(arr2);
    std::cout << "Expected [-5]: ";
    for (const int x: res2)
        std::cout << x << " ";
    std::cout << std::endl;

    const std::vector<int> arr3 = {3, 2, 2, 4, 1, 4};
    const std::vector<int> res3 = MajorityElementII::findMajorityElements(arr3);
    std::cout << "Expected []: ";
    for (const int x: res3)
        std::cout << x << " ";
    std::cout << std::endl;

    const std::vector<int> arr4 = {2, 2, 3, 1, 3, 2, 1, 1};
    const std::vector<int> res4 = MajorityElementII::findMajorityElements(arr4);
    std::cout << "Expected [1, 2]: ";
    for (const int x: res4)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
