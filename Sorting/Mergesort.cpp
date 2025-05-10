
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class MergeSort
{
public:
    static void conquer(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> mergedArr(high - low + 1);

        /**
         * Now we will start inserting elements into the mergedArr[]
         */

        /**
         * We create two indices index1 and index2
         * index1 will start from the starting index and track the first array
         * index2 will start from (mid + 1) index and track the second array
         */
        int index1 = low;
        int index2 = mid + 1;

        /**
         * To track the merged array we create mergedIndex
         * The mergedIndex will start from zero
         */
        int mergedIndex = 0;

        /**
         * This is for first sub-array = [3, 6, 9] and second sub-array = [2, 5, 8]
         */
        while (index1 <= mid && index2 <= high)
        {
            if (arr[index1] <= arr[index2])
            {
                mergedArr[mergedIndex] = arr[index1];
                mergedIndex++;
                index1++;
            }
            else
            {
                mergedArr[mergedIndex] = arr[index2];
                mergedIndex++;
                index2++;
            }
        }

        /**
         * The above while loop works while comparing both arrays
         * If the first array finishes first and elements remain in the second array
         * Or if the second array finishes first and elements remain in the first array
         * We add two more while loops to handle these cases
         */
        while (index1 <= mid)
        {
            /**
             * This is for first sub-array = [3, 6, 9]
             */
            mergedArr[mergedIndex++] = arr[index1++];
        }

        while (index2 <= high)
        {
            /**
             * This is for second sub-array = [2, 5, 8]
             */
            mergedArr[mergedIndex++] = arr[index2++];
        }

        /**
         * Now we copy the elements of merged array back into the original array
         */
        for (int i = 0, j = low; i < mergedArr.size(); i++, j++)
        {
            arr[j] = mergedArr[i];
        }
    }

    /**
     * Original array example: [6,3,9,5,2,8]
     * Divided into two sub-arrays:
     * First array: [6, 3, 9] -> low to mid
     * Second array: [5, 2, 8] -> mid + 1 to high
     * After sorting individually:
     * First array becomes: [3, 6, 9] -> tracked by index1
     * Second array becomes: [2, 5, 8] -> tracked by index2
     * Merged into new array called mergedArr, tracked by mergedIndex
     */
    static void divideArr(vector<int> &arr, int low, int high)
    {
        /**
         * Calculate mid = low + (high - low) / 2
         * This avoids potential overflow compared to (low + high)/2
         */
        int mid = low + (high - low) / 2;
        if (low >= high)
        { // Base case: subarray has 0 or 1 elements
            return;
        }

        divideArr(arr, low, mid);      // Sort left half
        divideArr(arr, mid + 1, high); // Sort right half
        conquer(arr, low, mid, high);  // Merge sorted halves
    }

    static void runTestCases()
    {
        vector<vector<int>> testCases;

        // Adding complex test cases
        testCases.push_back({});                                   // Empty array
        testCases.push_back({1});                                  // Single element
        testCases.push_back({2, 1});                               // Two elements unsorted
        testCases.push_back({1, 2});                               // Two elements sorted
        testCases.push_back({10, 16, 8, 12, 15, 6, 3, 9, 5, 100}); // Random unsorted array
        testCases.push_back({1, 2, 3, 4, 5, 6, 7, 8});             // Already sorted array
        testCases.push_back({8, 7, 6, 5, 4, 3, 2, 1});             // Reverse sorted array
        testCases.push_back({4, 2, 2, 8, 3, 3, 1});                // Array with duplicates

        // Generating additional complex test cases dynamically
        srand(time(0));
        for (int i = 0; i < 92; i++)
        {
            int size = (rand() % 91) + 10; // Random size between 10 and 100
            vector<int> randomArray(size);
            for (int j = 0; j < size; j++)
            {
                randomArray[j] = (rand() % 1000) - 500; // Random numbers between -500 and 499
            }
            testCases.push_back(randomArray);
        }

        // Running all test cases
        int testCaseNumber = 1;
        for (auto &testCase : testCases)
        {
            cout << "Test Case " << testCaseNumber << ":\n";
            cout << "Input: ";
            printArray(testCase);

            vector<int> sorted = testCase;
            divideArr(sorted, 0, sorted.size() - 1);

            cout << "Output: ";
            printArray(sorted);

            // Validate if the output is sorted
            if (isSorted(sorted))
            {
                cout << "Result: Pass\n\n";
            }
            else
            {
                cout << "Result: Fail\n\n";
            }

            testCaseNumber++;
        }
    }

    static bool isSorted(const vector<int> &arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    static void printArray(const vector<int> &arr)
    {
        cout << "[";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
            if (i < arr.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
};

int main()
{
    MergeSort::runTestCases();
    return 0;
}