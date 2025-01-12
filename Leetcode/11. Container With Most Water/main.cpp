#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int front = 0;
        int back = n-1;
        int areaMax = 0;
        while (front < back) {
            int area = min(height[front], height[back]) * (back - front);
            areaMax = max(areaMax, area);
            if(height[front] < height[back]) {
                front++;
            }
            else  back--;
        }
        return areaMax;
    }
};


int main() {
    Solution s;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    std::cout << s.maxArea(v) << std::endl;
    return 0;
}
