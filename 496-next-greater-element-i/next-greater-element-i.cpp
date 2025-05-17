class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge; //number -> nge
        stack<int> stk;

        for(int num:nums2){
            while(!stk.empty() && num>stk.top()){
                nge[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> result;

        for(int num:nums1){
            result.push_back(nge.count(num)? nge[num]:-1);
        }

        return result;

    }
};