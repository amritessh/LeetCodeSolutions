class Solution {
public:
    int findMin(vector<int>& nums) {
        //if only 1 element, return that element
        if(nums.size() == 1) return nums[0];

        //initializing the start and the end pointers
        int left = 0, right = nums.size()-1;

        //if the last element is greater than the first element then there is no rotation
        if(nums[right]>nums[0]){
            return nums[0];
        }

        //binary search way
        while(right>=left){
            //find the mid element
            int mid = left + (right-left)/2;

            //if mid element is greater than its next element then mid+1 element is the smallest. this point would be the point of change. from higher to lower value
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }

            //if the mid element is lesser than its previous element then mid element is the smallest
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }

            //if the mid element value is greater than its 0th element, this means that the least value is still somewhere to the right as we are still dealing with elements greater than nums[0]
            if(nums[mid]>nums[0]){
                left = mid+1;
            }
            //if nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
            else{
                right = mid-1;
            }
        }
        return -1;
    }
};