#include <iostream>
using namespace std;

int main(){
	int x=0;
	cout << "0 bits: " << endl;
	for(int i=31;i>=0;--i){
		if(x&(1<<i)) cout << "1" ;
		else cout << "0";
	}
	cout << endl;
	x=-1;
	cout << "-1 bits: " << endl;
	for (int i=31;i>=0;--i){
		if(x&(1<<i)) cout << "1" ;
		else cout << "0";
	}
	cout << endl;
	cout << "(-x^y)+x Equivalent to x?-y:y, where x is 0 or 1: " << endl;
	x=0;
	int y = 5;
	cout << "x==0" << " : ";
	cout << (x?-y:y) << " -- ";
	cout << (-x^y)+x << endl;
	cout << "x==1" << " : ";
	x=1;
	cout << (x?-y:y) << " -- ";
	cout << (-x^y)+x << endl;
	int s = 44;
	cout << s << " bits: " << endl;
	for(int i=31;i>=0;--i){
		if((1<<i)&s) cout << "1";
		else cout << "0";
	}
	cout << endl;
	int lo = s&~(s-1);
	cout << "loest one bit: " << endl;
	cout << lo << endl;
	int lz = (s+lo)&~s;
	cout << "lowest zero bit above lo: " << endl;
	cout << lz << endl;
	cout << "add lz to the set: " << endl;
	s |= lz;
	cout << s << endl;
	cout << "reset bits below lz: " << endl;
	s &= ~(lz-1);
	cout << s << endl;
	cout << "put back right number of bits at end: " << endl;
	s |= (lz/lo/2)-1;
	cout << s << endl;
	return 0;
}
