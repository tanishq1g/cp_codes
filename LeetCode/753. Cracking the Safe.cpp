class Solution {
public:
    set<string> st;
    string ans;
    int n, k;
    void dfs(string str){
        string temp = "";
        for(int i = 0; i < k; i++){
            temp = str + char(i + '0');
            // cout << str << ' ' << i << ' ' << temp << '\n';
            if(st.find(temp) == st.end()){
                cout << temp << '\n';
                st.insert(temp);
                dfs(temp.substr(1, n - 1));
                ans += char(i + '0');
            }
            
        }
    }
    string crackSafe(int nn, int kk) {
        ans = "";
        n = nn;
        k = kk;
        string t = "";
        for(int i = 1; i < n; i++){
            t += "0";
        }
        dfs(t);
        return ans + t;
    }
};