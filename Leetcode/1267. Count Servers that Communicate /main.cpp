#include <iostream>
using namespace std;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> R(m);
        vector<int> C(n);
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                R[j] = grid[i][j];
                C[j] = grid[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && (R[j] > 1 || C[j] > 1) ) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> grid = {{1,0}, {0,1}};
    cout << Solution().countServers(grid) << endl;
    return 0;
}
