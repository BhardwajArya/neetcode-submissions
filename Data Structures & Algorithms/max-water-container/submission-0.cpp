class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxa=0;
        int l=0;
        int r = heights.size()-1;
        while(l<r){
            int area = min(heights[l], heights[r])*(r-l);
            maxa = max(area, maxa);
            if(heights[r]>heights[l])l++;
            else{
                
                r--;
            }
            

            
        }
        return maxa;
    }
};
