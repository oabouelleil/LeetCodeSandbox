#include <iostream>
#include <vector>

using namespace std;

#define RUN_SOLUTION 1

/**
 * Solution 0 - Sum positive gains
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    int maxProfitBetween(vector<int> &prices, int start, int end) {
        int maxDifference = 0;
        int minBuy = INT_MAX;

        for (int i = start; i < end; ++i) {
            minBuy = min(minBuy, prices[i]);
            maxDifference = max(maxDifference, prices[i] - minBuy);
        }

        return maxDifference;
    }

    int maxProfit(vector<int> &prices) {
        int maxDifference = 0;

        for (int i = 0; i <= prices.size(); ++i) {
            maxDifference = max(maxDifference, maxProfitBetween(prices, 0, i) +
                                               maxProfitBetween(prices, i,
                                                                prices.size()));
        }

        return maxDifference;
    }
};

#endif

/**
 * Solution 0 - Sum positive gains
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#if RUN_SOLUTION == 1

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        int minBuy = INT_MAX, maxSell = INT_MIN;
        int maxDiffLeft = 0, maxDiffRight = 0;
        vector<int> prefixDiff(n), suffixDiff(n);

        for (int i = 0; i < n; ++i) {
            minBuy = min(minBuy, prices[i]);
            maxDiffLeft = max(maxDiffLeft, prices[i] - minBuy);
            prefixDiff[i] = maxDiffLeft;

            maxSell = max(maxSell, prices[n-1-i]);
            maxDiffRight = max(maxDiffRight, maxSell - prices[n-1-i]);
            suffixDiff[n-1-i] = maxDiffRight;
        }

        int maxDifference = 0;

        for(int i = 0; i < n-1; ++i) {
            maxDifference = max(maxDifference, prefixDiff[i] + suffixDiff[i+1]);
        }
        maxDifference = max(maxDifference, prefixDiff[n-1]);

        return maxDifference;
    }
};

#endif

int main() {
    Solution sol;
    vector<int> prices;

    // 6
    prices = {3, 3, 5, -1, 0, 3, 1, 4};
    cout << sol.maxProfit(prices) << endl;


    // 4
    prices = {1, 2, 3, 4, 5};
    cout << sol.maxProfit(prices) << endl;

    // 0
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
