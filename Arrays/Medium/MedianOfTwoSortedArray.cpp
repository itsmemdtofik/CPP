#include <iostream>
#include <vector>

class MedianTwoSortedArray {
public:
    /* Merge two sorted arrays into one sorted array */
    static std::vector<int> mergeArr(const std::vector<int> &arr1, const std::vector<int> &arr2) {
        int i = 0, j = 0;
        std::vector<int> merged(arr1.size() + arr2.size());
        int mergeIdx = 0;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                merged[mergeIdx++] = arr1[i++];
            } else {
                merged[mergeIdx++] = arr2[j++];
            }
        }

        while (i < arr1.size())
            merged[mergeIdx++] = arr1[i++];
        while (j < arr2.size())
            merged[mergeIdx++] = arr2[j++];

        return merged;
    }

    /* Find median of two sorted arrays */
    static double median(const std::vector<int> &nums1, const std::vector<int> &nums2) {
        const std::vector<int> merged = mergeArr(nums1, nums2);
        const size_t n = merged.size();

        if (n % 2 == 1) {
            return merged[n / 2];
        }
        return static_cast<double>(merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};

int main() {
    const std::vector<int> nums1 = {1, 2, 2};
    const std::vector<int> nums2 = {3, 4, 4};

    double med = MedianTwoSortedArray::median(nums1, nums2);
    std::cout << "The median is: " << med << std::endl;

    const std::vector<int> nums3 = {1, 2};
    const std::vector<int> nums4 = {3, 4, 5};

    med = MedianTwoSortedArray::median(nums3, nums4);
    std::cout << "The median is: " << med << std::endl;

    return 0;
}
