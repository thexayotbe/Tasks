class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        vector<bool> isVowel(26, false);

        for (char c: {'a', 'e', 'i', 'o', 'u'}) {
            isVowel[c - 'a'] = true;
        }


        int maxVowels = 0;
        int currentVowels = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel[s[i] - 'a']) {
                currentVowels++;
            }
        }

        maxVowels = currentVowels;

        if (maxVowels == k) return maxVowels;
        for (int i = k; i < n; i++) {
            if (isVowel[s[i-k] - 'a']) {
                currentVowels--;
            }
            if (isVowel[s[i] - 'a']) currentVowels++;

            maxVowels = max(maxVowels, currentVowels);
            if (maxVowels == k) break;
        }
        return maxVowels;
    }
};
