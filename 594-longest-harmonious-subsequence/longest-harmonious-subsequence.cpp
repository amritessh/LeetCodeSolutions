class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int res = 0;
        for (auto& [num, cnt] : count) {
            if (count.count(num + 1)) {
                res = max(res, cnt + count[num + 1]);
            }
        }
        return res;
    }
};