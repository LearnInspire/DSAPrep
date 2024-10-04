class Solution {
/*recursive approach
private: 
    int bs(vector<int>& nums, int low, int high, int target){
        //base condition
        if(low > high) return -1;
        int mid = (low + high)/2;
        if(target == nums[mid]) return mid;
        else if(target > nums[mid]) return bs(nums, mid + 1, high, target);
        return bs(nums, low, mid - 1, target);
    }*/
public:
    int search(vector<int>& nums, int target) {
        /*iterative approach*/
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
        //return bs(nums, 0, nums.size()-1, target);
    }
};