int Solution::maxArr(vector<int> &a) {
    vector<int> su(a.size()), di(a.size());

    int max_su = INT_MIN;
    int min_su = INT_MAX;

    int max_di = INT_MIN;
    int min_di = INT_MAX;

    for(int i = 0; i < a.size(); i++)
    {
        su[i] = a[i] + i;
        if(max_su < su[i])
            max_su = su[i];
        if(min_su > su[i])
            min_su = su[i];

        di[i] = a[i] - i;
        if(max_di < di[i])
            max_di = di[i];
        if(min_di > di[i])
            min_di = di[i];
    }
    // for(int i = 0; i < a.size(); i++)
    // {
    //     cout<<su[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i = 0; i < a.size(); i++)
    // {
    //     cout<<di[i]<<' ';
    // }

    // cout<<'\n'<<max_su<<' '<<min_su<<' '<<max_di<<' '<<min_di<<'\n';
    return max(max_su - min_su, max_di - min_di);
}
