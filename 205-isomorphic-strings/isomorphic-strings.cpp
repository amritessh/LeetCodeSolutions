class Solution {
public:
    bool isIsomorphic(string s, string t) {
       return helper(s,t) && helper(t,s);
       
    }
       
    bool helper(string s, string t){
       
        unordered_map<char,char> str;

        for(int i = 0 ; i < s.length(); i++){
            if(str.count(s[i]) && str[s[i]]!=t[i]){
                return false;
            }
            str[s[i]] = t[i];

        }
            return true;
        
    }
};