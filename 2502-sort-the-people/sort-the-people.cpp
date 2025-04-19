class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> mp; 
        int n = names.size();
        for(int i = 0 ; i < n ; i++){
            mp[heights[i]] = names[i];
        }

        sort(heights.begin(),heights.end());

        vector<string> sorted_names(n);

        for(int i = n - 1; i >= 0 ; i--){
            sorted_names[n - i -1] = mp[heights[i]];
        }

        return sorted_names;


    }
};