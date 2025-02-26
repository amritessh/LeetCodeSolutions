class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for( int num: nums){
            if(mp.find(num) == mp.end()){
                mp[num] = 1;
            }
            else{
                mp[num]+=1;
            }
        }

        for(auto entry:mp){
            if(entry.second>nums.size()/2) return entry.first;
        }

        return 0;
    }
};