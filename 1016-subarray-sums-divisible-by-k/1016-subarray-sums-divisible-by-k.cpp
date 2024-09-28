class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //best approach: TC:O(n), SC:O(n)
        int n = nums.size();
        int sum = 0, result = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; //for storing occurence of 0 sum, ek baar dekh chuke hai 0 ko

        for(int i = 0; i<n; i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end()){
                result += mp[rem];
            }
            mp[rem]++;
        }
        return result;

        /*Optimal approach from O(n3)2 loops to O(n2) 2 loops with cumulative sum, this gives TLE
        int n = nums.size();

        //cumulative sum
        for(int i = 1; i<n; i++){
            nums[i] += nums[i-1];
        }

        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){

                int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];

                if(sum % k == 0) count++;
            }
        }
        return count;*/
    }
};