class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> frequencies;
        int maxFrequency =0, totalFrequencies =0;
        for(int i = 0; i < nums.size(); i++){
            frequencies[nums[i]]++;
            int frequency = frequencies[nums[i]];

            if(frequency>maxFrequency){
                maxFrequency = frequency;
                totalFrequencies = frequency;
            }
            else if(frequency == maxFrequency){
                totalFrequencies += frequency;
            }
        }
        return totalFrequencies;
    }
};