class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // If already at most k distinct, no deletions needed
        if (freq.size() <= k) return 0;

        // Collect frequencies and sort them
        vector<int> counts;
        for (auto& p : freq) counts.push_back(p.second);
        sort(counts.begin(), counts.end());

        // Remove the least frequent characters
        int deletions = 0;
        int remove = freq.size() - k;
        for (int i = 0; i < remove; ++i) {
            deletions += counts[i];
        }
        return deletions;
    }
};