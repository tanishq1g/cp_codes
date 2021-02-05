vector<int> Solution::stepnum(int a, int b) {
    set<int> ve;
    queue<string> q;
    q.push("0");
    q.push("1");
    q.push("2");
    q.push("3");
    q.push("4");
    q.push("5");
    q.push("6");
    q.push("7");
    q.push("8");
    q.push("9");
    string str;
    int sq;
    long long int no, mno;
    int ss;
    bool flag = false;
    while(1){
        sq = q.size();
        mno = 0;
        for(int i = 0; i < sq; i++){
            str = q.front();
            // cout << str << '\n';
            no = stol(str);
            if(no >= a && no <= b)
                ve.insert(no);
            mno = max(mno, no);
            q.pop();
            if(str[0] != '1' && str[0] != '0'){
                q.push(char(str[0] - 1) + str);
            } 
            if(str[0] != '9'){
                q.push(char(str[0] + 1) + str);
            } 
            ss = str.size() - 1;
            if(str[ss] != '0'){
                q.push(str + char(str[ss] - 1));
            } 
            if(str[ss] != '9'){
                q.push(str + char(str[ss] + 1));
            } 
        }
        if(mno >= b){
            flag = true;
            break;
        }
    }

    vector<int> ret(ve.begin(), ve.end());
    return ret;
}
