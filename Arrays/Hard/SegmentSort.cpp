#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>

using namespace std;

/* Custom exception for path issue */
class NoPathFoundException final : public runtime_error {
public:
    explicit NoPathFoundException(const string &message) : runtime_error(message) {
    }
};

/* Pair class equivalent */
class Pair {
    int left;
    int right;

public:
    Pair() : left(0), right(0) {
    }

    Pair(const int l, const int r) : left(l), right(r) {
    }

    int getLeft() const { return left; }
    int getRight() const { return right; }

    string toString() const {
        return "(" + to_string(left) + "," + to_string(right) + ")";
    }
};

class SegmentSort {
public:
    static vector<Pair> sortSegment(const vector<Pair> &segments) {
        unordered_map<int, Pair> map; /* maps start -> Pair */
        unordered_set<int> starts;
        unordered_set<int> ends;

        /* Build map and sets */
        for (const auto &p: segments) {
            map[p.getLeft()] = p;
            starts.insert(p.getLeft());
            ends.insert(p.getRight());
        }

        /* Find starting point */
        int startPoint = -1;
        for (int s: starts) {
            if (ends.find(s) == ends.end()) {
                startPoint = s;
                break;
            }
        }

        if (startPoint == -1) {
            throw NoPathFoundException("No continuous path is found!");
        }

        /* Reconstruct the path */
        vector<Pair> sortedSegments;
        auto it = map.find(startPoint);
        while (it != map.end()) {
            sortedSegments.push_back(it->second);
            it = map.find(it->second.getRight());
        }

        return sortedSegments;
    }
};

int main() {
    const vector<Pair> segments = {
        Pair(4, 5),
        Pair(9, 4),
        Pair(5, 1),
        Pair(11, 9)
    };

    try {
        const vector<Pair> sortedSegments = SegmentSort::sortSegment(segments);
        for (const auto &p: sortedSegments) {
            cout << p.toString() << " ";
        }
        cout << endl;
    } catch (const NoPathFoundException &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
