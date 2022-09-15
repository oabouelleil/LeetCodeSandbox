#include <iostream>
#include <vector>

using namespace std;

#define RUN_SOLUTION 0

/**
 * Solution 0 - Binary Search
 * Time Complexity:     O(log(n))
 * Space Complexity:    O(1)
 */
#if RUN_SOLUTION==0
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int n = (int) nums.size();
        if(n == 1) return nums[0];
        int left = 0, right = n-1, mid;

        while(left <= right) {
            mid = (left + right) / 2;

            // Look for point where value decreases rather than increases
            if(mid && nums[mid] < nums[mid-1]) return nums[mid];

            if(nums[mid] >= nums[left]) {
                // Currently in left array
                if(nums[left] < nums[right]) return nums[left];

                // There is still a left and right array
                left = mid+1;
            } else {
                // Currently in right array
                right = mid-1;
            }
        }
        return -1; // Should never reach here
    }
};
#endif

int main() {
    Solution sol;
    vector<int> nums;

    nums = {3,4,5,1,2};
    cout << sol.findMin(nums) << endl;

    nums = {4,5,6,7,0,1,2};
    cout << sol.findMin(nums) << endl;

    nums = {11,13,15,17};
    cout << sol.findMin(nums) << endl;

    nums = {1};
    cout << sol.findMin(nums) << endl;

    nums = {1,2};
    cout << sol.findMin(nums) << endl;

    return 0;
}
