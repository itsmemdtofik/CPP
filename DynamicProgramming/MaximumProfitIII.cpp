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
     * !Approach: Bottom-Up(Tabulation) : Only Iterative no recursive call + storage (matrix table)
     * Step1: Create a matrix dp[][]
     * Step2: Initialize it to first rows and first column as zero
     * Step3: Main Logic
     * Step4: Return last rows and column matrix
     *
     * | Metric               | Complexity                                       |
    | -------------------- | ------------------------------------------------ |
    | **Time Complexity**  | `O(n * W)`                                       |
    | **Space Complexity** | `O(n * W)` for DP table + `O(n)` recursion stack |
     *
     * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaximumProfitIII {
public:
    static int knapsack(const vector<int> &weights, const vector<int> &values, const int W, const int n) {
        vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (weights[i - 1] <= j) {
                    dp[i][j] = max(
                        values[i - 1] + dp[i - 1][j - weights[i - 1]],
                        dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
    }
};

int main() {
    const vector<int> weight = {1, 3, 4, 5};
    const vector<int> value = {1, 4, 5, 7};
    constexpr int W = 7;
    const int n = weight.size();

    const int max_profit = MaximumProfitIII::knapsack(weight, value, W, n);
    cout << "Maximum Profit = " << max_profit << endl;

    return 0;
}
