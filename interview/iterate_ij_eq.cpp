/*
stackoverflow.com
   A friend of mine is interviewing for a job. One of the interview questions got me thinking, just wanted some feedback.

 There are 2 non-negative integers: i and j. Given the following equation, find an (optimal) solution to iterate over i and j in such a way that the output is sorted.

 2^i * 5^j
 So the first few rounds would look like this:

 2^0 * 5^0 = 1
 2^1 * 5^0 = 2
 2^2 * 5^0 = 4
 2^0 * 5^1 = 5
 2^3 * 5^0 = 8
 2^1 * 5^1 = 10
 2^4 * 5^0 = 16
 2^2 * 5^1 = 20
 2^0 * 5^2 = 25
 Try as I might, I can't see a pattern. Your thoughts?


 */
#include <iostream>
#include <queue>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

struct Q{
	int i,j,v;
	Q(int i,int j,int v):i(i),j(j),v(v){}
	friend bool operator < (const Q&a,const Q&b){
		return a.v>b.v;
	}
};
//equation: 2^i * 5^j
vector<int> dijkstra(int i,int j){
	vector<int> res;
	priority_queue<Q> mq;
	unordered_set<int> used;
	Q nn(0,0,1);
	mq.push(nn);
	used.insert(1);
	while(!mq.empty()){
		Q cur = mq.top();
		mq.pop();
		res.push_back(cur.v);
		if(cur.i==i&&cur.j==j) break;
		int t1 = cur.v*2,t2 = cur.v*5;
		if(cur.i<i&&used.find(t1)==used.end()){
			mq.push(Q(cur.i+1,cur.j,t1));
			used.insert(t1);
		}
		if(cur.j<j&&used.find(t2)==used.end()){
		   	mq.push(Q(cur.i,cur.j+1,t2));
			used.insert(t2);
		}
	}
	return res;
}

int main(int argc,char*argv[]){
	vector<int> res = dijkstra(5,5);
	for(int i=0;i<res.size();++i)
		cout << i << " : " << res[i] << endl;
	return 0;
}
