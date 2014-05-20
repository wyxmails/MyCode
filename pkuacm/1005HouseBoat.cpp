#include <iostream>
using namespace std;
int main()
{
	int line;
	double x, y;
	cin>>line;
	int year;
	for(int i=0;i<line;++i)
	{
		cin>>x>>y;
		year = 1 + 3.1416*(x*x+y*y)/100.0;
		cout << "Property " << i+1 << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
