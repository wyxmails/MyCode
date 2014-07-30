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

int romanToInt2(string s) {
        int n = s.size();
        if(n==0) return 0;
        unordered_map<char,int> dic;
        dic['I'] = 1; dic['V'] = 5; dic['X'] = 10; dic['L'] = 50;
        dic['C'] = 100; dic['D'] = 500; dic['M'] = 1000;
        int res = 0;
        for(int i=0;i<n;++i){
            if(i+1<n){
                if(dic[s[i+1]]>dic[s[i]]){
                    res += dic[s[i+1]]-dic[s[i]];
                    i++;
                }else{
                    int cnt=1;
                    while(i+1<n&&s[i+1]==s[i]){
                        cnt++; i++;
                    } 
                    res += cnt*dic[s[i]];
                }
            }else res += dic[s[i]];
        }
        return res;
}

int main(){
	string s;
	s = "I";
	cout << romanToInt(s) << endl;
}
