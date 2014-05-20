#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string binaryPrint(string s){
	int dot = s.find('.');
	string intStr, decStr;
	intStr = decStr = "";
	int intPart = atoi(s.substr(0,dot).c_str());
	while(intPart>0){
		intStr = char(intPart%2+'0')+intStr;
		intPart /= 2;
	}
	if(dot!=-1){
		double decPart = atof(s.substr(dot,s.size()-dot).c_str());
		decStr = '.';
		while(decPart>0){
			if(decStr.size()>32) return "ERROR";
			decPart *= 2;
			if(decPart>=1){
			   	decStr += '1';
				decPart -= 1;
			}else decStr += '0';
		}
	}
	return intStr+decStr;
}

int main(int argc,char*argv[]){
	string s = "2.5";
	cout << binaryPrint(s) << endl;
	return 0;
}
