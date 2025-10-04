class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;               
        int j = height.size() - 1;
        int max_area = 0;        

        while (i < j) {
         
            int current_area = min(height[i], height[j]) * (j - i);
            max_area = max(max_area, current_area);

            // Move the pointer pointing to the shorter line
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_area;
    }
};
