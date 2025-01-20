
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

      unordered_map<int, pair<int,int>> hashmap;

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hashmap[mat[i][j]] = {i,j};
            }
        }

        vector<int> colCount(n, 0);
        vector<int> rowCount(m, 0);

        for(int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            auto position = hashmap[value];
            int row = position.first;
            int col = position.second;

            colCount[col]++;
            rowCount[row]++;

            if(colCount[col] == m || rowCount[row] == n) {
                return i;
            }
        }
        return -1;
    }
};
