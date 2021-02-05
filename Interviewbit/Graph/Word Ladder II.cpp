vector<vector<string> > Solution::findLadders(string a, string b, vector<string> &c) {
    c.push_back(a);
    c.push_back(b);
    int n = c.size();
    int ss = c[0].size(), cnt;
    vector<vector<int> > gr(n, vector<int> ());
    vector<vector<int> > parents(n, vector<int> ());
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
    vector<vector<string> > ret;
    while(q.empty() == false){
        sq = q.size();
        for(int i = 0; i < sq; i++){
            x = q.front();
            if(x == n - 1){
                flag = true;
                
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




void bfs(string& beginWord, string& endWord, unordered_set<string>& d, unordered_map<string, vector<string>>& neighbors, unordered_map<string, int>& dist){
    queue<string> q;
    q.push(beginWord);
    dist[beginWord] = 0;
    int lvl = 1;
    while(!q.empty()){
        int q_size = q.size();
        unordered_set<string> visited;
        for(int i = 0; i < q_size; i++){
            auto curr = q.front();
            q.pop();
            string nxt = curr;
            for(int j = 0; j < nxt.size(); j++){
                auto tmp = nxt[j];
                for(char c = 'a'; c <= 'z'; c++){
                    nxt[j] = c;
                    if(d.count(nxt) != 0){
                        neighbors[curr].push_back(nxt);
                        visited.insert(nxt);
                        if(dist.count(nxt) == 0){
                            dist[nxt] = lvl;
                            q.push(nxt);
                        }
                    }
                }
                nxt[j] = tmp;
            }
        }
        lvl++;
        for(string w: visited) d.erase(w);
    }
}

void dfs(string& curr, string& endWord, unordered_map<string, vector<string>>& neighbors, unordered_map<string, int>& dist, vector<string>& path, vector<vector<string>>& res){
    path.push_back(curr);
    if(curr == endWord){
        res.push_back(path);
        return;
    }
    for(auto nxt: neighbors[curr]){
        if(dist[nxt] == dist[curr] + 1){
            dfs(nxt, endWord, neighbors, dist, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> d(wordList.begin(), wordList.end());
    if(d.count(endWord) == 0) return res;
    unordered_map<string, vector<string>> neighbors;
    unordered_map<string, int> dist;
    bfs(beginWord, endWord, d, neighbors, dist);
    vector<string> path;
    dfs(beginWord, endWord, neighbors, dist, path, res);
    return res;
}