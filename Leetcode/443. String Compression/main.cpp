#include <iostream>
using namespace  std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0;
        int charsCount[26] = {0};
        for(char c : chars) {
            charsCount[c-'a']++;
        }
        for(int c : charsCount) {
            if(c == 1) len++;
            else if(c >1 ) len+=2;
        }
    return len;
    }
};

int main() {
    Solution solution;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    std::cout << solution.compress(chars) << std::endl;
    return 0;
}
