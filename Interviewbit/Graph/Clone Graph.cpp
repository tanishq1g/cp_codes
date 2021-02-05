/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode * Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL)
        return node;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> vis;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
    vis[node] = root;
    UndirectedGraphNode * cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        int sq = cur->neighbors.size();
        for(int i = 0; i < sq; i++){
            if(vis.find(cur->neighbors[i]) == vis.end()){
                vis[cur]->neighbors.push_back(new UndirectedGraphNode(cur->neighbors[i]->label));
                vis[cur->neighbors[i]] = vis[cur]->neighbors.back();
                q.push(cur->neighbors[i]);
            }
            else{
                vis[cur]->neighbors.push_back(vis[cur->neighbors[i]]);
            }
        }
    }
    return root;
}

