class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k)
            return false;
        int count[26] = {0};
        for (char c : s)
            count[c - 'a']++;
        int countOdd = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0)
                countOdd++;
        }
        return countOdd <= k;
    }
};