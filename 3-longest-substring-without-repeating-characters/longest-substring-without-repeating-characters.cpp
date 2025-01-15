class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> zet;
        int left = 0;
        int result = 0;

        for(int right = 0; right< s.size() ; right++){
                while(zet.find(s[right])!=zet.end()){
                    zet.erase(s[left]);
                    left++;
                }
                zet.insert(s[right]);
                result = max(result,right-left+1);
        }
        return result;
    }
};