class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        //first put all unique elements from nums1 in set1
        set<int> st1(begin(nums1), end(nums1));
        //put all unique elements from nums2 in set2
        set<int> st2(begin(nums2), end(nums2));

        vector<int> v1;
        vector<int> v2; //we will return {v1, v2}

        /*  set_difference: this STL copies the elements from the sorted s1 which aren't found in the sorted s2 to a
            container in sorted s2
            back_inserter: this STL can be used to add elements to the end of a container         */

        //find the difference in set1 and set2 & put unique elements of set1 in v1
        set_difference(begin(st1), end(st1), begin(st2), end(st2), back_inserter(v1));

        //find the difference in set2 and set1 & put all unique elements of set2 in v2
        set_difference(begin(st2), end(st2), begin(st1), end(st1), back_inserter(v2));

        return {v1, v2};
    }
};