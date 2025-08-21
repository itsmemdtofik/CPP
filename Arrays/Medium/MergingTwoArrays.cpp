#include <iostream>
#include <vector>


class MergingTwoArray {
public:
    static std::vector<int> mergeArr(const std::vector<int> &arr1, const std::vector<int> &arr2) {
        std::vector<int> merged(arr1.size() + arr2.size());
        int i = 0, j = 0, k = 0;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }

        while (i < arr1.size())
            merged[k++] = arr1[i++];
        while (j < arr2.size())
            merged[k++] = arr2[j++];

        return merged;
    }


    static void runTestCases() {
        struct TestCase {
            std::vector<int> arr1;
            std::vector<int> arr2;
            std::vector<int> expected;
        };

        const std::vector<TestCase> testCases = {
            {{1, 2, 3}, {4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7}},
            {{5, 6, 7}, {1, 2, 3}, {1, 2, 3, 5, 6, 7}},
            {{1}, {}, {1}},
            {{1}, {2}, {1, 2}},
            {{}, {1, 2, 3}, {1, 2, 3}},
            {{4, 5}, {}, {4, 5}},
            {{10}, {20, 30}, {10, 20, 30}},
            {{1, 2, 3}, {4, 5, 6}, {1, 2, 3, 4, 5, 6}},
            {{1, 3}, {2, 4}, {1, 2, 3, 4}},
            {{5, 6}, {7, 8}, {5, 6, 7, 8}}
        };

        int failedTestCount = 0;

        for (size_t i = 0; i < testCases.size(); i++) {
            auto result = mergeArr(testCases[i].arr1, testCases[i].arr2);
            if (result != testCases[i].expected) {
                failedTestCount++;
                std::cout << "Test case " << (i + 1) << " failed:\n";
                std::cout << "arr1: ";
                for (const int x: testCases[i].arr1)
                    std::cout << x << " ";
                std::cout << "\narr2: ";
                for (const int x: testCases[i].arr2)
                    std::cout << x << " ";
                std::cout << "\nExpected: ";
                for (const int x: testCases[i].expected)
                    std::cout << x << " ";
                std::cout << "\nGot: ";
                for (const int x: result)
                    std::cout << x << " ";
                std::cout << "\n-----------------------------\n";
            }
        }

        if (failedTestCount == 0) {
            std::cout << "All test cases passed!\n";
        } else {
            std::cout << "Total failed tests: " << failedTestCount << std::endl;
        }
    }
};

int main() {
    MergingTwoArray::runTestCases();
    return 0;
}
