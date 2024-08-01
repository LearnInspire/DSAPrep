class Solution {
public:
    int countSeniors(vector<string>& details) {
        //converting char to string first & then calculate age by getting
        // ones & tens places and checking if it's graeter than 60 or not
        int ans = 0;
        for(auto i:details){
            int age = (i[11] - '0')*10 + (i[12] - '0');
            if(age > 60) ans++;
        }
        return ans;

        /*
        int count = 0;
        // iterate through the array of strings
        for (int i = 0; i < details.size(); i++) {
            if (details[i][11] > '6' ||
                details[i][11] == '6' && details[i][12] > '0')
                count++;
        }
        return count; */
    }
};