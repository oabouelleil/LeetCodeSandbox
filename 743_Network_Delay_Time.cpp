#include "LCUtils/Includes/LCIncludes.h"
#include "LCUtils/Includes/LCUtils.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - BFS (Dijkstra's?)
 * Time Complexity: O(V + E log V)
 * Space Complexity: O(V + E)
 */
#if RUN_SOLUTION == 0

struct ItemWeight {
    int item;
    int weight;

    ItemWeight(int item, int weight) : item(item), weight(weight) {}
};

class Solution {
private:

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        unordered_map<int, pair<int, vector<ItemWeight>>> nodes;
        queue<ItemWeight> bfs;

        // Add all nodes with edges to map
        for (const auto &edge: times) {
            nodes[edge[0]].second.emplace_back(edge[1], edge[2]);
        }

        // Start from k
        bfs.emplace(k, 0);

        while (!bfs.empty()) {
            const auto &curr = bfs.front();

            // Go through neighbours
            for (auto node: nodes[curr.item].second) {
                // Skip if looped back to first node
                if (node.item == k) continue;

                // Node unvisited or found shorter path
                if (nodes[node.item].first == 0
                    || node.weight + curr.weight < nodes[node.item].first) {
                    // Update to shorter path
                    nodes[node.item].first = node.weight + curr.weight;
                    // Visit again
                    bfs.emplace(node.item, node.weight + curr.weight);
                }
            }
            bfs.pop();
        }

        // If there are not equal, then not all nodes were visited
        if (nodes.size() != n) return -1;

        int time = -1;
        // Find max time, this is the shortest time to visit all
        for (const auto &node: nodes) {
            // Node was not visited for some reason, should have been caught by previous if statement
            if (node.second.first == 0 && node.first != k) return -1;
            time = max(time, node.second.first);
        }
        return time ? time : -1;
    }
};

#endif

int main() {
    Solution sol;
    vector<vector<int>> times;
    int n, k;

    // 2
    n = 4;
    k = 2;
    times = {{2, 1, 1},
             {2, 3, 1},
             {3, 4, 1}};
    LC::print(sol.networkDelayTime(times, n, k));

    // 1
    n = 2;
    k = 1;
    times = {{1, 2, 1}};
    LC::print(sol.networkDelayTime(times, n, k));

    // -1
    n = 2;
    k = 2;
    times = {{1, 2, 1}};
    LC::print(sol.networkDelayTime(times, n, k));

    // -1
    n = 4;
    k = 1;
    times = {{1, 2, 1},
             {2, 3, 7},
             {1, 3, 4},
             {2, 1, 2}};
    LC::print(sol.networkDelayTime(times, n, k));

    return 0;
}
