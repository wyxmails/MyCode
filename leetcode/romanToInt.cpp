#include <iostream>
#include <map>
#include <string>
using namespace std;
int romanToInt(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	map<char,int> mapsig;
	mapsig.clear();
	mapsig['I'] = 1;
	mapsig['V'] = 5;
	mapsig['X'] = 10;
	mapsig['L'] = 50;
	mapsig['C'] = 100;
	mapsig['D'] = 500;
	mapsig['M'] = 1000;
	int i,coef,res;
	res=0;
	i=0;
	while(s.size()>i){
		if(i==(s.size()-1)){
			coef = mapsig[s[i]];
			i++;
		}else{
			if(mapsig[s[i+1]]/mapsig[s[i]]==5){
				coef = 4*mapsig[s[i]];
				i += 2;
			}else if(mapsig[s[i+1]]/mapsig[s[i]]==10){
				coef = 9*mapsig[s[i]];
				i += 2;
			}else{
				coef = mapsig[s[i]];
				i++;
			}
		}
		res += coef;
	}	
	return res;
}

int main(){
	string s;
	s = "I";
	cout << romanToInt(s) << endl;
}
