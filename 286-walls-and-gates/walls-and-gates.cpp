class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //initiating rows and colums
        int m = rooms.size();
        int n = rooms[0].size();

        //initialising the queue to store the coordinates for BFS
        queue<pair<int,int>> q;

        //storing gate coordinates in the queue
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(rooms[i][j]==0) q.push({i,j});
            }
        }

        //4 possible directions to explore
        //contrary to the cartersian coordinates, up down left right       
        //directions are defined as below
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        //now running the BFS traversal
        while(!q.empty()){
        //start processing the queue
          int row = q.front().first;
          int col = q.front().second;
          q.pop();

        //initiate new coordinates as per the current coordiantes that is the gate, checking all 4 possible directions
          for(int i = 0 ; i < 4 ; i++){
            int r = row + dirs[i][0];
            int c = col + dirs[i][1];

            //checking the validity of the coordinates if r and c are valid or not
            if(r < 0 || r >=m || c < 0 || c >=n || rooms[r][c]!=INT_MAX){
                continue;
            }

            rooms[r][c] = rooms[row][col]+1;
            q.push({r,c});
          }  
        }
    }
};