class Solution {
public:
    int f(int ind, vector<int>& coins, int target, vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(ind < 0 || target < 0) return INT_MAX-1;
        if(dp[ind][target] != -1) return dp[ind][target];
        if(ind == 0){
            if(target % coins[0] == 0) return target/coins[ind];
        }

        int nontake = 0 + f(ind - 1, coins, target, dp);
        int take = INT_MAX;
        if(coins[ind] <= target){
            take = 1 + f(ind, coins, target - coins[ind], dp);
        }
        return dp[ind][target] = min(take, nontake);
    }
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        int ans = f(n-1, coins,target, dp);
        return (ans<INT_MAX-1)?ans : -1;
    }
};