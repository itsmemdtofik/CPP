/**
 * !Adding one the number represented as a carry of digits.
 *
 * !Approach:
 * Step1: Start from the least significant bit digit(i.g., The last element of an array) and add 1.
 * Step2: If adding 1 to the last element become 10 then set that position to 0
 * and propagate carry. Move this carry 1 to the left element.
 * Step3: If there is no carry, the process stop.
 * Step4: If you reach the most significant digit(the first element) and still have carry, you prepend 1 to array.
 *
 * Example:
 * Input = [1, 2, 4]
 * Output = {1, 2, 5}
 *
 * Input = [9, 9, 9]
 * Output = [1, 0, 0, 0]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> AddOneUsingList(vector<int> nums) {
    if (nums.empty())
        return nums;

    vector<int> result;
    int carry = 1;
    int i = nums.size() - 1;

    while (i >= 0 || carry > 0) {
        int digit = (i >= 0 ? nums[i] : 0) + carry;
        result.insert(result.begin(), digit % 10);
        carry = digit / 10;
        i--;
    }
    return result;
}

int main() {
    cout << "Using the list:" << endl;

    vector<int> ex1 = AddOneUsingList({1, 2, 3});
    for (int x: ex1)
        cout << x << " ";
    cout << endl;

    vector<int> ex2 = AddOneUsingList({9, 9, 9});
    for (int x: ex2)
        cout << x << " ";
    cout << endl;

    vector<int> ex3 = AddOneUsingList({});
    for (int x: ex3)
        cout << x << " ";
    cout << endl;

    return 0;
}
