class Solution {
public:
    // TC: O(n logn), SC: O(n)
    //Implementation using Hashmap
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<string> result;
        map<int, string> mp;
        for(int i = 0; i<names.size(); i++){
            mp[heights[i]] = names[i];
        }

        for(auto i: mp){
            result.push_back(i.second);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};