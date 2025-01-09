#include <iostream>
using namespace std;


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
int main() {
    Solution solution;
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";
    cout << solution.prefixCount(words, pref) << endl;
    return 0;
}
