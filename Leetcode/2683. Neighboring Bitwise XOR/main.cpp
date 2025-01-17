#include <iostream>
using namespace std;
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        for(int first : {0,1}) {
            vector<int> original(n,0);
            original[0] = first;
            for(int i = 0 ;i < n;++i) {
                original[i+1] = derived[i] ^ original[i];
            }
            if(original[n-1] ^ original[0] == derived[n-1]) {
                return true;
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> v = {1,1,0};
    std::cout << s.doesValidArrayExist(v) << std::endl;
    return 0;
}
