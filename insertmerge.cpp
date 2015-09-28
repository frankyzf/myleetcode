#include "common.h"
//not checked yet

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0)
        {
            return vector<Interval>{newInterval};
        }
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval,
                              [](const Interval& inter, const Interval& val){return inter.start < val.start;});
        it = intervals.insert(it, newInterval);
        int index = distance(intervals.begin(), it);
        int i = index-1;
        int last = newInterval.end;
        int first = newInterval.start;
        for ( ;i >=0; --i) {
            if(intervals[i].end < newInterval.start)
                break;
            else{
                if(last < intervals[i].end){
                    last = intervals[i].end;
                }
                if(first > intervals[i].start){
                    first = intervals[i].start;
                }
            }
        }

        int j = index +1;
        for(; j < intervals.size(); ++j){
            if(intervals[j].start > last){
                break;
            }
            else if(last < intervals[j].end){
                last = intervals[j].end;
            }
        }
        auto begin = intervals.begin() + (i+1);
        auto end = intervals.begin() + j;
        intervals.erase(begin, end);
        intervals.emplace(intervals.begin()+(i+1), first, last);
        return intervals;
    }
};



int main() {

    return 1;
}