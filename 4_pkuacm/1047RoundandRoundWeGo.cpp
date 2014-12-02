#include <iostream>
#include <string>
using namespace std;

int main(int argc,char*argv[]){
	string s,tmps;
	int count[10],tmpcount[10];
	int len,carry;
	bool flag;
	while(cin>>s){
		len = s.size();
		for(int i=0;i<10;++i) count[i]=tmpcount[i]=0;
		for(int i=0;i<len;++i){
			count[s[i]-'0']++;
		}
		tmps = s;
		flag = true;
		for(int i=2;i<=len;++i){
			carry=0;
			for(int j=tmps.size()-1;j>=0;j--){
				int tmp = tmps[j]-'0'+s[j]-'0'+carry;
				tmps[j] = (char)(tmp%10+'0');
				carry = tmp/10;
			}
			if(carry){flag=false;break;}
			for(int k=0;k<10;++k) tmpcount[k]=0;
			for(int k=0;k<tmps.size();++k){
				tmpcount[tmps[k]-'0']++;
			}
			for(int k=0;k<10;++k){
				if(count[k]!=tmpcount[k]){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(!flag) cout << s << " is not cyclic" << endl;
		else cout << s << " is cyclic" << endl;
	}
	return 0;
}
