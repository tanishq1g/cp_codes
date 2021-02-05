int Solution::trailingZeroes(int n) {
    int p = 5, cnt = 0;
    while( p <= n){
        cnt += n / p;
        p *= 5;
    }
    return cnt;
}
