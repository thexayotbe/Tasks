#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: right (1), left (2), down (3), up (4)
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Cost matrix to store the minimum cost to reach each cell
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0; // Starting cell has cost 0

        // Min-heap priority queue: {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // Start with the top-left cell

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentCost = current[0];
            int i = current[1];
            int j = current[2];

            // If we reach the bottom-right cell, return the cost
            if (i == m - 1 && j == n - 1) {
                return currentCost;
            }

            // Explore all 4 directions
            for (int dir = 0; dir < 4; dir++) {
                int x = i + directions[dir][0];
                int y = j + directions[dir][1];

                // Check if the new cell is within the grid boundaries
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newCost = currentCost + (grid[i][j] == dir + 1 ? 0 : 1);

                    // If the new cost is smaller, update the cost and push to the heap
                    if (newCost < cost[x][y]) {
                        cost[x][y] = newCost;
                        pq.push({newCost, x, y});
                    }
                }
            }
        }

        // If no path is found, return -1 (though the problem guarantees a solution)
        return -1;
    }
};