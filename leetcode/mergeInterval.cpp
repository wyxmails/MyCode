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
bool isLower(const Interval&i1,const Interval&i2){
return i1.start<i2.start;
}
vector<Interval> merge(vector<Interval> &intervals) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(intervals.size()<=1) return intervals;
    sort(intervals.begin(),intervals.end(),isLower);
    for(int i=0;i<intervals.size()-1;++i){
        if(intervals[i].end>=intervals[i+1].start){
            if(intervals[i].end<intervals[i+1].end){
                intervals[i].end = intervals[i+1].end;
            }
            intervals.erase(intervals.begin()+i+1);
            i--;
        }
    }
    return intervals;
}
