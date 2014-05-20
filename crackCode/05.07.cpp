#include <iostream>
#include <vector>
using namespace std;

int findMiss(vector<vector<int> > bitMem){
	vector<vector<int> > tmp;
	tmp.assign(bitMem.begin(),bitMem.end());
	int cntOne,cntZero;
	int res = 0;
	int bit = 0;
	while(tmp.size()>0){
		cntOne = cntZero = 0;
		for(int i=0;i<tmp.size();++i){
			if(tmp[i][0]==0) cntZero++;
			else cntOne++;
		}
		if(cntOne>=cntZero){
		   	for(int i=0;i<tmp.size();++i){
				if(tmp[i][0]==1){
					tmp.erase(tmp.begin()+i);
					i--;
				}else tmp[i].erase(tmp[i].begin());
			}
		}else{
		   	for(int i=0;i<tmp.size();++i){
				if(tmp[i][0]==0){
					tmp.erase(tmp.begin()+i);
					i--;
				}else tmp[i].erase(tmp[i].begin());
			}
		   	res |= 1<<bit;
		}
		bit++;
	}
	return res;
}

int main(int argc,char*argv[]){
	vector<vector<int> > vec;
	vector<int> v;
	for(int i=0;i<10;++i){
		if(i==5) continue;
		v.clear();
		for(int j=0;j<31;++j){
			if(i&(1<<j)) v.push_back(1);
			else v.push_back(0);
		}
		vec.push_back(v);
	}
	
	cout << findMiss(vec) << endl;
	return 0;
}
