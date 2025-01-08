class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        int maximum = *max_element(candies.begin(), candies.end());
        for(int i = 0; i< candies.size(); i++) {
            result.at(i) = candies[i]+extraCandies >= maximum;
        }
       return result;
    }
};

