class Solution {
public:
    static bool cmp(pair<int, char> &a, pair<int, char> &b){
        if(a.first == b.first){
            if(a.second == 'l'){
                return true;
            }
            else{
                return false;
            }
        }
        return a.first < b.first;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, char> > ve;
        vector<vector<int> > ret; 
        for(int i = 0; i < n; i++){
            ve.push_back(make_pair(intervals[i][0], 'l'));    
            ve.push_back(make_pair(intervals[i][1], 'r'));    
        }
        sort(ve.begin(), ve.end(), cmp);
        n = ve.size();
        for(int i = 0; i < n; i++){
            cout << ve[i].first << ' ' << ve[i].second << ' ';
        }cout << endl;
        int i = 0, le;
        while(i < n){
            le = i;
            while(ve[i].second == 'l'){
                i++;
            }
            while( i < n && ve[i].second == 'r'){
                i++;
            }
            ret.push_back(vector<int> {ve[le].first, ve[i - 1].first});
        }
        return ret;
    }
};