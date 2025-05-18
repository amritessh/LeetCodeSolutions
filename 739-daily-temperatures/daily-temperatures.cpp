class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0); // Initialize result with 0s
        stack<int> stk; // Stores indices of days with unresolved warmer days
        
        for (int currDay = 0; currDay < n; ++currDay) {
            int currentTemp = temperatures[currDay];
            
            // Pop indices from the stack while current temp is higher
            while (!stk.empty() && temperatures[stk.top()] < currentTemp) {
                int prevDay = stk.top();
                stk.pop();
                answer[prevDay] = currDay - prevDay; // Update waiting days
            }
            stk.push(currDay); // Push current day to stack
        }
        return answer;
    }
};