/**
 * <pre>
 * !0/1 Knapsack Problems
 * You are given N items. Each item has:
 * A weight w[i]
 * A value v[i]
 * You also have a knapsack with a maximum capacity W.
 * You need to choose a subset of items such that:
 * The total weight of selected items does not exceed W
 * The total value is maximized
 * You can either take an item or not (0/1 Knapsack — each item is included at most once)
 *
 * @param Examples:
 * Weights: [1, 3, 4, 5]
 * Values:  [1, 4, 5, 7]
 * Capacity(W): 7
 * !Approach: Recursion
 * Time Complexity: O(2^n) — since every item has two choices (pick or not pick), leading to exponential time.
 * Space Complexity: O(n) — due to recursive call stack depth.
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaximumProfit {
public:
    static int knapsack(const vector<int> &weights, const vector<int> &values, const int W, const int n) {
        if (n == 0 || W == 0) {
            return 0;
        }

        if (weights[n - 1] <= W) {
            return max(
                values[n - 1] + knapsack(weights, values, W - weights[n - 1], n - 1),
                knapsack(weights, values, W, n - 1));
        }
        return knapsack(weights, values, W, n - 1);
    }
};

int main() {
    const vector<int> weight = {1, 3, 4, 5};
    const vector<int> value = {1, 4, 5, 7};
    constexpr int W = 7;
    const int n = weight.size();

    const int max_profit = MaximumProfit::knapsack(weight, value, W, n);
    cout << "Maximum Profit = " << max_profit << endl;

    return 0;
}
