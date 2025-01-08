#include <iostream>
using namespace std;
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int counts = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i; j<words.size(); j++) {
                if(words[j].starts_with(words[i]) && words[j].ends_with(words[i])) {
                    counts += 1;
                }
            }
        }
        return counts;
    }

};

int main() {
    vector<string> words = {"a","aba","ababa","aa"};
    Solution solution;
    cout << solution.countPrefixSuffixPairs(words) << endl;
    return 0;
}
