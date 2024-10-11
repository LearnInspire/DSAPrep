class Solution {
public:
    int choose(int n, vector<int>& nums, vector<int>& dp) {
        // base case
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if(i>1) pick += dp[i - 2];
            int nonpick = 0 + dp[i - 1];
            dp[i] = max(pick, nonpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return choose(n, nums, dp);
    }
};