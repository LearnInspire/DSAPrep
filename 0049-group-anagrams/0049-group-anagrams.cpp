class Solution {
public:
    /*method1: using sorting, sort all of the strings of input array & maintain a map
    eg: aet-> {eat, tea, ate} in sbko jb sort krenge toh string bnegi aet so jinko bhi 
    sort krke aet bnega voh sbko ek grp mein daalo coz voh anagrams honge
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //length of string
        int n = strs.size();

        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i<n; i++){
            string temp = strs[i];
            sort(begin(temp), end(temp)); //n log n for sorting
            mp[temp].push_back(strs[i]);
        }

        for(auto it: mp){
            result.push_back(it.second);
        }
        
        return result;
        //TC: k * n logn, n is input's string size
    }*/

    //method 2: Constraint was given that all letters are small case, so will make arry of 26 char 
    //& count each char of input string & maintain the frequency for the same
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, vector<string>> groups;

        for(int i = 0; i<strs.size(); i++){
            vector<int> freq(26, 0); //array with 26 char a to z initialized with 0
            for(auto ch: strs[i]) freq[ch - 'a']++;
            groups[freq].push_back(strs[i]);
        }
        
        for(auto it: groups) result.push_back(it.second);
        return result;
    }
    //TC: n * (m*26), n is input string size, m is size of each string
};