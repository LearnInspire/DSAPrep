class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //if array is empty
        if(nums.size() == 0) return 0;
        /* using 2 pointer approach, keeping 1st to keep track of unique ele, 2nd to traverse thru the array 
        by comparing the 1st pointers ele & checking whether they're unique or different, return the i wherever 1st is standing as the no of unique elements*/
        int first = 0;

        for(int second = 1; second<nums.size(); second++){
            if(nums[first] != nums[second]){
                first++;
                nums[first] = nums[second];
            }
        }
        return (first+1);
    }
};