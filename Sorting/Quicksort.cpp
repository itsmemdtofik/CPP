#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class QuickSortClass {
public:
    static int _f_Partition(vector<int>& arr, int low, int high) {
        int i = low;
        int j = high + 1;
        int pivot = arr[low]; // First element as pivot

        while (i <= j) {
            do {
                i++;
            } while (i <= high && arr[i] <= pivot);

            do {
                j--;
            } while (j >= low && arr[j] > pivot);

            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[j]); // Put pivot in correct place
        return j;
    }

    static void _f_QuickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int j = _f_Partition(arr, low, high);
            _f_QuickSort(arr, low, j - 1);
            _f_QuickSort(arr, j + 1, high);
        }
    }

    static void runTestCases() {
        vector<vector<int>> testCases;

        // Manually added test cases
        testCases.push_back({2, 7, 1, 15, 5, 20, 40});
        testCases.push_back({1});
        testCases.push_back({2, 1});
        testCases.push_back({1, 2});
        testCases.push_back({10, 16, 8, 12, 15, 6, 3, 9, 5, 100});
        testCases.push_back({1, 2, 3, 4, 5, 6, 7, 8});
        testCases.push_back({8, 7, 6, 5, 4, 3, 2, 1});
        testCases.push_back({4, 2, 2, 8, 3, 3, 1});

        // Random test cases
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < 92; i++) {
            int size = rand() % 91 + 10; // Size between 10 and 100
            vector<int> randomArray(size);
            for (int j = 0; j < size; j++) {
                randomArray[j] = rand() % 1000 - 500; // Values between -500 and 499
            }
            testCases.push_back(randomArray);
        }

        bool allTestsPassed = true;

        // Execute test cases
        for (const auto& testCase : testCases) {
            vector<int> sorted = testCase;
            if (!sorted.empty())
                _f_QuickSort(sorted, 0, sorted.size() - 1);

            if (!isSorted(sorted)) {
                allTestsPassed = false;
                cout << "Failed Test Case: ";
                printArray(testCase);
                cout << endl;
            }
        }

        if (allTestsPassed)
            cout << "All test cases passed!" << endl;
        else
            cout << "Some test cases failed." << endl;
    }

    static bool isSorted(const vector<int>& arr) {
        for (size_t i = 0; i + 1 < arr.size(); ++i) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    static void printArray(const vector<int>& arr) {
        cout << "[";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
};

int main() {
    QuickSortClass::runTestCases();
    cout << "\n---------------------------------------------\n";
    return 0;
}
