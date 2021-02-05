int Solution::titleToNumber(string str) {
    int n = str.size();
    int c = 0;
    
    for(int i = 0; i < n; i++){
        c += (str[i] - 'A') * pow(26, n - i - 1);
    }
    return c;
}
