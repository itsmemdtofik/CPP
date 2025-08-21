#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class LongestSubarraySumK {
public:
    /* Function to find the length of the longest subarray with sum equal to K */
    static int maxLength(const std::vector<int> &arr, const int K) {
        if (arr.empty())
            return 0;

        std::unordered_map<int, int> sumIndexMap;
        int maxLength = 0;
        int currentSum = 0;

        /* Initialize for subarray starting from index 0 */
        sumIndexMap[0] = -1;

        for (int i = 0; i < arr.size(); ++i) {
            currentSum += arr[i];

            /* Check if (currentSum - K) exists in the map */
            if (sumIndexMap.find(currentSum - K) != sumIndexMap.end()) {
                maxLength = std::max(maxLength, i - sumIndexMap[currentSum - K]);
            }

            /* Store the first occurrence of each sum */
            if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {
                sumIndexMap[currentSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    const std::vector<int> arr1 = {9, -3, 3, -1, 6, -5};
    std::cout << LongestSubarraySumK::maxLength(arr1, 0) << std::endl;

    const std::vector<int> arr2 = {9, -3, 3, -1, 6, -5};
    std::cout << LongestSubarraySumK::maxLength(arr2, 6) << std::endl;

    const std::vector<int> arr3 = {1, 0, -3};
    std::cout << LongestSubarraySumK::maxLength(arr3, 0) << std::endl;

    const std::vector<int> arr4 = {1, 2, 3};
    std::cout << LongestSubarraySumK::maxLength(arr4, 5) << std::endl;

    const std::vector<int> arr5 = {0, 0, 0, 0};
    std::cout << LongestSubarraySumK::maxLength(arr5, 0) << std::endl;

    const std::vector<int> arr6 = {};
    std::cout << LongestSubarraySumK::maxLength(arr6, 0) << std::endl;

    const std::vector<int> arr7(100000, 0);
    std::cout << LongestSubarraySumK::maxLength(arr7, 0) << std::endl;

    const std::vector<int> arr8 = {1, -1, 1, -1, 1, -1};
    std::cout << LongestSubarraySumK::maxLength(arr8, 0) << std::endl;

    const std::vector<int> arr10 = {6, 1, 2, 3};
    std::cout << LongestSubarraySumK::maxLength(arr10, 6) << std::endl;

    const std::vector<int> arr11 = {1, 2, 3, 5};
    std::cout << LongestSubarraySumK::maxLength(arr11, 5) << std::endl;

    return 0;
}
