class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longestSequence = 0;
        int left = 0;
        int right = 0;
        int numsZeroes = 0;

        while(right<nums.size()){
            if(nums[right]==0){
                numsZeroes++;
            }

            while(numsZeroes == 2){
                if(nums[left]==0){
                    numsZeroes--;
                }
                left++;
            }

            longestSequence = max(longestSequence, right-left + 1);

            right++;
        }

        return longestSequence;
    }
};