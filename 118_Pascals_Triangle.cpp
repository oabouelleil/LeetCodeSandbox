#include "LCIncludes.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Build row by row
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 *
 * @note Easy way to understand complexity of this
 *       is that it's a triangle, so half a n*n square
 *       so 0.5n^2, O(n^2)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        // Create base pascal triangle with 1s on the sides
        for (int i = 0; i < numRows; ++i) {
            pascal[i].resize(i + 1);
            pascal[i][0] = 1;
            pascal[i][i] = 1;
        }

        // Calculate
        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        return pascal;
    }
};

#endif

void printPascal(const vector<vector<int>> &pascal) {
    const size_t n = pascal.size();
    for (size_t i = 0; i < n; ++i) {
        // Padding
        for (size_t j = i; j < n; ++j) cout << " ";


        for (size_t j = 0; j < i + 1; ++j) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<vector<int>> pascal;

    /**     1
     *     1 1
     *    1 2 1
     *   1 3 3 1
     *  1 4 6 4 1
     */

    printPascal(sol.generate(5));

    // 1
    printPascal(sol.generate(1));

    return 0;
}
