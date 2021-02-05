bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    vector<pair<int, char> > ve;
    for(int i = 0; i < n; i++){
        if(arrive[i] == depart[i])
            continue;
        ve.push_back(make_pair(arrive[i], 'a'));    
        ve.push_back(make_pair(depart[i], 'd'));
    } 
    sort(ve.begin(), ve.end(), [](const pair<int, char> &a, const pair<int, char> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    int c = 0;
    int nn = ve.size();
    for(int i = 0; i < nn; i++){
        if(ve[i].second == 'a')
            c++;
        else{
            c--;
        }
        if(c > K)
            return false;
    }
    return true;
}
