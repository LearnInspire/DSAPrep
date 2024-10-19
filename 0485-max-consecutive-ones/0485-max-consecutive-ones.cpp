class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxLen = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            maxLen = max(cnt, maxLen);
        }
        return maxLen;
    }
};