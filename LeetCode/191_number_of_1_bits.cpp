class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        for (int i = 0; i < 32; i++)
        {
            if(1 & n)
                c++;
            n = n >> 1;
        }

    }
    int hammingWeight(uint32_t n) {
        int c = 0;
        while(n != 0){
            c++;
            n = n & (n-1);
        }
        return c;
    }
};