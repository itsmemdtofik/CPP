/**
 * ! Stock Buy and Sell – Max one Transaction Allowed.
 * ! Time Complexity : O(n) Space Complexity: O(1)
 *
 * Given an array prices[] of length N, representing the prices of the stocks on
 * different days, the task is to find the maximum profit possible by buying and
 * selling the stocks on different days when at most one transaction is allowed.
 * Here one transaction means 1 buy + 1 Sell.
 *
 * Note: Stock must be bought before being sold.
 *
 * Examples:
 *
 * Input: prices[] = {7, 10, 1, 3, 6, 9, 2}
 * Output: 8
 * Explanation: Buy for price 1 and sell for price 9.
 *
 *
 * Input: prices[] = {7, 6, 4, 3, 1}
 * Output: 0
 * Explanation: Since the array is sorted in decreasing order, 0 profit can be
 * made without making any transaction.
 *
 * Input: prices[] = {1, 3, 6, 9, 11}
 * Output: 10
 * Explanation: Since the array is sorted in increasing order, we can make
 * maximum profit by buying at price[0] and selling at price[n-1]
 *
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class StockBuyAndSell {
public:
    static int stockBuyAndSell(const vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int minPrice = INT_MAX;
        int maxProfit = 0; /* No profit for now */

        for (int price: prices) {
            minPrice = min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

int main() {
    const vector<int> prices1 = {7, 1, 0, 5, 3, 6, 4};
    const vector<int> prices2 = {7, 6, 4, 3, 1};
    const vector<int> prices3 = {1, 2, 1, 3, 4, 5};
    const vector<int> prices4 = {10, 22, 5, 75, 65, 80};

    cout << "Max Profit for prices1: " << StockBuyAndSell::stockBuyAndSell(prices1) << endl;
    cout << "Max Profit for prices2: " << StockBuyAndSell::stockBuyAndSell(prices2) << endl;
    cout << "Max Profit for prices3: " << StockBuyAndSell::stockBuyAndSell(prices3) << endl;
    cout << "Max Profit for prices4: " << StockBuyAndSell::stockBuyAndSell(prices4) << endl;

    return 0;
}
