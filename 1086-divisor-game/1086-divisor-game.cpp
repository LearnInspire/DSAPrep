class Solution {
public:
    bool divisorGame(int n) {
        //recursive solution
        /*if(n<=1) return false;
        for(int x = 1; x < n; x++){
            if(n % x == 0){
                return !divisorGame(n-x);
            }
        }
        return false;*/

        //mathematical solution
        if(n % 2 == 0){
            return true;
        }
        else return false;
    }
};