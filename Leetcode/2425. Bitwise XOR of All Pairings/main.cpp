#include <iostream>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
        int xor1 = 0, xor2 = 0;

        for (int num: nums1) {
            xor1 ^= num;
        }
        for (int num: nums2) {
            xor2 ^= num;
        }
        return (nums2.size() % 2 ? xor1 : 0) ^ (nums1.size() % 2 ? xor2 : 0);
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {
        2, 1, 3
    }, nums2 = {
        10, 2, 5, 0
    };
    std::cout << solution.xorAllNums(nums1, nums2) << std::endl;
    return 0;
}
