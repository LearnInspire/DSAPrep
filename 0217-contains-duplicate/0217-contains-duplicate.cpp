class Solution {
public:
//Brute Force -> is to iterate through the array & compare every ele with every other ele, TC: O(n2), SC: O(1)
//2) Better -> sort the array first, while traversing in the first pass have two pointers, compare both of the elements
// & increment the pointers after each comparison. TC: O(n logn), sc: O(n)
//Optimal --> create one hashsset bcz set doesn't contains duplicates, start iterating the array if element isn't presnt in set
//i.e we haven't find the second instance yet & add the number to the set. If it's already present then return true.
// If there are no duplicates found then return false.
/*A set is chosen because it provides average (O(1)) time complexity for both insertions and membership checks, 
which makes it efficient for checking duplicates.*/

/*Sol 2:    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i< nums.size() - 1; i++){
            if(nums[i]== nums[i+1]){
                return true;
            }
        }
        return false;
    }*/

/*Sol 3:*/  bool containsDuplicate(vector<int>& nums) {
    unordered_set <int> seen;

    for(int i:nums){
        if(seen.count(i)>0)
            return true;
        seen.insert(i);
    }
    return false;
    }
};