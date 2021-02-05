int Solution::solve(int n) {
    int mod = 1e9 + 7, count = 0, i;
    if(n <= 1)
        return n;
    
    count = 1;
    for(i = 2; i < 32; i++){
        if(n < (1 << i)){
            break;
        }
        else{
            count += (1 << (i - 1)) + ((1 << (i - 2)) * (i - 1));
        }
        cout << i << ' ' << count << '\n';
    }
    
    return 0;
}
