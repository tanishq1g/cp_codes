
// permutation recursion array

class Solution {
public:
    int count, n2;
    void func(vector<int> &ve, int l, int r){
        // for(int i = 0; i < n2; i++){
        //     cout << ve[i] << ' ';
        // } cout << endl;
        if(l == r){
            // for(int i = 1; i <= n2; i++){
            //     if(i % ve[i - 1] == 0 || ve[i - 1] % i == 0)
            //         continue;
            //     else
            //         return;
            // }
            if((l + 1) % ve[l] == 0 || ve[l] % (l + 1) == 0){
                count++;
            }
            // count++;
            return;
        }
        for(int i = l; i <= r; i++){
            swap(ve[l], ve[i]);
            if((l + 1) % ve[l] == 0 || ve[l] % (l + 1) == 0){
                func(ve, l + 1, r);
            }
            swap(ve[l], ve[i]);
        }
    }
    int countArrangement(int n) {
        count = 0;
        n2 = n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            ve[i] = i + 1;   
        }
        func(ve, 0, n - 1);
        return count;
    }
};