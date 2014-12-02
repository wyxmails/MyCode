#include <iostream>
//#include <cstdlib>
using namespace std;
/*
 Validate if a given string is numeric.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */
/*test case
 * "32.e-80123" true
 * " 005047e+6" true
 * "6e6.5" false
 * "3." true
 * "e9" false
 * "5e" false
 * "0e" false*/
bool isNumber(const char *s) {
	int i=0;
	while(s[i]==' ') i++;
	int ee = -1;
	int dot = -1;
	bool num = false;
	if(s[i]=='+'||s[i]=='-') i++;
	for(;s[i]!='\0';++i){
		if(ee==-1&&s[i]=='e'){
			if(!num) return false;
			if(s[i+1]=='+'||s[i+1]=='-') i++;  //005047e+6 true
			ee = 0;
		}else if(dot==-1&&s[i]=='.'){
			if(ee!=-1) return false; 
			if(num) dot = 1;    //3. true
			else dot = 0;
		}else{
			if(isdigit(s[i])){
			if(ee==0) ee=1;  //2e3 true
			if(dot==0) dot=1; //.1 true
			num = true;
			continue;
		} 
		else if(s[i]==' ') break;
		else return false;
		}
	}
	while(s[i]==' ') i++;
	if(s[i]=='\0'){
		if(ee==0||dot==0) return false;
		return num;
	} 
	return false;
}
int main(int argc,char*argv[]){
	return 0;
}
