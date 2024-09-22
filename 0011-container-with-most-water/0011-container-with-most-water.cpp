class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n - 1;
        int maxWater = 0;
        while(left < right){
            int width = right - left;
            int length = min(height[left], height[right]);
            int area = width * length;
            maxWater = max(maxWater, area);

            if(height[left] > height[right])
            //move greedily, keep the bigger height, bcz we're reducing width so we 
            //need to keep greater height to achieve bigger arrea
            {
                right --;
            }
            else left++;

        }
        return maxWater;
    }
};