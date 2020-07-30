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


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n){
    if(n == 1){
        if(p[0].petrol >= p[0].distance)
            return 0;
        else
            return -1;
    }
    int start = 0, end = 1, le;
    while(start < n){
        le = 0;
        for(int i = 0; i < n; i++){
            le += p[start + i].petrol - p[start + i].distance;
            if(le < 0){
                start++;
                if(start == end){
                    end = (end + 1) % n;
                }
                break;
            }
            end = (end + 1) % n;
        }
        if(start == end){
            return start;
        }
    }
    return -1;
}