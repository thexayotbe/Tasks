class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char nums : s) {
            if (nums == '1')
                totalOnes++;
        }

        int currentZeros = 0;
        int currentOnes = totalOnes;
        int maxScore = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                currentZeros++;
            } else {
                currentOnes--;
            }
            maxScore = max(maxScore, currentZeros + currentOnes);
        }
        return maxScore;
    }
};