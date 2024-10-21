/*class Solution {
public:
    int n, m;
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        // match case
        if (s[i] == s[j])
            return dp[i][j] = 1 + helper(i - 1, j - 1, s, t, dp);

        // not match case
        else
            return dp[i][j] = max(helper(i - 1, j, s, t, dp),
                                  helper(i, j - 1, s, t, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return dp[n-1][m-1] = helper(n, m, text1, text2, dp);
    }
};*/

class Solution {
public:
    int pre(int n, int m, string& s1, string& s2, vector<vector<int>>& dp) {
        if (n < 0 or m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s1[n] == s2[m])
            return dp[n][m] = pre(n - 1, m - 1, s1, s2, dp) + 1;
        else
            return dp[n][m] = max(pre(n - 1, m, s1, s2, dp),
                                  pre(n, m - 1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        pre(n, m, text1, text2, dp);
        return dp[n - 1][m - 1];
    }
};