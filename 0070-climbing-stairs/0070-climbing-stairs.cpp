class Solution {
public:
    int climbStairs(int n) {
        // M3: Space optimization approach
        if (n == 0 || n == 1)
            return 1;
        int prev = 1;
        int prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int curr_i = prev2 + prev;
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
        /* M2: tabulation
        if (n == 0 || n == 1)
            return 1;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];*/

        /*M1: using recursion gives TLE
        if(n == 0) return 1;
        if(n == 1) return 1;

        int left = climbStairs(n-1);
        int right = climbStairs(n-2);

        return left + right;*/
    }
};