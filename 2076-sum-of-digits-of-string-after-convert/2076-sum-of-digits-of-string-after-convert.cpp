class Solution {
public:
    int transform(int x) {
        int num = 0;
        while(x) {
            num+=x%10;
            x/=10;
        }
        return num;
    }
    int convert(string s) {
        int res = 0;
        for(int i=0;i<s.length();i++) {
            res+=(s[i]-'0');
        }
        return res;
    }
    
    int getLucky(string s, int k) {
                string sum = "";
        for(int i=0;i<s.length();i++) sum+=to_string((s[i]-'a')+1);
        int x = convert(sum);
        cout<<x;
        while(k>1) {
            x = transform(x);
            k--;
        }
        return x;
    }
};