class Solution {
public:
//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(nlogn), S.C : O(n)
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        //iterate over string array
        for(int i = 0; i<n; i++){
            string time = timePoints[i];

            string hourSubstr = time.substr(0,2);
            string minsSubstr = time.substr(3);

            int hrmins = stoi(hourSubstr);
            int mins = stoi(minsSubstr);

            minutes[i] = 60*hrmins + mins;
        }
        //sort the minutes array
        sort(begin(minutes), end(minutes));

        int result = INT_MAX;
        for(int i = 1; i<n; i++){
            result = min(result, minutes[i]-minutes[i-1]);
        }
        
        return min(result, (24*60 - minutes[n-1] + minutes[0]));
    }
};