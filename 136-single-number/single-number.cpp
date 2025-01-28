class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hashTable;
        for(int i = 0; i < nums.size(); i++){
            hashTable[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(hashTable[nums[i]]==1){
                return nums[i];
            }
        }
        return 0;
    }
};