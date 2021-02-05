// class Solution {
// public:
//     static bool cmp(vector<int> &a, vector<int> &b){
//         return a[0] < b[0];
//     }
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end(), cmp);
//         vector<vector<int>> ret;
//         if(n == 0){
//             return ret;
//         }
//         ret.push_back(intervals[0]);
//         int l;
//         for(int i = 1; i < n; i++){
//             l = ret.size() - 1;
//             if(intervals[i][0] < ret[l][1]){
//                 ret[l][1] = max(intervals[i][1], ret[l][1]);
//             }
//             else{
//                 ret.push_back(intervals[i]);
//             }
//         }
//         return ret;
//     }
// };

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0){
            return vector<vector<int> > {newInterval};
        }
        auto fn = upper_bound(intervals.begin(), intervals.end(), newInterval, [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        vector<vector<int> > ret; 
        int s;
        if(fn == intervals.begin()){
            ret = vector<vector<int> > {newInterval};
        }
        else{
            ret = vector<vector<int> > (intervals.begin(), fn);
            s = ret.size() - 1;;
            if(ret[s][1] >= newInterval[0]){
                ret[s][1] =  max(ret[s][1], newInterval[1]);
            }
            else{
                ret.push_back(newInterval);
            }
        }
        for(auto itr = fn; itr != intervals.end(); itr++){
            s = ret.size() - 1;
            vector<int> temp = *itr;
            if(ret[s][1] >= temp[0]){
                ret[s][1] = max(ret[s][1], temp[1]);
            }
            else{
                ret.push_back(*itr);
            }
        }
        return ret;
    }
}; 