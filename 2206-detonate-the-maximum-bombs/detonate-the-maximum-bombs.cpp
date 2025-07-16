class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
            long long d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if (d <= r1 * r1) {adj[i].push_back(j);}
                if (d <= r2 * r2) { adj[j].push_back(i);} }}
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> visit;
            res = max(res, dfs(i, visit, adj));}
        return res;
    }

private:
    int dfs(int i, unordered_set<int>& visit, vector<vector<int>>& adj) {
        if (!visit.insert(i).second) return 0;
        for (int nei : adj[i]) {
            dfs(nei, visit, adj);
        }
        return visit.size();
    }
};