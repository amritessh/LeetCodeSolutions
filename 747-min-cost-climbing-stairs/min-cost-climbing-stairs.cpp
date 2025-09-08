class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size()+1);

        for(int i = 2; i < minCost.size(); i++){
            int takeOneStep = minCost[i-1]+cost[i-1];
            int takeTwoSteps = minCost[i-2]+cost[i-2];
            minCost[i] = min(takeOneStep,takeTwoSteps);
        }
        return minCost[minCost.size()-1];
    }
};