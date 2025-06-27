class UnionFind{
private:
    vector<int> parent, rank;
    int count;

public:
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size,0);
        count = size;
        for(int i = 0 ; i < size; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void union_set(int x,int y){
        int xset = find(x), yset = find(y);
        if(rank[xset]<rank[yset]){
            parent[xset] = yset;
        } else if(rank[xset]>rank[yset]){
            parent[yset]=xset;
        }else{
            parent[yset]=xset;
            rank[xset]++;
        }
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // int n = isConnected.size();
        UnionFind dsu(n);
        int numberOfComponents = n;

        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            if(dsu.find(u) != dsu.find(v)){
                numberOfComponents--;
                dsu.union_set(u, v);
            }
        }
        return numberOfComponents;
    }
};