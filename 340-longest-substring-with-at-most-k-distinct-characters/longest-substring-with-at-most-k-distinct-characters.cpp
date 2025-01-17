class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int result = 0;
        unordered_map<char,int> freq;

        for(right = 0; right<s.size(); right++){
            freq[s[right]]++;
            while(freq.size()>k){
                freq[s[left]]--;
                
                if(freq[s[left]]==0) freq.erase(s[left]);
                
                left++;
            }
        result = max(result,right-left+1);
        }

        return result;
    }
};