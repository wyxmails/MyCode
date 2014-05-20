#include <iostream>
#include <map>
using namespace std;

int main(int argc,char*argv[]){
	int t;
	map<string,string> mapstr;
	mapstr.clear();
	mapstr["ab"] = "c";
	mapstr["ba"] = "c";
	mapstr["ac"] = "b";
	mapstr["ca"] = "b";
	mapstr["bc"] = "a";
	mapstr["cb"] = "a";
	string str,rep;
	cin>>t;
	map<string,string>::iterator it;
	while(t--){
		cin>>str;
		for(int i=0;i<str.size();){
			if(i>0){
				if(str[i]!=str[i-1]){
					i--;
					continue;
				}
			}
			if(i<str.size()-1){
				if(str[i]==str[i+1]){
					i++;
					continue;
				}
			}else break;
			rep = str.substr(i,2);
			it = mapstr.find(rep);
			if(i<str.size()-2)
				str = str.substr(0,i) + (*it).second + str.substr(i+2);
			else
				str = str.substr(0,i) + (*it).second;
		}
		cout << str.size();
	}
	return 0;
}
