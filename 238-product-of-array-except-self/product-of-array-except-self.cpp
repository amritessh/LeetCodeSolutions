class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
    //length of the input array
    int length = nums.size();

    //left and right arrays 
    vector<int> L(length),R(length),answer(length);

    //L[i] contains the product of all the elements to the left
    // Note: for the element at index '0', there are no elements to the left, so the L[0] would be 1
    
    L[0] = 1;
    for(int i = 1 ; i < length; i++){
        L[i] = nums[i-1]*L[i-1];
    }

    R[length - 1] = 1;
    for(int i = length - 2; i >= 0 ; i--){
        R[i] = nums[i+1]*R[i+1];
    }

    //constructing the answer array
    for(int i = 0 ; i < length ; i++){
        answer[i] = L[i]*R[i];
    }
    
    return answer;


    //      int n = nums.size();  
    //     vector<int> ans(n);
        
    //     vector<int> left_product(n);
    //     vector<int> right_product(n);
        
    //     left_product[0]=1;
    //     for(int i = 1; i < n ; i++){
    //         left_product[i] = left_product[i-1]*nums[i-1];
    //     }
        
    //     right_product[n-1] = 1;
    //     for(int j = n-2; j >= 0; j--){
    //         right_product[j] = right_product[j+1]*nums[j+1];
    //     }
        
    //     for(int k =0 ; k<n ; k++){
    //         ans[k] = left_product[k]*right_product[k];
    //     }
        
    //     return ans;
    }
};