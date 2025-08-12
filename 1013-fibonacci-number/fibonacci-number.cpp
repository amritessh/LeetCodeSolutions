class Solution {
public:
unordered_map<int,int> cache{{0,0},{1,1}};
    int fib(int n) {
        // unordered_map<int,int> cache{{0,0},{1,1}};
        if(cache.find(n)!=cache.end()){
            return cache[n];
        }

        cache[n] = fib(n - 1) + fib(n - 2);
        return cache[n];

    }
};