#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(int argc,char*argv[]){
	int N,K,num;
	int left[500];
	int right[500];
	int light[1001],heavy[1001];
	int noanswer=0,outlight,lightnum,outheavy,heavynum;
	int tmplight=0,tmpheavy=0;
	set<int> setequal;
	set<int> setuneql;
	setequal.clear();
	setuneql.clear();
	char cmp;
	cin>>N>>K;
	for(int i=0;i<=N;++i){
		light[i] = 0;
		heavy[i] = 0;
	}
	while(K>0){
		cin>>num;
		for(int i=0;i<num;++i)
			cin>>left[i];
		for(int i=0;i<num;++i)
			cin>>right[i];
		cin>>cmp;
		if(cmp=='<'){
			for(int i=0;i<num;++i){
				if(setequal.find(left[i])==setequal.end())
						light[left[i]]++;
				if(setequal.find(right[i])==setequal.end())
						heavy[right[i]]++;
			}
		}
		if(cmp=='>'){
			for(int i=0;i<num;++i){
				if(setequal.find(left[i])==setequal.end())
						heavy[left[i]]++;
				if(setequal.find(right[i])==setequal.end())
						light[right[i]]++;
			}
		}
		if(cmp=='='){
			for(int i=0;i<num;++i){
				setequal.insert(left[i]);
				setequal.insert(right[i]);
			}
		}
		K--;
	}
	for(int i=1;i<=N;++i){
		if(setequal.find(i)==setequal.end())
			setuneql.insert(i);
	}
	lightnum=heavynum=0;
	set<int>::iterator it;
	bool flag;
	for(it=setuneql.begin();it!=setuneql.end();++it){
		if(light[*it]==lightnum) tmplight = *it;
		if(light[*it]>lightnum){
			outlight = *it;
			lightnum = light[*it];
		}
		if(heavy[*it]==heavynum) tmpheavy = *it;
		if(heavy[*it]>heavynum){
			outheavy = *it;
			heavynum = heavy[*it];
		}
	}
	if(lightnum!=heavynum){
		if(lightnum>heavynum){
			if(light[tmplight]==light[outlight]) cout << noanswer << endl;
			else cout << outlight << endl;			
		}else{
			if(heavy[tmpheavy]==heavy[outheavy]) cout << noanswer << endl;
			else cout << outheavy << endl;
		}
	}else{
		if(setuneql.size()==1){
			it = setuneql.begin();
			cout << *it << endl;
		}else
			cout << noanswer << endl;
	}
	return 0;
}
