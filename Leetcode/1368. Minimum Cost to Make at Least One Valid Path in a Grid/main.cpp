#include <iostream>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = 0;
        int col = 0;
        int cut = 0;
        for (int pos = 0; pos < grid.size(); pos++) {
            for (int posInner  = 0; posInner < grid[pos].size(); posInner++) {
                if (grid[pos][posInner] == 1 && col < grid[pos].size()) {
                    col++;
                }
                else if (grid[pos][posInner] == 2 && col > 0) {
                    col--;
                }
                else if (grid[pos][posInner] == 3 && row < grid.size()) {
                    row++;
                }
                else if (grid[pos][posInner] == 4 && row > 0) {
                    row--;
                }
            }
        }
        cout << col << endl;
        cout << row << endl;
    }
};

