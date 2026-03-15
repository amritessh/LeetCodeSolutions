class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> rows(picture.size()),cols(picture[0].size());

        for(int i = 0 ; i < picture.size() ; i++){
            for(int j = 0 ; j < picture[0].size(); j++){
                if(picture[i][j]=='B') rows[i]++, cols[j]++;
            }
        }

        int res = 0;
        for(int i = 0 ; i < picture.size() ; i++){
            for(int j = 0 ; j < picture[0].size(); j++){
                if(picture[i][j]=='B' && rows[i]==1 && cols[j]==1) res++;
            }
        }
        return res;
    }
};