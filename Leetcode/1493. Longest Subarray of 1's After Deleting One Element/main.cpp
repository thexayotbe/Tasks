#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
       int n = nums.size();
        int left = 0;
        int maxLen = 0;
        int zeros = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++;
            }

            while(zeros > 1) {
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left);
        }
        if(maxLen == n ) {
            return maxLen -1;
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    std::cout << s.longestSubarray(nums) << std::endl;
    return 0;
}
