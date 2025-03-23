class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while(left<right){
            int h = min(height[left],height[right]);
            res = max(res,h*(right-left));
            while(height[left]<=h && left < right) left++;
            while(height[right]<=h && left < right) right--;
        }
        return res;
    }
};