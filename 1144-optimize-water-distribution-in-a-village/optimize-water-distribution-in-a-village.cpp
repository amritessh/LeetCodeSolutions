#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> group;
    vector<int> rank;
    
public:
    UnionFind(int size) {
        // Container to hold the group id for each member
        // Note: the index of member starts from 1,
        //   thus we add one more element to the container.
        group.resize(size + 1);
        rank.resize(size + 1);
        for (int i = 0; i < size + 1; ++i) {
            group[i] = i;
            rank[i] = 0;
        }
    }
    
    /**
     * Return the group id that the person belongs to.
     */
    int find(int person) {
        if (group[person] != person) {
            group[person] = find(group[person]);  // Path compression
        }
        return group[person];
    }
    
    /**
     * Join the groups together.
     * return:
     * false when the two persons belong to the same group already,
     * otherwise true
     */
    bool unionSets(int person1, int person2) {
        int group1 = find(person1);
        int group2 = find(person2);
        if (group1 == group2) {
            return false;
        }
        
        // Attach the group of lower rank to the one with higher rank
        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
        return true;
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> orderedEdges;
        
        // Add the virtual vertex (index with 0) along with the new edges
        for (int i = 0; i < wells.size(); ++i) {
            orderedEdges.push_back({0, i + 1, wells[i]});
        }
        
        // Add the existing edges
        for (const auto& pipe : pipes) {
            orderedEdges.push_back(pipe);
        }
        
        // Sort the edges based on their cost
        sort(orderedEdges.begin(), orderedEdges.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        
        // Iterate through the ordered edges
        UnionFind uf(n);
        int totalCost = 0;
        
        for (const auto& edge : orderedEdges) {
            int house1 = edge[0];
            int house2 = edge[1];
            int cost = edge[2];
            
            // Determine if we should add the new edge to the final MST
            if (uf.unionSets(house1, house2)) {
                totalCost += cost;
            }
        }
        
        return totalCost;
    }
};