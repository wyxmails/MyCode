/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if(n<=2) return n;
        map<pair<double,double>,set<int> > mark;
        double k,v;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(fabs(points[i].x-points[j].x)<0.0000001){
                    k = INT_MAX;
                    v = points[i].x;
                }else{
                    k = double(points[i].y-points[j].y)/double(points[i].x-points[j].x);
                    v = points[i].y-k*points[i].x;
                }
                auto it = mark.find(make_pair(k,v));
                if(it!=mark.end()){
                    it->second.insert(i);
                    it->second.insert(j);
                }else{
                    mark[make_pair(k,v)].insert(i);
                    mark[make_pair(k,v)].insert(j);
                }
            }
        }
        int M=2;
        auto it = mark.begin();
        for(;it!=mark.end();++it){
            M = it->second.size()>M?it->second.size():M;
        }
        return M;
    }
};
