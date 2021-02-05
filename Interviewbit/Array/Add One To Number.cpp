vector<int> Solution::plusOne(vector<int> &a) {
    for(int i = a.size() - 1; i >= 0; i--)
    {
        a[i] += 1;
        int rem = a[i] % 10;
        if (rem == 0) {
            a[i] = 0;
            if(i == 0){
                a.insert(a.begin(), 1);
            }
        }
        else{
            break;
        }
    }

    for(int i = 0; i < a.size();)
    {
        if(a[i] == 0)
            a.erase(a.begin());
        else
            break;
    }

    return a;
}
