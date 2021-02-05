// int Solution::hammingDistance(const vector<int> &ve) {
//     int n = ve.size();
//     int mo = 1000000007;
//     int count = 0;
//     int c, cnt;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             c = ve[i] ^ ve[j];
//             cnt = 0;
//             while(c){
//                 c = c & (c - 1);
//                 cnt++;
//             }  
//             count = (count + cnt) % mo;
//             count = (count + cnt) % mo;
//         }    
//     }
//     return count;
// }


// int Solution::hammingDistance(const vector<int> &ve) {
//     int n = ve.size();
//     int mo = 1000000007;
//     int count = 0;
//     int x0, x1;
//     for(int i = 0; i < 31; i++){
//         x0 = 0; x1 = 0;
//         for(int j = 0; j < n; j++){
//             if(ve[j] & (1 << i))
//                 x1++;
//             else
//                 x0++;
//         }
//         count = (count + (2 * (x0 * x1)) % mo);
//         if(count >= mo)
//             count -= mo;
//         // cout << i << ' ' << x0 << ' ' << x1 << ' ' << count << '\n';
//     }
//     return count;
// }


int Solution::hammingDistance(const vector<int> &A) {
    int inputSize = A.size();
    int mod = 1000000007;
    int sum = 0;
    for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
        int cntBitOne = 0, cntBitZero = 0;
        for(int i = 0; i < inputSize; i++) {
            if (A[i] & (1 << bitPosition)) cntBitOne++;
            else cntBitZero++;
        }
        sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
        if (sum >= mod) sum = sum - mod;
    }
    return sum;
}