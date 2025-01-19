class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int first = 0 , second = height.size()-1;
        
        // for(int i = 0; i < height.size() ; i++){
        while(first<second){
   // area.push_back(abs(height[second]-height[first])*min(height[first],height[second]));
   //                if(height[first]<height[second]) first++;
   //                else second--;
   //      }  
   //                sort(area.begin(),area.end());
   //      int n = area.size();
   //                 int res = area[n-1];
            
            
            int h = min(height[first],height[second]);
            res = max(res, h*(second-first));
            while(height[first] <= h && first < second) first++;
            while(height[second]<= h && first < second) second--;
        }
    return res;
}
                  
};