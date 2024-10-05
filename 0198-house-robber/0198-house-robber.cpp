//recursive solution gives TLE error: time/space: O(2^N)/O(N)+O(N)
/*class Solution {
public:
    int choose(int ind, vector<int> &nums){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        int pick = nums[ind] + choose(ind-2, nums);
        int notPick = 0 + choose(ind-1, nums);
        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return choose(n-1, nums);
    }
};*/

//memoization(top-down): time/space: O(N)/O(N)
/*class Solution{
public:
    int choose(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + choose(ind-2, nums, dp);
        int nonPick = 0 + choose(ind-1, nums, dp);
        return dp[ind] = max(pick, nonPick);
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return choose(n-1, nums, dp);
    }
};*/

//tabulation(bottom-up approach): time/space: O(n)/O(n)
/*class Solution{
public:
    int choose(int n, vector<int> &nums, vector<int> &dp){
        // Base case: If there are no elements in the array, return 0
        dp[0] = nums[0];
        
        for(int i = 1; i<=n-1; i++)
        {
        int pick = nums[i];
        if(i>1){
            pick += dp[i-2];
        }
        int nonPick = dp[i-1];
        dp[i] = max(pick, nonPick);
        }
        return dp[n-1];
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return choose(n, nums, dp);
    }
};*/

//space optimization: time/space: O(n)/O(1)
class Solution{
public:
    int rob(vector<int> &nums){
        int n = nums.size();
        int prev  = nums[0]; // Initialize the maximum sum ending at the previous element
        int prev2 = 0; // Initialize the maximum sum ending two elements ago

        for(int i = 1; i<n; i++){
            int pick = nums[i]; // Maximum sum if we pick the current element
            if(i>1) pick += prev2; // Add the maximum sum two elements ago

            int nonPick = prev;
            int curri = max(pick, nonPick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};