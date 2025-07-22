class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                    DFS(grid, i, j);  // Mark border-connected land as escapable
                }
            }
        }


        int enclaveCount = 0;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 1) {  // Unmarked land = enclave
                    enclaveCount++;
                }
                // Note: We don't restore 'E' back to '1' since we only need count
            }
        }
        
        return enclaveCount;
    }


private:
    int ROWS, COLS;
    
    // DFS to mark all boundary-connected land cells as escapable
    void DFS(vector<vector<int>>& grid, int i, int j) {
        // Only process land cells (1)
        if(grid[i][j] != 1) return;
        
        // Mark current land cell as escapable (can reach boundary)
        grid[i][j] = 2;  // Using 2 instead of 'E' for integer grid
        
        // Explore all 4 directions with bounds checking
        if(j < COLS-1) DFS(grid, i, j+1);    // Right
        if(i < ROWS-1) DFS(grid, i+1, j);    // Down
        if(j > 0) DFS(grid, i, j-1);         // Left
        if(i > 0) DFS(grid, i-1, j);         // Up
    }
};