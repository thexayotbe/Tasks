#include <iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++) {
            if(nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        while(slow < nums.size()) {
            nums[slow] = 0;
            slow++;
        }
        for(int nums : nums) {
            cout << nums << ' ';
        }
    }
};
int main() {
    vector<int>  nums = {0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);

    return 0;
}
