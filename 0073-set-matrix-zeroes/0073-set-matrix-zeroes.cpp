class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        // step 1: Traverse the matrix and mark 1st row & col accordingly:
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0)
                {
                    //mark the ith row
                    matrix[i][0] = 0;
                    //mark the jth col
                    if(j!=0)
                    {
                        matrix[0][j] = 0;
                    }
                    else col0 = 0;
                }
            }
        }

        //start from inner matrix, i = 1; j = 1
        // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][j]!=0)
                {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }
        // Step 3: mark first row then col as zero
        if(matrix[0][0] == 0)
        {
            for(int j = 0; j<n; j++)
            {
                matrix[0][j]=0;
            }
        }

        if(col0 == 0)
        {
            for(int i = 0; i<m; i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};