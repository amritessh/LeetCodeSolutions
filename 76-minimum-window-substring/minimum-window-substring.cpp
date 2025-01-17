class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }

        unordered_map<char,int> mp;
        for(int i = 0; i <t.size(); i++){
            mp[t[i]]++;
        }

        int count = 0;
        int left = 0;
        int min_length = INT_MAX;
        int min_start = 0;

        for(int right = 0; right<s.size(); right++ ){
            if(mp[s[right]]>0){
                count++;
            }

            mp[s[right]]--;
            if(count == t.length()){
                while(left<right && mp[s[left]] < 0){
                    mp[s[left]]++, left++;
                }

                if(min_length > right-left){
                    min_length = right -(min_start = left)+1;
                }

                mp[s[left++]]++;
                count--;
            }
        }

        return min_length == INT_MAX?"":s.substr(min_start,min_length);

    }
};