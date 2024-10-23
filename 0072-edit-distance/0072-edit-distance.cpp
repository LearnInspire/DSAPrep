class Solution {
public:
    //using DP
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        //base case
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = helper(i-1, j-1, s1, s2, dp);

        return dp[i][j] = 1 + min(helper(i-1, j, s1, s2, dp), min(helper(i, j-1, s1, s2, dp), helper(i-1, j-1, s1, s2, dp)));

    }

    int minDistance(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, s1, s2, dp);
    }

    /*
    int helper(string s1, string s2, int i, int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(s1[i] == s2[j]) return helper(s1, s2, i-1, j-1);
        else{
            return 1 + min(helper(s1, s2, i-1, j), min(helper(s1, s2, i, j-1), helper(s1, s2, i-1, j-1)));
        }
    }
    int minDistance(string s1, string s2) {
        //using rescursion, gives Memory Limit Exceeded error bcz TC is O(n3)
        int n = s1.size();
        int m = s2.size();

        return helper(s1, s2, n-1, m-1);  
    }*/
};