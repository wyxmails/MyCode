/*
 given a set of N points 
 where each point is represented as a combination of x and y coordinates, 
 print all sets of collinear points 
 such that set size is more than or equal to 3. 
 */
#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <set>
using namespace std;

struct Point{
	int x;
	int y;
};


vector<vector<Point> > collinearPoints(vector<Point> &vec){
	map<pair<double,double>,set<int> > mark;
	double k,v;
	for(int i=0;i<vec.size();++i){
		for(int j=0;j<vec.size();++j){
			if(i==j) continue;
			if(vec[i].x==vec[j].x){
				k = INT_MAX;
				v = vec[i].x;
			}else{
				k = double(vec[i].y-vec[j].y)/double(vec[i].x-vec[j].x);
				v = vec[i].y-k*vec[i].x;
			}
			map<pair<double,double>,set<int> >::iterator it;
			it = mark.find(make_pair(k,v));
			if(it!=mark.end()){
				it->second.insert(i);
				it->second.insert(j);
			}else{
				mark[make_pair(k,v)].insert(i);
				mark[make_pair(k,v)].insert(j);
			}
		}
	}
	vector<vector<Point> > res;
	vector<Point> line;
	map<pair<double,double>,set<int> >::iterator it;
	for(it=mark.begin();it!=mark.end();++it){
		if(it->second.size()>=3){
			set<int>::iterator it1;
			line.clear();
			for(it1=it->second.begin();it1!=it->second.end();++it1)
				line.push_back(vec[*it1]);
			res.push_back(line);
		}
	}
	return res;
}

int main(int argc,char*argv[]){
	vector<Point> vec;
	Point p;
	p.x = 1;p.y=2;vec.push_back(p);
	p.x=3;p.y=6;vec.push_back(p);
	p.x=5;p.y=10;vec.push_back(p);
	p.x=3;p.y=5;vec.push_back(p);
	vector<vector<Point> > res = collinearPoints(vec);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j){
			cout << res[i][j].x << " " << res[i][j].y << endl;
		}
		cout << endl;
	}
	return 0;
}
