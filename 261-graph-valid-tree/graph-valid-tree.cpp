class UnionFind{
private: 
    vector<int> parent,rank;


public:
UnionFind(int size){
    parent.resize(size);
    rank.resize(size,0);
    for(int i = 0 ; i < size; i++){
        parent[i] = i;
    }
}


int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}


void union_set(int x, int y){
    int rootX = find(x), rootY = find(y);

    if(rootX!=rootY){
        if(rank[rootX]<rank[rootY]) parent[rootY] = rootX;
        else if(rank[rootX]>rank[rootY]) parent[rootX] = rootY;
        else{
            parent[rootX] = rootY;
            rank[rootX]++;
        }
    }
}


};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int connectedComponents = n;
        UnionFind dsu(n);
        if(edges.size()!=n-1) return false;
        for(auto& edge:edges){
            int u = edge[0], v = edge[1];

            if(dsu.find(u)!=dsu.find(v)){
                connectedComponents--;
                dsu.union_set(u,v);
            }
        }
        return connectedComponents==1;
    }
};