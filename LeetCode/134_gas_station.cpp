#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int s = gas.size();
//         if(s == 0)
//             return -1;
//         int start = -1, next = -1, fuel = 0;
//         for (int i = 0; i < s; i++){
//             if(gas[i] >= cost[i]){
//                 start = i;
//                 // cout<<"start "<<start<<'\n';
//                 next = i;
//                 fuel = 0;
//                 while(1){
//                     fuel = fuel + gas[next] - cost[next];
//                     next = next + 1;
//                     if(next == s)
//                         next = 0;
//                     // cout<<".  "<<fuel<<' '<<next<<'\n';
//                     if(fuel < 0){
//                         break;
//                     }
//                     if(next == start){
//                         return start;
//                     }
//                 }

//             }
//         }
//         return -1;
        int start = 0;
        int totalGas = 0, currGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            if (currGas < 0) {
                start = i;
                currGas = 0;
            }
            currGas = currGas + gas[i] - cost[i];
            totalGas = totalGas + gas[i] - cost[i];
        }
        if (currGas >= 0 && totalGas >= 0)
            return start;
        return -1;
    }
};