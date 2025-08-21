/**
 * <pre>
 * !Count Length Of Cycle: Floyd's Tortoise and Hare algorithm (Cycle-Finding Algorithm)
 * !Time Complexity: O(n), Space Complexity: O(1)
 * Step1: Tortoise (slow) moves 1 step at a time.
 * Step2: Hare (fast) moves 2 steps at a time.
 * Step3: If they meet(slow == fast), a cycle exists.
 * Step4: To find cycle length, freeze fast and move slow until they meet again, counting steps.
 * Step5: Return the cycle length
 * </pre>
 */

#include <iostream>
#include <vector>
using namespace std;


int cycleLength(const vector<int> &arr, const int startIndex) {
    if (arr.empty() || startIndex < 0 || startIndex >= static_cast<int>(arr.size())) {
        return -1;
    }

    int slow = startIndex;
    int fast = startIndex;

    while (fast >= 0 && fast < static_cast<int>(arr.size())) {
        slow = arr[slow];
        fast = arr[fast];

        if (fast < 0 || fast >= static_cast<int>(arr.size())) {
            break;
        }
        fast = arr[fast];

        if (slow == fast) {
            int cycleLen = 0;
            do {
                slow = arr[slow];
                cycleLen++;
            } while (slow != fast);
            return cycleLen;
        }
    }

    return -1;
}

int main() {
    cout << "Expected : 2, 3, 3, 3, 3, -1, -1, -1, -1, -1, 2, 3, 3, 3, 3, -1, -1, -1, -1, -1" << endl;

    cout << cycleLength({1, 0}, 0) << endl; // 2 (0→1→0)
    cout << cycleLength({1, 2, 0}, 0) << endl; // 3 (0→1→2→0)
    cout << cycleLength({1, 2, 3, 1}, 0) << endl; // 3 (0→1→2→3→1)
    cout << cycleLength({1, 2, 3, 4, 2}, 0) << endl; // 3 (0→1→2→3→4→2)
    cout << cycleLength({1, 2, 3, 4, 5, 3}, 0) << endl; // 3 (0→1→2→3→4→5→3)
    cout << cycleLength({1, 2, 3, -1}, 0) << endl; // -1 (0→1→2→3→-1, invalid)
    cout << cycleLength({1, 2, 3, 4}, 0) << endl; // -1 (0→1→2→3→4, out of bounds)
    cout << cycleLength({1, -1, 3, 4}, 0) << endl; // -1 (0→1→-1, invalid)
    cout << cycleLength({1, 2, 3, 5}, 0) << endl; // -1 (0→1→2→3→5, out of bounds)
    cout << cycleLength({1}, 0) << endl; // -1 (0→1, no cycle)
    cout << cycleLength({1, 0}, 1) << endl; // 2 (1→0→1)
    cout << cycleLength({1, 2, 0}, 2) << endl; // 3 (2→0→1→2)
    cout << cycleLength({1, 2, 3, 1}, 3) << endl; // 3 (3→1→2→3)
    cout << cycleLength({1, 2, 3, 4, 2}, 4) << endl; // 3 (4→2→3→4)
    cout << cycleLength({1, 2, 3, 4, 5, 3}, 5) << endl; // 3 (5→3→4→5)

    cout << cycleLength({}, 0) << endl; // -1 (empty array)
    cout << cycleLength({1, 0}, -1) << endl; // -1 (invalid startIndex)
    cout << cycleLength({1, 0}, 2) << endl; // -1 (startIndex out of bounds)
    cout << cycleLength({1, 2, 3, -1}, 3) << endl; // -1 (3→-1, invalid)

    cout << "Using Floyd's Tortoise and Hare : " << cycleLength({1, 0}, 0) << endl; // 2
    cout << "Using Floyd's Tortoise and Hare : " << cycleLength({1, 2, 0}, 0) << endl; // 3
    cout << "Using Floyd's Tortoise and Hare : " << cycleLength({1, 2, 3, 1}, 0) << endl; // 3

    return 0;
}
