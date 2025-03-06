class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // vector<int> ans;
        int n = grid[0].size();
        int missing = -1;
        int repeat = -1;

        unordered_map<int,int> freq;

        for(auto& row:grid){
            for(int num:row){
                freq[num]++;
            }
        }

        for(int num = 1; num<=n*n;num++){
            if(!freq.count(num)){missing = num;}
            else if(freq[num]==2){repeat = num;}
        }
    
    return {repeat,missing};
}
};