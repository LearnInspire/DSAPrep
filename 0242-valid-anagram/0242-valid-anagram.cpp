class Solution {
public:
    bool isAnagram(string s, string t) {
        //check the length, if length of both strings are not same then return false; they aren't anagram
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> countS, countT;
        for(char c:s){
            countS[c]++;
        }
        for(char c: t){
            countT[c]++;
        }
        return countT == countS;
    }
};