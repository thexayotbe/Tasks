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
