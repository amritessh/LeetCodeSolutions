class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res;
        for(int i=1; i <=n; i++){
            if(i%m==0) res-=i;
            else res+=i;
        }
        return res;
    }
};