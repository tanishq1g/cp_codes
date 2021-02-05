int Solution::solve(vector<int> &a, int b, int c) {
    if(c == 0)
        return 0;
    int n = a.size();
    vector<bool> ch(11, false);
    vector<int> count(11, 0);
    for(int i = 0; i < n; i++){
        ch[a[i]] = true;    
    } 
    for(int i = 1; i < 11; i++){
        count[i] = count[i - 1];
        if(ch[i - 1] == true)
            count[i]++;
        // cout << i << ' ' << count[i] << '\n';
    }

    string s = to_string(c);
    int ss = s.size();
    if(ss < b){
        return 0;
    }
    else if(ss > b){
        if(ch[0] == true && b > 1){
            return (count[10] - 1) * pow(count[10], b - 1);
        }
        else{
            return pow(count[10], b);
        }
    }

    int cnt = 0;
    if(ch[0] == true && ss > 1){
        cnt += (count[s[0] - '0'] - 1) * pow(count[10], ss - 1);
    }
    else{
        cnt += count[s[0] - '0'] * pow(count[10], ss - 1);
    }
    for(int i = 1; i < ss; i++){
        if(ch[s[i - 1] - '0'] == false){
            break;
        }
        // cout << cnt << '\n';
        cnt += count[s[i] - '0'] * pow(count[10], ss - i - 1); 
    }
    return cnt;
}
