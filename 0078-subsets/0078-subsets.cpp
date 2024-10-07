class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    //using recursion
    void solve(int idx, vector<int>& nums, vector<int>& temp){
        int n = nums.size();
        //base case
        if(idx == n){
            result.push_back(temp);
            return;
        }

        //add in resultant ds
        temp.push_back(nums[idx]);
        //pick recursive call
        solve(idx+1, nums, temp);
        //remove from resultant ds
        temp.pop_back();
        //not pick recursive call
        solve(idx+1, nums, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int idx = 0;

        solve(0, nums, temp);
        return result;
    }
};