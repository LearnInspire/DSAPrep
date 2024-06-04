class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>freq;
        int count = 0, flag = 0;
        for(auto i: s) freq[i]++;
        for(auto i: freq) {
            if(i.second&1){
                flag = 1;
                count+=i.second-1;
            }  
            else count+=i.second;
        }
        return flag==1?count+1:count;
    }
};