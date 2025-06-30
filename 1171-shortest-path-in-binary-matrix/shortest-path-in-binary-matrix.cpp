class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();

        //check if the source and destination itself are blocked then there is no path betweej them, if so return default -1
        if(grid[0][0]==1 || grid[N-1][N-1]) return -1;

        //since question says we can move 8 directionally which means we can move left right and diagonally as well to find the path, so here we are defining all the 8 directions

        vector<pair<int,int>> directions = {{0,0},{1,0},{0,1},{1,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};

        //initialising a visit vector matrix
        vector<vector<bool>> visit(N,vector<bool>(N,false));

        //initialising a queue of r,c,path_length to traverse in BFS manner
        queue<tuple<int,int,int>> q;
        //initialise the queue with first cell, 1 as path length
        q.push({0,0,1});
        //mark the first cell as visited
        visit[0][0] = true;

        //while loop to process the input in BFS manner
        while(!q.empty()){
            //process the queue in FIFO manner, pop the element at the front
            auto[r,c,length] = q.front();
            q.pop();

            //check if row and colum have reached the destination, then return the length
            if(r == N-1 && c == N-1) return length;
            
            //otherwise keep traversing in all the directions
            for(auto [dr,dc]: directions){
                //initialise the neighboring row and neighboring column with the current row and coulumn with the directions
                int nr = r+dr, nc = c+dc;

                //checking iff the neighboring row and column are traversable which is within the bounds or the cell is not blocked or the cell is not in the visited vector
                if(nr>=0 && nc>=0 && nr<N && nc<N && grid[nr][nc]==0 && !visit[nr][nc]){    
                    //push the cell to the queue to process it 
                    q.push({nr,nc,length+1});
                    //mark the cell as visited 
                    visit[nr][nc] = true;

                }
            }
        }
        //return -1 if no path found
    return -1;
    }
};