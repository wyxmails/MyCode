#include <iostream>
#include <vector>
using namespace std;
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	int n = intervals.size();
	if(n==0){
		intervals.push_back(newInterval);
		return intervals;
	}
	int s=n-1;
	int e=0;
	for(int i=0;i<n;++i){
		if(intervals[i].start>=newInterval.start){
			s = i;
			break;
		}
	}
	for(int i=n-1;i>=0;--i){
		if(intervals[i].end<=newInterval.end){
			e = i;
			break;
		}
	}
	if(s>0){
		if(intervals[s-1].end>=newInterval.start) s--;
	}
	if(e<n-1){
		if(intervals[e+1].start<=newInterval.end) e++;
	}
	if(s==e){
		if(intervals[s].start>newInterval.end){
			intervals.insert(intervals.begin()+s,newInterval);
			return intervals;
		} 
		if(intervals[s].end<newInterval.start){
			intervals.insert(intervals.begin()+s+1,newInterval);
			return intervals;
		} 
	}
	if(s>e){
		intervals.insert(intervals.begin()+e+1,newInterval);
		return intervals;
	}
	intervals[s].start = min(newInterval.start,intervals[s].start);
	intervals[s].end = max(newInterval.end,intervals[e].end);
	if(s<e)
		intervals.erase(intervals.begin()+s+1,intervals.begin()+e+1);
	return intervals;
}
vector<Interval> insert2(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        if(n==0){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        int start=-1;
        int end = -1;
        for(int i=0;i<n;++i){
            if(start==-1){
                if(newInterval.start<intervals[i].start||(newInterval.start>=intervals[i].start&&newInterval.start<=intervals[i].end)) start = i;
            }
            if(end==-1){
                if(newInterval.end>intervals[n-i-1].end||(newInterval.end<=intervals[n-i-1].end&&newInterval.end>=intervals[n-i-1].start)) end = n-i-1;
            }
            if(start!=-1&&end!=-1) break;
        }
        if(start==-1&&end==-1) return intervals;
        if(start==-1) intervals.push_back(newInterval);
        else if(end==-1) intervals.insert(intervals.begin(),newInterval);
        else{
            if(end<start){
                intervals.insert(intervals.begin()+start,newInterval);
            }else if(start==end){
                intervals[start].start = min(newInterval.start,intervals[start].start);
                intervals[end].end = max(newInterval.end,intervals[end].end);
            }else{
                intervals[start].start = min(newInterval.start,intervals[start].start);
                intervals[start].end = max(newInterval.end,intervals[end].end);
                intervals.erase(intervals.begin()+start+1,intervals.begin()+end+1);
            }
        }
        return intervals;
}

vector<Interval> insert3(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        int l,r;
        l=r=-1;
        for(int i=0;i<n&&(l==-1||r==-1);++i){
            if(l==-1&&(intervals[i].start>newInterval.start||
                (intervals[i].start<=newInterval.start&&
                intervals[i].end>=newInterval.start))) 
                l = i;
            if(r==-1&&(intervals[n-i-1].end<newInterval.end||
                (intervals[n-i-1].end>=newInterval.end&&
                intervals[n-i-1].start<=newInterval.end))) 
                r=n-i-1;
        }
        if(l==-1)
            intervals.push_back(newInterval);
        else if(l>r){
            intervals.insert(intervals.begin()+l,newInterval);
        }else{
            intervals[l].start = min(intervals[l].start,newInterval.start);
            intervals[l].end = max(intervals[r].end,newInterval.end);
            if(l<r) intervals.erase(intervals.begin()+l+1,intervals.begin()+r+1);
        }
        return intervals;
}
int main(int argc,char*argv[]){
	return 0;
}
