// it reduces to finding the shortest path in an unweighted graph. 

// int Solution::knight(int a, int b, int c, int d, int e, int f) {
//         // => The chessboard is of size A x B.
//         // => The Knight is initially at position (C, D).
//         // => The Knight wants to reach position (E, F).
//     struct cmp{
//         bool operator ()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
//         const {
//             return a.first <= b.first;
//         }
//     };
//     vector<vector<bool> > vis(a + 1, vector<bool> (b + 1, false));
//     vector<vector<int> > dist(a + 1, vector<int> (b + 1, INT_MAX));
//     vis[c][d] = true;

//     set<pair<int, pair<int, int>>, cmp> st;

//     vector<int> dx{-1, -2, -1, -2, 1, 2, 1, 2};
//     vector<int> dy{-2, -1, 2, 1, -2, -1, 2, 1};
//     int x, y;
    
//     for(int i = 0; i < 8; i++){
//         x = c + dx[i];
//         y = d + dy[i];
//         if(x <= 0 || y <= 0 || x > a || y > b){
//             continue;
//         }
//         cout << x << ' ' << y << '\n';
//         // dist[x][y] = 1;
//         st.insert(make_pair(1, make_pair(x, y)));
//     }
    
//     for(auto itr = st.begin(); itr != st.end(); itr++){
//         cout << itr->first << ' ' << itr->second.first << ' ' << itr->second.second << '\n';
//     }

//     set<pair<int, pair<int, int>>, cmp>::iterator itr;

//     int mx, my;
//     while(st.empty()){
//         itr = st.begin();
//         mx = itr->second.first;
//         my = itr->second.second;
//         vis[mx][my] = true;

//         for(int i = 0; i < 8; i++){
//             x = mx + dx[i];
//             y = my + dy[i];
//             if(x <= 0 || y <= 0 || x > a || y > b){
//                 continue;
//             }
//             if(vis[x][y])
//                 continue;
//             cout << x << ' ' << y << '\n';
            
//         }    
//         st.erase(itr);
//     }
//     return 0;
// }


int Solution::knight(int A, int B, int C, int D, int E, int F) {
    // If initial and final position are the same.
    if(C==E && D==F)
        return 0;
    
    // Moves a knight can make.
    pair<int, int> moves[]={{1,2}, {1,-2}, {-1,2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited;
    
    // Visited array, initially all positions not visited.
    for(int i=0; i<A; i++)
    {
        vector<bool> tmp(B, false);
        visited.push_back(tmp);
    }
    
    // Initial position.
    q.push({{C-1, D-1}, 0});
    visited[C-1][D-1]=true;
    
    
    
    // BFS
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int moves_till_now=q.front().second; // Number of moves.
        
        q.pop();
        
        // Trying all moves.
        for(int i=0; i<8; i++)
        {
            int row=x+moves[i].first;
            int col=y+moves[i].second;
            
            if(row==E-1 && col==F-1) // If goal reached.
                return moves_till_now+1;
            
            // Checking bounds and that this is first visit.
            if(row>=0 && row<A && col>=0 && col<B && !visited[row][col])
            {
                visited[row][col]=true;
                q.push({{row,col}, moves_till_now+1});
            }
        }
        
    }
    // If goal unreachable.
    return -1;
}
