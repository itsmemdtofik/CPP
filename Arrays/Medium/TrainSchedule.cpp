/**
 * <pre>
 * ! Train Schedule : Two Pointer + TreeMap Approach
 * Given arrival and departure times of trains, determine the minimum number of platforms needed so no trains waits.
 * Arrival = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
 * Departure = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
 * Output = 3
 * Explanation: Max 3 trains are at the station at the same time between 9:40 and 12:00
 * When a train arrives → we need one more platform (+1)
 * When a train departs → we can free one platform (-1)
 * We store these changes using a TreeMap, which keeps time sorted automatically.
 * 900  → +1
 * 910  → -1
 * 940  → +1
 * 950  → +1
 * 1100 → +1
 * 1120 → -1
 * 1130 → -1
 * 1200 → -1
 * 1500 → +1
 * 1800 → +1
 * 1900 → -1
 * 2000 → -1
 * Processed chronologically, the algorithm finds the peak overlap = 3 platforms.
 * </pre>
 *
 * @param arr
 * @param dept
 * @return
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class TrainSchedule {
public:
    static int findPlatformUsingTwoPointer(const vector<int> &arr, const vector<int> &dept) {
        vector<int> arrival = arr;
        vector<int> departure = dept;

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int platform = 1;
        int maxPlatform = 1;
        int i = 1, j = 0;

        while (i < arrival.size() && j < departure.size()) {
            if (arrival[i] <= departure[j]) {
                platform++;
                i++;
            } else {
                platform--;
                j++;
            }
            maxPlatform = max(maxPlatform, platform);
        }

        return maxPlatform;
    }

    /* Map-based approach (TreeMap equivalent) */
    static int findMaxPlatformUsingHashMap(const vector<int> &arrival, const vector<int> &departure) {
        map<int, int> m;
        for (int num: arrival) {
            m[num] += 1;
        }
        for (int num: departure) {
            m[num] -= 1;
        }

        int platform = 0;
        int maxPlatform = 0;

        for (const auto &entry: m) {
            platform += entry.second;
            maxPlatform = max(maxPlatform, platform);
        }

        return maxPlatform;
    }
};

int main() {
    const vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    const vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << TrainSchedule::findPlatformUsingTwoPointer(arrival, departure) << endl;
    return 0;
}
