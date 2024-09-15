class Solution {
public:
    /*A2: we don't need any array to store freq of vowels, we can take a mask & do the XOR with 1<<x, x = no of shifts
    as per the vowel, for a do shift 1 time, for e do it 2 times, for i for 3 times & so on*/
    int findTheLongestSubstring(string s) {
        int mask = 0; //00000 presenting aeiou frequencies
        unordered_map<int, int> mp;
        mp[mask] = -1; //initially
        int result = 0;

        for(int i = 0; i < s.length(); ++i){
            if(s[i] == 'a'){
                mask = mask ^ (1<<0);
            }
            if(s[i] == 'e'){
                mask = mask ^ (1<<1);
            }
            if(s[i] == 'i'){
                mask = mask ^ (1<<2);
            }
            if(s[i] == 'o'){
                mask = mask ^ (1<<3);
            }
            if(s[i] == 'u'){
                mask = mask ^ (1<<4);
            }

            if(mp.find(mask) != mp.end()){
                result = max(result, i - mp[mask]);
            }
            else{
                mp[mask] = i;
            }
        }
        return result;
    }




    /*int findTheLongestSubstring(string s) {
        //A1: storing freq of vowels in array of size 5 then storing the array state in strings,
        //storing the states in map & do look up in map & find the length of the substr, TC: O(n)
        unordered_map<string, int> mp;

        vector<int> state(5, 0); //a e i o u(00000)

        string currState = "00000";
        mp[currState] = -1;

        int result = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a'){
                //state[0] = (state[0] + 1) % 2;//slighter better way is instead of adding 1& finding %2, XOR 1^1 = 0
                //set bit as 1 if odd or set bit as 0 if even
                state[0] = state[0]^1;
            }
            else if(s[i] == 'e'){
                //state[1] = (state[1] + 1) % 2;
                state[1] = (state[1]^1);
            }
            else if(s[i] == 'i'){
                state[2] = (state[2]^1);
            }
            else if(s[i] == 'o'){
                state[3] = (state[3]^1);
            }
            else if(s[i] == 'u'){
                state[4] = (state[4]^1);
            }

        currState = "";
        for(int j = 0; j < 5; j++){
            currState += to_string(state[j]);
        }

        if(mp.find(currState) != mp.end()){
            result = max(result, i - mp[currState]);
        }
        else{
            mp[currState] = i; 
        }
        }
        return result;
    }*/
};