class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        //brute force
        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = 0; j< arr.size(); j++){
        //         if( i!=j && arr[i]==2*arr[j]) return true;
        //     }
        // }
        // return false;

        //set lookup
        
        unordered_set<int> seen;
        for(int num:arr){
            if(seen.count(2*num) || (num%2) == 0 && seen.count(num/2)){
                return true;
            }
            seen.insert(num);
        }
        return false;

    }
};