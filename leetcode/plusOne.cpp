/*
 *Given a number represented as an array of digits, plus one to the number.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int cnt=0;
	bool flag = false, b=false;
	vector<int>::iterator it = digits.end();
	it--;
	while(it!=digits.begin()){
		if(*it==9) *it = 0;
		else{
		*it += 1;
		b = true;
		break;
		}
		it--;
	}
	if(!b){
		if(*it==9){ 
			*it = 1;
			flag = true;
		}else{
			*it += 1;
		}
	}
	if(flag) digits.push_back(0);
	return digits;
}

int main(){
	vector<int> tmpvec,tmpvec2;
	tmpvec.clear();
	srand(time(0));
	int val,n;
	cin>>n;
	for(int i=0;i<n;++i){
		val = rand()%10;
		cout << val << ",";
		tmpvec.push_back(val);
	}
	cout << endl;
	tmpvec2.clear();
	tmpvec2 = plusOne(tmpvec);
	vector<int>::iterator it = tmpvec2.begin();
	while(it!=tmpvec2.end()){
	   	cout << *it << ",";
		it++;
	}
	cout << endl;
	return 0;
}
