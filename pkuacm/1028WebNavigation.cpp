#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc,char*argv[]){
	string strInput,url,command;
	string cururl = "http://www.acm.org/";
	int pos;
	stack<string> backstack,forstack;
	getline(cin,strInput);
	while(strInput!="QUIT"){
		pos = strInput.find_first_of(' ');
		if(pos>0){
			command = strInput.substr(0,pos);
			url = strInput.substr(pos+1,strInput.size()-pos);
		}else{
			command = strInput;
		}
		if(command=="VISIT"){
			backstack.push(cururl);
			cururl = url;
			while(!forstack.empty()) forstack.pop();
			cout << url << endl;
		}else if(command=="BACK"){
			if(!backstack.empty()){
				forstack.push(cururl);
				cururl = backstack.top();
				backstack.pop();
				cout << cururl << endl;
			}else{
				cout << "Ignored" << endl;
			}
		}else if(command=="FORWARD"){
			if(!forstack.empty()){
				backstack.push(cururl);
				cururl = forstack.top();
				forstack.pop();
				cout << cururl << endl;
			}else{
				cout << "Ignored" << endl;
			}
		}
			
		getline(cin,strInput);	
	}
	return 0;
}
