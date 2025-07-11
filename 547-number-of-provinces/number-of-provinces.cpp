class UnionFind {
private:
    vector<int> parent;   // root[i] = root of the tree containing i
    vector<int> rank;   // rank[i] = height of tree rooted at i
    int count = 0;      // Number of disjoint sets/components remaining

public:
    /**
     * CONSTRUCTOR: Initialize n separate disjoint sets
     * - root[i] = i: each element is its own root initially
     * - count = sz: initially we have 'sz' separate components
     * Time: O(n)
     */

    UnionFind(int sz) {
        parent.resize(sz);
        rank.resize(sz, 0);  // ✅ Initialize to 0 directly, height-based
        count = sz;
        
        for (int i = 0; i < sz; i++) {
            parent[i] = i;     // Only need to set root
        }
    }

    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // Already in same set - no union needed
        if (rootX != rootY) {
            // Union by rank: attach smaller tree to larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;        // Make rootX the parent of rootY
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;        // Make rootY the parent of rootX
            } else {
                // Same rank: arbitrarily choose one as parent, increment its rank
                parent[rootY] = rootX;
                rank[rootX] += 1;           // New root's rank increases by 1
            }
            // Two sets merged into one → decrease component count
            count--;
        }
    }

    int getCount() {
        return count;
    }

};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind dsu(n);
        int numberOfComponents = n;

        for(int i = 0; i <n; i++){
            for(int j = i+1; j<n; j++){
                if(isConnected[i][j] && dsu.find(i)!=dsu.find(j)){
                    // numberOfComponents--;
                    dsu.union_set(i,j);
                }
            }
        }
        return dsu.getCount();
    }
};