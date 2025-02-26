class Solution {
public:
    void sortColors(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        // int min_index;
        // for (int i = 0; i < arr.size(); i++) {
        //     min_index = i;
        //     for (int j = i + 1; j < arr.size(); j++) {
        //         if (arr[j] < arr[min_index]) {
        //             min_index = j;
        //         }
        //     }
        //     // Swap current index with minimum element in rest of list
        //     int temp = arr[min_index];
        //     arr[min_index] = arr[i];
        //     arr[i] = temp;
        // }
    }
};