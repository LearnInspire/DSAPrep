class Solution {
    #define pic pair<int,char>
public:
    string longestDiverseString(int a, int b, int c) {
        string res; //Stores Longest happy string
        priority_queue<pic> maxheap;
        if(a>0) maxheap.push({a,'a'});
        if(b>0) maxheap.push({b,'b'});
        if(c>0) maxheap.push({c,'c'});

        //Try forming max length string as per constraint
        while(!maxheap.empty()){
            auto [count,character] = maxheap.top();
            maxheap.pop();

            int n=res.size();
            //Check if the current character has occurred in previous 2 indices
            if(n>=2 and res[n-1]==character and res[n-2]==character){
                if(maxheap.empty())
                    break;

                auto [nextCount,nextCharacter] = maxheap.top();
                maxheap.pop();

                res.push_back(nextCharacter);
                nextCount--;
                if(nextCount>0)
                    maxheap.push({nextCount,nextCharacter});
            }else{
                count--;
                res.push_back(character);
            }
            if(count>0)//Re-push the current character only if it has 1+ frequency
                maxheap.push({count,character});
        }
        return res;
    }
};