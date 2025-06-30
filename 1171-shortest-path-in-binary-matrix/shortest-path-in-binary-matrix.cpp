class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();

        //check if the source and destination itself are blocked then there is no path betweej them, if so return default -1
        if(grid[0][0]==1 || grid[N-1][N-1]) return -1;

        //since question says we can move 8 directionally which means we can move left right and diagonally as well to find the path, so here we are defining all the 8 directions

        vector<pair<int,int>> directions = {{0,0},{1,0},{0,1},{1,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};

        vector<vector<bool>> visit(N,vector<bool>(N,false));

        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        visit[0][0] = true;

        while(!q.empty()){
            auto[r,c,length] = q.front();
            q.pop();

            if(r == N-1 && c == N-1) return length;

            for(auto [dr,dc]: directions){
                int nr = r+dr, nc = c+dc;
                if(nr>=0 && nc>=0 && nr<N && nc<N && grid[nr][nc]==0 && !visit[nr][nc]){
                    q.push({nr,nc,length+1});
                    visit[nr][nc] = true;

                }
            }
        }
    return -1;
    }
};