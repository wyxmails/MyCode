#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int> > threesum(vector<int> S){
	int i,j,k,tmp;
	set<vector<int> > setres;
	setres.clear();
	vector<int> vectmp;
	for(i=0;i<S.size()-2;++i){
		for(j=i+1,k=S.size()-1;j<k;){
			tmp = S[i]+S[j]+S[k];
			if(tmp==0){
				vectmp.clear();
				vectmp.push_back(S[i]);
				vectmp.push_back(S[j]);
				vectmp.push_back(S[k]);
				setres.insert(vectmp);
				j++;
				k--;
			}else if(tmp<0){
				j++;
			}else k--;
		}
	}
	vector<vector<int> > vecres;
	vecres.clear();
	set<vector<int> >::iterator it;
	for(it=setres.begin();it!=setres.end();++it){
		vecres.push_back(*it);
	}
	return vecres;
}
int main(){
	vector<int> vec;
	vec.clear();
	int n,num;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>num;
		vec.push_back(num);
	}
	sort(vec.begin(),vec.end());
	vector<vector<int> > vecvec;
	vecvec.clear();
	vecvec = threesum(vec);
	for(int i=0;i<vecvec.size();++i){
		for(int j=0;j<vecvec[i].size();++j){
			cout << vecvec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
