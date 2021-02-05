int Solution::solve(string a, string b, vector<string> &c) {
    c.push_back(a);
    c.push_back(b);
    int n = c.size();
    int ss = c[0].size(), cnt;
    vector<vector<int> > gr(n, vector<int> ());
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cnt = 0;
            for(int k = 0; k < ss; k++){
                if(c[i][k] != c[j][k]){
                    cnt++;
                }
                if(cnt > 1)
                    break;
            }
            if(cnt == 1){
                gr[i].push_back(j);
                gr[j].push_back(i);
            }
        }    
    }

    vector<bool> vis(n, false);
    
    int lev = 0;
    queue<int> q;
    q.push(n - 2);
    int sq, x, cn;
    bool flag = false;
    
    while(q.empty() == false){
        sq = q.size();
        for(int i = 0; i < sq; i++){
            x = q.front();
            if(x == n - 1){
                flag = true;
                break;
            }
            q.pop();
            vis[x] = true;
            cn = gr[x].size();
            for(int j = 0; j < cn; j++){
                if(vis[gr[x][j]] == false){
                    q.push(gr[x][j]);
                }
            }
        }
        lev++;
        if(flag)
            break;
    } 
    return lev ;
}



void transform(string temp,queue<string> &q,unordered_map<string,int> &mp,unordered_map<string,int> &vis)
{
    for(int i=0;i<temp.size();i++)
    {
        string s=temp;
        for(int j=0;j<26;j++)
        {
            s[i]='a'+j;
            if(mp.find(s)!=mp.end() && vis.find(s)==vis.end())
            {
                q.push(s);
                vis[s]=1;
            }
        }
    }
}
int Solution::solve(string A, string B, vector<string> &C) {
    int steps=0;
    if(A==B)return 0;
    
    unordered_map<string,int> mp;
    for(auto x:C)
    mp[x]=1;
    
    if(mp.find(B)==mp.end())
    return steps;
    
    queue<string> q;
    q.push(A);
    unordered_map<string,int> vis;
    vis[A]=1;
    steps=1;
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            auto temp=q.front();
            q.pop();
            if(temp==B)return steps;
            transform(temp,q,mp,vis);
        }
        steps++;
    }
    return steps;
}
