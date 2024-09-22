class Solution {
public:
    //using C++ STL
    int diagonalSum(vector<vector<int>>& mat) {
        int row = 0;
        auto lambda = [&](int sum, vector<int> vec){
            //diagonal elements sum only, for odd size, the middle ele is only one in central row
            //for even matrix size, there will be two different elements
            sum += vec[row];
            //check for odd or even matrix & include second element accordingly
            if(row != vec.size()-row-1) sum += vec[vec.size()-row-1];
            row++;
            return sum;
        };

        int result = accumulate(begin(mat), end(mat), 0, lambda); //this is 2d matrix so mat is passed as a whole array, not a single element 
        return result;
        
    }
};