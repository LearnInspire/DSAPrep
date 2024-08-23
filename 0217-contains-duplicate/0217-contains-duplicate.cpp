class Solution {
public:
//Brute Force -> is to iterate through the array & compare very ele with every other ele, TC: O(n2), SC: O(1)
//Better -> sort the array first, while traversing in the first pass have two pointers, compare both of the elements
// & increment the pointers after each comparison. TC: O(n logn), sc: O(n)
//Optimal --> create one hashsset bcz set doesn't contains duplicates, start iterating the array if element isn't presnt in set
//i.e we haven't find the second instance yet & add the number to the set. If it's already present then return true.
// If there are no duplicates found then return false.
    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i< nums.size() - 1; i++){
            if(nums[i]== nums[i+1]){
                return true;
            }
        }
        return false;
    }
};