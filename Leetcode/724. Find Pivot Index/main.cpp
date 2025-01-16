class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int size = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftTotal = 0;
        for (int i = 0; i < size; i++) {
            int rightTotal = total  - leftTotal - nums[i];
            if(rightTotal == leftTotal) {
                return i;
            }
            leftTotal += nums[i];
        }
        return -1;
    }
};
