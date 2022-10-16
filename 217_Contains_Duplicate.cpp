#include "LCUtils/Includes/LCIncludes.h"
#include "LCUtils/Includes/LCUtils.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Hash Set
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> visited;
        for (const auto &num: nums) {
            if (!visited.insert(num).second) return true;
        }
        return false;
    }
};

#endif

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 2, 3, 1};
    LC::print("Parameter 1: ", nums);
    LC::print("Solution", sol.containsDuplicate(nums));

    nums = {1, 2, 3, 4};
    LC::print("Parameter 1: ", nums);
    LC::print("Solution", sol.containsDuplicate(nums));

    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    LC::print("Parameter 1: ", nums);
    LC::print("Solution", sol.containsDuplicate(nums));

    return 0;
}
