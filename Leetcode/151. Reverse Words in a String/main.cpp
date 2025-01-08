class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> tokens;

        while(ss>>word) {
            tokens.push_back(word);
        }
        string result = "";
        for(int i = tokens.size() - 1; i >= 0; i--) {
            result += tokens[i] + " ";
        }
        result.pop_back();
        return result;
    }
};