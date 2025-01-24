class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int N = arr.size();
        int i = 0;

        //keep going up
        while(i+1 < N && arr[i]<arr[i+1]) i++;

        //first element cannot be peak neither the last element
        if(i ==0 || i == N-1) return false;

        //down
        while(i+1<N && arr[i]>arr[i+1]) i++;

        return i == N-1;


    }
};