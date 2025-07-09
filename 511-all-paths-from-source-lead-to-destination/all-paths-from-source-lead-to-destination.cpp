#include <vector>
using namespace std;

class Solution {
private:
    enum Color { WHITE, GRAY, BLACK };
    
    bool leadsToDest(const vector<vector<int>>& graph, int node, int dest, vector<Color>& states) {
        // If the state is GRAY, this is a backward edge and hence, it creates a loop.
        if (states[node] == GRAY) {
            return false;
        }
        
        // If already processed (BLACK), return true
        if (states[node] == BLACK) {
            return true;
        }
        
        // If this is a leaf node, it should be equal to the destination.
        if (graph[node].empty()) {
            return node == dest;
        }
        
        // Now, we are processing this node. So we mark it as GRAY
        states[node] = GRAY;
        
        for (int next : graph[node]) {
            // If we get a `false` from any recursive call on the neighbors, we short circuit and return from there.
            if (!leadsToDest(graph, next, dest, states)) {
                return false;
            }
        }
        
        // Recursive processing done for the node. We mark it BLACK
        states[node] = BLACK;
        return true;
    }
    
    vector<vector<int>> buildDigraph(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        return graph;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph = buildDigraph(n, edges);
        vector<Color> states(n, WHITE);  // Initialize all nodes as WHITE
        return leadsToDest(graph, source, destination, states);
    }
};