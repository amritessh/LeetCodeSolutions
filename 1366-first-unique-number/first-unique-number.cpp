class FirstUnique {
public:

    queue<int> qu; 
    unordered_map<int, int> freq;

    FirstUnique(vector<int>& nums) {
        freq.clear();
        while(!qu.empty()) qu.pop();
        for (auto num: nums) qu.push(num), freq[num]++;
    }
    
    int showFirstUnique() {
        while(!qu.empty() && freq[qu.front()] > 1){
            qu.pop();
        }
        if(qu.empty()) return -1;
        else return qu.front(); 
    }
    
    void add(int value) {
        qu.push(value);
        freq[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */