#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char* argv[]){
	int len, items, num;
	cin>>len>>items;
	string str = "";
	map<int,string> mapstr;
	for(int i=0;i<items;++i){
		cin>>str;
		num=0;
		for(int j=0;j<len-1;++j){
			for(int k=j+1;k<len;++k){
				if(str[k]<str[j])
					num += 1;
			}
		}
		mapstr[num*100+i] = str;
		str = "";
	}
	for(map<int,string>::iterator it=mapstr.begin();it!=mapstr.end();++it){
		cout << (*it).second << endl;
	}
	return 0;
}
