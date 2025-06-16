class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int from_left = 0, n = colors.size(), from_right = n - 1;
        while (colors[from_left] == colors[n-1]) from_left++;
        while (colors[from_right] == colors[0]) from_right--;
        return max(from_right, n-from_left-1);
    }
};