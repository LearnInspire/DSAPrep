class Solution {
public:
    void solve(int idx, string& s, vector<string>& path, vector<vector<string>>& result){
        //base case
        if(idx == s.size()){
            result.push_back(path);
            return;
        }

        for(int i = idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solve(0, s, path, result);
        return result;
    }
};