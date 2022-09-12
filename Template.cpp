#include <iostream>

using namespace std;

#define RUN_SOLUTION 0

/**
 * Solution 0 - Zero Solution
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION==0
class Solution {
public:
    int function() {
        return 0;
    }
};
#endif

/**
 * Solution 1 - One Solution
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION==1
class Solution {
public:
    int function() {
        return 1;
    }
};
#endif

int main() {
    Solution sol;

    std::cout << sol.function() << std::endl;

    return 0;
}
