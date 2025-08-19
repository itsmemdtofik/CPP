#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Interval {
    int startTime;
    int endTime;
    int price;

public:
    Interval(const int s, const int e, const int p) {
        startTime = s;
        endTime = e;
        price = p;
    }

    int getStart() const { return startTime; }
    int getEnd() const { return endTime; }
    int getPrice() const { return price; }

    void setStart(const int s) { startTime = s; }
    void setEnd(const int e) { endTime = e; }
    void setPrice(const int p) { price = p; }

    string toString() const {
        return "Start: '" + to_string(startTime) +
               "', End: '" + to_string(endTime) +
               "' Price: '" + to_string(price) + "'";
    }
};

vector<Interval> getMinimumPriceIntervals(const vector<Interval> &priceIntervals) {
    vector<Interval> result;
    map<int, int> mp;

    for (auto &interval: priceIntervals) {
        int currentPrice = interval.getPrice();
        for (int i = interval.getStart(); i < interval.getEnd(); i++) {
            if (mp.find(i) != mp.end()) {
                int currentValue = mp[i];
                mp[i] = min(currentValue, currentPrice);
            } else {
                mp[i] = currentPrice;
            }
        }
    }

    for (auto &entry: mp) {
        if (!result.empty()) {
            Interval &latestItem = result.back();
            if (latestItem.getPrice() != entry.second) {
                latestItem.setEnd(entry.first);
                result.emplace_back(entry.first, entry.first + 1, entry.second);
            } else {
                latestItem.setEnd(entry.first + 1);
            }
        } else {
            result.emplace_back(entry.first, entry.first + 1, entry.second);
        }
    }

    return result;
}

int main() {
    const vector<Interval> intervals = {
        Interval(0, 4, 5),
        Interval(2, 8, 3),
        Interval(7, 11, 10)
    };

    const vector<Interval> result = getMinimumPriceIntervals(intervals);
    for (auto &iv: result) {
        cout << iv.toString() << endl;
    }

    return 0;
}
