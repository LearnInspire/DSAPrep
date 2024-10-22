class Solution {
private:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // base case, recuirsive solution gives TLE so memoizing it
        if (j < 0)
            return 1; // we get all combinations of s2 in s1
        if (i < 0)
            return 0; // the pattern in s2 is still left & S1 is exhausted

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) +
                              f(i - 1, j, s, t,
                                dp); // I found one g but looking for another
                                     // different occurence of g, e.g2
        }
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};