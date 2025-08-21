#include <iostream>
#include <vector>
using namespace std;

class ProductOfArrExceptSelfII {
public:
    static vector<int> productArrExceptSelf(vector<int> arr) {
        if (arr.empty())
            return arr;

        int product = 1;
        for (int i = 0; i < arr.size(); i++) {
            product *= arr[i];
        }

        cout << "Product of all elements: " << product << endl;

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = product / arr[i];
        }

        return arr;
    }

    static void printArray(const vector<int> &arr) {
        for (const int num: arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    const vector<int> arr = {1, 2, 3, 4};
    const vector<int> result = ProductOfArrExceptSelfII::productArrExceptSelf(arr);

    cout << "Product Of Array Except Self: ";
    ProductOfArrExceptSelfII::printArray(result);

    return 0;
}
