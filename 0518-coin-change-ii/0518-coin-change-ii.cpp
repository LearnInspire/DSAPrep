class Solution {
public:
    int f(int ind,int target,vector<int>&coin, vector<vector<int>>& dp)
    {
        if(ind==0)
            return(target%coin[0]==0);

        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake = f(ind-1,target,coin, dp);
        int take=0;
        if(coin[ind]<=target) take=f(ind,target-coin[ind],coin, dp);
        return dp[ind][target] = (take+nottake);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return f(n-1,amount,coins, dp);
    }
};