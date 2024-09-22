class Solution {
public:
    int trap(vector<int>& height) {
        //TC: O(3n), SC: O(2n), calculate leftMax & rightMax for each of the index & maintain them in arrays
        //for calculating storage capacity = min(leftMax, rightMax) - index, min jitna hi paani store ho paayega
        int n = height.size();
        if(n == 0) return 0;
        int leftMax[n], rightMax[n];
        
        //for calculating left Prefixsum or leftmax; fill in leftMax array
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        //for calculating right suffixSum or rightMax; fill in rightMax array
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0 ; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int maxWater = 0;
        for(int i = 0; i<n; i++){
            maxWater += min(leftMax[i], rightMax[i]) - height[i];
            
        }
        return maxWater;
    }
};