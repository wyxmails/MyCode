#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
bool mark[51][51];
int m;
struct Q{
int cur,t,left,step;
bool eat[51];

Q(){memset(eat,false,sizeof(eat));}
Q(int cur,int t,int left,int step):cur(cur),t(t),left(left),step(step){memset(eat,false,sizeof(eat));}
friend bool operator <(Q a,Q b){
return a.t>b.t;
}
};

class TurntableService{
public:
int calculateTime(vector <string> fav){
memset(mark,false,sizeof(mark));
m = fav.size();
for(int i=0;i<m;++i){
stringstream ss(fav[i]);
int num;
while(ss>>num) mark[i][num] = true;
}
priority_queue<Q> pq;
for(int i=1;i<m;++i){
	int step = min(i,m-i);
	Q now(i,0,m,step+1);
	pq.push(now);
}
pq.push(Q(0,0,m,0));
while(!pq.empty()){
Q now = pq.top();
int cur = now.cur;
cout << "cur: " << cur << endl;
pq.pop();
int cnt = countPerson(now);
if(cnt==0) continue;
now.t += now.step+15;
cout << "t: " << now.t << endl;
now.left-=cnt;
cout << "left: " << now.left << endl;
if(now.left==0) return now.t;
for(int i=0;i<m;++i){
if(i==cur) continue;
int step = min(abs(i-cur),m-abs(i-cur));
now.step = step+1;now.cur = i;
pq.push(now);
}
}
return 2*(m-1)+15*m;
}
private:
int countPerson(Q &now){
int res = 0;
for(int i=now.cur,j=0;j<m;++j,i=(i+1)%m){
if(mark[i][j]){
if(!now.eat[i]){
res++;
cout << i << "-" << j << " ";
now.eat[i] = true;
}
}
}
cout << endl;
return res;
}
};

int main(){
	//string arr[] = {"0 2", "1", "0 1"};
	//string arr[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"};
	string arr[] = {"9", "1 2", "2 0 6", "7 4", "0 9 1 9 4", "3 0 3 2 0", "6 4 6 8 3", "3 4 9 6 7", "5 3", "2 2 1 3 9", "0 0 1 9"};
	vector<string> vec;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
		vec.push_back(arr[i]);
	TurntableService ts;
	cout << ts.calculateTime(vec) << endl;
	return 0;
}
