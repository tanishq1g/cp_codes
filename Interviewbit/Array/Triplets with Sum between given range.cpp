int Solution::solve(vector<string> &A) {
    int n=A.size(),i;
    double power=1,num;
    vector<double>a;
    for(auto s:A){
        if(s[1]!='.'||s[0]>='2'){
            //a[i++]=2;
            continue;
        }
        num=0;
        num+=s[0]-'0';
        power=0.1;
        for(i=2;i<s.size();i++){
            num+=(s[i]-'0')*power;
            power/=10.0;
        }
        a.push_back(num);
    }
    //a contains all nos. lesser than 2 converted in double
    sort(a.begin(),a.end());
    double sum;
    if(a.size()<3)return 0;
    sum=a[0]+a[1]+a[2];
    if(sum>=2.0)return 0;
    n=a.size();
    sum=a[n-1]+a[n-2]+a[n-3];
    if(sum<=1)return 0;
    return 1;
}
