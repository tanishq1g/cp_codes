vector<int> Solution::flip(string a) {

    vector<int> sol(2);
    vector<int> arr(a.size());

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '0')
            arr[i] = 1;
        else
            arr[i] = -1;
    }
    // for(int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<' ';
    // }
    // cout<<'\n';
    // kadane's algo
    int sum = 0;
    int ma = INT_MIN;
    int p = -1, q = -1;

    for(int i = 0; i < arr.size(); i++)
    {
        if(sum < 0){
            sum = 0;
            p = i;
        }
        sum += arr[i];
        if(ma < sum){
            ma = sum;
            q = i;
            sol[0] = p;
            sol[1] = q;
        }
        // cout<<arr[i]<<" p "<<p<<" q "<<q<<" sum "<<sum<<" sol "<<sol[0]<<' '<<sol[1]<<" ma "<<ma<<'\n';
    }
    if(ma == -1)
        return vector<int> ();
    sol[0]++;
    sol[1]++;
    return sol;
}