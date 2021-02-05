int Solution::divide(int p, int q) {
    long long A = p,B = q;
    if(B==0) return INT_MAX;
    if(B==1) return A;
    bool sign = 0;
    long long int ans = 0;
    if(A<0) sign = (!sign);
    if(B<0) sign = (!sign);
    A = abs(A),B = abs(B);
    if(B>A) return 0;
    while(A>B){
        for(long long int i=31;i>=0;i--){
            if((B<<i)<=A){
                ans = (ans|((long long)1<<(i)));
                A = (A-(B<<(i)));
                break;
            }
        }
    }
    if(ans>INT_MAX) return INT_MAX;
    if(!sign)return ans;
    else return 0-ans;
}
