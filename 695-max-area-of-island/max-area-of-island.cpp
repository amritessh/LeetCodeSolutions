class Solution {
public:
   int mark_island_area(vector<vector<int>>& grid, int i , int j , int rows, int columns){
       if(i<0 || j<0 || i>=rows || j>=columns || grid[i][j]!=1) return 0;
       
       grid[i][j]=2;
       
       return(1+mark_island_area(grid,i+1,j,rows,columns)+mark_island_area(grid,i-1,j,rows,columns)+mark_island_area(grid,i,j+1,rows,columns)+mark_island_area(grid,i,j-1,rows,columns));
        
       
   }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0 ;
        
        int area = 0;
        int columns = grid[0].size();
          
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j]==1){
                    area = max(area,mark_island_area(grid, i , j , rows, columns));
                }
            }
        }
    return area;
    }
};