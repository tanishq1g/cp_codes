#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int main(){
    // Creates a max heap 
    priority_queue <int> pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from max heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    }
    // 30 20 10 5 1 
  

    // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    // Creates a min heap 
    priority_queue <int, vector<int>, greater<int> > pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
//   1 5 10 20 30
    return 0;
}


using namespace std; 
  
// User defined class, Point 
class Point 
{ 
   int x; 
   int y; 
public: 
   Point(int _x, int _y) 
   { 
      x = _x; 
      y = _y; 
   } 
   int getX() const { return x; } 
   int getY() const { return y; } 
}; 
  
// To compare two points 
class myComparator 
{ 
public: 
    int operator() (const Point& p1, const Point& p2) 
    { 
        return p1.getX() > p2.getX(); 
    } 
}; 
  
// Driver code 
int main () 
{ 
    // Creates a Min heap of points (order by x coordinate) 
    priority_queue <Point, vector<Point>, myComparator > pq; 
  
    // Insert points into the min heap 
    pq.push(Point(10, 2)); 
    pq.push(Point(2, 1)); 
    pq.push(Point(1, 5)); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        Point p = pq.top(); 
        cout << "(" << p.getX() << ", " << p.getY() << ")"; 
        cout << endl; 
        pq.pop(); 
    } 
  
    return 0; 
} 



// min heap and printing kth smallest 
auto comp = [](int a, int b){
    return a > b;
};

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
        make_heap(ve.begin(), ve.end(), comp);
            // for (auto i : ve) std::cout << i << ' ';cout << endl;
        for(int i = 0; i < k - 1; i++){
            // cout <<pq.top()<<'\n';
            // pq.pop();
            // cout <<ve.front() << ' '<< ve.size() << '\n';
            pop_heap(ve.begin(), ve.end() - i, comp);
            // for (auto i : ve) std::cout << i << ' ';cout << endl;
        }
        cout << ve.front() << '\n';
    }
    return 0;
}