int Solution::singleNumber(const vector<int> &ve) {
    // int n = ve.size(), x;
    // int ret = 0;
    // for(int i = 31; i >= 0; i--){
    //     x = 0;
    //     for(int j = 0; j < n; j++){
    //         if(ve[j] & (1 << i)){
    //             x += 1;
    //         }
    //     }
    //     if(x % 2 == 1){
    //         ret |= (1<<i);
    //     }
    // }
    // return ret;


    int n = ve.size();
       int result = 0;
       for (int i = 0; i < n; i++) {
           result ^= A[i];
       }
       return result;
}
