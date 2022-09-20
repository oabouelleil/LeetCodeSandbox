#include "LCIncludes.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Min Buy
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minBuy = INT_MAX;
        int maxDifference = 0;

        for (const auto &price: prices) {
            minBuy = min(minBuy, price);
            maxDifference = max(maxDifference, price - minBuy);
        }

        return maxDifference;
    }
};

#endif

int main() {
    Solution sol;
    vector<int> prices;

    // 5
    prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;

    // 0
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
