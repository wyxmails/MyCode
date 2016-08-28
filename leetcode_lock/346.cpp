/*
346. Moving Average from Data Stream  QuestionEditorial Solution  My Submissions
Total Accepted: 7046 Total Submissions: 12493 Difficulty: Easy
Given a stream of integers and a window size, 
calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        num = size;
        vv.resize(num);
        for(int i=0;i<num;++i)
            vv[i] = 0;
        start = 0;
        cur = 0;
    }
    
    double next(int val) {
        if(num<=0)
            return 0;
        vv[cur] = val;
        cur = (cur+1)%num;
        start++;
        int avg=0;
        for(int i=0;i<num;++i){
            avg += vv[i];
        }
        double res=0.0;
        if(start<num)
            res = avg*1.0/start;
        else
            res = avg*1.0/num;
        return res;
    }
private:
    vector<int> vv;
    int num;
    int start;
    int cur;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
