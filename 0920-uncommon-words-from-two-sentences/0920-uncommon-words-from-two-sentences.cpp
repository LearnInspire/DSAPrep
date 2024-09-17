class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> ans;

        stringstream ss1(s1), ss2(s2);
        string temp;

        while(ss1>>temp){
            mp[temp]++;
        }

        while(ss2>>temp){
            mp[temp]++;
        }

        for(auto itr: mp){
            if(itr.second == 1){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};