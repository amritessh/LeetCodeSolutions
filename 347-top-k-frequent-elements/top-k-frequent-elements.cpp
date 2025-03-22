class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        //store the frequency of the elements
        for(int num: nums){
            mp[num]++;
        }

        //convert the frequency-number map into array
        vector<pair<int,int>> arr;
        for(const auto&p:mp){
            arr.push_back({p.second,p.first});
        }

        //sort this array into descending order because we want to extract top k elements 
        sort(arr.rbegin(),arr.rend());

        //resulting vector
        vector<int> res;


        //just pick the top k elements from the array.
        for(int i = 0; i < k ; i++){
            res.push_back(arr[i].second);
        }

        return res;
    }
};