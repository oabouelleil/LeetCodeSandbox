#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define RUN_SOLUTION 0

/**
 * Solution 0 - Sort
 * Time Complexity: O(nlog(n))
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    int maxArea(int h,
                int w,
                vector<int> &horizontalCuts,
                vector<int> &verticalCuts) {
        const size_t hN = horizontalCuts.size();
        const size_t vN = verticalCuts.size();

        /** DISTANCES **/
        int maxHorizontalDistance = INT_MIN;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        maxHorizontalDistance = max(horizontalCuts[0], maxHorizontalDistance);
        for (int i = 1; i < hN; ++i) {
            maxHorizontalDistance = max(
                    horizontalCuts[i] - horizontalCuts[i - 1],
                    maxHorizontalDistance);
        }
        maxHorizontalDistance = max(h - horizontalCuts[hN - 1],
                                    maxHorizontalDistance);

        int maxVerticalDistance = INT_MIN;
        sort(verticalCuts.begin(), verticalCuts.end());
        maxVerticalDistance = max(verticalCuts[0], maxVerticalDistance);
        for (int i = 1; i < vN; ++i) {
            maxVerticalDistance = max(
                    verticalCuts[i] - verticalCuts[i - 1],
                    maxVerticalDistance);
        }
        maxVerticalDistance = max(w - verticalCuts[vN - 1],
                                  maxVerticalDistance);

        /** DO THE MAGIC **/
        const size_t result = (size_t) (maxHorizontalDistance) *
                              (size_t) (maxVerticalDistance);
        return (int) (result % (1000000000 + 7));
    }
};

#endif

int main() {
    Solution sol;

    int h, w;
    vector<int> horizontalCuts, verticalCuts;

    h = 5;
    w = 4;
    horizontalCuts = {1, 2, 4};
    verticalCuts = {1, 3};
    // Output: 4
    cout << sol.maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    h = 5;
    w = 4;
    horizontalCuts = {3, 1};
    verticalCuts = {1};
    // Output: 6
    cout << sol.maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    h = 5;
    w = 4;
    horizontalCuts = {3};
    verticalCuts = {3};
    // Output: 9
    cout << sol.maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    h = 1000000000;
    w = 1000000000;
    horizontalCuts = {2};
    verticalCuts = {2};
    // Output: 81
    cout << sol.maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    return 0;
}
