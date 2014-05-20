#include <iostream>
using namespace std;

int main(){
	char c;
	bool canBeDivided = false;
	int remainder;
	while(cin>>c){
		remainder = (remainder*2+(c-'0'))%3;
		canBeDivided = (remainder==0);
	}
	if(canBeDivided) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}
