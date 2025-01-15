#include <iostream>
using namespace std;
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
int main() {
    Solution solution;
    vector<int> gain = {-5,1,5,0,-7};
    std::cout << solution.largestAltitude(gain) << std::endl;
    return 0;
}
