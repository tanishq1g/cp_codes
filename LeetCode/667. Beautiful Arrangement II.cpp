
// array recursion 
class Solution {
public:
    bool flag;
    vector<int> ret;
    int k2, n2;
    void func(vector<int> &ve, int l, int r){
        if(l == r){
            for(int i = 0; i < n2; i++){
                cout << ve[i] << ' ';
            } cout << endl;
            set<int> st;
            for(int i = 1; i < n2; i++){
                st.insert(abs(ve[i] - ve[i - 1]));
            }
            cout << st.size() << '\n';
            if(st.size() == k2){
                ret = ve;
                flag = true;
            }
            return;
        }
        for(int i = l; i <= r; i++){
            if(flag)
                return;
            swap(ve[l], ve[i]);
            func(ve, l + 1, r);   
            swap(ve[l], ve[i]);   
        }
    }
    vector<int> constructArray2(int n, int k) {
        vector<int> ve(n);
        k2 = k;
        n2 = n;
        for(int i = 0; i < n; i++){
            ve[i] = i + 1;
        }          
        flag = false;
        func(ve, 0, n - 1);
        return ret;
    }

    vector<int> constructArray(int n, int k) {
        vector<int> ve(n);
        int x = n - k;
        for(int i = 0; i < n; i++){
            ve[i] = i + 1;
        }          
        for(int i = x, p = 0; i < n; i += 2, p++){
            ve[i] = n - p; 
        }
        for(int i = x + 1, p = x + 1; i < n; i += 2, p++){
            ve[i] = p;
        }
        return ve;
    }
};