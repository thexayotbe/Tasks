class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        short int result = 0;
        for(string word : words) {
            if(word.starts_with(pref)) {
                result ++;
            }
        }
        return result;
    }
};

