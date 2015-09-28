#include "common.h"
//not checked yet
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() ==0)
            return intervals;
        sort(intervals.begin(), intervals.end(),
             [](const Interval& left, const Interval& right){return left.start < right.start;});
        int start = intervals[0].start;
        int end = intervals[0].end;
        int i = 0;
        int size = intervals.size();
        vector<Interval> res;
        while(i < size){
            int j = i+1;
            start = intervals[i].start;
            end = intervals[i].end;
            while(j<size && end >= intervals[j].start){

                end = max(intervals[j].end, end);
                ++j;
            }
            res.emplace_back(start, end);
            i = j;
        }
        return res;
    }
};


int main() {
    vector<Interval> data {{1,4}, {1,5}};
    auto res = Solution().merge(data);
    for(auto v: res){
        cout << v.start << "->" << v.end ;
    }
    return 1;
}