#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main(int argc,char*argv[]){
	long long N;
	long long sum;
	long long tmp;
	int t,k;
	bool flag;
	string str,outstr;
	cin>>t;
	while(t){
		N=0;
		outstr = "";
		sum=0;
		cin>>k>>str>>N;
		flag = true;
		for(int i=0;i<k;++i){
			if(str[k-i-1]=='p'){
				tmp = (long long)(1)<<i;
			}else{
				tmp = -((long long)(1)<<i);
			}
			if(((sum+tmp)>>i&1)==(N>>i&1)){
				if(((tmp>>2)+(sum>>2))>>62>0){
					flag = false;
					break;
				}
				outstr = '1' + outstr;
				sum +=tmp;
			}else{
				outstr = '0' + outstr;
			}
		}
		if(sum==N&&flag&&!(k==64&&str[0]=='p'&&outstr[0]=='1'))
			cout << outstr << endl;
		else
			cout << "Impossible" << endl;
		t--;
	}
}
