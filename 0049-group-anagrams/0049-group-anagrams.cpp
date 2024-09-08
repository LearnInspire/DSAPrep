class Solution {
public:
    //method1: using sorting, sort all of the strings of input array & maintain a map
    //eg: aet-> {eat, tea, ate} in sbko jb sort krenge toh string bnegi aet so jinko bhi 
    //sort krke aet bnega voh sbko ek grp mein daalo coz voh anagrams honge
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //length of string
        int n = strs.size();

        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i<n; i++){
            string temp = strs[i];
            sort(begin(temp), end(temp));
            mp[temp].push_back(strs[i]);
        }

        for(auto it: mp){
            result.push_back(it.second);
        }
        
        return result;
    }

    /*vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    }*/
};