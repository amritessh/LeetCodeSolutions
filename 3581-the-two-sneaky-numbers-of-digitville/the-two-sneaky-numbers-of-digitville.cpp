class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto& [num,count]:mp){
            if(count>1)  res.push_back(num);
        }
        return res;
    }
};