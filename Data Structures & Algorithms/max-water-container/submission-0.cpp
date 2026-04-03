class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size()-1;
        int maxArea = 0;
        int area;

        while(left < right)
        {
            area = min(heights[left], heights[right]) * (right-left);
            maxArea = max(maxArea, area);
            
            if(heights[left] <= heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        
        return maxArea;
    }
};
