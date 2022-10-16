#include "LCUtils/Includes/LCIncludes.h"
#include "LCUtils/Includes/LCUtils.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Unordered Map
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> previous;
        for (int i = 0; i < nums.size(); ++i) {
            if (previous.count(nums[i])) return {previous[nums[i]], i};
            previous[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};

#endif

int main() {
    Solution sol;
    vector<int> nums;
    int target;

    nums = {2, 7, 11, 15};
    target = 9;
    LC::print("Nums: ", nums, "Target: ", target);
    LC::print("Solution", sol.twoSum(nums, target));

    nums = {3, 2, 4};
    target = 6;
    LC::print("Nums: ", nums, "Target: ", target);
    LC::print("Solution", sol.twoSum(nums, target));

    nums = {3, 3};
    target = 6;
    LC::print("Nums: ", nums, "Target: ", target);
    LC::print("Solution", sol.twoSum(nums, target));

    nums = {-1, -2, -3, -4, -5};
    target = -8;
    LC::print("Nums: ", nums, "Target: ", target);
    LC::print("Solution", sol.twoSum(nums, target));

    return 0;
}
