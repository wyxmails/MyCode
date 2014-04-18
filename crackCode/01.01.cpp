#include <iostream>
#include <string>
using namespace std;

bool isUnique2(string str){
	/*assume ASCII, char set size is 256*/
	int size = 256;
	bool arr[size];
	for(int i=0;i<size;++i){
		arr[i] = false;
	}
	for(int i=0;i<str.size();++i){
		if(arr[str[i]]) return false;
		arr[str[i]] = true;
	}
	return true;
}

bool isUnique(string str){
	int checker = 0;
	for(int i=0;i<str.size();++i){
		int val = str[i] - 'a';
		if((checker & (1<<val)) > 0) return false;
		checker |= (1<<val);
	}
	return true;
}

int main(int argc,char*argv[]){
	string s1,s2;
	cin>>s1;
	if(isUnique(s1))
		cout << "Is unique!" << endl;
	else
		cout << "Not unique!" << endl;
	cin>>s2;
	if(isUnique2(s2))
		cout << "Is unique2!" << endl;
	else
		cout << "Not unique2!" << endl;
		
	return 0;
}
