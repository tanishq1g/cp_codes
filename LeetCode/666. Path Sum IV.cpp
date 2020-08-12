// tree

class Solution {
    int su;
public:
    void dfs(vector<int> &tr, int ind, int va){
        if(ind >= 15){
            su += va;
            return;
        }
        if(tr[ind] == -1){
            return;
        }
        int x = 2 * ind;
        if(x + 1 < 15 && tr[x + 1] == -1 && x + 2 < 15 && tr[x + 2] == -1){
            su += va;
        }
        if(x + 1 < 15){
            dfs(tr, x + 1, va + tr[ind]);
        }
        if(x + 2 < 15){
            dfs(tr, x + 2, va + tr[ind]);
        }
    }

    int pathSum(vector<int>& ve) {
        vector<int> tr(15, -1);
        int n = ve.size();
        int d, p, val;
        for(int i = 0; i < n; i++){
            d = ve[i] / 100;
            ve[i] %= 100;
            p = ve[i] / 10;
            ve[i] %= 10;
            val = ve[i];
            tr[pow(2, d - 1) - 1 + p - 1] = val;
        }
        for(int i = 0; i < n; i++){
            cout << tr[i] << ' ';
        } cout << endl;
        su = 0;
        dfs(tr, 0, 0);  
        return su;   
    }
};