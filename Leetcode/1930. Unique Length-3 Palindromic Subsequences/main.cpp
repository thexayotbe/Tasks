#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Step 1: Store indices of each character
        unordered_map<char, vector<int>> charIndices;
        for (int i = 0; i < s.length(); ++i) {
            charIndices[s[i]].push_back(i);
        }

        // Step 2: Find unique palindromic subsequences
        unordered_set<string> uniquePalindromes; // To store unique palindromes

        for (char x = 'a'; x <= 'z'; ++x) {
            if (charIndices.count(x) == 0) continue; // Skip characters not in the string

            const vector<int>& indices = charIndices[x]; // Get indices of character x
            int n = indices.size();

            // Iterate through all pairs of indices (i, j) where i < j
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    // Step 2.1: Collect middle characters
                    unordered_set<char> middleChars;
                    for (int k = indices[i] + 1; k < indices[j]; ++k) {
                        middleChars.insert(s[k]);
                    }

                    // Step 2.2: Add palindromes to the set
                    for (char y : middleChars) {
                        string palindrome = string(1, x) + y + x; // Form "x_yx"
                        uniquePalindromes.insert(palindrome);
                    }
                }
            }
        }

        // Step 3: Return the count of unique palindromes
        return uniquePalindromes.size();
    }

};

int main() {
    Solution solution;
    cout << solution.countPalindromicSubsequence("aabca") << endl;
    return 0;
}
