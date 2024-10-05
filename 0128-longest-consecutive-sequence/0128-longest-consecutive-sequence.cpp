class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        //iterate thru the array & put everything in set
        //O(n)
        for(int i = 0; i<n; i++)
        {
            st.insert(nums[i]);
        }

        //start from the first element of the sequence,
        //we're not chceking the in b/w elements of the sequence
        //always start from the starting point & increase the length accordingly
        for(auto it : st)
        {
            //O(2n)
            if(st.find(it-1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    x = x + 1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};