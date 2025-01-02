class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Define the set of vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Preprocess: Create a prefix sum array
        vector<int> prefix(words.size() + 1, 0);
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            bool isVowelString = (vowels.find(tolower(str.front())) != vowels.end() &&
                                  vowels.find(tolower(str.back())) != vowels.end());
            prefix[i + 1] = prefix[i] + (isVowelString ? 1 : 0);
        }

        // Process each query
        vector<int> ans(queries.size(), 0);
        for (int queryIndex = 0; queryIndex < queries.size(); queryIndex++) {
            int start = queries[queryIndex][0];
            int end = queries[queryIndex][1];
            ans[queryIndex] = prefix[end + 1] - prefix[start];
        }

        return ans;
    }
};