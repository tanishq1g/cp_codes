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

// STACK AND HEAPS



class LRUCache{
private:
    unordered_map<int, list<pair<int, int>>::iterator > umap;
    list<pair<int, int> > li;
    int cap;
public:
    LRUCache(int c){
        cap = c;
    }
    
    int get(int key){
        if(umap.find(key) == umap.end()){
            return -1;
        }
        unordered_map<int, list<pair<int, int>>::iterator >::iterator itr = umap.find(key);
        int x = itr->second->second;
        
        li.erase(itr->second);
        li.push_back(make_pair(key, value));
        list<pair<int, int>>::iterator it = li.end();
        advance(it, -1);
        umap[key] = it;
        return x;
    }
    
    void set(int key, int value){
        unordered_map<int, list<pair<int, int>>::iterator >::iterator itr = umap.find(key);

        if(itr == umap.end()){
            if(li.size() == cap){
                umap.erase(li.front().first);
                li.pop_front();
            }
            li.push_back(make_pair(key, value));
            list<pair<int, int>>::iterator it = li.end();
            advance(it, -1);
            umap[key] = it;
        }
        else{
            li.erase(itr->second);
            li.push_back(make_pair(key, value));
            list<pair<int, int>>::iterator it = li.end();
            advance(it, -1);
            umap[key] = it;
        }
        // cout << "\nstart " << li.size() << '\n';
        // for(list<pair<int, int> >::iterator itr = li.begin(); itr != li.end(); itr++){
        //     cout << itr->first << ' ' << itr->second << ' ' << ' ' ;
        // }cout << "\nend";
    }
};


8
82
SET 97 30 
GET 43 GET 13 SET 48 56 GET 67 GET 60 
SET 74 43 
SET 72 39 
SET 100 59 
GET 85 SET 91 62 GET 72 SET 1 4 GET 1 GET 53 GET 5 
SET 59 60 
SET 18 95 
GET 37 GET 61 GET 15 
SET 66 38 
GET 22 GET 10 
SET 33 1 
GET 5 
SET 57 59 
SET 69 11 SET 29 70 SET 75 47 GET 6 GET 2 SET 68 90 GET 27 GET 39 SET 1 6 GET 58 GET 49 SET 8 18 SET 70 98 GET 29 SET 71 19 SET 81 93 GET 55 SET 44 8 GET 51 
SET 89 86 
GET 91 GET 35 SET 84 26 SET 43 95 GET 92 
SET 21 21 
GET 39 GET 93 GET 23 GET 86 GET 95 GET 9 GET 3 
SET 23 85 
SET 58 26 
1 SET 93 3 
GET 97 GET 31 GET 50 
2 SET 57 13 
3 SET 49 55 
GET 29 GET 58 GET 77 
4 SET 21 98 
5 SET 6 95 
GET 83 GET 24 
6 SET 16 37 
7 SET 54 85 
8 SET 55 25 
GET 37 GET 93 GET 59 GET 24