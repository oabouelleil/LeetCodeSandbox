#include "LCUtils/Includes/LCIncludes.h"
#include "LCUtils/Includes/LCUtils.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Counting Sort
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    void sortColors(vector<int> &nums) {
        array<size_t, 3> count{};
        for (const auto &num: nums) {
            ++count[num];
        }

        size_t j = 0;
        for (size_t i = 0; i < count.size(); ++i) {
            while (count[i]-- > 0) {
                nums[j++] = static_cast<int>(i);
            }
        }
    }
};

#endif

int main() {
    Solution sol;
    vector<int> nums;

    nums = {2, 0, 2, 1, 1, 0};
    LC::print("Example 1");
    LC::print("nums:   ", nums);
    sol.sortColors(nums);
    LC::print("Solution", nums);

    nums = {2, 0, 1};
    LC::print("Example 2");
    LC::print("nums:   ", nums);
    sol.sortColors(nums);
    LC::print("Solution", nums);

    return 0;
}
