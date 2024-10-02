class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        //sort the list of lists
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        //traversing the vector
        for(int i = 0; i<n; i++){
        //ans khali hai, 1st interval add kro & khaali nhi hai but jaise [8,10] aaya jo 1,6 se bda hai 
        //so 8,10 ko agle interval mein add kro coz voh merge vali range mein nhi hai
            if(ans.empty() || arr[i][0] > ans.back()[1]) 
            {
                ans.push_back(arr[i]);
            }
            //merging is possible so pichle interval ke second ko comparison vale ke first se replace kro like 2,6 ko 1,3 mein krke hoga 1,6
            //but agr bda nhi hai toh jaise [15,18]hai pichla [16,17]hai comparison, so yeh merge hoga 16,17 ke liye new interval nhi hoga so use max
            else{
                ans.back()[1] = max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};