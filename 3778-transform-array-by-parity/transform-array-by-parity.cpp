class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]%2==0) res.push_back(0);
            else res.push_back(1);
        }
        sort(res.begin(),res.end());
        return res;
    }
};