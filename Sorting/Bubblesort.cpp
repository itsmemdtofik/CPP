#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BubbleSortOptimization
{
public:
    vector<int> optimizedBubbleSort(vector<int> arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            /**
             * The variable swapped is a boolean flag that tracks whether
             * any elements were swapped during a pass of the inner loop.
             * If no swaps were made during a pass, it means that the array is already sorted,
             * and there is no need to continue iterating through the list.
             */
            bool swapped = false;
            for (int j = 0; j < arr.size() - i - 1; j++)
            {
                /**
                 * Note down that here we are using the > symbol for ascending order.
                 * But if you want this in descending order then you can change this > to <.
                 * If you go for selection sort then you will get the opposite -
                 * > symbol for descending and < for ascending order.
                 */
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped)
            {
                break;
            }
        }
        return arr;
    }
};

int main()
{
    int i, n, count = 0;
    string itemString;

    cout << "Enter the size of items: ";
    cin >> n;

    cout << "Enter the number of items: ";
    vector<string> names(n);
    for (i = 0; i < names.size(); i++)
    {
        cin >> names[i];
    }

    cout << "Printing before sorting: " << endl;
    for (i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }

    cout << "Enter the name to be searched: ";
    cin >> itemString;

    for (i = 0; i < names.size(); i++)
    {
        if (names[i] == itemString)
        {
            count++;
            break;
        }
    }

    if (count > 0)
    {
        cout << "Item is found: " << itemString << "\tAt location: " << i
             << "\tAnd count is: " << count << endl;
    }
    else
    {
        cout << "Item is not present in list!" << endl;
    }

    // Sorting strings using bubble sort
    for (i = 0; i < names.size() - 1; i++)
    {
        for (int j = 0; j < names.size() - i - 1; j++)
        {
            if (names[j].compare(names[j + 1]) > 0)
            {
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    cout << "Printing after sorting: " << endl;
    for (i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }

    // Accessing the array
    vector<int> newArr = {-2, 45, 0, 11, -9};
    BubbleSortOptimization bblSort;

    vector<int> sortedArr = bblSort.optimizedBubbleSort(newArr);

    cout << "Sorted array is: " << endl;
    for (int num : sortedArr)
    {
        cout << num << endl;
    }

    return 0;
}