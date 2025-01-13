#include <iostream>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int result = 0;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                result++;
                left++;
                right--;
            } else if (sum > k) right--;
            else left++;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4};
    int k = 2;
    Solution s;
    std::cout << s.maxOperations(nums, k) << std::endl;
    return 0;
}
