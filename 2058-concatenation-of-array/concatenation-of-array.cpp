class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            nums.push_back(nums[i]);
        }
        // vector<int> ans(2*n);
        
        // for(int i = 0 ; i < nums.size() ; i++){
        //     ans[i]=nums[i];
        //     ans[i+n]=nums[i];
        // }
        return nums;
    }
};