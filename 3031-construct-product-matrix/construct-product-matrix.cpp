class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        vector<vector<int>> p(grid.size(),vector<int>(grid[0].size()));

        long long suffix = 1;
        for(int i = grid.size()-1 ; i >= 0 ; i--){
            for(int j = grid[0].size()-1 ; j >=0 ; j--){
                p[i][j] = suffix;
                suffix = suffix * grid[i][j]%MOD;
            }
        }

        long long prefix = 1;
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                p[i][j] = p[i][j] * prefix % MOD;
                prefix = prefix * grid[i][j] % MOD;
            }
        }

        return p;
    }
};