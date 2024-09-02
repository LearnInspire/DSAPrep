class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        //method 2: calculate remainder & iterate once, TC: O(2n)
        //in constraints, k value is very big so take long long instead of int
        long long totalSum = 0; //totalChalksInOneIteration

        for(int i = 0; i<chalk.size(); i++){
            totalSum += chalk[i];
            //if k is so small that we can't even run 1st iteration, then don't sum till end & break
            //then return the index post running for loop where it will exhaust 
            if(totalSum > k){  
                break;
            }
        }

        //remainder 
        int remaining = k % totalSum;
        for (int j = 0; j < chalk.size(); j++){
            if(remaining < chalk[j]){
                return j;
            }
            remaining -= chalk[j];
        }
        return -1;

        /*method 1: using simulation means whatever stated in ques, will implement in the similar fashiom
        while(true){
            //iterate through the array
            for(int i = 0; i<chalk.size(); i++){
                if(k < chalk[i]){
                    return i;
                }
                k -= chalk[i];
            }
        }
        /method 1 gives TLE error; TC: O((k/sum) * n)      */
    }
};