#include <iostream>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int> > &grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int> > vis(R, vector<int>(C, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,
            int>>>> pq;
        int vol = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                    pq.push({grid[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
            int minBdHt = 0;
            while (!pq.empty()) {
                int currHt = pq.top().first;
                int r = pq.top().second.first;
                int c = pq.top().second.second;
                minBdHt = max(currHt, minBdHt);
                pq.pop();
                int dr[4] = {0,0, -1,1};
                int dc[4] = {1,-1, 0, 0};
                for (int i = 0; i < 4; i++) {
                    int rr = r+dr[i];
                    int cc = c+dc[i];
                    if(rr>=0 && rr< R && cc>=0 && cc< C && vis[rr][cc]==false) {
                        pq.push({grid[rr][cc], {rr, cc}});
                        vis[rr][cc] = true;
                        if(grid[rr][cc] < minBdHt) {
                            vol += minBdHt - grid[rr][cc];
                        }
                    }
                }
            }
            return vol;
        };
    }
};
    int main() {
        Solution s;
        vector<vector<int> > heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
        std::cout << s.trapRainWater(heightMap) << std::endl;
        return 0;
    }
