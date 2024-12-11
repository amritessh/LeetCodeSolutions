class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> expected ;
        
        
        copy(heights.begin(), heights.end(), back_inserter(expected));
        
        sort(heights.begin(),heights.end());
        
        for(int i = 0 ; i < heights.size() ; i++){
            
            if(heights[i]!=expected[i]){
                 count++;
            }
        }
        return count;
    }
};