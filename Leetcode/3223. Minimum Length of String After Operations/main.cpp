#include <iostream>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int chars[26] = {0};
        for(char ch : s) {
            chars[ch - 'a']++;
        }
        int len = 0;

       for(int i = 0; i < 26; i++) {
           if(chars[i] %2 == 1 ) {
               chars[i] = 1;
           }
           else if(chars[i] %2 == 0 && chars[i] > 2 ) {
               chars[i] = 2;
           }
           len+=chars[i];
       }
        return len;
    }
};

int main() {
    Solution solution;
    string s = "ucvbutgkohgbcobqeyqwppbxqoynxeuuzouyvmydfhrprdbuzwqebwuiejoxsxdhbmuaiscalnteocghnlisxxawxgcjloevrdcj";
    std::cout << solution.minimumLength(s) << std::endl;
    return 0;
}
