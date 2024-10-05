class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;
    int n;

    void solve(vector<int>& temp, vector<int>& nums) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            //temp mein nhi hai ele tbhi na lenge usko; used set bcz find operation takes O(1) time in set
            if (st.find(nums[i]) == st.end()) {
                // pick
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                // explore
                solve(temp, nums);
                // undo the action, not pick
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // 1st approach using temp array & set to avoid duplicates in the
        // result: to avoid exploring the same elements twice
        n = nums.size();
        vector<int> temp;
        solve(temp, nums);
        return result;
    }
};