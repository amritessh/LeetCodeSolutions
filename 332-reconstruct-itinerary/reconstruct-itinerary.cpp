class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Build adjacency list
        unordered_map<string, deque<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]); // Map departure → arrival
        }
        
        // Step 2: Sort destinations in descending lexical order
        for (auto& [src, dests] : adj) {
            // Reverse sort to access smallest element via back()
            sort(dests.rbegin(), dests.rend());
        }
        
        // Step 3: DFS to build itinerary
        vector<string> res;
        dfs("JFK", adj, res); // Start DFS from JFK
        
        // Step 4: Reverse result (post-order → correct itinerary)
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& res) {
        // Process all outgoing edges from current airport
        while (!adj[src].empty()) {
            // Step 3a: Pick smallest lexical destination
            string dst = adj[src].back(); // Accesses last element (smallest)
            adj[src].pop_back(); // Remove the ticket
            // Step 3b: Recursively visit next airport
            dfs(dst, adj, res);
        }
        // Step 3c: Add current airport (post-order)
        res.push_back(src);
    }
};
