class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        //basic edge case
        if(n == 0) return 0;
        int maxLen = 0;
        vector<int> map(256, -1);
        int l = 0, r = 0;
        while(r < n){
            if(map[s[r]] != -1){
                l = max(map[s[r]]+1, l);
            }
            map[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
        
    }
};