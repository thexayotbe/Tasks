class Solution {
public:
    int waysToSplitArray(vector<int> &nums) {
        int result = 0;
        long long int totalSum = 0, leftSum =  0;
        for(int num : nums) {
            totalSum+=num;
        }
        for(int i = 0; i<nums.size()-1;i++) {
            leftSum += nums[i];
            long long int rightSum = totalSum - leftSum; ;
            if(leftSum >= rightSum) {
                result += 1;
            }

        }
        return result;
    }
};
