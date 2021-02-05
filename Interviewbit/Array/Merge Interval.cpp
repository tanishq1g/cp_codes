

// /**
//  * Definition for an interval.
//  * struct Interval {
//  *     int start;
//  *     int end;
//  *     Interval() : start(0), end(0) {}
//  *     Interval(int s, int e) : start(s), end(e) {}
//  * };
//  */
// vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
//    int i;
//    vector<Interval> A;
//    for(i=0;i<intervals.size();i++)
//    {
//        if(newInterval.start>intervals[i].start && newInterval.start>intervals[i].end)
//        {
//            A.push_back(intervals[i]);
//        }
//        else
//            break;
//    }
//    Interval s;
//    if(i!=intervals.size() && intervals[i].start<newInterval.start )
//         s.start=intervals[i].start;
//     else if(i!=intervals.size())
//         s.start=newInterval.start;
//    if(i==intervals.size())
//    {    s.start=newInterval.start;
//         s.end=newInterval.end;
//    }
//    int f=0;
//    while(i<intervals.size())
//    {
//        if(newInterval.end>=intervals[i].start && newInterval.end<intervals[i].end)
//        {
//            s.end=intervals[i].end;
//            i++;
//            f=1;
//            break;
//        }
//        else if(newInterval.end<intervals[i].start )
//        {
//            s.end=newInterval.end;
//            f=1;
//            break;
//        }
//        i++;
//    }
//    if(f==0)
//     s.end=newInterval.end;
//    A.push_back(s);
//    while(i<intervals.size())
//    {
//        A.push_back(intervals[i]);
//        i++;
//    }
//    return A;
// }


vector<Interval> Solution::insert(vector<Interval> &ve, Interval newInterval) {
    // vector<Interval>::iterator itr;
    if(newInterval.start > newInterval.end){
        swap(newInterval.start, newInterval.end);
    }
    auto itr = lower_bound(ve.begin(), ve.end(), newInterval, [](const Interval &a, const Interval &b) -> bool {
        return a.start < b.start;
    });
    cout << itr->start << ' ' << itr->end;
    return ve;
}

