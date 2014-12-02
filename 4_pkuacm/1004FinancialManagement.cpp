#include <iostream>
using namespace std;

int main()
{
	double a;
	double sum = 0.0;
	int i=0;
	while(i<12&&cin>>a)
	{
		i++;
		sum += a;
	}
	cout << "$" << sum/12 << endl;
}
