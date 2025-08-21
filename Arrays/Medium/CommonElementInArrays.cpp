#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void findCommonElements(const vector<int> &arr1, const vector<int> &arr2, const vector<int> &arr3) {
    const unordered_set<int> set1(arr1.begin(), arr1.end());
    const unordered_set<int> set2(arr2.begin(), arr2.end());

    bool found = false;
    cout << "Common elements: ";
    for (int num: arr3) {
        if (set1.count(num) && set2.count(num)) {
            cout << num << " ";
            found = true;
        }
    }
    if (!found)
        cout << "None";
    cout << endl;
}

int main() {
    int m, n, o;

    cout << "Enter the size of first array: ";
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < m; i++)
        cin >> arr1[i];

    cout << "Enter the size of second array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    cout << "Enter the size of third array: ";
    cin >> o;
    vector<int> arr3(o);
    cout << "Enter elements of third array: ";
    for (int i = 0; i < o; i++)
        cin >> arr3[i];

    findCommonElements(arr1, arr2, arr3);

    return 0;
}
