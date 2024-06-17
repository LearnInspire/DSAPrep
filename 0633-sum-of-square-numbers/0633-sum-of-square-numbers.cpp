class Solution {
public:
    //T(n) = O(n)
    bool judgeSquareSum(int c) {
        unordered_map<int, int> squares;

        for(int i = 0; i<= sqrt(c); i++){
            squares[i*i]++;
            int ans = c - i*i;

            if(squares[ans]){
                return true;
            }
        }
        return false;
    }
};