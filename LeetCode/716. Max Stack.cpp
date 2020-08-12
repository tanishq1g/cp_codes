// class MaxStack {
// public:
//     /** initialize your data structure here. */
//     stack<int> st;
//     stack<int> mst;
//     stack<int> buffer;
//     MaxStack() {

//     }
    
//     void push(int x) {
//         st.push(x);
//         if(mst.empty()){
//             mst.push(x);
//         }
//         else{
//             if(x >= mst.top()){
//                 mst.push(x);
//             }
//         }
//     }
    
//     int pop() {
//         int x = st.top();
//         st.pop();
//         if(x == mst.top()){
//             mst.pop();
//         }
//         return x;
//     }
    
//     int top() {
//         if(st.empty())
//             return -1;
//         return st.top();
//     }
    
//     int peekMax() {
//         if(mst.empty())
//             return -1;
//         return mst.top();
//     }
    
//     int popMax() {
//         if(mst.empty())
//             return -1;
//         int x = mst.top();
//         // mst.pop();

//         while(x != st.top()){
//             buffer.push(pop());
//         }
//         pop();
//         while(!buffer.empty()){
//             push(buffer.top());
//             buffer.pop();
//         }

//         return x;
//     }
// };

// /**
//  * Your MaxStack object will be instantiated and called as such:
//  * MaxStack* obj = new MaxStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->peekMax();
//  * int param_5 = obj->popMax();
//  */

class MaxStack {
    list<int> dll; //double-linked list, O(1) for insert/delete
    map<int, vector<list<int>::iterator>, greater<int>> m; //sorted map, largest key at begin(); O(1) to find max, O(log(n)) to insert/delete
public:
    void push(int x) {
        dll.push_front(x);
        m[x].push_back(dll.begin());
    }
    int pop() {
        int x = dll.front();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        dll.pop_front();
        return x;
    }
    int top() { return dll.front(); }
    int peekMax() { return m.begin()->first; }
    int popMax() {
        int x = m.begin()->first;
        auto it = (m.begin()->second).back();
        dll.erase(it);
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        return x;
    }
};