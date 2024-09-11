class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int differentBit = start ^ goal;
        while(differentBit){
            //AND operation with 1
            if(differentBit & 1){
                count ++;
            }
            //right shift by 1
            differentBit = differentBit >> 1;
        }
        return count;
    }
};