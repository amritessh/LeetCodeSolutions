class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        // Initialize result matrix and visited tracker
        vector<vector<int>> heights(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;  // {row, col, height}
        
        // 4 directions: right, down, left, up
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // Phase 1: Initialize - Add all water cells as sources
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {  // Water cell found
                    q.push({i, j, 0});     // Water has height 0
                    visited[i][j] = true;   // Mark as visited
                    heights[i][j] = 0;     // Set height to 0
                }
            }
        }
        
        // Phase 2: Multi-source BFS - Spread from all water cells simultaneously
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int row = curr[0], col = curr[1], height = curr[2];
            
            // Explore 4 directions
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                // Check bounds and if not visited
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                    !visited[newRow][newCol]) {
                    
                    visited[newRow][newCol] = true;           // Mark as visited
                    heights[newRow][newCol] = height + 1;     // Assign height
                    q.push({newRow, newCol, height + 1});     // Add to queue
                }
            }
        }
        
        return heights;
    }
};

/*
===============================================================================
                              ALGORITHM EXPLANATION
===============================================================================

PROBLEM: Assign heights to land/water cells such that:
1. Water cells have height 0
2. Adjacent cells differ by at most 1
3. Maximize the overall heights

SOLUTION: Multi-Source BFS
- Start from ALL water cells (height 0) simultaneously
- Spread outward level by level
- Each level = distance from nearest water = optimal height

EXAMPLE WALKTHROUGH:
────────────────────

Input: isWater = [[0,1],    0 = land, 1 = water
                  [0,0]]

Step 1 - Initialize:
Water cells: (0,1) 
Queue: [(0,1,0)]
Heights: [[0,0],     Visited: [[F,T],
          [0,0]]              [F,F]]

Step 2 - BFS Level 1 (height = 1):
Process (0,1,0):
- Check (0,0): valid, unvisited → height = 1
- Check (1,1): valid, unvisited → height = 1

Queue: [(0,0,1), (1,1,1)]
Heights: [[1,0],     Visited: [[T,T],
          [0,1]]              [F,T]]

Step 3 - BFS Level 2 (height = 2):
Process (0,0,1): no unvisited neighbors
Process (1,1,1): 
- Check (1,0): valid, unvisited → height = 2

Queue: [(1,0,2)]
Heights: [[1,0],     Visited: [[T,T],
          [2,1]]              [T,T]]

Step 4 - BFS Level 3:
Process (1,0,2): no unvisited neighbors
Queue empty → Done!

Final Result: [[1,0],
               [2,1]]

Maximum height achieved: 2 ✓

===============================================================================
                              WHY THIS WORKS
===============================================================================

1. OPTIMAL HEIGHTS:
   - Height of any cell = distance to nearest water
   - This maximizes heights while satisfying adjacency constraint

2. MULTI-SOURCE BFS:
   - All water cells start expanding simultaneously  
   - First time we reach a cell = shortest distance from any water
   - Guarantees optimal solution

3. CONSTRAINT SATISFACTION:
   - BFS expands level by level (distance 0, 1, 2, ...)
   - Adjacent cells in consecutive levels differ by exactly 1
   - Satisfies "at most 1" difference requirement

4. TIME/SPACE COMPLEXITY:
   - Time: O(m×n) - each cell visited once
   - Space: O(m×n) - for heights, visited, and queue

===============================================================================
                            PATTERN RECOGNITION
===============================================================================

This is Template 7: Multi-Source BFS from our BFS guide!

KEY CHARACTERISTICS:
✅ Multiple starting points (all water cells)
✅ Distance/value propagation  
✅ "Nearest X" type problem
✅ Level-by-level expansion

SIMILAR PROBLEMS:
- 01 Matrix (distance to nearest 0)
- Rotting Oranges (time for all oranges to rot)
- Walls and Gates (distance to nearest gate)

TEMPLATE PATTERN:
1. Add all sources to queue with initial value
2. BFS expansion with level tracking
3. Update result when adding to queue (not when processing)

===============================================================================
*/