class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n); //to store left side product
        vector<int> right(n); //to store right side product for any particular element

        left[0] = 1;
        right[n-1] = 1;
        //to store in left 
        for(int i = 1; i<n; i++){
            left[i] = left[i-1]*nums[i-1];
        }

        //to store in right
        for(int i = n-2; i>=0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        
        vector<int> result(n);
        for(int i = 0; i<n; i++){
            result[i] = left[i] * right[i];
        }
        return result;
    }
};