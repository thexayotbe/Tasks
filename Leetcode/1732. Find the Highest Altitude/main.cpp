class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> prefixSum(n+1, 0);
        int maxGain = 0;
        for (int i = 1; i < n; i++) {
            int sum = prefixSum[i-1] + gain[i-1];
            maxGain = max(maxGain, sum);
            prefixSum[i] = sum;
        }
        return maxGain;
    }
};
