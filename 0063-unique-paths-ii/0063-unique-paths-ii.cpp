//memoization approach:
/*class Solution {
public:
    int find(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int up = find(i-1, j, grid, dp);
        int left = find(i, j-1, grid, dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find(m-1, n-1, grid, dp);
    }
};*/
//tabulation approach: introduce nested loops for 2D dp
/*class Solution {   gives runtime error
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //decalare a 2D dp array of size m*n
        vector<vector<int>> dp(m, vector<int>(n, -1));

        //base cases
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i>=0 && j >= 0 && grid[m][n] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(grid[i][j] != -1){
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i>0) up = dp[i-1][j];
                if(i>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};*/

class Solution {
public:
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                if(obstacleGrid[i][j]!=1)
                {
                if(i==0&&j==0)     //base case 
                {
                if(obstacleGrid[0][0]==0)
                {
                 dp[i][j]=1;
                 continue;
                }
                }
                else
                {
                    int down=0,right=0;
                    if(i>0)
                     down=dp[i-1][j];
                     if(j>0)
                     right=dp[i][j-1];
                   
                   dp[i][j]=down+right;
                }
                }
            }
        }

        return dp[n-1][m-1];
    }
};
