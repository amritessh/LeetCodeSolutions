class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // vector<int> res;
        
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i + 1] ) return i;
        }
        return nums.size()-1;
    }
};