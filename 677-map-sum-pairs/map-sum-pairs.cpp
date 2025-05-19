class MapSum {
    struct TrieNode {
        unordered_map<char, unique_ptr<TrieNode>> children;
        int score = 0;
    };

    unordered_map<string, int> map_;
    TrieNode root;

public:
    MapSum() {}

    void insert(const string& key, int val) {
        int delta = val - (map_.count(key) ? map_[key] : 0);
        map_[key] = val;
        TrieNode* cur = &root;
        cur->score += delta;
        for (char c : key) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = make_unique<TrieNode>();
            }
            cur = cur->children[c].get();
            cur->score += delta;
        }
    }

    int sum(const string& prefix) {
        TrieNode* cur = &root;
        for (char c : prefix) {
            auto it = cur->children.find(c);
            if (it == cur->children.end()) {
                return 0;
            }
            cur = it->second.get();
        }
        return cur->score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */