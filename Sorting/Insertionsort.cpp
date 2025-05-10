#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i, temp, j, n;

    cout << "Enter the size of Item: ";
    cin >> n;

    vector<int> a(n); // Using vector instead of array

    cout << "Enter the number of Items: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Before sorting: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        // Shift elements greater than temp to the right
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }

    cout << "After sorting: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}