class Solution {
public:
    int res = 0;
    int sumOfMultiples(int n) {
        for(int i = 1 ; i <=n ; i++ ){
            if(i%3 == 0 || i%5 == 0 || i%7==0) res+=i;
        }
        return res;
    }
};