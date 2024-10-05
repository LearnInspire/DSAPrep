//Recursive solution
/*class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};*/

//Tabulation Approach: Bottom up
/*class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        vector<int> dp(n+1, -1);
        //base cases: as there's only 1 way to return from 0 & 1
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n]; //storing the result in last cell of the dp table
    }
};
*/
//Space optimization approach
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        //base cases: as there's only 1 way to return from 0 & 1
        int prev = 1;
        int prev2 = 1;
        for(int i = 2; i<=n; i++){
            int curr_i = prev + prev2;
            prev2 = prev;
            prev = curr_i;
        }
        return prev; //after iterative loop ended, we can simply returns prev as our ans
    }
};
