class Solution {

private:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return{};

        int numRows = matrix.size();
        int numCols = matrix[0].size();

        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;

        for(int i = 0 ; i < numRows ; i++){
            pacificQueue.push({i,0});
            atlanticQueue.push({i,numCols-1});
        }

        for(int i = 0 ; i < numCols ; i++){
            pacificQueue.push({0,i});
            atlanticQueue.push({numRows-1,i});
        }

        vector<vector<bool>> pacificReachable = bfs(pacificQueue, matrix, numRows, numCols);
        vector<vector<bool>> atlanticReachable = bfs(atlanticQueue, matrix, numRows, numCols);

        vector<vector<int>> commonCells;
        for(int i = 0 ; i < numRows ; i++){
            for(int j = 0 ; j < numCols ; j++){
                if(pacificReachable[i][j] && atlanticReachable[i][j]) commonCells.push_back({i,j});
            }
        }
        return commonCells;
    }

private:
    vector<vector<bool>> bfs(queue<pair<int,int>>& q, vector<vector<int>>& matrix, int numRows, int numCols){
        vector<vector<bool>> reachable(numRows, vector<bool>(numCols,false));

        while(!q.empty()){
            pair<int,int> current = q.front();
            q.pop();

            int row = current.first;
            int col = current.second;


            reachable[row][col] = true;

            for(auto& di:dir){
                int newRow = row + di[0];
                int newCol = col + di[1];



            if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) {
                    continue;
                }


                                if (reachable[newRow][newCol]) {
                    continue;
                }

                                if (matrix[newRow][newCol] < matrix[row][col]) {
                    continue;
                }

                q.push({newRow, newCol});
            }
        }

        return reachable;

    }

};