#include <iostream>
#include <vector>

class MergeSortedArrInPlace {
public:
    static void merge(std::vector<int> &nums1, const int m, const std::vector<int> &nums2, const int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }


    static void runTestCases() {
        struct TestCase {
            std::vector<int> nums1;
            int m;
            std::vector<int> nums2;
            int n;
            std::vector<int> expected;
        };

        const std::vector<TestCase> testCases = {
            {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
            {{1}, 1, {}, 0, {1}},
            {{0}, 0, {1}, 1, {1}},
            {{2, 0}, 1, {1}, 1, {1, 2}},
            {{4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, {1, 2, 3, 4, 5, 6}}
        };

        for (size_t idx = 0; idx < testCases.size(); ++idx) {
            TestCase t = testCases[idx];
            std::vector<int> original = t.nums1;

            merge(t.nums1, t.m, t.nums2, t.n);

            std::cout << "Test case " << idx + 1 << ":\n";
            std::cout << "nums1: ";
            for (const int x: original)
                std::cout << x << " ";
            std::cout << " (m=" << t.m << ")\n";

            std::cout << "nums2: ";
            for (const int x: t.nums2)
                std::cout << x << " ";
            std::cout << "\nResult: ";
            for (const int x: t.nums1)
                std::cout << x << " ";
            std::cout << "\nExpected: ";
            for (const int x: t.expected)
                std::cout << x << " ";

            std::cout << (t.nums1 == t.expected ? "\nPASS ✓" : "\nFAIL ✗") << "\n\n";
        }
    }
};

int main() {
    MergeSortedArrInPlace::runTestCases();
    return 0;
}
