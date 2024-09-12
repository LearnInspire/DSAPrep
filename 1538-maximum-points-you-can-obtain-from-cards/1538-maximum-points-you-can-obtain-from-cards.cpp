class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum = 0, rsum = 0, maxSum = 0;
        for (int i = 0; i < k; i++){ // adding ele's with window size of k
            lsum = lsum + arr[i];
        } 
        maxSum = lsum;
        int n = arr.size();
        int rindex = n - 1;
        for (int i = k - 1; i >= 0; i--) { // removing one ele from window from k-1, k-2, k-3, k-4 & adding one ele from right
            lsum = lsum - arr[i];
            rsum = rsum + arr[rindex];
            rindex = rindex - 1;
            maxSum = max(maxSum, rsum + lsum);
        }
        return maxSum;
    }
};