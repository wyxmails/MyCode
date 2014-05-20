#include <iostream>
using namespace std;
//f[i] = (f[i-1] + m) % i;
// i=2~n is number of people in the circle
// m is the dead person's number
int main(int argc,char*argv[]){
	int m,n,k,pos;
	bool flag;
	int result[14];
	for(int i=0;i<14;++i){
		result[i] = 0;
	}
	while(cin>>k && k){
		if(result[k-1] != 0){
			cout << result[k-1] << endl;
			continue;
		}
		m = k+1;
		pos = m;
		while(true){
			flag = true;
			for(int i=1;i<k;++i){
				pos = m - (2*k-i+1-pos);
				if(pos%(2*k-i))
					pos %= (2*k-i);
				else
					pos = 2*k-i;
				if(pos<=k){
					flag = false;
					break;
				}
			}
			if(!flag){
				if(0==m%(2*k))
					m += k+1;
				else
					m++;
				if(m%(2*k))
					pos = m%(2*k);
				else
					pos = 2*k;
			}
			else
				break;
		}
		cout << m << endl;
		result[k-1] = m;
	}
	return 0;
}
