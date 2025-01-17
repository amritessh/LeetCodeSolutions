class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
            int left = 0;
        int right = 0;
        int maxFreq = 0;
        int result = 0;
        unordered_map<char,int> freq;

        for(right = 0; right<s.size(); right++){
            freq[s[right]]++;
            while(freq.size()>2){
                freq[s[left]]--;
                
                if(freq[s[left]]==0) freq.erase(s[left]);
                
                left++;
            }
        result = max(result,right-left+1);
        }

        return result;
    }
};