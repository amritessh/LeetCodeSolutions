class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0, result = 0, currentSum = 0, k = 10001;
        vector<int> countMap(k, 0);
        for (int end = 0; end < nums.size(); end++) {
            int currentElement = nums[end];
            countMap[currentElement]++;
            currentSum += currentElement;
            while (start < end && countMap[currentElement] > 1) {
                countMap[nums[start]]--;
                currentSum -= nums[start];
                start++;
            }
            // update result with maximum sum found so far
            result = max(result, currentSum);
        }
        return result;
    }
};