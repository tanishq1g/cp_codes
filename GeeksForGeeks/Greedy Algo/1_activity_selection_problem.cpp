#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

// 1) Sort the activities according to their finishing time
// 2) Select the first activity from the sorted array and print it.
// 3) Do following for remaining activities in the sorted array.



void SelectActivities(vector<int>s,vector<int>f){ 
// Vector to store results. 
    vector<pair<int,int>>ans; 
  
// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 
  
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p; 
  
    for(int i=0;i<s.size();i++){ 
        // Pushing elements in priority queue where the key is f[i] 
        p.push(make_pair(f[i],s[i])); 
    } 
  
    auto it = p.top(); 
    int start = it.second; 
    int end = it.first; 
    p.pop(); 
    ans.push_back(make_pair(start,end)); 
  
    while(!p.empty()){ 
        auto itr = p.top(); 
        p.pop(); 
        if(itr.second >= end){ 
            start = itr.second; 
            end = itr.first; 
            ans.push_back(make_pair(start,end)); 
        } 
    } 
    cout << "Following Activities should be selected. " << endl << endl; 
  
    for(auto itr=ans.begin();itr!=ans.end();itr++){ 
        cout << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << endl; 
    } 
} 
  
// Driver program 
int main() 
{ 
    vector<int>s = {1, 3, 0, 5, 8, 5}; 
    vector<int>f = {2, 4, 6, 7, 9, 9}; 
    SelectActivities(s,f); 
  
    return 0; 
} 