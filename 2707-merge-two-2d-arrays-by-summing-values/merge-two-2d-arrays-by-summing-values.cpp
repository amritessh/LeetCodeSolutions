class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // map<int,int> keyToSum;

        // for(auto nums:nums1){
        //     keyToSum[nums[0]] = nums[1];
        // }


        // for(auto nums:nums2){
        //     keyToSum[nums[0]] += nums[1];
        // }


        // vector<vector<int>> mergedArray;
        // for(auto it:keyToSum){
        //     mergedArray.push_back({it.first,it.second});
        // }

        // return mergedArray;

        int N1 = nums1.size();
        int N2 = nums2.size();

        int ptr1 = 0;
        int ptr2 = 0;

        vector<vector<int>> mergedArray;
        while(ptr1 < N1 && ptr2 < N2){
            if(nums1[ptr1][0] == nums2[ptr2][0]){
                mergedArray.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            }
            else if(nums1[ptr1][0]<nums2[ptr2][0]){
                mergedArray.push_back(nums1[ptr1]);
                ptr1++;
            }
            else{
                mergedArray.push_back(nums2[ptr2]);
                ptr2++;
            }
        }

        while(ptr1 < N1){
            mergedArray.push_back(nums1[ptr1]);
            ptr1++;
        }

        while(ptr2<N2){
            mergedArray.push_back(nums2[ptr2]);
            ptr2++;
        }

        return mergedArray;
    }
};