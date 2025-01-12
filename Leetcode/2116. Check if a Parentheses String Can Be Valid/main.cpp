#include <iostream>
using namespace std;
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2 != 0 || n != locked.size()) return false;

        int openCount = 0;

        for(int i = 0; i < n; ++i) {
            if(locked[i] =='0' && s[i] == '(') {
                openCount++;
            }
            else openCount--;

            if(openCount < 0) return false;
        }

        openCount = 0;

        for(int i = n-1; i >= 0; --i) {
            if(locked[i] =='0' && s[i] == ')') {
                openCount++;
            }
            else openCount--;

            if(openCount < 0) return false;
        }
        return true;
    }
};


int main() {
    Solution solution;
    string s = "((()(()()))()((()()))))()((()(()";
    string locked = "10111100100101001110100010001001";
    std::cout << solution.canBeValid(s, locked)<< std::endl;
    return 0;
}
