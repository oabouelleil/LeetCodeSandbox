#include "LCUtils/Includes/LCIncludes.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Sum positive gains
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sum = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
            sum += prices[i + 1] - prices[i] > 0 ? prices[i + 1] - prices[i]
                                                 : 0;
        return sum;
    }
};

#endif

int main() {
    Solution sol;
    vector<int> prices;

    // 7
    prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;

    // 4
    prices = {1, 2, 3, 4, 5};
    cout << sol.maxProfit(prices) << endl;

    // 0
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
