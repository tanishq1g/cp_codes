// int target;
// bool dfs(vector<vector<int> > &gr, vector<bool> &vis, int cur){
//     // cout << cur << '\n';
//     vis[cur] = true;
//     if(cur == target){
//         return true;
//     }
//     int sa = gr[cur].size();
//     for(int i = 0; i < sa; i++){
//         if(vis[gr[cur][i]] == false){
//             if(dfs(gr, vis, gr[cur][i], target)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// int Solution::solve(vector<int> &a, vector<int> &b, vector<vector<int> > &c) {
//     int nc = c.size();
//     int n = a.size();
//     vector<vector<int> > gr(n, vector<int> ());
//     for(int i = 0; i < nc; i++){
//         gr[c[i][0] - 1].push_back(c[i][1] - 1);
//         gr[c[i][1] - 1].push_back(c[i][0] - 1);
//     }
//     for(int i = 0; i < n; i++){
//         cout << i << "-- ";
//         for(int j = 0; j < gr[i].size(); j++){
//             cout << gr[i][j]<< ' ';
//         } cout << endl; 
//     }
//     vector<bool> vis(n, false);
//     target = 22;
//     cout << dfs(gr, vis, 15) << '\n';
//     for(int i = 0; i < n; i++){
//         if(a[i] != b[i]){
//             // cout << a[i] - 1 << ' ' << b[i]  - 1<< '\n';
//             vector<bool> vis(n, false);
//             target = b[i] - 1;
//             if(!dfs(gr, vis, a[i] - 1)){
//                 return false;
//             } 
//         }    
//     }
//     return true;
// }


int root(int a, vector<int> &s)
{
    while(a!=s[a])
    a=s[a];
    return a;
}
void add(int a, int b, vector<int> &s)
{
    int r1=root(a,s);
    int r2=root(b,s);
    if(r1==r2)
        return;
    s[r1]=s[r2];
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n=(int)A.size();
    int m=(int)C.size();
    vector<int> s(n+1,0);
    for(int i=0;i<=n;i++)
    s[i]=i;
    for(int i=0;i<m;i++)
    add(A[C[i][0]-1],A[C[i][1]-1],s);
    for(int i=0;i<n;i++)
    {
        if(root(A[i],s)!=root(B[i],s))
        return 0;
    }
    return 1;
}