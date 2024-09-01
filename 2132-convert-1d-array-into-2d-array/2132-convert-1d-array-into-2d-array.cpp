class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        int i = 0, j = 0;
        vector<vector<int>>res(m, vector<int>(n));
        int s = o.size();
        if(s != m*n) return {};
        for(int k = 0; k < s; k++) {
            if(j%n == 0 && j != 0) {
                i++;
                j = 0;
            }
            res[i][j] = o[k];
            j++;
        }
        return res;
        
    }
};