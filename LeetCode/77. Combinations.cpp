// backtrack

class Solution {
    vector<vector<int>> ve;
    void func(vector<int> &a, vector<int> &cur, int ind, int k, int &n){
        cur.push_back(a[ind]);
        k--;
        if(k == 0){
            ve.push_back(cur);
            cur.pop_back();
            return;
        }
        for(int i = ind + 1; i < n; i++){
            func(a, cur, i, k, n);
        }
        cur.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            a[i] = i + 1;   
        }
        vector<int> cur;
        for(int i = 0; i < n; i++){
            func(a, cur, i, k, n);
        }
        return ve;
    }
};