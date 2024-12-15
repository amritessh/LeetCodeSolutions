class Solution {
    
    private:
    
    void mark_current_islands(vector<vector<char>> &grid, int i , int j, int rows, int columns){
        
        if(i<0 || i>=rows || j<0 || j>=columns || grid[i][j]!='1') return;
        grid[i][j]='2';
    
        mark_current_islands(grid,i+1,j,rows,columns);
        mark_current_islands(grid,i-1,j,rows,columns);
        mark_current_islands(grid,i,j+1,rows,columns);
        mark_current_islands(grid,i,j-1,rows,columns);
    }
    
    
    
    public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        
        int columns = grid[0].size();
        int no_of_islands = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j <columns; j++){
                if(grid[i][j]=='1'){
                    mark_current_islands(grid,i,j,rows,columns);
                    no_of_islands +=1;
                }
            }
        }
        return no_of_islands;
    }
};