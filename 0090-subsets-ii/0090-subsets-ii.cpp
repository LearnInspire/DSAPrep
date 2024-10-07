class Solution {
public:
    int ind;
    void solve(int ind, vector<int>& nums, vector<vector<int>>& result,
               vector<int> ds) {
            result.push_back(ds);

        for (int i = ind; i < nums.size() ; i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);
            solve(i + 1, nums, result, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end()); // to ignore duplicates
        solve(0, nums, result, ds);
        return result;
    }
};