class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int opened = 0;
        // for (char c : s) {
        for(int i = 0; i < s.length(); i++){
            if (s[i] == '(' && opened++ > 0) res += s[i];
            if (s[i] == ')' && opened-- > 1) res += s[i];
        }
        return res;
    }
};