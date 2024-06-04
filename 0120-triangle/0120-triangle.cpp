class Solution {
public:
    // Recursion solution gives TLE
    // time/space:- O(m*n) 
    /*int find(int i, int j, vector<vector<int>> &triangle){
        int m = triangle.size();
        int n = triangle[0].size();
        if(i == m - 1){
            return triangle[m-1][j];
        }

        int down = triangle[i][j] + find(i+1,j, triangle);
        int diagonal = triangle[i][j] + find(i+1, j+1, triangle);
        return min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();

        return find(0, 0, triangle);
    }*/

    //Memoization Approach: 
    //time/space: O(n*n) there are two nested loops/O(n*n)
    int find(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];

        if(i == n - 1){
            return triangle[n-1][j];
        }
        
        int down = triangle[i][j] + find(i+1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + find(i+1, j+1, triangle, n, dp);
        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return find(0, 0, triangle, n, dp);
    }
};