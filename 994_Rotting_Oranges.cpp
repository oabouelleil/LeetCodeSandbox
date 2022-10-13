#include "LCUtils/Includes/LCIncludes.h"

#define RUN_SOLUTION 1

/**
 * Solution 0 - Basic loop through all
 * Time Complexity: O((n*m)^2)
 * Space Complexity: O(n*m)
 */
#if RUN_SOLUTION == 0

// Hash function
struct hash2D {
    size_t operator()(const pair<size_t, size_t> &x) const {
        return x.first ^ x.second;
    }
};

class Solution {
public:
    unordered_set<pair<size_t, size_t>, hash2D> healthy;

    bool rotAdjacent(vector<vector<int>> &grid, int minute) {
        size_t m = grid.size(), n = grid[0].size();
        bool result = false;

        healthy.clear();

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                // Empty Cell
                if (grid[i][j] == 0) continue;

                // Fresh or just rotted this minute
                if (grid[i][j] == 1 || grid[i][j] == minute + 3) {
                    healthy.insert(pair<size_t, size_t>(i, j));
                    continue;
                }

                // Rotten, rot all adjacent ones
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = minute + 3;
                    result = true;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = minute + 3;
                    result = true;
                }
                if (i < m - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = minute + 3;
                    result = true;
                }
                if (j < n - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = minute + 3;
                    result = true;
                }
            }
        }
        return result;
    }

    int orangesRotting(vector<vector<int>> &grid) {
        int minute = 0;
        while (rotAdjacent(grid, minute++));
        return healthy.empty() ? minute - 1 : -1;
    }
};

#endif

/**
 * Solution 1 - BFS
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 */
#if RUN_SOLUTION == 1

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        size_t m = grid.size(), n = grid[0].size();
        queue<pair<size_t, size_t>> rotten, currentRotten;
        size_t freshCount = 0;
        int minute = 0;

        // Count fresh oranges and rotten to queue to start BFS
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ++freshCount;
                if (grid[i][j] == 2) rotten.emplace(make_pair(i, j));
            }
        }

        // BFS, freshCount > 0 is probably
        while (!rotten.empty() && freshCount > 0) {
            rotten.swap(currentRotten);

            while (!currentRotten.empty()) {
                auto &rottenOrange = currentRotten.front();
                size_t i = rottenOrange.first, j = rottenOrange.second;

                if (i > 0 && grid[i - 1][j] == 1) {
                    --freshCount;
                    grid[i - 1][j] = 2;
                    rotten.emplace(make_pair(i - 1, j));
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    --freshCount;
                    grid[i][j - 1] = 2;
                    rotten.emplace(make_pair(i, j - 1));
                }
                if (i < m - 1 && grid[i + 1][j] == 1) {
                    --freshCount;
                    grid[i + 1][j] = 2;
                    rotten.emplace(make_pair(i + 1, j));
                }
                if (j < n - 1 && grid[i][j + 1] == 1) {
                    --freshCount;
                    grid[i][j + 1] = 2;
                    rotten.emplace(make_pair(i, j + 1));
                }
                currentRotten.pop();
            }
            ++minute;
        }

        return freshCount ? -1 : minute;
    }
};

#endif

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // 4
    grid = {{2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}};
    cout << sol.orangesRotting(grid) << endl;

    // 2
    grid = {{2, 1, 1},
            {1, 1, 0},
            {0, 1, 2}};
    cout << sol.orangesRotting(grid) << endl;

    // -1
    grid = {{2, 1, 1},
            {0, 1, 1},
            {1, 0, 1}};
    cout << sol.orangesRotting(grid) << endl;

    // 0
    grid = {{0, 2}};
    cout << sol.orangesRotting(grid) << endl;

    return 0;
}
