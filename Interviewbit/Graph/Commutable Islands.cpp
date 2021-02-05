int find_parent(int i, vector<int> &disjointset){
    if(disjointset[i] != i){
        disjointset[i] = find_parent(disjointset[i], disjointset);
    }
    return disjointset[i];
}
void unionsets(int i, int j, vector<int> &disjointset){
    // int ip = find_parent(i);
    // int jp = find_parent(j);
    // disjointset[ip] = jp;
    disjointset[i] = j;
}

int Solution::solve(int no_nodes, vector<vector<int> > &ve) {
    sort(ve.begin(), ve.end(), [](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });
    int n = ve.size();
    vector<int> disjointset(no_nodes + 1);
    for(int i = 0; i <= no_nodes; i++){
        disjointset[i] = i;
    }

    int total = 0;


    int ip, jp;
    for(int i = 0; i < n; i++){
        // for(int j = 0; j < 3; j++){
        //     cout << ve[i][j] << ' '; 
        // }cout << endl;
        ip = find_parent(ve[i][0], disjointset);
        jp = find_parent(ve[i][1], disjointset);
        if(ip != jp){
            total += ve[i][2];
            unionsets(ip, jp, disjointset);
        }
    }
    return total;
}
