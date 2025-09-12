class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
         int large = -1;

        for(auto pair:mp){
            if(pair.second ==1 && pair.first > large){
                large = pair.first;
            }
        }
        return large;
    }
};