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

int partition(vector<int> &ve, int low, int high){
    int pivot = ve[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(ve[j] < pivot){
            i++;
            swap(ve[i], ve[j]);
        }
    }
    i++;
    swap(ve[i], ve[high]);
    return i;
}

int random_partition(vector<int> &ve, int low, int high){
    int n = high - low + 1;
    int pivot = rand() % n;
    swap(ve[low + pivot], ve[high]);
    return partition(ve, low, high);
}

void quicksort(vector<int> &ve, int low, int high){
    if(low >= high)
        return ;
    int pi = partition(ve, low, high);
    quicksort(ve, low, pi - 1);
    quicksort(ve, pi + 1, high);
}

int quickselect(vector<int> &ve, int low, int high, int k){
    if(k <= high && k >= low){
        int pi = random_partition(ve, low, high);
        // int pi = partition(ve, low, high);

        // cout << low << ' ' << high << ' ' << pi << ' ' << k << '\n';
        // for(int i = 0; i < ve.size(); i++){
        //     cout << ve[i] << ' ';
        // } cout << endl;
        if(k == pi)
            return ve[k];
        if(pi > k){
            return quickselect(ve, low, pi - 1, k);
        }
        return quickselect(ve, pi + 1, high, k);
    }
    return INT_MIN;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n;
        vector<int> ve(n);
        // int x;
        // priority_queue <int, vector<int>, greater<int> > pq;
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
            // cin >> x;
            // pq.push(x);
        }        
        cin >> k;
        // sort(ve.begin(), ve.end());
        // make_heap(ve.begin(), ve.end(), comp);
        //     // for (auto i : ve) std::cout << i << ' ';cout << endl;
        // for(int i = 0; i < k - 1; i++){
        //     // cout <<pq.top()<<'\n';
        //     // pq.pop();
        //     // cout <<ve.front() << ' '<< ve.size() << '\n';
        //     pop_heap(ve.begin(), ve.end() - i, comp);
        //     // for (auto i : ve) std::cout << i << ' ';cout << endl;
        // }
        // cout << ve.front() << '\n';

        // quicksort(ve, 0, n - 1);
        // for(int i = 0; i < n; i++){
        //     cout << ve[i] << ' ';
        // } cout << endl;
        cout << quickselect(ve, 0, n - 1, k - 1) << '\n';
    }
    return 0;
}
