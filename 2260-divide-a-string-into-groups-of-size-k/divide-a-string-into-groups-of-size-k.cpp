class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        
        for(int i = 0; i < s.size(); i += k) {
            string group = "";
            
            // Add k characters to the current group
            for(int j = i; j < i + k; j++) {
                if(j < s.size()) {
                    group += s[j];  // Add character from string
                } else {
                    group += fill;  // Add fill character if needed
                }
            }
            
            res.push_back(group);
        }
        
        return res;
    }
};