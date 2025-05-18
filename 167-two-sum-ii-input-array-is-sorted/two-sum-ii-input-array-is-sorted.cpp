class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
                int front=0,back=numbers.size()-1;
      // /  vector<int> index;
        
     //   for(int i = 1 ; i < numbers.size() ; i++){
        while(front<back){
            if(numbers[front]+numbers[back]<target) front++;
            if(numbers[front]+numbers[back]>target) back--;
            if(numbers[front]+numbers[back]==target) return {front+1,back+1} ;
        }
        return {};
    
    }
};