class Solution {
public:


    void helper(vector<char>& s, int left, int right){
        if (left >= right) return;
        swap(s[left], s[right]);
        helper(s, left + 1, right - 1);
    }
    void reverseString(vector<char>& s) {
        
        // just use the inbuilt function lol
        // return reverse(s.begin(),s.end());

        //recursive approach
        helper(s,0,s.size()-1);
    }
};