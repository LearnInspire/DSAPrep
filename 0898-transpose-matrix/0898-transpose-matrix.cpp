class Solution {
public:
    //TC: O(m*n), SC:O(1) bcz we take the extra 2D array to return the result
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); //original matrix: m*n

        vector<vector<int>> result(n, vector<int>(m)); //n*m diagonal elements will be same, side ke left & right part swaps honge

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};