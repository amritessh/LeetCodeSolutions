class UnionFind {
private:
    vector<int> group;
    vector<int> rank;
    
public:
    UnionFind(int size) {
        group.resize(size);
        rank.resize(size, 0);
        for (int person = 0; person < size; ++person) {
            group[person] = person;
        }
    }
    
    int find(int person) {
        if (group[person] != person) {
            group[person] = find(group[person]); // Path compression
        }
        return group[person];
    }
    
    bool unite(int a, int b) {
        int groupA = find(a);
        int groupB = find(b);
        if (groupA == groupB) return false; // Already connected
        
        // Union by rank
        if (rank[groupA] > rank[groupB]) {
            group[groupB] = groupA;
        } else if (rank[groupA] < rank[groupB]) {
            group[groupA] = groupB;
        } else {
            group[groupB] = groupA;
            rank[groupA]++;
        }
        return true;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // Sort logs by timestamp in ascending order
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        int groupCount = n;
        UnionFind uf(n);
        
        for (const auto& log : logs) {
            int timestamp = log[0];
            int friendA = log[1];
            int friendB = log[2];
            
            // Merge groups if not already connected
            if (uf.unite(friendA, friendB)) {
                groupCount--;
            }
            
            // All friends connected
            if (groupCount == 1) {
                return timestamp;
            }
        }
        
        return -1; // Not all friends connected
    }
};
