#include <iostream>
using namespace std;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
      unordered_map<int, pair<int,int>> hashmap;
        int n = arr.size();

        int col = mat.size();
        int row = mat[0].size();
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                hashmap[mat[i][j]] = {i,j};
            }
        }

        vector<int> colCount(col, 0);
        vector<int> rowCount(row, 0);

        for(int i = 0; i < n; i++) {
            int value = arr[i];
            auto position = hashmap[value];
            int row = position.first;
            int col = position.second;

            colCount[col]++;
            rowCount[row]++;

            if(colCount[col] == row || rowCount[row] == row) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int > arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
    std::cout <<solution.firstCompleteIndex(arr, mat)  << std::endl;
    return 0;
}
