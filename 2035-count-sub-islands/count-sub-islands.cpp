class Solution {
    vector<vector<bool>> visit;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        visit.assign(rows,vector<bool>(cols,false));

        int count = 0 ; 
        for(int i = 0; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid2[i][j] && !visit[i][j]){
                   count += dfs(i,j,grid1,grid2)
;                }
            }
        }
        
        return count;
    }

private:
    bool dfs(int r , int c , vector<vector<int>>&grid1, vector<vector<int>>&grid2){
        if(r<0||c<0||r>=grid1.size()||c>=grid1[0].size()||visit[r][c]||grid2[r][c]==0) {return true;
    }


    visit[r][c] = true;
    bool res = grid1[r][c] == 1;
    res &= dfs(r+1,c,grid1,grid2);
    res &= dfs(r-1,c,grid1,grid2);
    res &= dfs(r,c+1,grid1,grid2);
    res &= dfs(r,c-1,grid1,grid2);

    return res;
}
    
};