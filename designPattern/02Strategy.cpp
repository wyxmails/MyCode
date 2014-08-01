#include <iostream>
using namespace std;

class MallCasher{
public:
	MallCasher(){
		total = 0;
	}
	void clear(){
		total = 0;
	}
	double getTotalPrice(double price,int cnt){
		total += price*cnt;
		return total;
	}
private:
	double total;
};
class Offer{
public:
	double discount(double total,int n){
		return total*n/10;
	}
	double getCashBack(double total,int thresh,int back){
		int n = total/thresh;
		return total-n*back;
	}
};
int main(int argc,char *argv[]){
	double p;
	int c;
	MallCasher mc;
	double total = 0;
	while(cin>>p>>c) total = mc.getTotalPrice(p,c);
	cout << total << endl;
	Offer ds;
	total = ds.discount(total,8);
	cout << total << endl;
	total = ds.getCashBack(total,100,10);
	cout << total << endl;
	mc.clear();
	return 0;
}

