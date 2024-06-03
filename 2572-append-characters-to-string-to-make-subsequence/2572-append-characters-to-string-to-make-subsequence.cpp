class Solution {
public:
    int appendCharacters(string s, string t) {
        int slength = s.length(), tlength = t.length();
        int first=0, second=0;
        while(first < slength && second < tlength )
        {
            if(s[first] == t[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(second >= tlength) return 0;
        if(first >= slength)
        {
           return (tlength - second);
        }
        return 0;
    }
};