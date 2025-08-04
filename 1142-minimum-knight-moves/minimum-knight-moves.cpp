class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        
        // Knight moves
        vector<pair<int, int>> directions = {
            {1, 2}, {2, 1}, {2, -1}, {1, -2},
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
        };
        
        // Use set for visited positions (string key for simplicity)
        unordered_set<string> visited;
        queue<vector<int>> q; // {x, y, steps}
        
        q.push({0, 0, 0});
        visited.insert("0,0");
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int currX = curr[0], currY = curr[1], steps = curr[2];
            
            if (currX == x && currY == y) {
                return steps;
            }
            
            for (auto& dir : directions) {
                int nx = currX + dir.first;
                int ny = currY + dir.second;
                
                string key = to_string(nx) + "," + to_string(ny);
                
                // KEY OPTIMIZATION 2: Bound the search space
                // Don't explore positions that are too far from target
                if (nx >= -2 && ny >= -2 &&  // Don't go too negative
                    nx <= x + 2 && ny <= y + 2 &&  // Don't go too far past target  
                    visited.find(key) == visited.end()) {
                    
                    visited.insert(key);
                    q.push({nx, ny, steps + 1});
                }
            }
        }
        
        return -1;
    }
};