#include <iostream>
#include <vector>
using namespace std;


class Target{
public:
	vector<string> draw	(int n);
};

vector<string> Target::draw(int n){
		vector<string> vec(n,string(n,' '));
		for(int r=0;r<n;r+=2){
			for(int i=r;i<n-r;++i){
				vec[r][i] = '#';
				vec[i][r] = '#';
				vec[n-r-1][i] = '#';
				vec[i][n-r-1] = '#';
			}	
		}
		return vec;
}

int main(){
	Target t;
	vector<string> res = t.draw(9);
	for(int i=0;i<res.size();++i)
		cout << res[i] << endl;
	return 0;
}
