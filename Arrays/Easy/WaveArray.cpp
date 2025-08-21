/**
 * <pre>
 * !Wave Array
 *
 * Sort an array in wave form.
 * Given an unsorted array of integers, sort the array into a wave array. An
 * array arr[0.n-1] is sorted in wave form if:
 * arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
 *
 * Input: arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
 * Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80}
 *
 * Explanation:
 * here you can see {10, 5, 6, 2, 20, 3, 100, 80} first element is larger than
 * the second and the same thing is repeated again and again. large element –
 * small element-large element -small element and so on .it can be small
 * element-larger element – small element-large element -small element too. all
 * you need to maintain is the up-down fashion which represents a wave. there
 * can be multiple answers.
 *
 *
 * Input: arr[] = {20, 10, 8, 6, 4, 2}
 * Output: arr[] = {20, 8, 10, 4, 6, 2}
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm> /* for sort, swap */
using namespace std;

class WaveArray {
public:
    static vector<int> waveArray(vector<int> arr) {
        if (arr.empty())
            return arr;

        sort(arr.begin(), arr.end());

        for (size_t i = 0; i < arr.size() - 1; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
        return arr;
    }


    static vector<int> waveArrUsingList(vector<int> list) {
        if (list.empty())
            return list;

        sort(list.begin(), list.end());

        for (size_t i = 0; i < list.size() - 1; i += 2) {
            swap(list[i], list[i + 1]);
        }
        return list;
    }
};

int main() {
    const vector<int> arr = {10, 5, 6, 3, 2, 20, 100, 80};
    const vector<int> result = WaveArray::waveArray(arr);

    cout << "Wave Array : ";
    for (const int i: result) {
        cout << i << ", ";
    }
    cout << endl;


    cout << "List-based implementation:" << endl;
    const vector<int> list1 = {7, 1, 5, 3, 6, 4};
    const vector<int> list2 = {9, 6, 8, 3, 7};
    const vector<int> list3;

    cout << "Original: ";
    for (const int i: list1)
        cout << i << " ";
    cout << "\nWave sorted: ";
    for (const int i: WaveArray::waveArrUsingList(list1))
        cout << i << " ";
    cout << endl;

    cout << "Original: ";
    for (const int i: list2)
        cout << i << " ";
    cout << "\nWave sorted: ";
    for (const int i: WaveArray::waveArrUsingList(list2))
        cout << i << " ";
    cout << endl;

    cout << "Empty list: ";
    for (const int i: WaveArray::waveArrUsingList(list3))
        cout << i << " ";
    cout << endl;

    return 0;
}
