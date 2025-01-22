class Solution {
public:
    bool digit(int nums){
        int count = 0;
        while(nums){
            nums = nums/10;
            count++;
        }
        if(count%2==0) return true;
        
        else return false;
    }
    
    
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i<nums.size(); i++){
           if( digit(nums[i])) count++;
        }
        return count;
        
    }
};