class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
                int m = rolls.size();
        int sumOfM = 0;
        for(int i = 0; i < m; i++) sumOfM += rolls[i];
        int sumRem = mean*(m+n) - sumOfM;
        cout<<sumRem;
        if(sumRem>n*6 || sumRem<n) return {};
        // remainder dekho, aur quotient
        // jitna quotient hai, vo toh sbko min milega hi bki jitna bcha vo spread krdo
        int q = sumRem/n;
        int r = sumRem%n;
        vector<int>res(n, q);
        for(int i=1;i<=r;i++) res[i]++;
        return res;
    }
};