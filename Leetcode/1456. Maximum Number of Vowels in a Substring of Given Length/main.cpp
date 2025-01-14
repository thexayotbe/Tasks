class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int maxVowels = 0;
        int currentVowels = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }

        maxVowels = currentVowels;

        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i-k])) {
                currentVowels--;
            }
            if (isVowel(s[i])) currentVowels++;
            maxVowels = max(maxVowels, currentVowels);
        }
        return maxVowels;
    }
};