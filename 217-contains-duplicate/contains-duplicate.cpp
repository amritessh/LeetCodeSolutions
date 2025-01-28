class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0 ; i < nums.size(); i++){
            if(hashSet.contains(nums[i])) return true;
            hashSet.insert(nums[i]);
        }
        return false;
    }
};