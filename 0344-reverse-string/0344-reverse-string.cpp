class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0, last = s.size()-1;
        while(first < last) {
            swap(s[last], s[first]);
            last--;
            first++;
        }
    }
};