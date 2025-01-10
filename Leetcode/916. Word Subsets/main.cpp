#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    unordered_map<char, int> frequenctCount(const string& s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        return freq;

    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        unordered_map<char, int> maxFreq;
        for (string& b : words2) {
            unordered_map<char, int> freq = frequenctCount(b);
            for (auto& pair : freq) {
                char ch = pair.first;
                int count = pair.second;
                if (maxFreq.find(ch) == maxFreq.end() || maxFreq[ch] < count) {
                    maxFreq[ch] = count;
                }
            }
        }
        vector<string> result;
        for(string& a : words1) {
            unordered_map<char, int> freqA = frequenctCount(a);
            bool isUniversal = true;

            for (auto& pair : maxFreq) {
                char ch = pair.first;
                int requiredCount = pair.second;
                if (freqA.find(ch) == freqA.end() || freqA[ch] < requiredCount) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(a);
            }
        }
        for(string s : result) {
            cout << s << endl;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> word1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> word2 = {"e", "oo"};
    solution.wordSubsets(word1, word2);
    return 0;
}
