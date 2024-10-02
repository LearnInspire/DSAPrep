class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp; //ele->rank
        //to remove duplicates & save in sorted order & assign ranks acc to ascending order
        set<int> st(begin(arr), end(arr));

        int rank = 1;
        for(auto &num: st){
            mp[num] = rank;
            rank++;
        }

        //generating ans array usimg lookup in map & returning rank accordingly
        for(int i = 0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};