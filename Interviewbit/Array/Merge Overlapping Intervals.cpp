/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
vector<Interval> Solution::merge(vector<Interval> &ve) {
    int n = ve.size();
    if(n == 1)
        return ve;
    vector<Interval> ret;
    sort(ve.begin(), ve.end(), [](const Interval &a, const Interval &b){
        return a.first < b.first;
    });
    ret.push_back(ve[0]);
    int k = 0;
    for(int i = 1; i < n; i++){
        if(ret[k].end >= ve[i].start){
            ret[k].end = max(ret[k].end, ve[i].end);
        }
        else{
            k++;
            ret.push_back(ve[i]);
        }
    }
    return ret;
}
