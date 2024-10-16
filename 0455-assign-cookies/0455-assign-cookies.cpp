class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0;

        while(left < n && right < m){
            if(s[right] >= g[left]){
                left = left + 1;
            }
            right++;
        }
        return left;
    }
};