class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;

        for(int i : nums1){
            mp[i]=1;
        }

        for(int i : nums2){
            if(mp.find(i)!=mp.end() && mp[i]==1){
                res.push_back(i);
                mp[i] = 0;
            }
        }


        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());

        
        // unordered_set<int> setInter;

        // int pt1=0,pt2=0;

        // while(pt1<nums1.size() && pt2<nums2.size()){
        //     if(nums1[pt1]==nums2[pt2]){
        //         setInter.insert(nums1[pt1]);
        //         pt1++;
        //         pt2++;
        //     }

        //     else if(nums1[pt1]<nums2[pt2]){
        //         pt1++;
        //     }
        //     else{
        //         pt2++;
        //     }
        // }

        // // int k = setInter.size();
        // vector<int> res;

        // int curr = 0;
        // // copy(setInter.begin(), setInter.end(), back_inserter(res));
        // // for(int x = 0; x<setInter.size(); x++){
        // //     res.push_back(x);
        // // }

        // for(int i:setInter){
        //     res.push_back(i);
        // }

        return res;

    }
};