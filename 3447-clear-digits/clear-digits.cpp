class Solution {
public:
    string clearDigits(string s) {
        int ansLength = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(isdigit(s[i])) ansLength--;
            else s[ansLength++]=s[i];
        }
        s.resize(ansLength);
        return s;
    }
};