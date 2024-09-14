class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0, largestNumber = INT_MIN, ansLen = 0;
        for(auto i: nums) largestNumber = max(largestNumber, i);
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == largestNumber) len++;
            else {
                ansLen = max(len, ansLen);
                len = 0;
            }
        }
        ansLen = max(ansLen, len);
        return ansLen>0?ansLen:1;
        
    }
};