class Solution {
public:
    /*m2: 2 pointer approach
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int left = nums[0];
        int right = nums[n-1];
        while(left < right){
            long long sum = nums[left] + nums[right];
            if(sum == target){
                ans.push_back(left);
                ans.push_back(right);
                return ans;
            }
            else if(sum<target){
                left++;
            }
            else {
                right--;
            }
        }
        return {};
    }*/
    //m1: using unordered map, traversing & storing the current ele in map while looking for target - current in map
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            int firstEle = nums[i];
            int secondEle = target - firstEle;
            if(mp.find(secondEle) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[secondEle]);
                return ans;
            }
            mp[firstEle] = i;
        }
        return ans;
    }
};