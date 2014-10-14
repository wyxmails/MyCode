/*
 Given a real number between 0 and 1(e.g.,0.72) 
 that is passed in as a double, 
 print the binary representation. 
 If the number cannot be represented accurately in binary 
 with at most 32 characters, print "ERROR."
 */
#include <iostream>
using namespace std;

string DecimalRepresentation(double decimal){
	string res = "0.";;
	int i=0;
	while(decimal>0.0&&i<30){
		i++;
		decimal *= 2;
		char c = char(int(decimal)+'0');
		if(c=='1') decimal -= 1.0;
		res += c;
	}
	if(decimal>0.0) return "ERROR";
	return res;
}

int main(int argc,char*argv[]){
	double d = 0.1;
	cout << DecimalRepresentation(d) << endl;
	d = 0.2;
	cout << DecimalRepresentation(d) << endl;
	d = 0.5;
	cout << DecimalRepresentation(d) << endl;
	d = 0.625;
	cout << DecimalRepresentation(d) << endl;
	return 0;
}
