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
     * !Approach: Top-Down(Recursive + memoization) ==> Recursive + storage
     *
     * | Metric               | Complexity                                       |
       | -------------------- | ------------------------------------------------ |
       |   Time Complexity    | `O(n * W)`                                       |
       |   Space Complexity   | `O(n * W)` for DP table + `O(n)` recursion stack |
     *
     * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaximumProfitII {
public:
    static vector<vector<int> > dp;

    static int knapsack(const vector<int> &weights, const vector<int> &values, const int W, const int n) {
        if (dp.empty()) {
            dp.assign(n + 1, vector<int>(W + 1, -1));
        }

        if (n == 0 || W == 0) {
            return 0;
        }

        if (dp[n][W] != -1) {
            return dp[n][W];
        }

        if (weights[n - 1] <= W) {
            dp[n][W] = max(
                values[n - 1] + knapsack(weights, values, W - weights[n - 1], n - 1),
                knapsack(weights, values, W, n - 1));
            return dp[n][W];
        }

        dp[n][W] = knapsack(weights, values, W, n - 1);
        return dp[n][W];
    }
};


vector<vector<int> > MaximumProfitII::dp;

int main() {
    const vector<int> weight = {1, 3, 4, 5};
    const vector<int> value = {1, 4, 5, 7};
    constexpr int W = 7;
    const int n = weight.size();

    const int max_profit = MaximumProfitII::knapsack(weight, value, W, n);
    cout << "Maximum Profit = " << max_profit << endl;

    return 0;
}
