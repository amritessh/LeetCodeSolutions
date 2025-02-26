class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //boyer moore voting
        int count = 0;
        int candidate;

        for(int &num: nums){
            if(count == 0){
                candidate = num;
            }

            count += (num == candidate) ? 1:-1;
        }
        
        return candidate;
        //using sorting
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];

        //using maps
        // unordered_map<int,int> mp;
        // for( int num: nums){
        //     if(mp.find(num) == mp.end()){
        //         mp[num] = 1;
        //     }
        //     else{
        //         mp[num]+=1;
        //     }
        // }

        // for(auto entry:mp){
        //     if(entry.second>nums.size()/2) return entry.first;
        // }

        // return 0;
    }
};