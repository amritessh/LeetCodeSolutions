class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 0; i<prices.size();i++){
            max_profit = max(max_profit,prices[i]-min_price);
            min_price = min(min_price,prices[i]);
        }
        return max_profit;


        // int left = 0;
        // int right = 1;
        // int n = prices.size();
        // int profit = 0;
        // int maxProfit = 0;
        // while(right<n){
        //     if(prices[left] < prices[right]){
        //     profit = prices[right]- prices[left];
        //     maxProfit = max(maxProfit,profit);
        // }
        // else left = right;

        // right = right+1;
        // }
        // return maxProfit;
        
    }
};