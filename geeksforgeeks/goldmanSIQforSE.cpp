/*
 You have 4218 no of balls. 
 put 1 balls at top layer ,3 at 2nd top layer,
 then 6 and then 10 … Continue in this way. 
 How many layers are possible.? 
 */
#include <iostream>
using namespace std;
//L(n) = (n*(n+1))/2;
int getLayer(int n){
	int res=1;
	int sum=1;
	while(sum<n){
		res++;
		sum += (res*(res+1))/2;
	}
	return res;
}

int main(int argc,char*argv[]){
	int n = 4218;
	cout << getLayer(n) << endl;
	return 0;
}
