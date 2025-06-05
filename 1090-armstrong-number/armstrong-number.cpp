class Solution {
public:
    bool isArmstrong(int n) {
        int sum = 0;
        int dup = n;
        int digits = 0, temp = n;

        // Count number of digits
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        temp = n;
        while (temp > 0) {
            int lastDigit = temp % 10;
            sum += pow(lastDigit, digits);
            temp /= 10;
        }

        return sum == dup;
    }
};