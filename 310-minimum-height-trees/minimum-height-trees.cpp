#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Edge cases
        if (n < 2) {
            vector<int> centroids;
            for (int i = 0; i < n; i++) {
                centroids.push_back(i);
            }
            return centroids;
        }
        
        // Build the graph with adjacency list
        vector<unordered_set<int>> neighbors(n);
        for (const auto& edge : edges) {
            int start = edge[0], end = edge[1];
            neighbors[start].insert(end);
            neighbors[end].insert(start);
        }
        
        // Initialize the first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (neighbors[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        
        // Trim the leaves until reaching the centroids
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            
            // Remove the current leaves along with the edges
            for (int leaf : leaves) {
                // The only neighbor left for the leaf node
                int neighbor = *neighbors[leaf].begin();
                // Remove the edge along with the leaf node
                neighbors[neighbor].erase(leaf);
                if (neighbors[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            
            // Prepare for the next round
            leaves = newLeaves;
        }
        
        // The remaining nodes are the centroids of the graph
        return leaves;
    }
};