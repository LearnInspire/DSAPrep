class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int l = 0, r = 0, len = 0, zeros = 0, maxlen = 0;
        while (r < n) {
            if (nums[r] == 0)
                zeros++;

            if (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            if (zeros <= k) {
                len = r - l + 1;
                maxlen = max(len, maxlen);
            }
            r++;
        }
        return maxlen;
    }
};