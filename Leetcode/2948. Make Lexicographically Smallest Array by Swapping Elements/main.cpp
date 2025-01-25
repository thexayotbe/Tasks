#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        for(int i : nums) {
            cout << i << " ";
        }
        return nums;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,5,3,9,8};
    int  limit = 2;
    vector<int> result = sol.lexicographicallySmallestArray(nums, limit);
    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}