class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void solve(int idx, vector<int>& arr, int target,
               vector<vector<int>>& result, vector<int>& path) {
        if (target < 0)
            return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        // pick up the element
        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1])
                continue; // ignore duplicate elements
            path.push_back(arr[i]);
            solve(i + 1, arr, target - arr[i], result, path);
            path.pop_back();
            //solve(idx + 1, arr, target, result, path);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),
             candidates.end()); // ignoring duplicate elements
        solve(0, candidates, target, result, path);
        return result;
    }
};