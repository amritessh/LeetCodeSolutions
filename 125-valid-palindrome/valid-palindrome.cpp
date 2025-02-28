class Solution {
public:
    bool isPalindrome(string s) {
    //     int a = 0;
    //     int b = s.size()-1;
    //     while(a<b){
    //     if(!isalnum(s[a])){
    //         a++;
    //     }
    //     else if(!isalnum(s[b])){
    //         b--;
    //     }
    //     else if(tolower(s[a])!=tolower(s[b])) 
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         a++;
    //         b--;
    //     }
    //     }
    //     return true;
    // }    
    for(int i = 0, j = s.size()-1 ; i<j; i++ , j--){
        while(i<j && !isalnum(s[i])) i++;
        while(i<j && !isalnum(s[j])) j--;

        if(tolower(s[i])!= tolower(s[j])) return false;
    }

    return true;

    }
   
};