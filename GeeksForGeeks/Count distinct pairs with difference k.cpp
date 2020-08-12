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
#include <deque>
#include <stack>
#include <utility>

using namespace std;
#define INF 1e7

// hashing

#define MAX 100000
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)cin>>arr[i];
        
        int k; cin>>k;
        
        int fre_count[MAX]={0};
        
        for(int i=0;i<n;i++)
        {
            fre_count[arr[i]]++;
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            int x=arr[i];
            fre_count[x]--;
            if(x-k >=0 && fre_count[x-k]>0)
            count++;
            else if(x+k < MAX && fre_count[x+k]>0)
            count++;
            fre_count[x]=0;
        }
        cout<<count<<endl;
    }
    return 0;
}