class Solution {
public:
    vector<vector<int>> result;
    vector<int> ds;
    void solve(int idx, vector<int>& arr, int target,
               vector<vector<int>>& result, vector<int>& ds) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(ds);
            return;
        }
        int n = arr.size();
        if (idx == n)
            return;

        // picking up the ele
        ds.push_back(arr[idx]);

        solve(idx, arr, target - arr[idx], result, ds);

        ds.pop_back();

        // not picking up
        solve(idx + 1, arr, target, result, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target, result, ds);
        return result;
    }
};