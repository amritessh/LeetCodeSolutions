class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        int largestFreq = -1;
        for(auto& [num,freq]:mp){
            if(num == freq) largestFreq = max(largestFreq,num);
        }
        return largestFreq;
    }
};