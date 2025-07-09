class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans =0;
        for(int i =0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){ 
                    ans+=4; 
if(i+1<grid.size() && grid[i+1][j]==1)ans--;//if down neighbour is there
if(i-1>=0 && grid[i-1][j]==1)ans--; // if upward neighbour is there
if(j-1>=0 && grid[i][j-1]==1)ans--;// if left neighbour is there
if(j+1<grid[0].size() && grid[i][j+1]==1)ans--;//if right neighbour is there
                }
            }
        }
        return ans;
    }
};
