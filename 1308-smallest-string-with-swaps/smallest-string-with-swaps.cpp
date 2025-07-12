
class UnionFind{
private:
    vector<int> parent,rank;


public:
UnionFind(int size){
    parent.resize(size);
    rank.resize(size,0);
    for(int i = 0; i < size; i++){
        parent[i] = i;
    }
}

    int find(int x ){
        if(parent[x]!=x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y){
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

/*
1. build a graph using the given pairs, 
2. find the connected components in the graph, 
3. sort the characters in each connected component in ascending order
4. build the smallest string.
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind dsu(s.size());

        for(auto& pair:pairs){
            int u = pair[0],v=pair[1];
            dsu.union_set(u,v);
        }

        unordered_map<int,vector<int>> rootToComponent;
        for(int vertex = 0; vertex < s.size(); vertex++){
            int root = dsu.find(vertex);
            rootToComponent[root].push_back(vertex);
        }

        string smallestString(s.length(), ' ');
            for (auto component : rootToComponent) {
            vector<int> indices = component.second;
            
            // Sort the characters in the group
            vector<char> characters;
            for (int index : indices) {
                characters.push_back(s[index]);
            }
            sort(characters.begin(), characters.end());
            
            // Store the sorted characters
            for (int index = 0; index < indices.size(); index++) {
                smallestString[indices[index]] = characters[index];
            }
        }
        
        return smallestString;
    }
};