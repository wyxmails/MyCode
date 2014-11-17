/*Merge Intervals
   Given a collection of intervals, 
   merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

 bool cmp(const Interval&i1,const Interval&i2){
     return i1.start<i2.start;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start<=res[j].end) 
                res[j].end = max(res[j].end,intervals[i].end);
            else {
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }
};
