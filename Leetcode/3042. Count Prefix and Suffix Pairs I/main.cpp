class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int counts = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i; j < words.size(); j++) {
                if (j == i) continue;
                if (words[j].starts_with(words[i]) && words[j].ends_with(words[i])) {
                    counts += 1;
                }
            }
        }
        return counts;
    }
};