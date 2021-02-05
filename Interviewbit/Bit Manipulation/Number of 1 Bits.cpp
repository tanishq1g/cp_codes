int Solution::numSetBits(unsigned int n) {
    // int count = 0;
    // for(int i = 0; i < 32; i++){
    //     if(n & (1 << i))
    //         count++:
    // }
    // return count;

    unsigned int total_ones = 0;
            while (x != 0) {
                x = x & (x-1);
                total_ones++;
            }
            return total_ones;
}
