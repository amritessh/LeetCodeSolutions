class Solution {
public:
    int mySqrt(int x) {
        //always square root of x is going to be less than x/2 thats why set up boundary like that
        int left = 2, right = x/2; 
        long num;
        int pivot;

        if (x<2) return x;
        while(left<=right){
            pivot = left + (right - left)/2;
            //take a guess that pivot is the square root of x
            num = (long)pivot * pivot ;


            if( num < x){
                left = pivot + 1;
            }

            else if(num > x){
                right = pivot - 1;
            }

            else return pivot;

        }

        return right;
    }
};