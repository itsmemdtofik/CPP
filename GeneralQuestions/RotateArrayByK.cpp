#include <iostream>
using namespace std;

// 🔹 Rotate Array Right by k steps
vector<int> rotateRight(vector<int> arr, int k) {
    int n = arr.size();
    if (n == 0) return {}; // Handle empty array

    k = k % n; // Normalize k to be within array bounds
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        result[(i + k) % n] = arr[i];
    }

    return result;
}

// Utility function to print vector
void printVector(const vector<int> &arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3};
    vector<int> arr3 = {};
    vector<int> arr4 = {1};

    cout << "Rotate Right Examples:\n";
    printVector(rotateRight(arr1, 2)); // [4, 5, 1, 2, 3]
    printVector(rotateRight(arr2, 5)); // [2, 3, 1]
    printVector(rotateRight(arr3, 3)); // []
    printVector(rotateRight(arr4, 100)); // [1]

    return 0;
}
