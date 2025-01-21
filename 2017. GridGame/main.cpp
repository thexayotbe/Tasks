class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<long long> prefixTop(n, 0);
        vector<long long> prefixBottom(n, 0);

        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];

        for (int i = 1; i < n; ++i) {
            prefixTop[i] = prefixTop[i - 1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i - 1] + grid[1][i];
        }

        long long result = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long option1 = prefixTop[n - 1] - prefixTop[i];
            long long option2 = (i > 0) ? prefixBottom[i - 1] : 0;
            result = min(result, max(option1, option2));
        }
        return result;
    }
};
