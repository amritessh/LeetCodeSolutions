class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int n = prices.size();
        int profit = 0;
        int maxProfit = 0;
        while(right<n){
            if(prices[left] < prices[right]){
            profit = prices[right]- prices[left];
            maxProfit = max(maxProfit,profit);
        }
        else left = right;

        right = right+1;
        }
        return maxProfit;
        
    }
};