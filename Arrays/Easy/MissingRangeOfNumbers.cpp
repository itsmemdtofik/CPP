/**
 * <pre>
 * !Missing ranges of numbers.
 *
 * You have an inclusive interval [lower, upper] and a sorted array of unique
 * integers arr[], all of which lie within this interval. A number x is
 * considered missing if x is in the range [lower, upper] but not present in
 * arr. Your task is to return the smallest set of sorted ranges that includes
 * all missing numbers, ensuring no element from arr is within any range, and
 * every missing number is covered exactly once.
 *
 * Examples
 *
 * Input: arr[] = [14, 15, 20, 30, 31, 45], lower = 10, upper = 50
 * Output: [[10, 13], [16, 19], [21, 29], [32, 44], [46, 50]]
 * Explanation: These ranges represent all missing numbers between 10 and 50 not
 * present in the array
 *
 * Input: arr[] = [-48, -10, -6, -4, 0, 4, 17], lower = -54, upper = 17
 * Output: [[-54, -49], [-47, -11], [-9, -7], [-5, -5], [-3, -1], [1, 3],
 * [5,16]]
 * Explanation: These ranges represent all missing numbers between -54 and 17
 * not present in the array.
 * </pre>
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class MissingRangesOfNumber {
    /**
     * * Method to solve this problem.
     *
     * <pre>
     * Step1: Track the current number starting at lower.
     * Step2: For each number in the array, check if the current number is less than it.
     * If yes, we have a gap. Add the missing ranges from current to arr[i] - 1.
     * Then, update current to arr[i] + 1 (since we have handled that number).
     * Step3: Finally, check after the last number in arr[], if there is any gap left to upper.
     * </pre>
     */
public:
    static vector<pair<int, int> > missingRangeNumber(const vector<int> &arr, const int lower, int upper) {
        vector<pair<int, int> > result;

        int temp = lower;
        for (const int num: arr) {
            if (num > temp) {
                result.emplace_back(temp, num - 1);
            }
            temp = num + 1;
        }
        if (temp <= upper) {
            result.emplace_back(temp, upper);
        }

        return result;
    }
};

int main() {
    const vector<int> arr1 = {14, 15, 20, 30, 31, 45};
    constexpr int lower1 = 10;
    constexpr int upper1 = 50;
    vector<pair<int, int> > missing1 = MissingRangesOfNumber::missingRangeNumber(arr1, lower1, upper1);

    cout << "Missing Ranges are:\n";
    for (const auto &range: missing1) {
        cout << "[" << range.first << ", " << range.second << "]\n";
    }
    cout << endl;

    const vector<int> arr2 = {-48, -10, -6, -4, 0, 4, 17};
    constexpr int lower2 = -54;
    constexpr int upper2 = 17;
    const vector<pair<int, int> > missing2 = MissingRangesOfNumber::missingRangeNumber(arr2, lower2, upper2);

    cout << "Missing Ranges are:\n";
    for (const auto &range: missing2) {
        cout << "[" << range.first << ", " << range.second << "]\n";
    }
    cout << endl;

    const vector<int> arr3 = {3, 5, 8};
    constexpr int lower3 = 1;
    constexpr int upper3 = 10;
    const vector<pair<int, int> > missing3 = MissingRangesOfNumber::missingRangeNumber(arr3, lower3, upper3);

    cout << "Missing Ranges:\n";
    for (auto &range: missing3) {
        cout << "[" << range.first << ", " << range.second << "]\n";
    }

    return 0;
}
