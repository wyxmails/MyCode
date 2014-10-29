/*
 Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MoneyPresent(int cents){
	if(cents<0) return 0;
	if(cents<5) return 1;
	return MoneyPresent(cents-25)+MoneyPresent(cents-10)+MoneyPresent(cents-5)+MoneyPresent(cents-1);;
}

int MoneyPresentSets(int cents,int demon){
	int next_demon=0;
	switch(demon){
		case 25:
			next_demon=10;
			break;
		case 10:
			next_demon=5;
			break;
		case 5:
			next_demon=1;
			break;
		case 1:
			return 1;
	}
	int res = 0;
	for(int i=0;i*demon<=cents;++i){
		res += MoneyPresentSets(cents-i*demon,next_demon);
	}
	return res;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%30;
	cout << "cents: " << n << endl;
	cout << "ways: " << MoneyPresent(n) << endl;
	cout << "ways: " << MoneyPresentSets(n,25) << endl;
	return 0;
}
