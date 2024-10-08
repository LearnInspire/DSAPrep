class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int i;
        for(char &ch:s) {
            if(ch == '['){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        //stack size = opening brackets
        return ((st.size()+1)/2);
    }
};