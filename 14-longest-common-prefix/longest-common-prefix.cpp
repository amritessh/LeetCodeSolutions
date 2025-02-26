class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.size() == 0) return "";
        // string prefix = strs[0];
        // for(int i = 1; i < strs.size() ; i++){
        //     while(strs[i].find(prefix)!=0){
        //         prefix = prefix.substr(0,prefix.length()-1);
        //         if(prefix.empty()) return "";
        //     }
        // }
        //     return prefix;

        if(strs.empty()) return "";
        for(int i = 0 ; i <strs[0].size(); i++){
            char c = strs[0][i];

            for(int j = 1 ; j < strs.size(); j++){
                if(i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
        
    }
};