class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int result = 0;
        unordered_map<char,int> freq;

        for(right = 0; right<s.size(); right++){
            freq[s[right]]++;
            maxFreq = max(maxFreq,freq[s[right]]);

            if((right-left-maxFreq+1)>k){
                freq[s[left]]--;
                left++;
           
            }
        
            
        result = max(result,right-left+1);
        }

        return result;
    }
};