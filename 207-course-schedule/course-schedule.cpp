class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //stores the number of edges entering the particular node
        vector<int> indegree(numCourses);

        //adjacency list, adj[x] that contains all the nodes with an incoming edge from nodes x , ie neighbors of node x. 
        vector<vector<int>> adj(numCourses);
        for(auto prerequisite: prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }


        queue<int> q;
        for(int i = 0 ; i < numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int nodesVisited = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodesVisited++;

            for(auto& neighbor: adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        return nodesVisited == numCourses;
    }
};