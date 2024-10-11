class Solution {
public:
    int choose(int ind, vector<int>& nums, vector<int>& dp){
        //base case
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + choose(ind-2, nums, dp);
        int nonpick = 0 + choose(ind-1, nums, dp);
        return dp[ind] = max(pick, nonpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return choose(n-1, nums, dp); 
    }
};