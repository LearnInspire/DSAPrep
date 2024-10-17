class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        //to keep track of the farthest index we can reach from the start
        int maxIndex = 0;
        //i is current index
        for(int i = 0; i<n; i++){
            //If the current index is greater than maxIndex, it means the current index is not reachable
            if (i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};