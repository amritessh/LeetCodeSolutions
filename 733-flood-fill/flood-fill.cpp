class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if(originalColor!=newColor){
            dfs(image,sr,sc,originalColor,newColor);
        }
        return image;
    }


private:
    void dfs(vector<vector<int>>& image, int r , int c , int originalColor, int newColor){
        if(image[r][c]!= originalColor) return;

        image[r][c] = newColor;

            if (r >= 1) {
            dfs(image, r - 1, c, originalColor, newColor);
        }
        
        // 2. Left: ensure column index doesn't go below 0
        if (c >= 1) {
            dfs(image, r, c - 1, originalColor, newColor);
        }
        
        // 3. Down: ensure row index doesn't exceed the last row
        if (r + 1 < image.size()) {
            dfs(image, r + 1, c, originalColor, newColor);
        }
        
        // 4. Right: ensure column index doesn't exceed the last column
        if (c + 1 < image[0].size()) {
            dfs(image, r, c + 1, originalColor, newColor);
        }
    }
};