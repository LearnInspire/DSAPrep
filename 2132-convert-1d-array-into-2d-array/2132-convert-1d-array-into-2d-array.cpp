class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //using nested loops, TC: O(m*n) or O(len)
        int len = original.size();
        if(len != m*n) return {};

        int x = 0; //pointer for 1d array
        vector<vector<int>> res(m, vector<int>(n));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                res[i][j] = original[x++];
            }
        }
        return res;
    }
};