// binets method for finbonacci series
    void print2d(vector<vector<double> > &arr){
        for (size_t i = 0; i < arr.size(); i++){
            for (size_t j = 0; j < arr[i].size(); j++){
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    vector<vector<double> > multiply_matrices(vector<vector<double> > &a, vector<vector<double> > &b){
        vector<vector<double> > c{{1,1},{1,1}};
        for (int i = 0; i < 2; i++){
            for (size_t j = 0; j < 2; j++){
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }

    int climbStairs(int n){
        vector<vector<double> > arr{{1, 1}, {1, 0}};
        vector<vector<double> > ans{{1, 0}, {0, 1}};

        // binary representation of n and right shift
        while(n > 0){
            if((n & 1) == 1){
                ans = multiply_matrices(ans, arr);
                // cout<<"ans"<<'\n';print2d(ans);
            }
            n = n >> 1;
            // cout<<"n"<<n<<'\n';
            arr = multiply_matrices(arr, arr);
            // cout<<'\n'<<n<<'\n'<<"ans\n";print2d(ans);
            // cout<<"arr"<<'\n';print2d(arr);
        }
        return ans[0][0];
    }