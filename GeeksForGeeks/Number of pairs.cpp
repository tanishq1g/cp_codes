#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// array

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v1(n), v2(m);
        for(int i = 0; i < n; i++){
            cin >> v1[i];   
        }        
        for(int i = 0; i < m; i++){
            cin >> v2[i];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        // for(int i = 0; i < n; i++){
        //     cout << v1[i] << ' ';
        // } cout << endl;
        // for(int i = 0; i < m; i++){
        //     cout << v2[i] << ' ';
        // } cout << endl;
        int c = 0;
        vector<int>:: iterator itr;
        for(int i = 0; i < n; i++){
            if(v1[i] == 0){
                continue;
            }
            if(v1[i] == 1){
                for(int j = 0; j < n; j++){
                    if(v2[j] == 0){
                        c++;
                    }   
                    else{
                        break;
                    }
                }
                continue;
            }
            itr = upper_bound(v2.begin(), v2.end(), v1[i]);
            c += distance(itr, v2.end());
            // cout << i << ' ' << v1[i] << ' ' << *itr << ' ' <<distance(itr, v2.end()) << ' ' << c << '\n';
        }
        if(find(v2.begin(), v2.end(), 1) != v2.end()){
            int no1in2 = distance(find(v2.begin(), v2.end(), 1), upper_bound(v2.begin(), v2.end(), 1)); 
            int no2_in1 = distance(upper_bound(v1.begin(), v1.end(), 1), v1.end());
            c += no1in2 * no2_in1;
        }
        // cout << no1in2 << ' ' << no2_in1 << ' ' << *upper_bound(v2.begin(), v2.end(), 1) << '\n';
        cout << c << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll val,ll Y[],ll help[],ll n,ll m)
{
    if(val==0)
    return 0;
    if(val==1)
    return help[0];
    ll idx=upper_bound(Y,Y+m,val)-Y;
    ll res=m-idx;
    res+=help[0]+help[1];
    if(val==2)
    res-=(help[3]+help[4]);
    if(val==3)
    res+=help[2];
    return res;
}
int main() 
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll X[n],Y[m];
        for(ll i=0;i<n;i++)
        cin>>X[i];
        ll help[5]={0};
        for(ll i=0;i<m;i++)
        {   ll temp;
            cin>>temp;
            if(temp>=0 && temp<=4)
            help[temp]++;
            Y[i]=temp;
        }
        sort(Y,Y+m);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=solve(X[i],Y,help,n,m);
        }
        cout<<ans<<endl;
    }
	//code
	return 0;
}