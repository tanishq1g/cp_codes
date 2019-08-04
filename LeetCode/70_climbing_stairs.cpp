#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

void printvector(vector<int> &a){
    for (size_t i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<' ';
    }
    cout << '\n';
}

class Solution {
    int N;
    vector<int> mem;
public:
    // BRUTE FORCE
    // int count(int c, int n){
    //     if(c > n)
    //         return 0;
    //     if(c == n)
    //         return 1;
    //     return count(c + 1, n) + count(c + 2, n);
    // }
    // int climbStairs(int n) {
    //     int x = count(0, n);
    //     return x;
    // }

    // BRUTE FORCE WITH MEMOIZATION
    // int count(int c){
    //     if(c > N)
    //         return 0;
    //     if(c == N)
    //         return 1;
    //     if(mem[c] != 0)
    //         return mem[c];
    //     return count(c + 1) + count(c + 2);
    // }
    // int climbStairs(int n) {
    //     N = n;
    //     mem = vector<int>(n);
    //     // printvector(mem);
    //     int x = count(0);
    //     return x;
    // }

    // DP
    // int climbStairs(int n){
    //     if(n == 1)
    //         return 1;
    //     N = n + 1;
    //     mem = vector<int>(N);
    //     mem[0] = 0;
    //     mem[1] = 1;
    //     mem[2] = 2;
    //     for (size_t i = 3; i < N; i++){
    //         mem[i] = mem[i - 1] + mem[i - 2];
    //     }
    //     return mem[N - 1];
    // }


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
        if(n <= 2)
            return n;
        // n = n - 1;
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
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol.climbStairs(n);
    return 0;
}