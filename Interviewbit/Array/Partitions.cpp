int Solution::solve(int n, vector<int> &ve) {
    if(n < 3){
        return 0;
    }
    long long int su = 0;
    for(int i = 0; i < n; i++){
        su += ve[i];
    }
    if(su % 3 != 0)
        return 0;
    long long int need_su = su / 3;
    int s1 = 0, s3 = 0, i, j;
    for(i = 0; i < n - 2; i++){
        s1 += ve[i];
        if(s1 == need_su)
            break;
    }
    for(j = n - 1; j > i + 1; j--){
        s3 += ve[j];
        if(s3 == need_su)
            break;
    }

    // int s11 = 1, s33 = 1;
    s1 = 0; 
    s3 = 0;
    vector<int> ch(n, 0);  
    ch[i] = 1;
    for(int k = i + 1; k < j - 1; k++){
        s1 += ve[k];
        ch[k] = ch[k - 1];
        if(s1 == 0)
            ch[k]++;
    }
    int count = ch[j - 2];
    for(int k = j - 1; k > i + 1; k--){
        s3 += ve[k];
        // cout << k << ' ' << s3 << '\n';
        if(s3 == 0){
            count += ch[k - 2];
        }
    }
    // count += s11 * s33;
    return count;
}


#define ll long long
int Solution::solve(int A, vector<int> &B) {
    ll tot = 0;
    for(int val : B){
        tot += (ll)(val);
    }
    
    if(tot%3 != 0)return 0;
    
    tot = tot/3;
    ll cur  = 0,x = 0, ans = 0;
    for(int i =0;i<A-1;++i){
        cur += (ll)B[i];
        if(cur == 2*tot && i > 0){
            ans += x;
        }
        if(cur == tot){
            ++x;
        }
    }
    return ans;
    
    