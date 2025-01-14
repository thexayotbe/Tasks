#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u'};
        int maxVowels = 0;
        int currentVowels = 0;

        for(int i = 0 ; i < k ; i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                currentVowels++;
            }
        }
        maxVowels = currentVowels;

        for(int i = k; i < n ; i++) {
            if(vowels.find(s[i-k])!= vowels.end()) {
                currentVowels--;
            }
            if(vowels.find(s[i]) != vowels.end()) currentVowels++;

            maxVowels = max(maxVowels, currentVowels);
        }
        return maxVowels;
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    int k = 3;
    std::cout << solution.maxVowels(s, k) << std::endl;
    return 0;
}
