/**
 * <pre>
 * !Snow Pack or Trapping rain water.
 *
 * Given an array of non-negative integers representing the elevations from the
 * vertical cross-section of the range of hills, determine how many units of
 * snow could be captured between the hills.
 *
 * For example: ({0, 1, 3}, {0, 1, 2},{0, 4, 2},{0, 3, 0})
 * Implement: Find the amount of snow that could be captured.
 * </pre>
 */

#include <iostream>
#include <vector>
using namespace std;

class SnowPack {
public:
    static int computeSnowpack(const vector<int> &arr) {
        if (arr.size() < 3)
            return 0; /* Less than 3 elements can't trap snow */

        int left = 0;
        int right = arr.size() - 1;
        int leftMax = 0, rightMax = 0;
        int snow = 0;

        while (left < right) {
            if (arr[left] < arr[right]) {
                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    snow += leftMax - arr[left];
                }
                left++;
            } else {
                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    snow += rightMax - arr[right];
                }
                right--;
            }
        }

        return snow;
    }
};

int main() {
    vector<int> elevations = {0, 1, 3, 0, 1, 2, 0, 4, 2, 0, 3, 0};
    cout << "Snow captured: " << SnowPack::computeSnowpack(elevations) << " units" << endl;

    return 0;
}
