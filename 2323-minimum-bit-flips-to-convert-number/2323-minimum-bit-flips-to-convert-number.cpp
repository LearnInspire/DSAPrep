class Solution {
public:
/*Bit counting: Use a loop to repeatedly check the last bit of the XOR result using & 1. 
Right shift the XOR result (>> 1) to process the next bit. Continue until all bits are processed. 
The TC is O(k), where k is the number of bits in the binary representation of the larger of the two numbers (start or goal).*/
    int minBitFlips(int start, int goal) {
        int count = 0;
        // XOR will give 1 where the bits are different
        int differentBit = start ^ goal;
        while(differentBit){
            //If the last bit is 1, increment count
            count += differentBit & 1;
            //Right-shift to check the next bit
            differentBit = differentBit >> 1;
        }
        return count;
    }
};