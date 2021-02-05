int Solution::sqrt(int n) {
    if(n == 1)
        return 1;
    int mi = 1, ma = n, mid, sq;
    while(mi < ma){
        // cout << mi << ' ' << ma << '\n';
        if(ma > INT_MAX - mi){
            mid = floor(floor(mi / 2.0) + floor(ma / 2.0));
            // cout << floor(mi / 2.0) + floor(ma / 2.0) << ' ' << mid << '\n';
        }
        else
            mid = (ma + mi) / 2;
        if(mid > INT_MAX / mid){
            ma = mid;
            continue;
        }
        else
            sq = mid * mid;
        if(sq > n){
            ma = mid;
        }
        else if(sq < n){
            mi = mid + 1;
        }
        else 
            return mid;
    }
    return mi - 1;
}
