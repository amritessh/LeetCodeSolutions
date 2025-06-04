class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;

        vector<bool> numbers(n,true);
        for(int i = 2; i <= sqrt(n) ; i++){
            if(numbers[i]){
                for(int j = i*i; j<n; j+=i){
                    numbers[j] = false;
                }
            }
        }

        int numberOfPrimes = 0;
        for(int i = 2; i < n; i++){
            if(numbers[i]){
                numberOfPrimes++;
            }
        }
        return numberOfPrimes;
    }
};