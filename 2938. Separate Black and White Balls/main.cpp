#include <string>

class Solution {
public:
    long long minimumSteps(std::string s) {
        long long int count_zero = 0;
        long long int total_swaps = 0;
        for(int i = s.size()-1; i >=0 ; i--){
            if(s[i]=='0') count_zero++;
            else if (s[i]=='1') total_swaps+= count_zero;
        }
        return total_swaps;
    }
};
