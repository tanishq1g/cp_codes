string Solution::multiple(int n) {
    string str = "1";
    int s = to_string(n).size();
    for(int i = 1; i < s; i++){
        str += '0';
    }
    long long int no = stoll(str);
    int ss;
    bool ins;
    while(no % n != 0){
        ss = str.size();
        ins = false;
        for(int i = ss - 1; i >= 0; i--){
            // cout << i << '\n';
            if(str[i] == '0'){
                str[i] = '1';
                for(int j = i + 1; j < ss; j++){
                    str[j] = '0';
                }
                ins = true;
                break;
            }
        }
        if(ins == false){
            str = "1";
            for(int i = 0; i < ss; i++){
                str += '0';
            }
        }
        // cout << str << ' ' << no <<' ' << ss <<  '\n';
        no = stoll(str);
    }
    return str;
}
