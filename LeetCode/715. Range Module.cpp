class RangeModule {
public:
    list<vector<int> > range; 
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        cout << left << ' ' << right << '\n';
        int s = range.size();
        right--;
        if(s == 0){
            range.push_front(vector<int> {left, right});
            for(auto itr = range.begin(); itr != range.end(); itr++){
                cout << (*itr)[0] << ' ' << (*itr)[1] << '\n';
            }
            cout << endl;
            return;
        }
        auto itr = range.begin();
        bool flag = true;
        for( ; itr != range.end(); itr++){
            if((*itr)[0] <= left && (*itr)[1] >= left){
                flag = false;
                (*itr)[1] = max(right, (*itr)[1]);
                break;
            }
            else if((*itr)[0] >= left){
                flag = false;
                range.insert(itr, vector<int> {left, right});
                break;
            }
        }
        if(flag){
            range.push_back(vector<int> {left, right});
            for(auto itr = range.begin(); itr != range.end(); itr++){
                cout << (*itr)[0] << ' ' << (*itr)[1] << '\n';
            }
            cout << endl;
            return;
        }
        auto itr2 = itr;
        itr2++;
        for( ; itr2 != range.end(); itr++, itr2++){
            if((*itr)[1] >= (*itr2)[0]){
                (*itr)[1] = max((*itr2)[1], (*itr)[1]);
                range.erase(itr2);
            }
        }
        for(auto itr = range.begin(); itr != range.end(); itr++){
            cout << (*itr)[0] << ' ' << (*itr)[1] << '\n';
        }
        cout << endl;
        
    }
    
    bool queryRange(int left, int right) {
        right--;
        for(auto itr = range.begin(); itr != range.end(); itr++){
            if((*itr)[0] >= left && (*itr)[1] <= right){
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        right--;
        for(auto itr = range.begin(); itr != .end(); itr++){
            if((*itr)[0] < left && (*itr)[1] < right){
                
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */