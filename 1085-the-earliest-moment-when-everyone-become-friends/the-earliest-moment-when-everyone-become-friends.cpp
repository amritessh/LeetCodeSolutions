class UnionFind{
private:   
    vector<int> parent, rank;

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


    void union_set(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        

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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int connectedComponents = n;
        UnionFind dsu(n);
        sort(logs.begin(),logs.end());
        for(auto& log:logs){
            int u = log[1],v=log[2],t=log[0];

            if(dsu.find(u)!=dsu.find(v)){
                connectedComponents--;
                dsu.union_set(u,v);
            }
    
        if(connectedComponents == 1) return t;
        }
        return -1;
    }
};